// Components: NeoPixel , DRS Actuation Button

#include <Servo.h>
#include <Adafruit_NeoPixel.h>

int PIN = 6 ;
int NUMPIXELS = 10 ;

Servo myservo;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int str[2] ;
String data = "0000 22\n" ;

int Button_Pin = 2;
int state = HIGH;
int reading;
int previous = LOW;
unsigned long time = 0 ;
unsigned long debounce = 200;


void setup() {
  Serial.begin(9600) ;
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(Button_Pin, INPUT) ;
  pixels.begin(); // This initializes the NeoPixel library.

  for(int i = 0 ; i < 9 ; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 127)) ; 
    pixels.show() ;
    delay(30) ;
  }

  for(int i = 0 ; i < 9 ; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)) ; 
    pixels.show() ;
    delay(18) ;
  }

  for(int i = 0 ; i < 9 ; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 255, 51)) ; 
    pixels.show() ;
    delay(30) ;
  }

  for(int i = 0 ; i < 9 ; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)) ; 
    pixels.show() ;
    delay(18) ;
  }
 
  for(int i = 0 ; i < 9 ; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 255, 0)) ; 
    pixels.show() ;
    delay(30) ;
  }

   for(int i = 0 ; i < 9 ; i++) { 
   pixels.setPixelColor(i, pixels.Color(0, 0, 0)) ; 
    pixels.show() ;
    delay(18) ;
  }

}

void loop() {

  if (Serial.available() > 0 ) {
    data = Serial.readStringUntil('\n') ;
    //data = Serial.readString() ;
    //data = Serial.read() ;
  }


  /////////////////CONVERTING DATA INTO AN ARRAY////////////////////////////////////////////////
  int j = 0 ;
  int last = 0 ;

  for (int i = 0 ; i < data.length() ; i++) {

    //Serial.println(data.charAt(i)) ;

    if (data.charAt(i) != ' ') {
      j++ ;
    } else {

      str[0] = data.substring(last , j).toInt() ;

      last = j + 1 ;
      j++ ;
    }
  }

  str[1] = data.substring(last , data.length() - 1 ).toInt() ;


  Serial.print(str[0]) ;
  Serial.print(' ') ;
  Serial.println(str[1]) ;

  //////////////////////NEOPIXEL///////////////////////////////////////

  // map the number of pixels according to the RPM stored in str[0]   .
  if (str[0] < 1250) {
    for (int a = 0 ; a < 1 ; a++) {
      pixels.setPixelColor(a, pixels.Color(0, 150, 0)) ; // Moderately bright green color.
      pixels.show() ;
    }
  } else if (str[0] >= 1250 && str[0] < 2500 ) {
    for (int a = 0 ; a < 2 ; a++) {
      pixels.setPixelColor(a, pixels.Color(0, 150, 0)) ;  
      pixels.show() ;
    }
  } else if (str[0] >= 2500 && str[0] < 3750 ) {
    for (int a = 0 ; a < 3 ; a++) {
      pixels.setPixelColor(a, pixels.Color(0, 150, 0)) ;  
      pixels.show() ;
    }
  } else if (str[0] > 3750 && str[0] < 5000 ) {
    for (int a = 0 ; a < 4 ; a++) {
      pixels.setPixelColor(a, pixels.Color(255, 255, 0)) ; // Moderately yellow color.
      pixels.show() ;
    }
  } else if (str[0] >= 5000 && str[0] < 6250 ) {
    for (int a = 0 ; a < 5 ; a++) {
      pixels.setPixelColor(a, pixels.Color(255, 255, 0)) ;  
      pixels.show() ;
    }
  } else if (str[0] >= 6250 && str[0] < 7500 ) {
    for (int a = 0 ; a < 6 ; a++) {
      pixels.setPixelColor(a, pixels.Color(255, 255, 0)) ;  
      pixels.show() ;
    }
  } else if (str[0] >= 7500 && str[0] < 8750 ) {
    for (int a = 0 ; a < 7 ; a++) {
      pixels.setPixelColor(a, pixels.Color(255, 255, 0)) ;  
      pixels.show() ;
    }
  } else if (str[0] >= 8750 && str[0] < 10000 ) {
    for (int a = 0 ; a < 8 ; a++) {
      pixels.setPixelColor(a, pixels.Color(255, 0, 0)) ; // Bright red color.
      pixels.show() ;
    }
  }



//////////////////SERVO AND OVER RIDE SWITCH/////////////////////////////////////////////////

reading = digitalRead(Button_Pin);
if (reading == HIGH && previous == LOW && millis() - time > debounce) {
  state = !state ;
  time = millis();
}

if (state) {
  pixels.setPixelColor(10, pixels.Color(0, 150, 0)); // Moderately bright green color.
  pixels.show();
  myservo.write(0) ;
}
else {
  pixels.setPixelColor(10, pixels.Color(0, 0, 0)); // Moderately bright green color.
  pixels.show();
  myservo.write(22) ;
}
previous = reading;


////////////////////////////////////////////////////////////////////////////////////

for ( int i = 0 ; i < 10 ; i++) {
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
}

}
