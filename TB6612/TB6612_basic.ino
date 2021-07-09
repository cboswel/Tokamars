int PWMPin_fwd = 5;
int AIN1_fwd = 14;
int AIN2_fwd = 15;
int BIN1_fwd = 16;
int BIN2_fwd = 17;

int PWMPin_back = 6;
int AIN1_back = 2;
int AIN2_back = 3;
int BIN1_back = 18;
int BIN2_back = 4;

void setup() {
  pinMode(AIN1_fwd,OUTPUT);
  pinMode(AIN2_fwd,OUTPUT);
  pinMode(BIN1_fwd,OUTPUT);
  pinMode(BIN2_fwd,OUTPUT);

  digitalWrite(AIN1_fwd,HIGH);
  digitalWrite(AIN2_fwd,LOW);
  digitalWrite(BIN1_fwd,HIGH);
  digitalWrite(BIN2_fwd,LOW);

  pinMode(AIN1_back,OUTPUT);
  pinMode(AIN2_back,OUTPUT);
  pinMode(BIN1_back,OUTPUT);
  pinMode(BIN2_back,OUTPUT);

  digitalWrite(AIN1_back,HIGH);
  digitalWrite(AIN2_back,LOW);
  digitalWrite(BIN1_back,HIGH);
  digitalWrite(BIN2_back,LOW);
}

void loop() {
  analogWrite(PWMPin_fwd, 255);
  analogWrite(PWMPin_back, 255);  
}
