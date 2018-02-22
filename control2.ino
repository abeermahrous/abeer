byte ledpin = 2;

void setup() {

  pinMode( ledpin, OUTPUT  );
}

void loop() {
  for (int i=0;i<=10;i++)
  {
  analogWrite(ledpin, i);
  delay(1000);
  }
  for(int j=0; j>=10;j--)
  {
  digitalWrite(ledpin, j);
  delay(1000);
  }
}
