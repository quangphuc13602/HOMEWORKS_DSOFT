//const int LEDPIN = 2;
//const int BOOTPIN = 0;
//bool led_state = LOW;
//
//void setup() {
//  pinMode(LEDPIN, OUTPUT);
//  pinMode(BOOTPIN, INPUT_PULLUP);
//}
//
//void loop() {
//  int boot_state = digitalRead(BOOTPIN);
//  if (boot_state == LOW) {
//    delay(100);
//    if (digitalRead(BOOTPIN) == LOW) {
//      led_state = !led_state;
//      digitalWrite(LEDPIN, led_state);
//    }
//  }
//}
////issue: LED blink fastly when holding press
