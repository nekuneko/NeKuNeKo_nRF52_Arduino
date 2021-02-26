/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

const uint32_t g_ADigitalPinMap[] =
{
  // D0 .. D13
   2,  // D0  is P0.02 (A0, LED_BUILTIN)
   3,  // D1  is P0.03 (A1)
   4,  // D2  is P0.04 (A2, FSC_RST)
   5,  // D3  is P0.05 (A3, SDA)
  28,  // D4  is P0.28 (A4)
  29,  // D5  is P0.29 (A5)
  30,  // D6  is P0.30 (A6, Battery)
  31,  // D7  is P0.31 (A7, ARef, NEOPIXEL)
  20,  // D8  is P0.20 
   9,  // D9  is P0.09 (NFC1)
  10,  // D10 is P0.10 (NFC2)
  11,  // D11 is P0.11 (FSC_IRQ)
  15,  // D12 is P0.15          
  17,  // D13 is P0.17


  // D14 .. D21 (aka A0 .. A7)
   2,  // D14 is P0.02 (A0, LED_BUILTIN)
   3,  // D15 is P0.03 (A1)
   4,  // D16 is P0.04 (A2, FSC_RST)
   5,  // D17 is P0.05 (A3)
  28,  // D18 is P0.28 (A4)
  29,  // D19 is P0.29 (A5)
  30,  // D20 is P0.30 (A6, Battery)
  31,  // D21 is P0.31 (A7, ARef, NEOPIXEL)


  // D22 .. D23 (aka I2C pins)
   5,  // D22 is P0.05 (SDA, A3)
  41,  // D23 is P1.09 (SCL)
  

  // D24 .. D26 (aka SPI pins) - Provisional -
  20,  // D24 is P0.20 (D8, SPI_MISO)
  15,  // D25 is P0.15 (D12, SPI_MOSI)         
  17,  // D26 is P0.17 (D13, SPI_SCK)

  // Thus, there are 26 defined pins

  // The remaining pins are not usable:
  //
  //
  // The following pins were never listed as they were considered unusable
  //  0,      // P0.00 is XL1   (attached to 32.768kHz crystal)
  //  1,      // P0.01 is XL2   (attached to 32.768kHz crystal)
  // 18,      // P0.18 is RESET (attached to switch)
  // 
};

void initVariant()
{
  // LED1 & LED2
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

 // pinMode(PIN_LED2, OUTPUT);
 // ledOff(PIN_LED2);
}

