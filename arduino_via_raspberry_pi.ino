#include <Servo.h>

Servo myservo;

int servo_val = 0;


int incomingByte = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    servo_val = 60;
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    incomingByte = Serial.read();
    if (incomingByte == 115){
      servo_val = 120;
      Serial.println("set to 120");
    }
    else if (incomingByte == 119){
      servo_val == 50;
      Serial.println("set to 50");
    }
    myservo.write(servo_val);
    delay(15);
    Serial.print("I recieved: ");
    Serial.println(incomingByte, DEC);
  }
}
