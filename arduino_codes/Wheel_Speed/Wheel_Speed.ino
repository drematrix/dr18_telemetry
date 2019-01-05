unsigned long current = 0 ;
unsigned long prev = 0 ;

int inputState = 0 ;
int lastInputState = 0 ;

float angle = 51.43 ; // angle between the starting of two consecutive crest .
// float angle = 60 For the Rear tires.

float sped ;

void setup() {
  Serial.begin(2000000);
}


void loop() {

  int Sense_val = analogRead(0) ;

  if ( Sense_val > 700 ) inputState = 1;
  else inputState = 0 ;

  if (inputState != lastInputState) {

    if (inputState == HIGH) {

      current = millis() ;

      float timee = current - prev ;

      sped = ( angle / timee ) * 100 ; // Calculation of Omega ( w = theta / time ).
      sped *= 0.229 ; // Calcultaion of linear speed ( v = rw ), 0.229 is the radius of the tire in meters.
      sped *= 0.27 ; // Conversion to Km/hour.

      prev =  current ;
    }
  }
  Serial.println(int(sped)) ; // Printing and conversion into integer from float.
  lastInputState = inputState;
}