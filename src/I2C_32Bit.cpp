
#include <I2C_32Bit.h>

void I2C_32Bit_begin() {
	Wire.begin();
}

uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr) {
	return I2C_32Bit_readFromModule(&Wire, i2cAddr);
}

uint32_t I2C_32Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr) {
	uint8_t byteCount = 4;

	wire->beginTransmission(i2cAddr);
	wire->endTransmission();
	wire->requestFrom(i2cAddr, byteCount);

	if (wire->available()) {
		uint32_t firstByte = wire->read();
		uint32_t secondByte = wire->read();
		uint32_t thirdByte = wire->read();
		uint32_t fourthByte = wire->read();

		return (firstByte << 24) + (secondByte << 16) + (thirdByte << 8) + fourthByte;
	}

	return 0;
}

uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr) {
	return I2C_32Bit_readFromModule(&Wire, i2cAddr, registerAddr);
}

uint32_t I2C_32Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr) {
	uint8_t byteCount = 4;

	wire->beginTransmission(i2cAddr);
	wire->write(registerAddr);
	wire->endTransmission();
	wire->requestFrom(i2cAddr, byteCount);

	if (wire->available()) {
		uint32_t firstByte = wire->read();
		uint32_t secondByte = wire->read();
		uint32_t thirdByte = wire->read();
		uint32_t fourthByte = wire->read();

		return (firstByte << 24) + (secondByte << 16) + (thirdByte << 8) + fourthByte;
	}

	return 0;
}

void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint32_t data) {
	I2C_32Bit_writeToModule(&Wire, i2cAddr, data);
}

void I2C_32Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint32_t data) {
	uint8_t firstByte = data >> 24;
	uint8_t secondByte = (data >> 16) & 255;
	uint8_t thirdByte = (data >> 8) & 255;
	uint8_t forthByte = data & 255;

	wire->beginTransmission(i2cAddr);
	wire->write(firstByte);
	wire->write(secondByte);
	wire->write(thirdByte);
	wire->write(forthByte);
	wire->endTransmission();
}

void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint32_t data) {
	I2C_32Bit_writeToModule(&Wire, i2cAddr, registerAddr, data);
}

void I2C_32Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint32_t data) {
	uint8_t firstByte = data >> 24;
	uint8_t secondByte = (data >> 16) & 255;
	uint8_t thirdByte = (data >> 8) & 255;
	uint8_t forthByte = data & 255;

	wire->beginTransmission(i2cAddr);
	wire->write(registerAddr);
	wire->write(firstByte);
	wire->write(secondByte);
	wire->write(thirdByte);
	wire->write(forthByte);
	wire->endTransmission();
}

uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t pos) {
	return I2C_32Bit_readFlag(&Wire, i2cAddr, pos);
}

uint8_t I2C_32Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos) {
	uint32_t registerValue = I2C_32Bit_readFromModule(i2cAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos) {
	return I2C_32Bit_readFlag(&Wire, i2cAddr, registerAddr, pos);
}

uint8_t I2C_32Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos) {
	uint32_t registerValue = I2C_32Bit_readFromModule(i2cAddr, registerAddr);

	return GET_BIT_VALUE(registerValue, pos);
}

void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value) {
	I2C_32Bit_writeFlag(&Wire, i2cAddr, pos, value);
}

void I2C_32Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos, uint8_t value) {
	uint32_t registerValue = I2C_32Bit_readFromModule(i2cAddr);
	registerValue = I2C_32Bit_setBinary(registerValue, pos, value);
	I2C_32Bit_writeToModule(i2cAddr, registerValue);
}

void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value) {
	I2C_32Bit_writeFlag(&Wire, i2cAddr, registerAddr, pos, value);
}

void I2C_32Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value) {
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