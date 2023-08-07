#include "btnlib.h"

void button_init(button *btn, uint8_t pin) {
    btn->pin = pin;
    pinMode(btn->pin, INPUT_PULLUP);
}

uint8_t button_click(button *btn) {
    uint8_t btnState = digitalRead(btn->pin);
    if (!btnState && !btn->flag && millis() - btn->timer <= 500) {
        btn->flag = 1;
        btn->timer = millis();
        return 1;
    }
    if (btnState && btn->flag) {
        btn->flag = 0;
        btn->timer = millis();
    }
    return 0;
}

uint8_t button_hold(button *btn) {
    uint8_t btnState = digitalRead(btn->pin);
    if (!btnState) {
        if (!btn->flag) {
            btn->flag = 1;
            btn->timer = millis();
        } else if (millis() - btn->timer >= 1000) {
            btn->flag = 0; // Сброс _flag, чтобы предотвратить повторный вызов
            return 1;
        }
    }
    return 0;
}
