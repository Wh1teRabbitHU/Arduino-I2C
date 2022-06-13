#ifndef I2C_16BIT
#define I2C_16BIT

#include <Arduino.h>
#include <Wire.h>

#define GET_BIT_VALUE(binary, pos) (((binary >> pos) & 1) == 1 ? 1 : 0)

void I2C_16Bit_begin();

uint16_t I2C_16Bit_readFromModule(uint8_t i2cAddr);
uint16_t I2C_16Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr);
uint16_t I2C_16Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr);
uint16_t I2C_16Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr);
void I2C_16Bit_writeToModule(uint8_t i2cAddr, uint16_t data);
void I2C_16Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint16_t data);
void I2C_16Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint16_t data);
void I2C_16Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint16_t data);

uint8_t I2C_16Bit_readFlag(uint8_t i2cAddr, uint8_t pos);
uint8_t I2C_16Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos);
uint8_t I2C_16Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
uint8_t I2C_16Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
void I2C_16Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value);
void I2C_16Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos, uint8_t value);
void I2C_16Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
void I2C_16Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);

uint16_t I2C_16Bit_setBinary(uint16_t binary, uint8_t pos, uint8_t flagVal);

#endif