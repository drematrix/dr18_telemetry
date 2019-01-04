//This the code for Arduino 1 
//Components - 6 Ride height sensors ,  1 Rotary Pot 

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  Serial.begin(9600); 
}


void loop()
{

// Following is the code for calculating the distance from the analog value 
int volts0 = analogRead(A0); // value from sensor * (5/1025)  
float dist1 = 13*pow(volts0,-1) ; // worked out from the datasheet graph 

int volts1 = analogRead(A1); // value from sensor * (5/1025)  
float dist2 = 13*pow(volts1,-1) ; // worked out from the datasheet graph 

int volts2 = analogRead(A2); // value from sensor * (5/1025)  
float dist3 = 13*pow(volts2,-1) ; // worked out from the datasheet graph 

int volts3 = analogRead(A3); // value from sensor * (5/1025)  
float dist4 = 13*pow(volts3,-1) ; // worked out from the datasheet graph 

int volts4 = analogRead(A4); // value from sensor * (5/1025)  
float dist5 = 13*pow(volts4,-1) ; // worked out from the datasheet graph 

int volts5 = analogRead(A5); // value from sensor * (5/1025)  
float dist6 = 13*pow(volts5,-1) ; // worked out from the datasheet graph 

// followiing the code for the rotary potential and the brake pressure sensor 
int RotPot = analogRead(A6) ; 


// Sending the data over Serial Bus . 
Serial.print(volts0) ; 
Serial.print(" ") ;
Serial.print(volts1) ; 
Serial.print(" ") ;
Serial.print(volts2) ; 
Serial.print(" ") ;
Serial.print(volts3) ; 
Serial.print(" ") ;
Serial.print(volts4) ; 
Serial.print(" ") ; 
Serial.print(volts5) ; 
Serial.print(" ");
Serial.print(RotPot) ; 
Serial.print(" ") ;
delay(200);
}
