#include <Servo.h>



Servo ServoX; //
Servo ServoY; //



int ServoXPin = 10;
int ServoYPin = 9;



int JoystickX = 0; //
int JoystickY = 1; //



int valX; //
int valY; //



void setup() {
ServoX.attach( ServoXPin ); //
ServoY.attach( ServoYPin ); //
Serial.begin(9600);//
}



void loop() {
valX = analogRead( JoystickX ); //
valY = analogRead( JoystickY );



valX = map( valX, 0, 1023, 140, 40 ); //
valY = map( valY, 0, 1023, 140, 40 ); //

ServoX.write(valX ); //
ServoY.write( valY); //
//Serial.println("Eje X:"valX);
Serial.println(valX);
delay(2000); //
//Serial.println(" ");
Serial.println('\n');
//Serial.println("Eje Y");
//Serial.println( valY);
Serial.println('\n');
delay(2000); //
}
