int piezoPin = 8;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  float vo = 100; // Velocity MPH
  vo = vo*0.44704; // Velocity m/s

  float d = 150; // run distance ft
  d = d*0.3048; // run distance ft

  float a = 343; // speed of sound m/s

  float f_target = 200; // target frequency Hz
  float f[] = {
  (a - vo)/a*f_target,(a + vo)/a*f_target}; // Array of Frequencies. This is gonna get replaced with the curve
  
 
  float delta_t = d/vo*1000; // delay milliseconds
  Serial.print("First Frequency (Hz): ");  
  Serial.print(f[0]);       
  Serial.print("\n");  
  Serial.print("Second Frequency (Hz): ");  
  Serial.print(f[1]);       
  Serial.print("\n");  
  Serial.print("Time Before Trigger (ms): ");  
  Serial.print(delta_t);       
  Serial.print("\n\n");  
  for (int i = 0; i < 2; i++) {
    tone(piezoPin,f[i],delta_t);
    delay(delta_t); // This loop will get replaced with the full curve
  }
 
  
}

void loop() {
 
}
