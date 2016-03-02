int dir = 2;
int stp = 3;
int b1 = 4;
int b2 = 5;
int avto = 6;
int k1 =7;
int k2 =8;
int shag = 0;
int newshag = 0;
int positciya = 0;


int T = 500;
int T1=50;
void setup()

{
  Serial.begin(9600);
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(k1, INPUT);
  pinMode(k2, INPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(avto, INPUT);
  digitalWrite(k1, HIGH);
  digitalWrite(k2, HIGH);
  digitalWrite(avto, HIGH);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, HIGH);
}

void loop()

{
  if (Serial.available() > 0)
  {
    char val = Serial.read();
    Serial.println(val);
    if (val == 'y')
    { 
      while (digitalRead(k2) == HIGH)
      {
        digitalWrite(dir, LOW);
        digitalWrite(stp, HIGH);
        delayMicroseconds(T);
        digitalWrite(stp, LOW);
        delayMicroseconds(T);
      }
      shag=0;
      Serial.print("now shag:");
      Serial.println(newshag);
    }
    delay(1000);
  }
if (digitalRead(avto) == LOW)
{
  while (digitalRead(b1) == LOW && digitalRead(avto) == LOW && digitalRead(k1) == HIGH ) 
  {
    digitalWrite(dir, HIGH);
    digitalWrite(stp, HIGH);
    delayMicroseconds(T);
    digitalWrite(stp, LOW);
    delayMicroseconds(T);
    shag++;

  }
  Serial.println("V");
  Serial.println("ru");
  Serial.print("shag:");
  Serial.println(shag);
  Serial.println("");
  delay(T1);
  while (digitalRead(b2) == LOW && digitalRead(avto) == LOW && digitalRead(k2) == HIGH ) 
  {
    digitalWrite(dir, LOW);
    digitalWrite(stp, HIGH);
    delayMicroseconds(T);
    digitalWrite(stp, LOW);
    delayMicroseconds(T);
    shag--;

  }
  Serial.println("N");
  Serial.println("ru");
  Serial.print("shag:");
  Serial.println(shag);
  Serial.println("");
  delay(T1);
}
if (digitalRead(avto) == HIGH)
{
  while (digitalRead(k1) == HIGH && digitalRead(avto) == HIGH)
  {
    digitalWrite(dir, HIGH);
    digitalWrite(stp, HIGH);
    delayMicroseconds(T);
    digitalWrite(stp, LOW);
    delayMicroseconds(T);
    shag++;

  }
  Serial.println("V");
  Serial.println("AVTO");
  Serial.print("shag:");
  Serial.println(shag);
  Serial.println("");
  delay(T1);
  while (digitalRead(k2) == HIGH && digitalRead(avto) == HIGH)
  {
    digitalWrite(dir, LOW);
    digitalWrite(stp, HIGH);
    delayMicroseconds(T);
    digitalWrite(stp, LOW);
    delayMicroseconds(T);
    shag--;

  }
  Serial.println("N");
  Serial.println("AVTO");
  Serial.print("shag:");
  Serial.println(shag);
  Serial.println("");
  delay(T1);
}
}










