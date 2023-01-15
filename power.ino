#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float input_volt = 0.0;
float tot_volt = 0.0;
float temp=0.0;
float r1=100000.0;    //r1 value
float r2=10000.0;      //r2 value
int steps=0;
void setup()
{
   lcd.begin(16, 2);
   Serial.begin(9600);     //  opens serial port, sets data rate to 9600 bps
}
void loop()
{
    int analogvalue = analogRead(A0);
    temp = (analogvalue * 5.0) / 1024.0;  // FORMULA USED TO CONVERT THE VOLTAGE
    input_volt = temp / (r2/(r1+r2));
    if (input_volt != 0 ) 
    {
         lcd.setCursor(0, 0);
         lcd.print("  VOLTAGE: ");
         lcd.print(input_volt);
         lcd.print("  ");
         delay(700);
          tot_volt += input_volt;
          lcd.setCursor(0,0);
          lcd.print(" TOT_VOLT: ");
           lcd.print(tot_volt);
          lcd.print("  ");

      steps=steps+1;
    } 
//    Serial.print("Voltage= ");                 // prints the voltage value in the serial monitor
//    Serial.print(input_volt);
//    Serial.println(" Volts");

    lcd.setCursor(0, 1);
  lcd.print("    STEPS: ");
  lcd.print(steps);
    lcd.print("  ");

    delay(300);
}
