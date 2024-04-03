const float arduinoVCC = 5;
unsigned long ValueR1 = 5070;
unsigned long ValueR2 = 100000;
double Voltage_Source = 12;
const int alanogPin = A1;
const int inputResolution =1023;
float voltage_sensed;
float voltage;

void setup() {
  Serial.begin(9600);
  delay(500);
}

void loop() {
  readVoltage();

  Serial.print("Vin: ");
  Serial.print(voltage);
  Serial.println("V"); 
}

void readVoltage(){
    int A0Value = analogRead(alanogPin);
    float voltage_sensed = A0Value * (arduinoVCC / (float)inputResolution);       
    voltage = voltage_sensed * ( 1 + ( (float) ValueR2 /  (float) ValueR1) );  
}
