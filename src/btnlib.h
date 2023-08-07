#ifndef BNTLIB_TEST_BTNLIB_H
#define BNTLIB_TEST_BTNLIB_H

#include <Arduino.h>
#include <stdint.h>

typedef struct button{
    uint8_t pin;
    uint8_t lastState;
    unsigned long lastEventTime;
};

typedef void (*ButtonEventHandler)(struct button *button);
void button_init(struct button *button, uint8_t pin);
uint8_t button_get_state(struct button *button);
uint8_t isClick(struct button *pbtn);
uint8_t isHold(struct button *pbtn);

#endif //BNTLIB_TEST_BTNLIB_H
