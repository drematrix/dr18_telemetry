// Components: 4 Linear Potentials , 1 Gear Position Sensor   

const int fLeft = 4 ;
const int fRight = 5 ; 
const int rLeft = 6 ;
const int rRight = 7 ;
const int GPS = 3 ; 

void setup() {
  Serial.begin(9600) ; // Initialize Serial to log output  
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
      Serial.println("1") ; 
    }else if(GPS_val > 189 && GPS_val < 199) { 
      Serial.println("N") ; 
    }else if(GPS_val > 269 && GPS_val < 279) { 
      Serial.println("2") ; 
    }else if(GPS_val > 427 && GPS_val < 437) { 
      Serial.println("3") ; 
    }else if(GPS_val > 586 && GPS_val < 596) { 
      Serial.println("4") ; 
    }else if(GPS_val > 745 && GPS_val < 754) { 
      Serial.println("5") ; 
    }else if(GPS_val > 902 && GPS_val < 912) { 
      Serial.println("6") ; 
    }else { 
      Serial.println("E") ; 
    }
  
}
