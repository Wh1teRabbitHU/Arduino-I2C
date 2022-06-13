#ifndef I2C_8BIT
#define I2C_8BIT

#include <Arduino.h>
#include <Wire.h>

#define GET_BIT_VALUE(binary, pos) (((binary >> pos) & 1) == 1 ? 1 : 0)

void I2C_8Bit_begin();

uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr);
uint8_t I2C_8Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr);
uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr);
uint8_t I2C_8Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr);
void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t data);
void I2C_8Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint8_t data);
void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint8_t data);
void I2C_8Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t data);

uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t pos);
uint8_t I2C_8Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos);
uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
uint8_t I2C_8Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value);
void I2C_8Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos, uint8_t value);
void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
void I2C_8Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);

uint8_t I2C_8Bit_setBinary(uint8_t binary, uint8_t pos, uint8_t flagVal);

#endif