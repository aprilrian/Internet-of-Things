// include the library code:
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor = 9; // Posisi sensor dipasang
int state = LOW; // secara default, keadaan tidak ada motion/gerakan
int val = 0;
int buzzer = 7; // posisi buzzer di pasang
int lampu = 6; // posisi lampu dipasang
int LIGHT = LOW;

void setup()
{
    pinMode(sensor, INPUT); // inisialisasi sensor sebagai input
    pinMode(buzzer, OUTPUT);    // inisialisasi buzzer sebagai output
  	pinMode(lampu, OUTPUT);	// inisialisasi lampu sebagai output
  	lcd.begin(16, 2);
    lcd.print("LAMPU");
  	lcd.setCursor(0, 1);
    lcd.print("OFF             ");
}

void loop()
{
  	val = digitalRead(sensor);  // membaca value/nilai dari sensor
    if(LIGHT == LOW)
    {
      if (val == HIGH)
      {
          delay(100);     // delay 100 miliseconds
          if (state == LOW)
          {
              lcd.setCursor(0, 1);
              lcd.print("ON              ");
              digitalWrite(buzzer, HIGH);     //  Menghidupkan Buzzer
              digitalWrite(lampu, HIGH);     // Menghidupkan Lampu
              state = HIGH;   // Update variabel state menjadi HIGH
          }
      }
     else
      {
          delay(100);     // delay 100 miliseconds
          if (state == HIGH)
          {
              lcd.setCursor(0, 1);
              lcd.print("ON             ");
              digitalWrite(buzzer, LOW);     //  Mematikan Buzzer
              digitalWrite(lampu, HIGH);     // Mematikan Lampu
              state = LOW;   // Update variabel state menjadi LOW
            LIGHT = HIGH;
          }
      }
    }
  	else
    {
      if (val == HIGH)
      {
          delay(100);     // delay 100 miliseconds
          if (state == LOW)
          {
              lcd.setCursor(0, 1);
              lcd.print("OFF              ");
              digitalWrite(buzzer, HIGH);     //  Menghidupkan Buzzer
              digitalWrite(lampu, LOW);     // Menghidupkan Lampu
              state = HIGH;   // Update variabel state menjadi HIGH
          }
      }
     else
      {
          delay(100);     // delay 100 miliseconds
          if (state == HIGH)
          {
              lcd.setCursor(0, 1);
              lcd.print("OFF             ");
              digitalWrite(buzzer, LOW);     //  Mematikan Buzzer
              digitalWrite(lampu, LOW);     // Mematikan Lampu
              state = LOW;   // Update variabel state menjadi LOW
            LIGHT = LOW;
          }
      }
    }
}
