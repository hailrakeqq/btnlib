#include "btnlib.h"

void button_init(struct button *button, uint8_t pin, uint8_t state, uint8_t lastState)
{
    button->pin = pin;
    button->state = 0;
    button->lastState = 0;
    
    pinMode(button->pin, INPUT_PULLUP);
}

int8_t button_get_state(struct button *button){
    return digitalRead(button->pin);
}

bool isClick(struct button *pbtn){
    bool currentState = button_get_state(pbtn);
    unsigned long currentTime = millis();

    if(currentState != pbtn->lastState)
        pbtn->lastEventTime = currentTime;

    if(!currentState && (currentTime - pbtn->lastEventTime) >= 50 && (currentTime - pbtn->lastEventTime) <= 500) {
        pbtn->lastState = currentState;
        return true;
    }

    pbtn->lastState = currentState;
    return false;
}

bool isHold(struct button *pbtn){
    bool currentState = button_get_state(pbtn);
    unsigned long currentTime = millis();

    if(currentState != pbtn->lastState)
        pbtn->lastEventTime = currentTime;

    if(!currentState && (currentTime - pbtn->lastEventTime) > 500) {
        pbtn->lastState = currentState;
        return true;
    }

    pbtn->lastState = currentState;
    return false;
}   