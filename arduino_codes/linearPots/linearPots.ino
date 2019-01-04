const int fLeft = 4;
const int fRight = 5;
const int rLeft = 6;
const int rRight = 7;

void setup() {
  Serial.begin(9600); // Initialize Serial to log output  
}

void loop() {
// Following 4 inputs are for the linear potentials 

  Serial.print(analogRead(fLeft)); 
  Serial.print(" ");
  Serial.print(analogRead(fRight)); 
  Serial.print(" "); 
  Serial.print(analogRead(rLeft)); 
  Serial.print(" "); 
  Serial.println(analogRead(rRight)); 
  
}
