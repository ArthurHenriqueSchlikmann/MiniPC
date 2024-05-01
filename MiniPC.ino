
#define rele 7
#define botao 8
#define latch 4
#define cs 5
#define data 3
#define buzz 13

int DPins[4] = {11, 10, 9, 8};
int lig = LOW;
int err = LOW;
int btn = LOW;

int table[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};



void setup() {
  // put your setup code here, to run once:
  pinMode(botao, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(buzz, OUTPUT);
  for(int i =0; i < 4; i++) {
    pinMode(DPins[i], OUTPUT);
  }
  digitalWrite(buzz, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(err == HIGH) {
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    err = LOW;
  }
  btn = digitalRead(botao);
  if(btn == HIGH) {
      if(lig == HIGH) {lig = LOW;} else {lig = HIGH;}
      digitalWrite(rele, lig);
  }

  Serial.print("O rele está a: ");
  Serial.println(lig);
  Serial.print("O estado do rele é: ");
  Serial.println(btn);
}

void Display(int id, int num) {
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);
}
