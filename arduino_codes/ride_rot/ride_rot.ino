//Components - 6 Ride height sensors ,  1 Rotary Pot

const int fLeft = 0 ; 
const int fRight = 1 ; 
const int rLeft = 2 ; 
const int rRight = 3 ; 
const int mLeft = 4 ; 
const int mRight = 5 ; 
const int rotPot = 6 ; 



void setup() {
  pinMode(fLeft, INPUT);
  pinMode(rLeft, INPUT);
  pinMode(mLeft, INPUT);
  pinMode(fRight, INPUT);
  pinMode(rRight, INPUT);
  pinMode(mRight, INPUT);
  pinMode(rotPot, INPUT);
  Serial.begin(9600);
}


void loop() {

  // Following is the code for calculating the distance from the analog value
  int volts0 = analogRead(fLeft); // value from sensor * (5/1025)
  float dist1 = 13 * pow(volts0, -1) ; // worked out from the datasheet graph

  int volts1 = analogRead(rleft); // value from sensor * (5/1025)
  float dist2 = 13 * pow(volts1, -1) ; // worked out from the datasheet graph

  int volts2 = analogRead(mLeft); // value from sensor * (5/1025)
  float dist3 = 13 * pow(volts2, -1) ; // worked out from the datasheet graph

  int volts3 = analogRead(fRight); // value from sensor * (5/1025)
  float dist4 = 13 * pow(volts3, -1) ; // worked out from the datasheet graph

  int volts4 = analogRead(rRight); // value from sensor * (5/1025)
  float dist5 = 13 * pow(volts4, -1) ; // worked out from the datasheet graph

  int volts5 = analogRead(mRight); // value from sensor * (5/1025)
  float dist6 = 13 * pow(volts5, -1) ; // worked out from the datasheet graph

  // followiing the code for the rotary potential and the brake pressure sensor
  int pot_val = analogRead(rotPot) ;


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
  Serial.println(pot_val) ;

}
