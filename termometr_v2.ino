#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define DHTPIN 2  
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE); 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(9600);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); }

void loop() {
  float temp = dht.readTemperature();
  float wilg = dht.readHumidity();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 5);
  display.println("STACJA POGODOWA");
  display.drawLine(0, 15, display.width()-1, 15,SSD1306_WHITE);
  display.setCursor(2, 25);
  display.print("TEMPERATURA: ");
  display.print(temp);
  display.println(" `C");
  display.setCursor(2, 40);
  display.print("WILGOTNOSC:  ");
  display.print(wilg);
  display.print(" %");
  display.display(); 
  delay(2000);}
