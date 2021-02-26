/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Ha Thach for Adafruit Industries
 * Copyright (c) 2021 NeKuNeKo for NeKuNeKo Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _MINEW_MS88SF3_NRF52840_H
#define _MINEW_MS88SF3_NRF52840_H

#define _PINNUM(port, pin)    ((port)*32 + (pin))

/*------------------------------------------------------------------*/
/* LED
 *------------------------------------------------------------------*/
#define LEDS_NUMBER           2
#define LED_PRIMARY_PIN       _PINNUM(1, 04) // LED_BUILTIN   (D14) 
#define LED_SECONDARY_PIN     _PINNUM(1, 05) // LED_BLUETOOTH (D15)
#define LED_STATE_ON          1

#define LED_NEOPIXEL          _PINNUM(0, 12) // NEOPIXEL      (D23)
#define NEOPIXELS_NUMBER      1
#define BOARD_RGB_BRIGHTNESS  0x040404

/*------------------------------------------------------------------*/
/* BUTTON
 *------------------------------------------------------------------*/
#define BUTTONS_NUMBER        4
#define BUTTON_1              _PINNUM(0, 18) // !RESET
#define BUTTON_2              _PINNUM(1, 01) // DEV_CONNECT (D18)
#define BUTTON_3              _PINNUM(1, 02) // DEV_LEFT    (D19)
#define BUTTON_4              _PINNUM(1, 03) // DEV_RIGHT   (D20)
#define BUTTON_PULL           NRF_GPIO_PIN_PULLUP

//--------------------------------------------------------------------+
// BLE OTA
//--------------------------------------------------------------------+
#define BLEDIS_MANUFACTURER   "NeKuNeKo Inc."
#define BLEDIS_MODEL          "MINEW MS88SF3 (nRF52840)"

//--------------------------------------------------------------------+
// USB
//--------------------------------------------------------------------+
#define USB_DESC_VID           0x1993
#define USB_DESC_UF2_PID       0xB040
#define USB_DESC_CDC_ONLY_PID  0xA040

//------------- UF2 -------------//
#define UF2_PRODUCT_NAME      "MINEW MS88SF3 (nRF52840)"
#define UF2_VOLUME_LABEL      "MINW840BOOT"
#define UF2_BOARD_ID          "nRF52840-MINEW"
#define UF2_INDEX_URL         "https://www.github.com/nekuneko"

#endif // _MINEW_MS88SF3_NRF52840_H
