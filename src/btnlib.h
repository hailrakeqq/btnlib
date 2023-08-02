#ifndef BTNLIB_H
#define BTNLIB_H

#include <Arduino.h>
#include <stdint.h>
typedef struct button{
    uint8_t pin;
    uint8_t state;
    uint8_t lastState;
    unsigned long lastEventTime;
};

typedef void (*ButtonEventHandler)(struct button *button);
void button_init(struct button *button, uint8_t pin, uint8_t state, uint8_t lastState, uint32_t debounceTime, uint32_t lastDebounceTime);
int8_t button_get_state(struct button *button);
bool isClick(struct button *pbtn);
bool isHold(struct button *pbtn);

#endif //  BTNLIB_H
