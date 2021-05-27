// AUTOMATITZACIÓ Raul & Eric
int IN2 = 2; //motor
int IN3 = 3;  //motor
int IN4 = 4;  //motor
int rojo1 = 6;
int rojo2 = 7;
int verde1 = 8;
int verde2 = 9;
int finarriba =10;
int finabajo = 11;
int boton = 12;
int pito = 5;
void setup() {
  pinMode (pito, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (rojo1, OUTPUT);
  pinMode (rojo2, OUTPUT);
  pinMode (verde1, OUTPUT);
  pinMode (verde2, OUTPUT);
  pinMode (finarriba, INPUT);
  pinMode (finabajo, INPUT);
  pinMode (boton, INPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("PONT!");
  analogWrite (IN4, 100); //Velocidad motor 0 a 255

}
void sube() {
  while(finarriba == HIGH){
    finarriba = digitalRead(10);
    tone(5,4530,100);
    digitalWrite(rojo1, HIGH);
    digitalWrite(rojo2, HIGH);
    digitalWrite(verde1, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN2, LOW);
    delay(15);
    digitalWrite (IN3, LOW);
    delay(15);
  }
  digitalWrite (IN3, LOW);
  return;
}
void baja(){
  while (finabajo == HIGH){
    finabajo = digitalRead(11);
    tone(5,9900,100);
    digitalWrite (IN2, HIGH);
    digitalWrite (IN3, LOW);
    delay(15);
    digitalWrite (IN2, LOW);
    delay(15);
  }
  digitalWrite(rojo1, LOW);
  digitalWrite(rojo2, LOW);
  digitalWrite(verde1, HIGH);
  digitalWrite(verde2, HIGH);
  digitalWrite (IN2, LOW);
  return;
}
void loop() {
  finarriba = digitalRead(10);
  finabajo = digitalRead(11);
  boton = digitalRead(12);
  Serial.print("finarriba="); Serial.println(finarriba);
  Serial.print("finabajo ="); Serial.println(finabajo);
  Serial.print("boton    ="); Serial.println(boton);
  if (boton == HIGH && finabajo == LOW) {
    sube();
  }
  else if (boton == HIGH && finarriba == LOW) {
    baja();
  }
  else if (finabajo == HIGH && finarriba == HIGH) {
    baja();
  }
}
