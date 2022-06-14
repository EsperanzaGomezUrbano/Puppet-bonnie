#include <Servo.h>

Servo ServoX;
Servo ServoY;

int ServoXPin = 10;
int ServoYPin = 9;

int JoystickX = 0;
int JoystickY = 1;

int valX;
int valY;

const int axistime = 800;     //Tiempo de espera entre movimientos
const int turntime = 1500;    //Velocidad en la rutina de giro

void setup() {
  ServoX.attach( ServoXPin );
  ServoY.attach( ServoYPin );
}

void loop() {
  unsigned int i, j;
  unsigned int x, y;

  //Centrar
  x = y = 90;
  ServoX.write( x );
  ServoY.write( y );
  delay( 2000 );

  //Izquierda
  ServoX.write( 40 );
  delay( axistime );
  //Derecha
  ServoX.write( 140 );
  delay( axistime );
  //Centrar
  ServoX.write( 90 );
  delay( axistime );

  //Abajo
  ServoY.write( 40 );
  delay( axistime );
  //Arriba
  ServoY.write( 140 );
  delay( axistime );
  //Centrar
  ServoY.write( 90 );
  delay( axistime );

  //Derecha-Arriba
  ServoX.write( 140 );
  ServoY.write( 140 );
  delay( axistime );
  //Izquierda-Abajo
  ServoX.write( 40 );
  ServoY.write( 40 );
  delay( axistime );
  //Centrar
  ServoX.write( 90 );
  ServoY.write( 90 );
  delay( axistime );
  
  //Derecha-Abajo
  ServoX.write( 140 );
  ServoY.write( 40 );
  delay( axistime );
  //Izquierda-Arriba
  ServoX.write( 40 );
  ServoY.write( 140 );
  delay( axistime );
  //Centrar
  ServoX.write( 90 );
  ServoY.write( 90 );
  delay( axistime );

  //RUTINA PARA GIRAR
  x = y = 90;
  ServoX.write( x );
  ServoY.write( y );
  delay( 1000 );
  for ( i = 0; i < 50; i++ )
  {
    x = x - 1;
    y = y + 1;
    ServoX.write( x );
    ServoY.write( y );
    delay( 3 );
  }
  for ( j = 0; j < 5; j++ )     //Gira 5 veces
  {
    for ( i = 0; i < 100; i++ )
    {
      x = x + 1;
      ServoX.write( x );
      delayMicroseconds( turntime );
    }
    for ( i = 0; i < 100; i++ )
    {
      y = y - 1;
      ServoY.write( y );
      delayMicroseconds( turntime );
    }
    for ( i = 0; i < 100; i++ )
    {
      x = x - 1;
      ServoX.write( x );
      delayMicroseconds( turntime );
    }
    for ( i = 0; i < 100; i++ )
    {
      y = y + 1;
      ServoY.write( y );
      delayMicroseconds( turntime );
    }
  }
      
  delay(15);                           //
}
