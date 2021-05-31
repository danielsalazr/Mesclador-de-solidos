
#include <Encoder.h>
#include <OneButton.h>

#define sw 4

OneButton button1(sw, true);
Encoder myEnc(2, 3);

long posicion =0;
long oldPosition  = 64000;

int aState;
int aLastState;

bool estadoSalida = false;


long position(){
  long newPosition = myEnc.read()/4;
  /*if (newPosition != oldPosition) {
    oldPosition = newPosition;
  }*/
  return newPosition;
}


void click1() {
  Serial.println("Button 1 click.");
}

void longPressStart1() {
    estadoSalida =true;
    Serial.println("Button 1 longPress start");
} 
