#include <EEPROM.h>

#include <SPI.h>

#include <SD.h>

#define buzzer 4
#define led 2

int lig = LOW;
boolean dos = false;
String comando = "";
int sd = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  SD.begin();
  Serial.print("Booting ");
  for(int i = 0; i < 5; i++) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  sd = SD.exists("/dos.json");
  if(sd == 0) {
      Serial.println("Nao foi reconhecido um cartao com o MSXr DOS");
  } else {
    Serial.println("Foi reconhecido um cartao com MSXr DOS, prosseguindo");
    dos = true;
    delay(2000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(dos == false) {
    Serial.println("Digite um comando ou escreva um programa");
    delay(5000);
    comando = Serial.read();
  }
}