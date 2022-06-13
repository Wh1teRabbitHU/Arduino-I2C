#ifndef I2C_32BIT
#define I2C_32BIT

#include <Arduino.h>
#include <Wire.h>

#define GET_BIT_VALUE(binary, pos) (((binary >> pos) & 1) == 1 ? 1 : 0)

void I2C_32Bit_begin();

uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr);
uint32_t I2C_32Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr);
uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr);
uint32_t I2C_32Bit_readFromModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr);
void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint32_t data);
void I2C_32Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint32_t data);
void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint32_t data);
void I2C_32Bit_writeToModule(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint32_t data);

uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t pos);
uint8_t I2C_32Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos);
uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
uint8_t I2C_32Bit_readFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value);
void I2C_32Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t pos, uint8_t value);
void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
void I2C_32Bit_writeFlag(TwoWire *wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);

uint32_t I2C_32Bit_setBinary(uint32_t binary, uint8_t pos, uint8_t flagVal);

#endif