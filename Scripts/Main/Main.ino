
//float rel_v[] = -vo*(d - t*vo)/sqrt(d-t*vo)^2 + D^2); // Relative velocity 
//float f[] = (a + rel_v)/a*f_target; // Adjusted frequency based on relative velocity

int piezoPin = 5;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  // Initial Conditions For the Relppod Effect
  float vo = 100; // Velocity MPH
  vo = vo*0.44704; // Velocity m/s
  float d = 150; // run distance ft
  d = d*0.3048; // run distance m
  float D = 20; // Standoff Distance ft
  D = D*0.3048; // Standoff Distance m

  float a = 343; // Speed of sound m/s
  float f_target = 300; // Target frequency Hz

  

  float runtime = 2.5; 
  float rel_v[250];
  float f[250];
  
 for(int i=0; i < 250; i++) {
    float t = float(i)*.01;
    rel_v[i] = vo*(d - t*vo)/sqrt(pow(d-t*vo,2)+ pow(D,2));// Relative velocity 
    f[i] = (a - rel_v[i])/a*f_target; // Adjusted frequency based on relative velocity
    Serial.print(f[i]); 
    Serial.print("\n");
  }

for (int i = 0; i < 250; i++) {
  tone(piezoPin,f[i],10);
  delay(10);
  }
  float delta_t = d/vo*1000; // Delay milliseconds before source passes observer (Not useful rn i think)
  
  
  
  
 
  
}

void loop() {
 
}
