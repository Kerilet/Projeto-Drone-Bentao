/*

*/

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

int pot_value =0;
int PWM_value = 0;
int potencia = 0;



void setup() 
{

    Serial.begin(115200);
       
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("  Controle PWM  ");
    lcd.setCursor(0, 1);
    lcd.print("  Motor  Drone  ");
    delay(2000);
    lcd.setCursor(0, 0);
    lcd.print("PWM:    ");
    lcd.setCursor(0, 1);
    lcd.print("Potencia:    ");
    
    
    
}


void loop() 
{
    
    pot_value = analogRead (A0);
    PWM_value = map (pot_value, 1023, 0, 0, 255);
    potencia = map (PWM_value, 0, 255, 0, 100);
 
    analogWrite(3, PWM_value);

    lcd.setCursor(0, 0);
    lcd.print("PWM: ");
    lcd.print(PWM_value);
    lcd.print("          ");
    lcd.setCursor(0, 1);
    lcd.print("Potencia: ");
    lcd.print(potencia);
    lcd.print("%       ");
    Serial.print ("PWM: ");
    Serial.print(PWM_value);
    Serial.print("   ");
    Serial.print("Potencia: ");
    Serial.print(potencia);
    Serial.println("%");
    delay(100);
    
}
