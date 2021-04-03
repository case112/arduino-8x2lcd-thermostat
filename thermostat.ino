#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Temperature sensor connection on pin 4
#define ONE_WIRE_BUS 4

float temperature;
int thermostat_setting = 37; //if gets higher than 37 degrees switches power off

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//Display connections
//LiquidCrystal  (RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

void setup()
  {
  //Relay pin 2
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
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

  if (temperature < thermostat_setting) {
    digitalWrite(2,HIGH); 
    lcd.setCursor(0,0);
    lcd.print("PW: ");
    lcd.print("ON ");
    lcd.setCursor(0,1);
    lcd.print("C");
    lcd.print((char)223);
    lcd.print(": ");
    lcd.print(temperature, 1);
    delay(20000);
  }
  else {
    digitalWrite(2,LOW); 
    lcd.setCursor(0,0);
    lcd.print("PW: ");
    lcd.print("OFF");
    lcd.setCursor(0,1);
    lcd.print("C");
    lcd.print((char)223);
    lcd.print(": ");
    lcd.print(temperature, 1);
    // if temperature gets high cool off for a while
    delay(1800000);
  }
    
  }