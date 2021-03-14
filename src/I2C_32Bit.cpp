
#include <I2C_32Bit.h>

uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr) {
	uint8_t byteCount = 4;

	Wire.beginTransmission(i2cAddr);
	Wire.endTransmission();
	Wire.requestFrom(i2cAddr, byteCount);

	if (Wire.available()) {
		uint8_t firstByte = Wire.read();
		uint8_t secondByte = Wire.read();
		uint8_t thirdByte = Wire.read();
		uint8_t fourthByte = Wire.read();

		return (firstByte << 24) + (secondByte << 16) + (thirdByte << 8) + fourthByte;
	}

	return 0;
}

uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr) {
	uint8_t byteCount = 4;

	Wire.beginTransmission(i2cAddr);
	Wire.write(registerAddr);
	Wire.endTransmission();
	Wire.requestFrom(i2cAddr, byteCount);

	if (Wire.available()) {
		uint8_t firstByte = Wire.read();
		uint8_t secondByte = Wire.read();
		uint8_t thirdByte = Wire.read();
		uint8_t fourthByte = Wire.read();

		return (firstByte << 24) + (secondByte << 16) + (thirdByte << 8) + fourthByte;
	}

	return 0;
}

void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint32_t data) {
	uint8_t firstByte = data >> 24;
	uint8_t secondByte = (data >> 16) & 255;
	uint8_t thirdByte = (data >> 8) & 255;
	uint8_t forthByte = data & 255;

	Wire.beginTransmission(i2cAddr);
	Wire.write(firstByte);
	Wire.write(secondByte);
	Wire.write(thirdByte);
	Wire.write(forthByte);
	Wire.endTransmission();
}

void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint32_t data) {
	uint8_t firstByte = data >> 24;
	uint8_t secondByte = (data >> 16) & 255;
	uint8_t thirdByte = (data >> 8) & 255;
	uint8_t forthByte = data & 255;

	Wire.beginTransmission(i2cAddr);
	Wire.write(registerAddr);
	Wire.write(firstByte);
	Wire.write(secondByte);
	Wire.write(thirdByte);
	Wire.write(forthByte);
	Wire.endTransmission();
}

uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t pos) {
	uint32_t registerValue = I2C_32Bit_readFromModule(i2cAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos) {
	uint32_t registerValue = I2C_32Bit_readFromModule(i2cAddr, registerAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value) {
	uint32_t registerValue = I2C_32Bit_readFromModule(i2cAddr);
	registerValue = I2C_32Bit_setBinary(registerValue, pos, value);
	I2C_32Bit_writeToModule(i2cAddr, registerValue);
}

void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value) {
	uint32_t registerValue = I2C_32Bit_readFromModule(i2cAddr, registerAddr);
	registerValue = I2C_32Bit_setBinary(registerValue, pos, value);
	I2C_32Bit_writeToModule(i2cAddr, registerAddr, registerValue);
}

uint32_t I2C_32Bit_setBinary(uint32_t binary, uint8_t pos, uint8_t flagVal) {
	if (flagVal == 1) {
		return binary | (1 << pos);
	}

	return binary & (~(1 << pos));
}