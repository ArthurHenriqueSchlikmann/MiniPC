#include <EEPROM.h>

#define rele 7
#define botao 8
#define latch 4
#define cs 5
#define data 3
#define DPins[4] = {11, 10, 9, 8};

int lig = LOW;

int table[10] = 
{0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};



void setup() {
  // put your setup code here, to run once:
  pinMode(botao, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(data, OUTPUT);
  for(int i =0; i < 4; i++) {
    pinMode(DPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int btn = LOW;
  btn = digitalRead(botao);
  switch(btn) {
    case 1:
      if(lig == HIGH) {lig = LOW;} else {lig = HIGH;}
      digitalWrite(rele, lig);
    break;
  }
}

void Display(int id, int num) {
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);
}
