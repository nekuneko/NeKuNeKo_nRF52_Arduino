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
  // Digital Pins (D0 .. D23)
  26,  // D0  is P0.26 (HF) (Serial1 TX)
  27,  // D1  is P0.27 (HF) (Serial1 RX)
  47,  // D2  is P1.15
  45,  // D3  is P1.13 
  43,  // D4  is P1.11
  44,  // D5  is P1.12 
  42,  // D6  is P1.10 
  46,  // D7  is P1.14 
   7,  // D8  is P0.07 (HF)
   6,  // D9  is P0.06 (HF)
  40,  // D10 is P1.08 (HF)
  11,  // D11 is P0.11 (HF)
   8,  // D12 is P0.08 (HF)
  41,  // D13 is P1.09 (HF)

  36,  // D14 is P1.04 (LED1, LED_BUILTIN) 
  37,  // D15 is P1.05 (LED2, LED_BLUETOOTH)
  38,  // D16 is P1.06 (INT1)                    
  39,  // D17 is P1.07 (INT2)
  33,  // D18 is P1.01 (Button_Connect) 
  34,  // D19 is P1.02 (Button_Device_Left)        
  35,  // D20 is P1.03 (Button_Device_Right) 
   9,  // D21 is P0.09 (NFC1)
  10,  // D22 is P0.10 (NFC2)
  12,  // D23 is P0.12 (HF) (NEOPIXEL) 


  // Analog pins (A0 .. A7)
   2,  // D24 is P0.02 (A0)
   3,  // D25 is P0.03 (A1) 
   4,  // D26 is P0.04 (A2) (HF) (SDA1)
   5,  // D27 is P0.05 (A3) (HF) (SCL1)
  28,  // D28 is P0.28 (A4)
  29,  // D29 is P0.29 (A5)
  30,  // D30 is P0.30 (A6, Battery)
  31,  // D31 is P0.31 (A7, ARef)


  // I2C pins
  16,  // D32 is P0.16 (HF) (SDA)
  14,  // D33 is P0.14 (HF) (SCL) 
  
  // I2C1 - Suggested, not definitive - 
   4,  // D34 is P0.04 (HF) (SDA1, A2)
   5,  // D35 is P0.05 (HF) (SCL1, A3)


  // SPI pins
  15,  // D35 is P0.15 (HF) (SPI_MOSI) 
  13,  // D36 is P0.13 (HF) (SPI_MISO)
  19,  // D37 is P0.19 (HF) (SPI_SCK)   
  17,  // D38 is P0.17 (HF) (SPI_nCS)  

  // SPI1 pins - Suggested, not definitive - 
  11,  // D39 is P0.11 (HF) (SPI1_MOSI1, D11)
   8,  // D40 is P0.08 (HF) (SPI1_MISO1, D12)
  41,  // D41 is P1.09 (HF) (SPI1_SCK1,  D13)
  40,  // D42 is P1.08 (HF) (SPI1_nCS1,  D10)


  // QSPI pins (not exposed via any header / test point)
  23,  // D43 is P0.23 (HF) (QSPI CLK)   
  25,  // D44 is P0.25 (HF) (QSPI CS)
  20,  // D45 is P0.20 (HF) (QSPI Data 0)
  22,  // D46 is P0.22 (HF) (QSPI Data 1)
  24,  // D47 is P0.24 (HF) (QSPI Data 2)
  21,  // D48 is P0.21 (HF) (QSPI Data 3)


  //
  // Thus, there are 49 defined pins
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

};

void initVariant()
{
  // LED1 & LED2
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED2, OUTPUT);
  ledOff(PIN_LED2);
}

