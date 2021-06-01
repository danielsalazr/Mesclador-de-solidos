/**********************************
 *  LaBuhardillaDelLoco.xyz
 *  http://bit.ly/2MTrGne
 *
 **********************************/


#include <Arduino.h>
#include <encoder_conf.h>
#include <menu_conf.h>
#include <control.h>

// LCD I2C

unsigned int cantidadGiros = 25;

//LEDS
#define led1 8
#define led2 9
#define led3 10


int variable = 25;
int cont = 0;
int led_seleccionado = 0;

//Funciones:::::
void selectOption(){
  if(digitalRead(sw) == LOW){
      menu.call_function(1);
      //Serial.println(menu.call_function(1));
      delay(500);

  }
}

void fn_led1(){
  menu.change_screen(2);
  menu.set_focusedLine(0);
  led_seleccionado = 1;
}

void fn_led2(){
  menu.change_screen(3);
  menu.set_focusedLine(0);
  led_seleccionado = 2;
}


void fn_led3(){
  menu.change_screen(2);
  menu.set_focusedLine(0);
  led_seleccionado = 3;
}


void fn_todos(){
  menu.change_screen(3);
  menu.set_focusedLine(0);
  led_seleccionado = 0;
}


void fn_on(){

  switch(led_seleccionado){
    case 1:
      digitalWrite(led1,HIGH);
      break;
    case 2:
      digitalWrite(led2,HIGH);
      break; 
    case 3:
      digitalWrite(led3,HIGH);
      break;
    case 0:
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      break;   
  }

}


void fn_off(){
  switch(led_seleccionado){
    case 1:
      digitalWrite(led1,LOW);
      break;
    case 2:
      digitalWrite(led2,LOW);
      break; 
    case 3:
      digitalWrite(led3,LOW);
      break;
    case 0:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;   
  }
}




void cambiarValor() {

  int valor = posicion;
  
  
  lcd.setCursor (13, 0); lcd.print(variable);
  lcd.setCursor (0, 0); lcd.print(" ");
  lcd.setCursor (12, 0); lcd.write((uint8_t)14);

  while (1){

    button1.tick();

    posicion = position();

    if (posicion > oldPosition) {
        variable++;
        lcd.setCursor (13, 0);
        lcd.print(variable);
      } else if (posicion < oldPosition) {
        variable--;
        lcd.setCursor (13, 0);
        lcd.print(variable);
      }
      oldPosition=posicion;
      //Serial.println(String (variable) +"  "+ String(posicion));

      if (estadoSalida == true){
        break;
      }

      
  }
  estadoSalida = false;
  myEnc.write(valor);
  posicion = valor;
  oldPosition= valor;
  menu.update();

}

void automatico() {

  cont = 0;

  lcd.setCursor (0, 0); lcd.print("");
  lcd.setCursor (14, 0); lcd.write(3);
  lcd.setCursor (12, 0); lcd.write((uint8_t)14);

  lcd.setCursor (9, 1); lcd.print("T"); lcd.print(variable);
  lcd.setCursor (13, 1); lcd.print(cont);
  digitalWrite(10,1);
  while (1){

    button1.tick();
    if (falling(7) == true){
      cont++;
      lcd.setCursor (13, 1); lcd.print(cont);
    }

    if (estadoSalida == true || cont >= variable){
      digitalWrite(10,0);
      break;
    }
  }
  estadoSalida = false;
  menu.update();
}

void manual() {

  cont = 0;

  lcd.setCursor (0, 1); lcd.print(" ");
  lcd.setCursor (14, 1); lcd.write(3);
  lcd.setCursor (12, 1); lcd.write((uint8_t)14);

  digitalWrite(10,1);
  while (1){

    button1.tick();
    if (estadoSalida == true ){
      digitalWrite(10,0);
      break;
    }
  }
  estadoSalida = false;
  menu.update();
}




void fn_atras(){
  menu.change_screen(1);
  menu.set_focusedLine(0);
}



void setup() {

  myEnc.write(oldPosition);

  button1.attachClick(click1);
  button1.attachLongPressStart(longPressStart1);

  Serial.begin(9600);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT); 
  
  pinMode(sw,INPUT_PULLUP);
  
  lcd.init();
  //lcd.begin();
  lcd.backlight();
  lcd.createChar(3, check);
  

  menu.init();

  linea1.set_focusPosition(Position::LEFT); 
  linea2.set_focusPosition(Position::LEFT); 
  linea3.set_focusPosition(Position::LEFT); 
  linea4.set_focusPosition(Position::LEFT); 
   
  linea1.attach_function(1, automatico); 
  linea2.attach_function(1, manual);
  linea3.attach_function(1, fn_led3);
  linea4.attach_function(1, cambiarValor);

  menu.add_screen(pantalla1);



  linea1_2.set_focusPosition(Position::LEFT);
  linea2_2.set_focusPosition(Position::LEFT);
  linea3_2.set_focusPosition(Position::LEFT);

  linea1_2.attach_function(1, fn_on);
  linea2_2.attach_function(1, fn_off);
  linea3_2.attach_function(1, fn_atras);

  menu.add_screen(pantalla2);

  linea1_3.set_focusPosition(Position::LEFT);
  linea2_3.set_focusPosition(Position::LEFT);
  linea3_3.set_focusPosition(Position::LEFT);
  linea4_3.set_focusPosition(Position::LEFT);

  linea1_3.attach_function(1, cambiarValor);
  linea2_3.attach_function(1, fn_on);
  linea3_3.attach_function(1, fn_atras);

  menu.add_screen(pantalla3);


  pantalla1.set_displayLineCount(2);
  pantalla2.set_displayLineCount(2);
  pantalla3.set_displayLineCount(2);

  menu.set_focusedLine(0);

  menu.update();

}

void loop() {

  button1.tick();
  selectOption();

 //aState = digitalRead(outputA);
  posicion = position();
  //Serial.println(posicion);

    if (posicion != oldPosition){
      if (posicion > oldPosition) {
        menu.switch_focus(false);
      } else if (posicion < oldPosition) {
        menu.switch_focus(true);
      }
      menu.update();
      oldPosition = posicion;
  }
 // Serial.print(aState);*/

 //delay(10);

}





