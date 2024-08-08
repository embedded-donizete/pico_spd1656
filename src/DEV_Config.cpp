/*****************************************************************************
* | File      	:   DEV_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*----------------
* |	This version:   V3.0
* | Date        :   2019-07-31
* | Info        :   
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of theex Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include <Arduino.h>
#include <SPI.h>

#include "DEV_Config.h"

/**
 * GPIO read and write
**/
void DEV_Digital_Write(UWORD Pin, UBYTE Value)
{
	digitalWrite(Pin, Value);
}

UBYTE DEV_Digital_Read(UWORD Pin)
{
	return digitalRead(Pin);
}

/**
 * SPI
**/

arduino::MbedSPI MY_SPI(-1, EPD_MOSI_PIN, EPD_CLK_PIN);

void DEV_SPI_WriteByte(UBYTE Value)
{
	MY_SPI.transfer(Value);
}

void DEV_SPI_Write_nByte(UBYTE *pData, UDOUBLE Len)
{
	MY_SPI.transfer((void*) pData, Len);
}

/**
 * GPIO Mode
**/
void DEV_GPIO_Mode(UWORD Pin, UWORD Mode)
{
	pinMode(Pin, Mode);
}

/**
 * delay x ms
**/
void DEV_Delay_ms(UDOUBLE xms)
{
	delay(xms);
}

void DEV_GPIO_Init(void)
{
	DEV_GPIO_Mode(EPD_RST_PIN, HIGH);
	DEV_GPIO_Mode(EPD_DC_PIN, HIGH);
	DEV_GPIO_Mode(EPD_CS_PIN, HIGH);
	DEV_GPIO_Mode(EPD_BUSY_PIN, LOW);

	DEV_Digital_Write(EPD_CS_PIN, 1);
}
/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE DEV_Module_Init(void)
{
	DEV_GPIO_Init();
	MY_SPI.begin();
	MY_SPI.beginTransaction(arduino::SPISettings(2000000, MSBFIRST, SPI_MODE0));
	return 0;
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void DEV_Module_Exit(void)
{

}
