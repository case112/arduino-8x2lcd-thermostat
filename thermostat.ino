#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4

float temperature;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

void setup()
  {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  sensors.begin();
    
  lcd.begin(8, 2);
  lcd.setCursor(0,0);
  lcd.print("POWER:");
  lcd.setCursor(0,1);
  lcd.print("TEMP:");
  delay(2000);
  }

void loop()
  { 
  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);
  Serial.println(temperature, 1);

  if (temperature > 22) {
    digitalWrite(2,HIGH); 
  }
  else {
    digitalWrite(2,LOW);
  }

  lcd.setCursor(0,0);
  lcd.print("PW: ");
  lcd.print("ON");
  lcd.setCursor(0,1);
  lcd.print("C");
  lcd.print((char)223);
  lcd.print(": ");
  lcd.print(temperature, 1);

  delay(5000);
    
  }