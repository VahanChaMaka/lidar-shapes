/*
 * NON-ANGLE CODES DESCRIPTION
 */
 const int MOVE_TO_ZERO_CODE = 241;

 //PIN description 
 int _stepP = 2;
 int _stepM = 3;
 int _dirP = 4;
 int _dirM = 5;
 int _button = 8;
 
 int speed = 0;
 int divider = 4;
 long pulses_per_round = 800*divider;
 long pulse;
 long step;
 int pause;
 
 int code;

//go down until reach sensor. It will be the base point
void toZero(){
  digitalWrite(_dirP, LOW);
  while(digitalRead(_button) != 0){
    digitalWrite(_stepP, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(_stepP, LOW);
    delayMicroseconds(pulse);
  }
  Serial.write(MOVE_TO_ZERO_CODE);
  digitalWrite(_dirP, HIGH);
}

void setup() {
  pinMode(_dirP, OUTPUT);
  pinMode(_dirM, OUTPUT);
  digitalWrite(_dirP, HIGH);
  digitalWrite(_dirM, LOW);
  pinMode(_stepP, OUTPUT);
  pinMode(_stepM, OUTPUT);
  digitalWrite(_stepM, LOW);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, LOW); //motor enabled
  digitalWrite(7, LOW); //motor enabled
  pinMode(_button, INPUT);
  
  Serial.begin(9600);

  //speed = Serial.read();
  //step = 125000/speed;
  //pulse = step/2;
  //pulse = 75000/divider;
  pulse = 25000/divider;
  
  toZero();
}

void makeStep(int angle){
  long one_step = (360*60)/pulses_per_round;

  long current_iteration_angle = 0;
  for(long i = 0; i < angle; i = i + one_step){
    digitalWrite(_stepP, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(_stepP, LOW);
    delayMicroseconds(pulse);

    current_iteration_angle +=one_step;
  }
  delay(100);
  Serial.write(current_iteration_angle);
}

void loop() {
  if (Serial.available()) {
    code = Serial.read();
    if(code == MOVE_TO_ZERO_CODE){
      toZero();
    } else{
      makeStep(code);
    }
  }
}
