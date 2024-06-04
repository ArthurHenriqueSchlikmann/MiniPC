#include <SPI.h>

#include <SD.h>

#define buzzer 4
#define led 13

int lig = LOW;
boolean dos = false;
String comando;
int sd;

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
  if(sd == 1) {
      dos = true;
      Serial.println("Nao foi reconhecido um cartao com o MSXr DOS");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(dos == false) {
    Serial.println("Digite um comando ou escreva um programa");
    delay(5000);
    if(Serial.available() > 0) {
      comando = Serial.read();
    }
  }
}
