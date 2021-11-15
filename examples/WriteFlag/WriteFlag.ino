#include <I2C_16Bit.h>
#include <Wire.h>

// Put your own I2C address here
#define I2C_ADDR 0xFF

// Your register address, which can be found on your IC's datasheet
#define DATA_REGISTER_ADDR 0x12
#define ENABLED_FLAG_POS 3

void setup() {
	I2C_16Bit_begin();
}

uint8_t isEnabled = 0;

void loop() {
	I2C_16Bit_writeFlag(I2C_ADDR, DATA_REGISTER_ADDR, ENABLED_FLAG_POS, isEnabled);

	isEnabled = isEnabled == 1 ? 0 : 1;

	delay(1000);
}