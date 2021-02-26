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

#ifndef _VARIANT_MINEW_MS88SF3_NRF52840_
#define _VARIANT_MINEW_MS88SF3_NRF52840_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

//#define USE_LFXO    // Board uses 32khz crystal for LF (External Clock)
//#define USE_LFRC    // Board uses RC for LF (Internal Clock)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (49)
#define NUM_DIGITAL_PINS     (49)
#define NUM_ANALOG_INPUTS    (8) // A6 is used for battery, A7 is analog reference
#define NUM_ANALOG_OUTPUTS   (0)

// LEDs
#define PIN_NEOPIXEL         (23)
#define PIN_LED1             (14)
#define PIN_LED2             (15)

#define LED_BUILTIN          PIN_LED1
#define LED_CONN             PIN_LED2

#define LED_RED              PIN_LED1
#define LED_BLUE             PIN_LED2

#define LED_STATE_ON         1         // State when LED is litted


/*
 * Buttons
 */
#define PIN_BUTTON1          (18) // DEV_CONNECT
#define PIN_BUTTON2          (19) // DEV_LEFT
#define PIN_BUTTON3          (20) // DEV_RIGHT


/*
 * Analog pins
 */
#define PIN_A0               (24)
#define PIN_A1               (25)
#define PIN_A2               (26)
#define PIN_A3               (27)
#define PIN_A4               (28)
#define PIN_A5               (29)
#define PIN_A6               (30)
#define PIN_A7               (31)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t A6  = PIN_A6;
static const uint8_t A7  = PIN_A7;

#define ADC_RESOLUTION    14

// Other pins
#define PIN_AREF           (PIN_A7)
#define PIN_VBAT           (PIN_A6)
#define PIN_NFC1           (21)
#define PIN_NFC2           (22)

static const uint8_t AREF = PIN_AREF;



/*
 * Serial interfaces
 */
#define PIN_SERIAL1_TX       (0)
#define PIN_SERIAL1_RX       (1)



/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (32)
#define PIN_WIRE_SCL         (33)



/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MOSI         (35)
#define PIN_SPI_MISO         (36)
#define PIN_SPI_SCK          (37)

static const uint8_t SS   =  (38);
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;


// SPI Flash Pins
#define SDCARD_SPI      SPI
#define SDCARD_MOSI_PIN PIN_SPI_MOSI
#define SDCARD_MISO_PIN PIN_SPI_MISO
#define SDCARD_SCK_PIN  PIN_SPI_SCK
#define SDCARD_SS_PIN   PIN_SPI_SS  



// QSPI Pins
#define PIN_QSPI_SCK         43
#define PIN_QSPI_CS          44
#define PIN_QSPI_IO0         45
#define PIN_QSPI_IO1         46
#define PIN_QSPI_IO2         47
#define PIN_QSPI_IO3         48

// On-board SPI/QSPI Flash
#define EXTERNAL_FLASH_DEVICES   GD25Q16C
//#define EXTERNAL_FLASH_USE_QSPI

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif // _VARIANT_MINEW_MS88SF3_NRF52840_
