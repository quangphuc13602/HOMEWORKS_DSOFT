#include <Arduino.h>

int LEDPIN = 2;
enum States
{
  ON,
  OFF,
  BLINK
} state;
void setup()
{
  state = OFF;
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    String command = Serial.readString();
    command.trim();

    if (command == "on")
    {
      state = ON;
      Serial.println("led on");
    }
    else if (command == "off")
    {
      state = OFF;
      Serial.println("led off");
    }
    else if (command == "blink")
    {
      state = BLINK;
      Serial.println("led blink");
    }
  }
  switch (state)
  {
  case ON:
    digitalWrite(LEDPIN, HIGH);
    break;
  case OFF:
    digitalWrite(LEDPIN, LOW);
    break;
  case BLINK:
    digitalWrite(LEDPIN, HIGH);
    delay(2000);
    digitalWrite(LEDPIN, LOW);
    delay(2000);
    break;
  default:
    digitalWrite(LEDPIN, LOW);
    break;
  }
}
