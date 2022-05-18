/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

#include "RotaryEncoder.h"

#define PIN_IN1 6
#define PIN_IN2 7

extern RotaryEncoder *encoder;

int main() {
static int pos = 0;

    stdio_init_all();

    printf("Hello rotary encoder with IRQ\n");

    encoder = new RotaryEncoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);

    // Wait forever
    while (1) {
        int newPos = encoder->getPosition();
        if (pos != newPos) {
            printf("Pos %d Dir %d\n", newPos, (int)(encoder->getDirection()));
            pos = newPos;
        }
    };
    return 0;
}