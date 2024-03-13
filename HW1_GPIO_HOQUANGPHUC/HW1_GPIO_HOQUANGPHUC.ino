// LED on GPIO2
int LEDPIN = 2;
void setup()
{
    pinMode(LEDPIN, OUTPUT);
//    Serial.begin(115200);
}
void loop()
{
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
}
