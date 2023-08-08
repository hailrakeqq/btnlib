#ifndef BNTLIB_TEST_BTNLIB_H
#define BNTLIB_TEST_BTNLIB_H

#include <Arduino.h>
#include <stdint.h>

typedef struct {
    uint8_t pin;
    uint32_t timer;
    uint8_t flag;
} button;


typedef void (*ButtonEventHandler)(button *button);
void button_init(button *button, uint8_t pin);
uint8_t button_click(button *pbtn);
uint8_t button_hold(button *pbtn);

#endif //BNTLIB_TEST_BTNLIB_H
