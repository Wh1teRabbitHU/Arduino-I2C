# Arduino-I2C

- [Arduino-I2C](#arduino-i2c)
	- [Description](#description)
	- [Functions](#functions)
		- [I2C_XXBit_readFromModule](#i2c_xxbit_readfrommodule)
		- [I2C_XXBit_writeToModule](#i2c_xxbit_writetomodule)
		- [I2C_XXBit_readFlag](#i2c_xxbit_readflag)
		- [I2C_XXBit_writeFlag](#i2c_xxbit_writeflag)
		- [I2C_XXBit_setBinary](#i2c_xxbit_setbinary)
	- [Macros](#macros)
		- [GET_BIT_VALUE(binary, pos)](#get_bit_valuebinary-pos)

## Description

A ligthweight communication library over the Arduino framework to make the I2C communication simpler with external IC's like sensors, RTC, ADCs, DACs and many others. Under the hood this library is using the Wire and the Arduino library to deal with the low level communication. Depending on the target device's register size, there are 3 different variations available: 8Bit, 16Bit and 32Bit. Each variation has it's own separate source filse, include the one that your target IC has. (I2C_8Bit.h, I2C_16Bit.h and I2C_32Bit.h) You can include more than one variants if necessary, every variant has it's own unique prefixes.

## Functions

The following functions are available in every variant with the same name, the anly differences are the size of the used register size. and the method prefixes.

### I2C_XXBit_readFromModule

__Full signatures:__
- uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr);
- uint8_t I2C_8Bit_readFromModule(TwoWire &wire, uint8_t i2cAddr);
- uint16_t I2C_16Bit_readFromModule(uint8_t i2cAddr);
- uint16_t I2C_16Bit_readFromModule(TwoWire &wire, uint8_t i2cAddr);
- uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr);
- uint32_t I2C_32Bit_readFromModule(TwoWire &wire, uint8_t i2cAddr);
- uint8_t I2C_8Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr);
- uint8_t I2C_8Bit_readFromModule(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr);
- uint16_t I2C_16Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr);
- uint16_t I2C_16Bit_readFromModule(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr);
- uint32_t I2C_32Bit_readFromModule(uint8_t i2cAddr, uint8_t registerAddr);
- uint32_t I2C_32Bit_readFromModule(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr);

These methods are reading a register value from the target slave device. If the data is unavailable or something went wrong with the addressing, this method will return with 0. The provided register address points to the target register. The methods without register address are special version of the same implementation, because some ICs need no register addressing. The return type depends on the variation and it returns the full content of the target register, without consumption.

### I2C_XXBit_writeToModule

__Full signatures:__
- void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t data);
- void I2C_8Bit_writeToModule(TwoWire &wire, uint8_t i2cAddr, uint8_t data);
- void I2C_16Bit_writeToModule(uint8_t i2cAddr, uint16_t data);
- void I2C_16Bit_writeToModule(TwoWire &wire, uint8_t i2cAddr, uint16_t data);
- void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint32_t data);
- void I2C_32Bit_writeToModule(TwoWire &wire, uint8_t i2cAddr, uint32_t data);
- void I2C_8Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint8_t data);
- void I2C_8Bit_writeToModule(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t data);
- void I2C_16Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint16_t data);
- void I2C_16Bit_writeToModule(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint16_t data);
- void I2C_32Bit_writeToModule(uint8_t i2cAddr, uint8_t registerAddr, uint32_t data);
- void I2C_32Bit_writeToModule(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint32_t data);

These methods are writing into a register to a target slave device. The provided register address points to the target register. The methods without register address are special version of the same implementation, because some ICs need no register addressing. The input data parameter will be written into the target register without any modification or truncation. If the register contains more than one unique data, you have to take care of that. (The read/write flag methods can help with that, more details below)

### I2C_XXBit_readFlag

__Full signatures:__
- uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t pos);
- uint8_t I2C_8Bit_readFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t pos);
- uint8_t I2C_16Bit_readFlag(uint8_t i2cAddr, uint8_t pos);
- uint8_t I2C_16Bit_readFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t pos);
- uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t pos);
- uint8_t I2C_32Bit_readFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t pos);
- uint8_t I2C_8Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
- uint8_t I2C_8Bit_readFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
- uint8_t I2C_16Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
- uint8_t I2C_16Bit_readFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
- uint8_t I2C_32Bit_readFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);
- uint8_t I2C_32Bit_readFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos);

This method will only read one bit of data from the provided register address from the provided bit position. The methods without register address are special version of the same implementation, because some ICs need no register addressing. The return value is always one bit, which can be used as a 'boolean' data type.

### I2C_XXBit_writeFlag

__Full signatures:__
- void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value);
- void I2C_8Bit_writeFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t pos, uint8_t value);
- void I2C_16Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value);
- void I2C_16Bit_writeFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t pos, uint8_t value);
- void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t pos, uint8_t value);
- void I2C_32Bit_writeFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t pos, uint8_t value);
- void I2C_8Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
- void I2C_8Bit_writeFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
- void I2C_16Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
- void I2C_16Bit_writeFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
- void I2C_32Bit_writeFlag(uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);
- void I2C_32Bit_writeFlag(TwoWire &wire, uint8_t i2cAddr, uint8_t registerAddr, uint8_t pos, uint8_t value);

This method writes only one bit in the target slave device on the provided register address. The methods without register address are special version of the same implementation, because some ICs need no register addressing. The provided value should be a binary type, using any other values might cause unexpected behaviour. (It will always clear the flag if the provided value is larger than 1 bit) To change a flag on the target device, the library has to read the full register value and after manipulating it, writing back to the device. If the IC relies on the write operation, it should be considered before using this method.

### I2C_XXBit_setBinary

__Full signatures:__
- uint8_t I2C_8Bit_setBinary(uint8_t binary, uint8_t pos, uint8_t flagVal);
- uint16_t I2C_16Bit_setBinary(uint16_t binary, uint8_t pos, uint8_t flagVal);
- uint32_t I2C_32Bit_setBinary(uint32_t binary, uint8_t pos, uint8_t flagVal);

This is a util method which can help with changing a flag's value in a registry value. It will ony change the bit on the given position, so it's ideal to change multiple flags at once. The return value is the updated register value. Important to note, that tthis method will not communicate with the device, the changes are local and only visible on the return value.

## Macros

The following macro is available in every variant:

### GET_BIT_VALUE(binary, pos)

It returns the one bit value from the given integer from the provided bit position.

