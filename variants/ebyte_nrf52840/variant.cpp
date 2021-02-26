/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)
  Copyright (c) 2021, NeKuNeKo Inc. (Github: @nekuneko)
  
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

const uint32_t g_ADigitalPinMap[] = // - Provisional pinout, may be subject to changes
{
  // D0 .. D14
   5,  // D0  is P0.05 (TX, SDA1, A3) Serial1
  41,  // D1  is P1.09 (RX, SCL1)     Serial1
  12,  // D2  is P0.12 
  45,  // D3  is P1.13 
  36,  // D4  is P1.04 (Button_Right)
  26,  // D5  is P0.26 
   6,  // D6  is P0.06
   7,  // D7  is P0.07
   8,  // D8  is P0.08
   9,  // D9  is P0.09 (NFC1)
  10,  // D10 is P0.10 (NFC2)
  43,  // D11 is P1.11 (LED2, LED_BLUETOOTH)
  42,  // D12 is P1.10 (LED1, LED_BUILTIN)
  17,  // D13 is P0.17 (Neopixel) (QSPI Data 0) 
  38,  // D14 is P1.06 (Button_Connect)

  // D15 .. D22 (aka A0 .. A7)
   2,  // D15 is P0.02 (A0)
   3,  // D16 is P0.03 (A1) 
   4,  // D17 is P0.04 (A2)
   5,  // D18 is P0.05 (A3, SDA1)
  28,  // D19 is P0.28 (A4)
  29,  // D20 is P0.29 (A5)
  30,  // D21 is P0.30 (A6, Battery)
  31,  // D22 is P0.31 (A7, ARef)

  // D23 .. D24 (aka I2C pins)
  13,  // D23 is P0.13 (SDA)
  24,  // D24 is P0.24 (SCL) 
  
  // D25 .. D26 (aka I2C1/Serial1 pins) - Suggested, not definitive - 
   5,  // D25 is P0.05 (I2C1_SDA1, TX, A3)
  41,  // D26 is P1.09 (I2C1_SCL1, RX)

  // D27 .. D30 (aka SPI pins)
  22,  // D27 is P0.22 (SPI_MOSI)
  15,  // D28 is P0.15 (SPI_MISO)
  20,  // D29 is P0.20 (SPI_SCK)
  34,  // D30 is P1.02 (SPI_nCS)

  // D31 .. D34 (aka SPI1 pins) - Suggested, not definitive - 
   8,  // D31 is P0.08 (SPI1_MOSI1)
  12,  // D32 is P0.12 (SPI1_MISO1)
   4,  // D33 is P0.04 (SPI1_SCK1, A2)
   7,  // D34 is P0.07 (SPI1_nCS1)

  // D35 .. D36 Alternate pins for Serial1
  26,  // D35 is P0.26 (TX, D5)
   6,  // D36 is P0.06 (RX, D6)

  // D37 SWO
  32,      // P1.00 is SWO   (attached to debug header)

  //
  // Thus, there are 36 defined pins
  //
  //
  // The remaining pins are not usable:
  //
  //
  // The following pins were never listed as they were considered unusable
  //  0,      // P0.00 is XL1   (attached to 32.768kHz crystal)
  //  1,      // P0.01 is XL2   (attached to 32.768kHz crystal)
  // 18,      // P0.18 is RESET (attached to switch)
  // 32,      // P1.00 is SWO   (attached to debug header)
  //
  //
  // This module doesn't expose all QSPI pins, so this interface is unusable
  // QSPI pins (not exposed via any header / test point)
  // 19,  // D27 is P0.19 (QSPI CLK)
  // 20,  // D28 is P0.20 (QSPI CS)     *used
  // 17,  // D29 is P0.17 (QSPI Data 0) *used
  // 22,  // D30 is P0.22 (QSPI Data 1) *used
  // 23,  // D31 is P0.23 (QSPI Data 2) 
  // 21,  // D32 is P0.21 (QSPI Data 3)
  //
  // 
  // The remaining pins are not connected (per module)
  //
  // 11,      // P0.11 is not connected per module
  // 14,      // P0.14 is not connected per module
  // 16,      // P0.16 is not connected per module
  // 19,      // P0.19 is not connected per module (QSPI CLK)
  // 21,      // P0.21 is not connected per module (QSPI Data 3)
  // 23,      // P0.23 is not connected per module (QSPI Data 2)
  // 25,      // P0.25 is not connected per module
  // 27,      // P0.27 is not connected per module
  // 33,      // P1.01 is not connected per module
  // 35,      // P1.03 is not connected per module
  // 37,      // P1.05 is not connected per module
  // 39,      // P1.07 is not connected per module
  // 40,      // P1.08 is not connected per module
  // 44,      // P1.12 is not connected per module
  // 46,      // P1.14 is not connected per module
  // 47,      // P1.15 is not connected per module
};

void initVariant()
{
  // LED1 & LED2
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED2, OUTPUT);
  ledOff(PIN_LED2);
}

