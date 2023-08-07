#include "btnlib.h"

void button_init(struct button *button, uint8_t pin)
{
    button->pin = pin;
    button->lastState = 0;

    pinMode(button->pin, INPUT_PULLUP);
}

uint8_t button_get_state(struct button *button){
    return digitalRead(button->pin);
}

uint8_t isClick(struct button *pbtn){
    int8_t currentState = button_get_state(pbtn);
    unsigned long currentTime = millis();

    if(currentState != pbtn->lastState)
        pbtn->lastEventTime = currentTime;

    if(!currentState && (currentTime - pbtn->lastEventTime) >= 50 && (currentTime - pbtn->lastEventTime) <= 500) {
        pbtn->lastState = currentState;
        return 1;
    }

    pbtn->lastState = currentState;
    return 0;
}

uint8_t isHold(struct button *pbtn){
    int8_t currentState = button_get_state(pbtn);
    unsigned long currentTime = millis();

    if(currentState != pbtn->lastState)
        pbtn->lastEventTime = currentTime;

    if(!currentState && (currentTime - pbtn->lastEventTime) > 500) {
        pbtn->lastState = currentState;
        return 1;
    }

    pbtn->lastState = currentState;
    return 0;
}