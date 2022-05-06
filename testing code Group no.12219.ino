int sensor = A5; // identifying the port of the sensor to get reads from it.
int buzzer = 3; // identifying the port of the buzzer to take signals and apply the code
float resistor = 326.6; // set the resistance value that is put in the circuit.
void setup() {
 pinMode(sensor,INPUT);
 pinMode(buzzer,OUTPUT);
 Serial.begin(9600);
 
}

void loop() {
  int sensorvalu = analogRead(sensor); // idnetifying the postive pin of the sensor.
  float voltsensor = sensorvalu * (5.0/1023); // identrifying the voltage that sensor had
  float voltresistor = 5 - voltsensor; // get the voltage of the resistor by substracting the volt of the sensor from the volt of the ardiuno
  float sensorresist = (voltsensor * resistor)/voltresistor; // get the sensor resistance to calculate the temperature due to it.
  int temperature = (sensorresist - 105)/.33333; // the relation of between the temperature and the sensor resistance as demonstrated in its datasheet.
  Serial.println(temperature); // print the temperature after every .5 second in the serial monitor command.
  delay(500);
}
