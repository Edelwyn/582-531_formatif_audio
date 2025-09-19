#include <Arduino.h>

#define MA_BROCHE_BOUTON 39
#define MA_BROCHE_ANGLE 32

#include <FastLED.h>

CRGB monPixel;

#include <MicroOscSlip.h>
// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.

// Les messages sortants sont écrits directement sur la sortie et ne nécessitent pas de réservation d'octets supplémentaires. aa

MicroOscSlip<128> monOsc(&Serial);
 
 
void setup() {

  Serial.begin(115200);

  pinMode( MA_BROCHE_BOUTON , INPUT );

  FastLED.addLeds<WS2812,27,GRB>( & monPixel, 1);

}
 
void loop() {

  int maLectureAngle;

  maLectureAngle = analogRead(MA_BROCHE_ANGLE);

  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );

  //Serial.println(maLectureBouton);

 
  monOsc.sendInt("/bouton",maLectureBouton);

  monOsc.sendInt("/angle",maLectureAngle);

  delay(100);
 
  if(maLectureAngle > 2000) {

    monPixel = CRGB(0, 50,255);

    FastLED.show();

  }else {

    monPixel = CRGB(150, 100,0);
    FastLED.show();
  }
 
 
}
 