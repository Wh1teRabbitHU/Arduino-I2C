#include <I2C_16Bit.h>
#include <Wire.h>

// Put your own I2C address here
#define I2C_ADDR 0xFF

// Your register address, which can be found on your IC's datasheet
#define DATA_REGISTER_ADDR 0x12
#define ENABLED_FLAG_POS 3

void setup() {
	Serial.begin(9600);

	I2C_16Bit_begin();
}

void loop() {
	uint8_t flagValue = I2C_16Bit_readFlag(I2C_ADDR, DATA_REGISTER_ADDR, ENABLED_FLAG_POS);

	Serial.print("Enabled: ");
	Serial.println(flagValue ? "Yes" : "No");

	delay(1000);
}