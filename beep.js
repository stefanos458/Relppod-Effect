// create web audio api context
var audioCtx = new (window.AudioContext || window.webkitAudioContext)();

// create Oscillator node
var oscillator = audioCtx.createOscillator();
var gainNode = audioCtx.createGain();

oscillator.type = 'square';
oscillator.connect(audioCtx.destination);


//float rel_v[] = -vo*(d - t*vo)/sqrt(d-t*vo)^2 + D^2); // Relative velocity 
//float f[] = (a + rel_v)/a*f_target; // Adjusted frequency based on relative velocity

var vo = 100; // Velocity MPH
vo = vo*0.44704; // Velocity m/s
var d = 150; // run distance ft
d = d*0.3048; // run distance m
var D = 20; // Standoff Distance ft
D = D*0.3048; // Standoff Distance m

var a = 343; // Speed of sound m/s
var f_target = 300; // Target frequency Hz

var runtime = 2.5; 
var rel_v = [250];
var f = [250];


for(var i=0; i < 250; i++) {
	var t = i*.01;
	rel_v[i] = vo*(d - t*vo)/Math.sqrt(Math.pow(d-t*vo,2)+ Math.pow(D,2));// Relative velocity 
	f[i] = (a - rel_v[i])/a*f_target; // Adjusted frequency based on relative velocity
	console.log(f[i]); 
	console.log("\n");
}

for (var i = 0; i < 250; i++) {
	oscillator.frequency.setValueAtTime(f[i], audioCtx.currentTime); // value in hertz
	oscillator.start();
}	

var delta_t = d/vo*1000; // Delay milliseconds before source passes observer (Not useful rn i think)

