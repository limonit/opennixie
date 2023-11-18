#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/rtc.h"
#include "pico/time.h"
#include "main.h"
#include "displayHAL.h"
#include "ntp_client.h"
#include "button.h"
#include "pico/cyw43_arch.h"

#include "lwip/dns.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"

bool timer_100us_isr(struct repeating_timer *t);
bool timer_100us_isr2(struct repeating_timer *t);
struct repeating_timer timer;
struct repeating_timer timer3;
NTP_T *state = NULL;
struct button buttonA;
enum Mode mode;

static bool ntp_update_time(struct repeating_timer *t)
{
  cyw43_arch_lwip_begin();
  int err = dns_gethostbyname(NTP_SERVER, &state->ntp_server_address, ntp_dns_found, state);
  cyw43_arch_lwip_end();
  state->dns_request_sent = true;
  if (err == ERR_OK)
  {
    ntp_request(state); // Cached result
  }
  else if (err != ERR_INPROGRESS)
  { // ERR_INPROGRESS means expect a callback
    printf("dns request failed\n");
    ntp_result(state, -1, NULL);
  }
  return true;
}

int64_t modeAlarmCb(alarm_id_t id, void *user_data)
{
  mode = DISPLAY_TIME;
  return 0;
}

int init_everything()
{
  displayHALInit();
  datetime_t t;
  memset(&t, 0, sizeof(datetime_t));
  rtc_init();
  rtc_set_datetime(&t);
  add_repeating_timer_us(100, timer_100us_isr, NULL, &timer);
  displayHALSetDim(false);

  if (cyw43_arch_init())
  {
    printf("failed to initialise WiFi\n");
    cancel_repeating_timer(&timer);
    return 1;
  }

  cyw43_arch_enable_sta_mode();

  if (cyw43_arch_wifi_connect_timeout_ms(ssid, pass, CYW43_AUTH_WPA2_AES_PSK, 10000))
  {
    printf("failed to connect\n");
    cancel_repeating_timer(&timer);
    cyw43_arch_deinit();
    return 1;
  }

  buttonInit(&buttonA, 14);
  mode = DISPLAY_TIME;

  return 0;
}

int main(void)
{
  stdio_init_all();
  while (init_everything())
  {
    printf("Initialization failed. Retrying...\n");
    sleep_ms(1500);
  }
  state = ntp_init();
  ntp_update_time(NULL);
  add_repeating_timer_ms(30 * 15 * 1000, ntp_update_time, NULL, &timer3);

  while (1)
  {
    cyw43_arch_poll();
    if (buttonIsKeyPressed(&buttonA)) {
      static alarm_id_t modeAlarm = -1;
      if (mode != DISPLAY_TIME) {
        cancel_alarm(modeAlarm); 
        if (++timezone > 12) {
          timezone = -12;
        }
      }
      mode = SET_TIMEZONE;
      modeAlarm = add_alarm_in_ms(2000, modeAlarmCb, NULL, false);
      datetime_t utc_time;
      rtc_get_datetime(&utc_time);
      int8_t local_hour = utc_time.hour + timezone;
      if (local_hour > 23) local_hour -= 24;
      if (local_hour < 0) local_hour += 24;
      displayHALSetImmediatly(local_hour/10, local_hour%10, abs(timezone)/10, abs(timezone)%10);
    }
    sleep_ms(20);
  }
}

bool timer_100us_isr(struct repeating_timer *t)
{
  static uint8_t buttonCnt = 0;
  static uint16_t basicCnt = 0;
  displayHAL100usStep();

  if (++buttonCnt > 100) {
    buttonCnt = 0;
    button10MsStep(&buttonA);
  }

  if (mode == DISPLAY_TIME) {
    if (++basicCnt > 20000) {
      basicCnt = 0;
      datetime_t utc_time;
      rtc_get_datetime(&utc_time);
      int8_t local_hour = utc_time.hour + timezone;
      if (local_hour > 23) local_hour -= 24;
      if (local_hour < 0) local_hour += 24;
      displayHALSetCrossfade(local_hour / 10, local_hour % 10, utc_time.min / 10, utc_time.min % 10);
    }
  }
  return true;
}