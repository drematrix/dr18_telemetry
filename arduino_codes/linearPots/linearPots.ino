// Components: 4 Linear Potentials , 1 Gear Position Sensor , 1 Lap Timing Button 

const int fLeft = 4 ;
const int fRight = 5 ; 
const int rLeft = 6 ;
const int rRight = 7 ;
const int GPS = 3 ; 

void setup() {
  Serial.begin(9600) ; // Initialize Serial to log output
  pinMode(A0,INPUT)  
}

void loop() {

// Following 4 inputs are for the linear potentials 

  Serial.print(analogRead(fLeft)) ; 
  Serial.print(" ") ;
  Serial.print(analogRead(fRight)) ; 
  Serial.print(" ") ; 
  Serial.print(analogRead(rLeft)) ; 
  Serial.print(" ") ; 
  Serial.print(analogRead(rRight)) ; 
  Serial.print(" ") ; 
  
// Following input is for the Gear Position Sensor 

  int GPS_val = analogRead(GPS) ; 

    if(GPS_val > 111 && GPS_val < 121) { 
      Serial.print("1") ; 
    }else if(GPS_val > 189 && GPS_val < 199) { 
      Serial.print("N") ; 
    }else if(GPS_val > 269 && GPS_val < 279) { 
      Serial.print("2") ; 
    }else if(GPS_val > 427 && GPS_val < 437) { 
      Serial.print("3") ; 
    }else if(GPS_val > 586 && GPS_val < 596) { 
      Serial.print("4") ; 
    }else if(GPS_val > 745 && GPS_val < 754) { 
      Serial.print("5") ; 
    }else if(GPS_val > 902 && GPS_val < 912) { 
      Serial.print("6") ; 
    }else { 
      Serial.print("E") ; 
    }
  
// Following input is for Lap Timing Button 

  Serial.println(digitalRead(A0)) ; 

}
