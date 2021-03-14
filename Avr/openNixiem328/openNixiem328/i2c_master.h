/*
 * i2c_master.h
 *
 * Created: 2018-04-01 12:41:01
 *  Author: Trojan
 */ 


#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_

#define I2C_READ 0x01
#define I2C_WRITE 0x00

void i2c_init(void);
char i2c_start(char address);
char i2c_write(char data);
char i2c_read_ack(void);
char i2c_read_nack(void);
char i2c_transmit(char address, char* data, int length);
char i2c_receive(char address, char* data, int length);
char i2c_writeReg(char devaddr, char regaddr, char* data, int length);
char i2c_readReg(char devaddr, char regaddr, char* data, int length);
void i2c_stop(void);

#endif /* I2C_MASTER_H_ */