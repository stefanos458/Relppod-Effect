
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
  float f_target = 200; // Target frequency Hz

  float rel_v[1000];
  float f[1000];
  
  for(int i=0; i < 1000; i++) {
    float t = float(i);
    rel_v[i] = ((-vo*(d - t*vo)/sqrt(d-t*vo))*(-vo*(d - t*vo)/sqrt(d-i*vo)) + D*D); // Relative velocity 
    f[i] = (a + rel_v[i])/a*f_target; // Adjusted frequency based on relative velocity
    Serial.print(rel_v[i]); 
    Serial.print(f[i]); 
  }
  
  
  float delta_t = d/vo*1000; // Delay milliseconds before source passes observer (Not useful rn i think)
  
  Serial.print("First Frequency (Hz): ");  
  Serial.print(f[0]);       
  Serial.print("\n");  
  Serial.print("Second Frequency (Hz): ");  
  Serial.print(f[1]);       
  Serial.print("\n");  
  Serial.print("Time Before Trigger (ms): ");  
  Serial.print(delta_t);       
  Serial.print("\n\n");  
  
  
 
  
}

void loop() {
 
}
