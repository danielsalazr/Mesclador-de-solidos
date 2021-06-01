#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>
#include <string.h>

uint8_t check[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
int cont = 0;
int variable = 25;
unsigned int contadorGlobal = 0;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

LiquidLine linea1(1, 0, "Automatico");
LiquidLine linea2(1, 1, "Manual");
//LiquidLine linea3(1, 0, "Detener");
LiquidLine linea4(1, 1, "configurar");
LiquidScreen pantalla1(linea1,linea2/*,linea3*/,linea4);
/*
LiquidLine linea1_2(1, 0, "ON");
LiquidLine linea2_2(1, 1, "OFF");
LiquidLine linea3_2(1, 0, "Atras");
LiquidScreen pantalla2(linea1_2,linea2_2,linea3_2);
*/



LiquidLine linea1_3(1, 0, "cant giros  ", variable);
LiquidLine linea2_3(1, 1, "Contador  ", contadorGlobal);
LiquidLine linea3_3(1, 0, "Atras");
//LiquidLine linea4_3(1, 1, "Atras");
LiquidScreen pantalla3(linea1_3,linea2_3,linea3_3/*, linea4_3*/);

LiquidMenu menu(lcd,pantalla1/*,pantalla2*/, pantalla3);










