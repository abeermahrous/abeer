//Arduino code:

int L1 = 6, L2 = 7, L3 = 8, L4 = 9; // Pins connected to Motor driver L298N H-Bridge module

void setup()
{                
  // initialize the digital pins we will use as an output.
  pinMode(L1, OUTPUT);     
  pinMode(L2, OUTPUT);     
  pinMode(L3, OUTPUT);     
  pinMode(L4, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop()
{
  forward(500);
  halt(2000);
  reverse(500);
  halt(2000);
  rightSpin(500);
  halt(2000);
  leftSpin(500);
  halt(2000);
}

// robMove routine switches the correct inputs to the L298N for the direction selected.
void robMove(int l1, int l2, int r1, int r2)
{
  digitalWrite(L1, l1);
  digitalWrite(L2, l2);
  digitalWrite(L3, r1);
  digitalWrite(L4, r2);  
}

void reverse(int wait)
{
  Serial.println("Moving backward");
  robMove(LOW, HIGH, LOW, HIGH);
  delay(wait);
}

void forward(int wait)
{
  Serial.println("Moving forward");
  robMove(HIGH, LOW, HIGH, LOW);
  delay(wait);
}

void leftSpin(int wait)
{
  Serial.println("Spinning left");
  robMove(HIGH, LOW, LOW, HIGH);
  delay(wait);
}

void rightSpin(int wait)
{
  Serial.println("Spinning right");
  robMove(LOW, HIGH, HIGH, LOW);
  delay(wait);
}

void halt(int wait)
{
  Serial.println("Stopping");
  robMove(LOW, LOW, LOW, LOW);
  delay(wait);
}
