#include <Arduino.h>

#define pushButton_pin 0
#define LEDPIN 2
int toggleled = LOW;
enum States
{
  ON,
  OFF,
  BLINK
} state;

void toggleLED()
{
  toggleled = !toggleled;
  changeLED();
}
void setup()
{
  Serial.begin(115200);
  state = OFF;
  pinMode(LEDPIN, OUTPUT);
  pinMode(pushButton_pin, INPUT_PULLUP);
  attachInterrupt(pushButton_pin, toggleLED, RISING);
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
void changeLED()
{
  if (toggleled == HIGH)
  {
    digitalWrite(LEDPIN, toggleled);
    Serial.println("led on");
  }
  else
  {
    digitalWrite(LEDPIN, toggleled);
    Serial.println("led off");
  }
}
