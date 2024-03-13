const int touchPin = 4;
const int ledPin = 2;
int touchCounter = 0;
int touchState = 0;
int lastTouchState = 0;
unsigned long touchTime = 0;
unsigned long touchInterval = 500;
int ledstate = LOW;

void setup()
{
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  touchState = touchRead(touchPin);

  if (touchState < 15)
  {
    if (lastTouchState == 0)
    {
      unsigned long currentTime = millis();
      if (currentTime - touchTime < touchInterval)
      {
        touchCounter++;
      }
      touchTime = currentTime;
    }
    lastTouchState = 1;
  }
  else
  {
    lastTouchState = 0;
  }

  if (touchCounter % 2 == 0)
  {
    ledstate = !ledstate;
    digitalWrite(ledPin, ledstate);
  }
}
