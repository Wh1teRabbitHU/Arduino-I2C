#include <I2C_16Bit.h>
#include <Wire.h>

// Put your own I2C address here
#define I2C_ADDR 0xFF

// Your register address, which can be found on your IC's datasheet
#define DATA_REGISTER_ADDR 0x12

void setup() {
	Serial.begin(9600);

	I2C_16Bit_begin();
}

void loop() {
	uint16_t registerData = I2C_16Bit_readFromModule(I2C_ADDR, DATA_REGISTER_ADDR);

	Serial.print("Register data: ");
	Serial.println(registerData);

	delay(1000);
}