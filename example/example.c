#include "btnlib.h"

button btn1;
void setup()
{
    Serial.begin(9600);
    button_init(&btn1, 2);
}

void loop() {
    if (button_click(&btn1))
    {
        Serial.println("press 1");
    }
    if (button_hold(&btn1)) {
        Serial.println("hold 1");
    } 
}