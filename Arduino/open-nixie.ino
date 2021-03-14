#include <ESP8266WiFi.h>
#include <time.h>
#include <EEPROM.h>
#include "sntp.h"
unsigned long timer_cntr;
unsigned long timeUpdateTimer;
unsigned long buttonTimer;
unsigned long sysTick;
unsigned long int seconds = 0;
unsigned int wifiMonitorTimer;
unsigned int currentNetwork;
bool connectedSincePoweron = false;
bool dim = true;
signed char timezone = 0;

String ssids[] = { "FreeWifi" , "network2", "blablabla"};
String keys[] = { "", "network2key", "blablabla" };

enum  {
  FAILURE,
  CONNECTED,
  SCANNING,
  SETUP,
  CONNECTION_DELAY
} connectionStatus;

enum  {
  TIME,
  TIMEZONE
} clockMode;

int display[4];

#define TUBE1 5
#define TUBE2 4
#define TUBE3 0
#define TUBE4 2

#define DECODER_A 14
#define DECODER_B 12
#define DECODER_C 13
#define DECODER_D 15

#define BUTTON_UP 1
#define BUTTON_DN 3

#define LED 16

#define NETWORKS_NUMBER  (sizeof(ssids) / sizeof(ssids[0]))

void setup() {

  EEPROM.begin(sizeof(char));
  timezone = EEPROM.read(0);


  
  // initialize inbuilt LED pin as an output.
  pinMode(TUBE1, OUTPUT);
  pinMode(TUBE2, OUTPUT);
  pinMode(TUBE3, OUTPUT);
  pinMode(TUBE4, OUTPUT);

  pinMode(DECODER_A, OUTPUT);
  pinMode(DECODER_B, OUTPUT);
  pinMode(DECODER_C, OUTPUT);
  pinMode(DECODER_D, OUTPUT);

  pinMode(LED, OUTPUT);

  pinMode(BUTTON_UP, INPUT);
  pinMode(BUTTON_DN, INPUT);

  digitalWrite(TUBE1, LOW);
  digitalWrite(TUBE2, LOW);
  digitalWrite(TUBE3, LOW);
  digitalWrite(TUBE4, LOW);

  digitalWrite(DECODER_A, HIGH);
  digitalWrite(DECODER_B, HIGH);
  digitalWrite(DECODER_C, HIGH);
  digitalWrite(DECODER_D, HIGH);
  
  testTubes();
  
  timer_cntr = micros();
  set_number (11);

  display[0] = NETWORKS_NUMBER / 10;
  display[1] = NETWORKS_NUMBER % 10;
  display[2] = WiFi.scanNetworks() / 10;
  display[3] = WiFi.scanNetworks() % 10;

  timeUpdateTimer = millis();

  connectionStatus = FAILURE;
  wifiMonitorTimer = seconds;

  digitalWrite(LED, LOW);

  WiFi.softAP("net-fake", "12345678aaaaqwer", 2, true);

  configTime(3600 * timezone, 0, "0.pl.pool.ntp.org", "0.europe.pool.ntp.org", "0.pool.ntp.org");

  monitorWiFi();
}

// loop function runs over and over again forever
void loop() {

  if ((micros() - timer_cntr) > 2800) {
    timer_cntr = timer_cntr + 2800;
    switch_tube();
    delay(2);
  }

  if ((millis() - sysTick) > 1000) {
    sysTick = millis();
    seconds++;
  }

  if (digitalRead(BUTTON_UP) == LOW || digitalRead(BUTTON_DN) == LOW) {
    if (digitalRead(BUTTON_UP) == LOW && clockMode == TIME) {
      clockMode = TIMEZONE;
      buttonTimer = millis();
    } else if (digitalRead(BUTTON_UP) == LOW && (clockMode == TIMEZONE) && (millis() - buttonTimer > 500)) {
      timezone++;
      if (timezone >= 12) timezone = 12;
      configTime(3600 * timezone, 0, "0.pl.pool.ntp.org", "0.europe.pool.ntp.org", "0.pool.ntp.org");
      buttonTimer = millis();
    }
    else if (digitalRead(BUTTON_DN) == LOW && (clockMode == TIMEZONE) && (millis() - buttonTimer > 500)) {
      timezone--;
      if (timezone <= -12) timezone = -12;
      configTime(3600 * timezone, 0, "0.pl.pool.ntp.org", "0.europe.pool.ntp.org", "0.pool.ntp.org");
      buttonTimer = millis();
    }
  }

  if (clockMode == TIMEZONE && (millis() - buttonTimer > 5000)) {
    clockMode = TIME;
    timeUpdateTimer = millis() + 10001;
    EEPROM.write(0, timezone);
    EEPROM.commit();
  }

  if (digitalRead(BUTTON_DN) == LOW) {
    if (millis() - buttonTimer > 500) {
      buttonTimer = millis();
      if (digitalRead(LED) == LOW) digitalWrite(LED, HIGH);
      else digitalWrite(LED, LOW);
    }
  }

  if (((millis() - timeUpdateTimer) > 10000) && clockMode == TIME) {
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    display[0] = t->tm_hour / 10;
    display[1] = t->tm_hour % 10;
    display[2] = t->tm_min / 10;
    display[3] = t->tm_min % 10;
    timeUpdateTimer = millis();

    if (t->tm_hour >= 23 || t->tm_hour <= 5) dim = true;
    else dim = false;
  }

    if (((millis() - timeUpdateTimer) > 250) && clockMode == TIMEZONE) {
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    display[0] = t->tm_hour / 10;
    display[1] = t->tm_hour % 10;
    display[2] = abs(timezone) / 10;
    display[3] = abs(timezone) % 10;
    timeUpdateTimer = millis();
  }

  if ((connectionStatus == FAILURE && seconds - wifiMonitorTimer > 20 && !connectedSincePoweron) ||
      (connectionStatus == FAILURE && seconds - wifiMonitorTimer > 5 * 60 && connectedSincePoweron)) {
    monitorWiFi();
  }

  if (connectionStatus == CONNECTED && seconds - wifiMonitorTimer > 60) {
    monitorWiFi();
  }

  if (connectionStatus == SCANNING && ((seconds - wifiMonitorTimer > 5) || (WiFi.scanComplete() >= 0))) {
    monitorWiFi();
  }

  if (connectionStatus == SETUP && seconds - wifiMonitorTimer > 1) {
    WiFi.disconnect();
    WiFi.begin(ssids[currentNetwork].c_str(), keys[currentNetwork].c_str());
    delay(1);
    monitorWiFi();
  }

  if (connectionStatus == CONNECTION_DELAY && seconds - wifiMonitorTimer > 15) {
    monitorWiFi();
  }

}

void switch_tube()
{
  static int current_tube = 0;
  static int dimmer = 0;
  set_number(11);

  dimmer++;
  if (!(dimmer%3) && dim) {
    digitalWrite(TUBE1, LOW);
    digitalWrite(TUBE2, LOW);
    digitalWrite(TUBE3, LOW);
    digitalWrite(TUBE4, LOW);
    return;
  }

  if (current_tube == 0) { 
    digitalWrite(TUBE4, LOW);
    if (display[current_tube] != 0) {
      set_number(display[current_tube]);
      digitalWrite(TUBE1, HIGH);
    }
    current_tube = 1;
    return;
  }

  if (current_tube == 1) {
    digitalWrite(TUBE1, LOW);
    set_number(display[current_tube]);   
    digitalWrite(TUBE2, HIGH);
    current_tube = 2;
    return;
  }

  if (current_tube == 2) {  
    digitalWrite(TUBE2, LOW);
    set_number(display[current_tube]);
    digitalWrite(TUBE3, HIGH);
    current_tube = 3;
    return;
  }

  if (current_tube == 3) {    
    digitalWrite(TUBE3, LOW);
    set_number(display[current_tube]);
    digitalWrite(TUBE4, HIGH);
    current_tube = 0;
    return;
  }
}

void set_number (int digit)
{
  if (digit == 0) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, HIGH);
    digitalWrite(DECODER_C, LOW);
    digitalWrite(DECODER_A, LOW);
  }

  if (digit == 1) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, HIGH);
    digitalWrite(DECODER_C, HIGH);
    digitalWrite(DECODER_A, LOW);
  }

  if (digit == 2) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, HIGH);
    digitalWrite(DECODER_C, HIGH);
    digitalWrite(DECODER_A, HIGH);
  }

  if (digit == 3) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, LOW);
    digitalWrite(DECODER_C, HIGH);
    digitalWrite(DECODER_A, HIGH);
  }
  if (digit == 4) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, LOW);
    digitalWrite(DECODER_C, HIGH);
    digitalWrite(DECODER_A, LOW);
  }

  if (digit == 5) {
    digitalWrite(DECODER_B, HIGH);
    digitalWrite(DECODER_D, LOW);
    digitalWrite(DECODER_C, LOW);
    digitalWrite(DECODER_A, LOW);
  }

  if (digit == 6) {
    digitalWrite(DECODER_B, HIGH);
    digitalWrite(DECODER_D, LOW);
    digitalWrite(DECODER_C, LOW);
    digitalWrite(DECODER_A, HIGH);
  }

  if (digit == 8) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, LOW);
    digitalWrite(DECODER_C, LOW);
    digitalWrite(DECODER_A, HIGH);
  }

  if (digit == 7) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, LOW);
    digitalWrite(DECODER_C, LOW);
    digitalWrite(DECODER_A, LOW);
  }

  if (digit == 9) {
    digitalWrite(DECODER_B, LOW);
    digitalWrite(DECODER_D, HIGH);
    digitalWrite(DECODER_C, LOW);
    digitalWrite(DECODER_A, HIGH);
  }

  if (digit >= 10) {
    digitalWrite(DECODER_B, HIGH);
    digitalWrite(DECODER_D, HIGH);
    digitalWrite(DECODER_C, HIGH);
    digitalWrite(DECODER_A, HIGH);
  }
}

void monitorWiFi()
{
  wifiMonitorTimer = seconds;

  if (WiFi.status() == WL_CONNECTED) {
    connectionStatus = CONNECTED;
    WiFi.scanDelete();
    configTime(3600 * timezone, 0, "0.pl.pool.ntp.org", "0.europe.pool.ntp.org", "0.pool.ntp.org");
    connectedSincePoweron = true;
    return;
  }

  if (connectionStatus == CONNECTED || connectionStatus == FAILURE) {
    WiFi.scanNetworks(true);
    connectionStatus = SCANNING;
    return;
  }

  if (connectionStatus == SETUP) {
    connectionStatus = CONNECTION_DELAY;
    return;
  }

  if (connectionStatus == CONNECTION_DELAY) {
    connectionStatus = FAILURE;
    return;
  }

  if (connectionStatus == SCANNING) {
    int n = WiFi.scanComplete();
    int j = 0;
    for (int i = 0; i < n; i++) {
      for (j = 0; j < NETWORKS_NUMBER; j++) {
        if (WiFi.SSID(i) == ssids[j]) {
          WiFi.scanDelete();
          connectionStatus = SETUP;
          currentNetwork = j;
          return;
        }
      }
    }
    WiFi.scanDelete();
    WiFi.disconnect();
    connectionStatus = FAILURE;
    return;
  }
}

void testTubes()
{
  digitalWrite(TUBE1, LOW);
  digitalWrite(TUBE2, LOW);
  digitalWrite(TUBE3, LOW);
  digitalWrite(TUBE4, LOW);

  digitalWrite(TUBE1, HIGH);
  for (int i = 0; i < 10; i++) {
    set_number(i);
    delay(200);
  }
  digitalWrite(TUBE1, LOW);

  digitalWrite(TUBE2, HIGH);
  for (int i = 0; i < 10; i++) {
    set_number(i);
    delay(200);
  }
  digitalWrite(TUBE2, LOW);

  digitalWrite(TUBE3, HIGH);
  for (int i = 0; i < 10; i++) {
    set_number(i);
    delay(200);
  }
  digitalWrite(TUBE3, LOW);

  digitalWrite(TUBE4, HIGH);
  for (int i = 0; i < 10; i++) {
    set_number(i);
    delay(200);
  }
  digitalWrite(TUBE4, LOW);
}
