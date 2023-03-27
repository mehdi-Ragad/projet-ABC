#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 60
int lightSensorPin = 5; // Pin du capteur de lumière

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

                                                                                                    int ledPin = 6;  // On renomme la broche 6 en "ledPin"
                                                                                                    int timer = 100; // On définit uen durée de 0,1 seconde pour la variable timer
void setup() {
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
 Serial.begin(9600);     //Set serial baud rate to 9600 bps


 pinMode(lightSensorPin, INPUT);
    Serial.begin(9600);  
   // colorWipe(strip.Color(0,0,255));


                                                                                                     pinMode (ledPin, OUTPUT);

}

void loop()
{
 int lightValue = analogRead(lightSensorPin); // Lecture de la valeur du capteur de lumière
  Serial.println(lightValue); // Affichage de la valeur sur le port série


  if ((lightValue > 200) && (lightValue < 500)) { // Si la lumière est faible
    afficher (strip.Color(0,0,255));
    
  }
  else if (lightValue > 500 ) {
    eteindre();
  }
  else if ((lightValue > 0) && (lightValue < 200) ) {
     afficher (strip.Color(255,0,0));
  }
  delay(2000); // Délai avant la prochaine lecture

  
  
  

}

void colorWipe(uint32_t color) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
  }
}

void afficher(uint32_t color) {

      
      
      
      for (int i = 0; i<strip.numPixels(); i++) { 
        strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        strip.show();        
      }
  delay (10);
  
    
  
}

void eteindre() {
    
    strip.clear();                          //  Update strip to match
    strip.show();
    delay(1000);
  }
