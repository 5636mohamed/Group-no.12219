int sensor = A5;
int buzzer = 3;
float resistor = 326.6;
void setup() {
 pinMode(sensor,INPUT);
 pinMode(buzzer,OUTPUT);
 Serial.begin(9600);
 
}

void loop() {
  int sensorvalu = analogRead(sensor);
  float voltsensor = sensorvalu * (5.0/1023);
  float voltresistor = 5 - voltsensor;
  float sensorresist = (voltsensor * resistor)/voltresistor;
  int temperature = (sensorresist - 105)/.33333;
  Serial.println(temperature);
  delay(500);

  if (temperature >= 300) {
    for(int i=0;i<3;i++){
  digitalWrite (buzzer, 1);
  delay (500);
  digitalWrite (buzzer, 0);
  delay (500);

  }}
}
