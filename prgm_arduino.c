#include <Wire.h>

byte Address = 0x20;
byte LED_P7_ON = 0b10000000,
     LED_P6_ON = 0b01000000,
     LED_P5_ON = 0b00100000,
     LED_P4_ON = 0b00010000; // Ajout du point-virgule à la fin de la déclaration

void setup() 
{
    Wire.begin();
}

void loop() 
{
    static int blinkCount = 0;
    SwitchLED(0, 0, LED_P5_ON, 0); // Allumer LED5 uniquement
    delay(200);
    SwitchLED(0, 0, 0, 0); // Éteindre toutes les LEDs
    delay(500);
    
    blinkCount++;
    
    // Si 5 clignotements de LED5 ont eu lieu, allumer et éteindre LED4
    if(blinkCount == 5) 
    {
        SwitchLED(0, 0, 0, LED_P4_ON); // Allumer LED4
        delay(200);
        SwitchLED(0, 0, 0, 0); // Éteindre LED4
        delay(200);
        blinkCount = 0; // Réinitialiser le compteur
    }
}

void SwitchLED(byte led7, byte led6, byte led5, byte led4) 
{
    byte LED_ON = 0xFF; //initialisation des 4 bits de poids fort à 1
    //Par défaut, les leds éteintes sont à 1.
    
    //adaptation en fonction des leds qu'on veut allumer
    LED_ON &= ~led7; 
    LED_ON &= ~led6;
    LED_ON &= ~led5; 
    LED_ON &= ~led4;
    
    Wire.beginTransmission(Address);
    Wire.write(LED_ON);
    Wire.endTransmission();
}
