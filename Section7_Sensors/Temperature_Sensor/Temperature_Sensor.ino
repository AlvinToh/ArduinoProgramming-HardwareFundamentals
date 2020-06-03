const int temp_pin = A0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  float voltage;
  float temp_c;
  
  // Read voltage and convert temperature
  voltage = analogRead(temp_pin) * 5.0 / 1023;
  temp_c = 100.0 * voltage - 50;
  
  // Paste voltage and temperature
  Serial.print("Voltage: " );
  Serial.print(voltage);
  Serial.print(" deg C: ");
  Serial.println(temp_c);
}
