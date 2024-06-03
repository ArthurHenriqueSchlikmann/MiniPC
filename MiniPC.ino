#define buzzer 4
#define led 2

int lig = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  digitalWrite(buzzer, HIGH);
  delay();
  Serial.print("Booting ");
  for(int i=0; 1<10; i++) {
    Serial.print(". ");
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
