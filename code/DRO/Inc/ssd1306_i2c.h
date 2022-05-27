/*
 * Copyright (c) 2017, Stanislav Lakhtin. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. No personal names or organizations' names associated with the
 *    Atomthreads project may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SSD1306_SSD1306_I2C_H
#define SSD1306_SSD1306_I2C_H

#include "stm32f1xx_hal.h"

#include "../../DRO/Inc/calipers.h"
#include "../../DRO/Inc/fonts.h"

// address of device is // 011110+SA0+RW - 0x3C or 0x3D

#define DEFAULT_7bit_OLED_SLAVE_ADDRESS 0x78
#define I2C_COMMAND 0x00
#define I2C_DATA 0x40

#define SSD1306_WIDTH  128
#define SSD1306_HEIGHT  64
#define SSD1306_BUFFER_LENGTH  (SSD1306_WIDTH*SSD1306_HEIGHT/8)


typedef enum SSD1306_COLOR {
  white = 0,
  black = 1
} SSD1306_COLOR_t;

void ssd1306_init();

/// paint commands
void ssd1306_clear(void);
void ssd1306_refresh(void);

void ssd1306_gotoxy(uint16_t x, uint16_t y);
char ssd1306_drawstring(char* str);
bool ssd1306_drawhmm(uint8_t line, volatile caliper* cal);

#endif
