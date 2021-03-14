
#include <I2C_8Bit.h>


uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr) {
	uint8_t byteCount = 1;

	Wire.beginTransmission(i2cAddr);
	Wire.endTransmission();
	Wire.requestFrom(i2cAddr, byteCount);

	if (Wire.available()) {
		return Wire.read();
	}

	return 0;
}

uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr) {
	uint8_t byteCount = 1;

	Wire.beginTransmission(i2cAddr);
	Wire.write(registerAddr);
	Wire.endTransmission();
	Wire.requestFrom(i2cAddr, byteCount);

	if (Wire.available()) {
		return Wire.read();
	}

	return 0;
}

void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t data) {
	Wire.beginTransmission(i2cAddr);
	Wire.write(data);
	Wire.endTransmission();
}

void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint8_t data) {
	Wire.beginTransmission(i2cAddr);
	Wire.write(registerAddr);
	Wire.write(data);
	Wire.endTransmission();
}

uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t pos) {
	uint8_t registerValue = I2C_8Bit_readFromModule(i2cAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos) {
	uint8_t registerValue = I2C_8Bit_readFromModule(i2cAddr, registerAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value) {
	uint8_t registerValue = I2C_8Bit_readFromModule(i2cAddr);
	registerValue = I2C_8Bit_setBinary(registerValue, pos, value);
	I2C_8Bit_writeToModule(i2cAddr, registerValue);
}

void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value) {
	uint8_t registerValue = I2C_8Bit_readFromModule(i2cAddr, registerAddr);
	registerValue = I2C_8Bit_setBinary(registerValue, pos, value);
	I2C_8Bit_writeToModule(i2cAddr, registerAddr, registerValue);
}

uint8_t I2C_8Bit_setBinary(uint8_t binary, uint8_t pos, uint8_t flagVal) {
	if (flagVal == 1) {
		return binary | (1 << pos);
	}

	return binary & (~(1 << pos));
}