#include <Arduino.h>
#define pushButton_pin 0
#define LED_pin 2
int led_state = LOW;

void IRAM_ATTR toggleLED()
{
  led_state = !led_state;
  changeLED();
}
void setup()
{
  Serial.begin(115200);
  pinMode(LED_pin, OUTPUT);
  pinMode(pushButton_pin, INPUT_PULLUP);
  attachInterrupt(pushButton_pin, toggleLED, RISING);
}
void loop()
{
}
void changeLED()
{
  if (led_state == HIGH)
  {
    digitalWrite(LED_pin, led_state);
    Serial.println("led on");
  }
  else
  {
    digitalWrite(LED_pin, led_state);
    Serial.println("led off");
  }
}
