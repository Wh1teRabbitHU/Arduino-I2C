#include <I2C_16Bit.h>
#include <Wire.h>

// Put your own I2C address here
#define I2C_ADDR 0xFF

// Your register address, which can be found on your IC's datasheet
#define DATA_REGISTER_ADDR 0x12

void setup() {
	I2C_16Bit_begin();
}

uint16_t counter = 0;

void loop() {
	I2C_16Bit_writeToModule(I2C_ADDR, DATA_REGISTER_ADDR, counter++);

	delay(1000);
}