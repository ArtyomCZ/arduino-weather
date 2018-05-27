#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
  
void setup() {
  lcd.begin(2, 2);
  lcd.setCursor(0,1);
  lcd.blink();
  dht.begin();
  Serial.begin(9600);
  Serial.println("Komunikace zahajena");
  delay(2000);
  lcd.clear();
}
 
void loop() {

  float t = dht.readTemperature();
  ; float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) {
    lcd.clear();
    lcd.blink();
    lcd.setCursor(0,0);
    lcd.print(" [!] CHYBA [!]");
    Serial.println("[!]Chyba: nelze ziskat data senzoru");
    lcd.setCursor(0,1);
    lcd.print("Pripojte senzor");
    delay(1000);
    lcd.noDisplay();
    delay(800);
    lcd.display();
  }
  else {
  lcd.display();
  lcd.noBlink();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Teplota: ");
  lcd.print(t);
  Serial.print("teplota: ");
  Serial.println(t);
  lcd.write(B11011111); // = °
  lcd.print("C"); 
  lcd.setCursor(0,1);
  lcd.print("Vlhkost: ");
  lcd.print(h);
  Serial.print("vlhkost: ");
  Serial.println(h);
  lcd.print("%");
  delay (2000);
  }  
}
