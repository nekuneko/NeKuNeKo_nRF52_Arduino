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

#ifndef _VARIANT_MINEW_MS50SFA2_NRF52832_MINI_
#define _VARIANT_MINEW_MS50SFA2_NRF52832_MINI_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

//#define USE_LFXO    // Board uses 32khz crystal for LF
//#define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (32u)
#define NUM_DIGITAL_PINS     (32u)
#define NUM_ANALOG_INPUTS    (8u)
#define NUM_ANALOG_OUTPUTS   (0u)

// LEDs
#define PIN_LED1             (17)
#define PIN_LED2             (27)

#define LED_BUILTIN          PIN_LED1
#define LED_CONN             PIN_LED2

#define LED_RED              PIN_LED1
#define LED_BLUE             PIN_LED2

#define LED_STATE_ON         1     // State when LED is litted

// PIN_SWO = PIN_SS = PIN_DFU = 18



/*
 * Analog pins
 */
#define PIN_A0               (2)    // nc
#define PIN_A1               (3)
#define PIN_A2               (4)
#define PIN_A3               (5)    // nc
#define PIN_A4               (28)
#define PIN_A5               (29)
#define PIN_A6               (30)
#define PIN_A7               (31)   // nc

static const uint8_t A0  = PIN_A0 ; // nc
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ; // nc
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ; // nc
#define ADC_RESOLUTION    14

// Other pins
#define PIN_AREF           PIN_A7   // nc  
#define PIN_VBAT           PIN_A6
#define PIN_NFC1           (9)
#define PIN_NFC2           (10)

static const uint8_t AREF = PIN_AREF;



/*
 * Serial interfaces
 */
#define PIN_SERIAL_TX       (PIN_A1)
#define PIN_SERIAL_RX       (PIN_A2)



/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (PIN_A4)
#define PIN_SPI_MOSI         (PIN_A5)
#define PIN_SPI_SCK          (PIN_A6)

static const uint8_t SS   = 18 ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t SCK  = PIN_SPI_SCK ;



/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (11u)
#define PIN_WIRE_SCL         (12u)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif // _VARIANT_MINEW_MS50SFA2_NRF52832_MINI_
