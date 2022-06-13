
#include <I2C_8Bit.h>

void I2C_8Bit_begin() {
	Wire.begin();
}

uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr) {
	return I2C_8Bit_readFromModule(&Wire, i2cAddr);
}

uint8_t I2C_8Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr) {
	uint8_t byteCount = 1;

	wire->beginTransmission(i2cAddr);
	wire->endTransmission();
	wire->requestFrom(i2cAddr, byteCount);

	if (wire->available()) {
		return wire->read();
	}

	return 0;
}

uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr) {
	return I2C_8Bit_readFromModule(&Wire, i2cAddr, registerAddr);
}

uint8_t I2C_8Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr) {
	uint8_t byteCount = 1;

	wire->beginTransmission(i2cAddr);
	wire->write(registerAddr);
	wire->endTransmission();
	wire->requestFrom(i2cAddr, byteCount);

	if (wire->available()) {
		return wire->read();
	}

	return 0;
}

void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t data) {
	I2C_8Bit_writeToModule(&Wire, i2cAddr, data);
}

void I2C_8Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint8_t data) {
	wire->beginTransmission(i2cAddr);
	wire->write(data);
	wire->endTransmission();
}

void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint8_t data) {
	I2C_8Bit_writeToModule(&Wire, i2cAddr, registerAddr, data);
}

void I2C_8Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t data) {
	wire->beginTransmission(i2cAddr);
	wire->write(registerAddr);
	wire->write(data);
	wire->endTransmission();
}

uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t pos) {
	return I2C_8Bit_readFlag(&Wire, i2cAddr, pos);
}

uint8_t I2C_8Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos) {
	uint8_t registerValue = I2C_8Bit_readFromModule(i2cAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos) {
	return I2C_8Bit_readFlag(&Wire, i2cAddr, registerAddr, pos);
}

uint8_t I2C_8Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos) {
	uint8_t registerValue = I2C_8Bit_readFromModule(i2cAddr, registerAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value) {
	I2C_8Bit_writeFlag(&Wire, i2cAddr, pos, value);
}

void I2C_8Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos, uint8_t value) {
	uint8_t registerValue = I2C_8Bit_readFromModule(i2cAddr);
	registerValue = I2C_8Bit_setBinary(registerValue, pos, value);
	I2C_8Bit_writeToModule(i2cAddr, registerValue);
}

void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value) {
	I2C_8Bit_writeFlag(&Wire, i2cAddr, registerAddr, pos, value);
}

void I2C_8Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value) {
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