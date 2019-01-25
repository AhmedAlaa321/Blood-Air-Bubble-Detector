#include <LiquidCrystal.h>
const int laserPin = 13;
const int ledPin = 10;
const int sensorPin = A0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buzzer = 8;

void setup() {

Serial.begin(9600);
pinMode(buzzer, OUTPUT);
lcd.begin(16,2);
lcd.clear( );
pinMode(laserPin, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(sensorPin, INPUT);

}

void loop() {

int sensorStatus = analogRead(sensorPin);
digitalWrite(laserPin, HIGH);

Serial.println(sensorStatus);

if (sensorStatus  > 50  )
{lcd.setCursor(0,0);
   lcd.print("Bubble detected");
   delay(500);
   
   for(int i=0;i<=2;i++)
    {
            tone(buzzer,2000);// Send 2KHz sound signal...
            digitalWrite (ledPin , HIGH );
            delay(500);
            noTone(buzzer);// Stop sound...
            digitalWrite (ledPin , LOW );
            delay(500);
            
            }// ...for 1sec 
  lcd.clear();          
}
  
Serial.println(sensorStatus);


}
