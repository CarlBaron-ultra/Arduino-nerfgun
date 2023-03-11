/*uses code from
https://myhowtosandprojects.blogspot.com/2014/02/sainsmart-2-channel-5v-relay-arduino.html
https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
https://www.parallax.com/product/pir-sensor-with-led-signal/
Arduino cookbook 2nd edition pg 606-609
*/
#include <Servo.h>
Servo myservo;
int pos = 180;         //was originally set to 0
int relayPin1 = 7;     //IN1 connected to digital pin 7
const int PirPin = 2;  //PIR sensor on pin2


void setup() {
  //gives time for the PIR module to warm up
  delay(20000);
  //sets digital pin as output
  pinMode(relayPin1, OUTPUT);
  //Servo attached to digital pin 9
  myservo.attach(9);

  pinMode(PirPin, INPUT);

  attachInterrupt(0, analyze, CHANGE);  //0 is interrupt 0 which for the uno is digital pin2

  //prevents relay from starting up engaged
  digitalWrite(relayPin1, HIGH);
}

void loop() {
  //energiezes the relay and lights the LED
  digitalWrite(relayPin1, LOW);
  //Serial.println(digitalRead(2), DEC);
  //delay(1000);
  //wait 5 seconds to give the motor time to spool up
  delay(5000);
  // if (digitalRead(2)) {
  //   digitalWrite(relayPin1, HIGH);         //de-energizes the relay and LED
  //   for (pos = 180; pos >= 0; pos -= 1) {  // goes from 0 degrees to 180 degrees
  //     // in steps of 1 degree
  //     myservo.write(pos);  // tell servo to go to position in variable 'pos'
  //     delay(15);           // waits 15 ms for the servo to reach the position
  //   }
  //   for (pos = 0; pos <= 180; pos += 1) {  // goes from 180 degrees to 0 degrees
  //     myservo.write(pos);                  // tell servo to go to position in variable 'pos'
  //     delay(15);                           // waits 15 ms for the servo to reach the position
  //   }

    // delay(5000);
  }
  //delay(1000);  //wait for a second
}

//interrupt
void analyze() {
  digitalWrite(relayPin1, HIGH);         //de-energizes the relay and LED
  for (pos = 180; pos >= 0; pos -= 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15 ms for the servo to reach the position
  }
  for (pos = 0; pos <= 180; pos += 1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);                  // tell servo to go to position in variable 'pos'
    delay(15);                           // waits 15 ms for the servo to reach the position
  }
}

// void pin_ISR(){
// PIRstate = digitalRead(2);
//     digitalWrite(relayPin1, HIGH);  //de-energizes teh relay and LED
//     delay(5000);
//     digitalWrite(relayPin1, LOW); //energiezes the relay and lights the LED

// }
