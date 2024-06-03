#define buzzer 4
#define led 2

int lig = LOW;
String comando;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  Serial.print("Booting ");
  for(int i=0; 1<10; i++) {
    Serial.print(". ");
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Digite um comando ou escreva um programa");
  if(Serial.available() > 0) {
      comando = Serial.read();
  }
}
