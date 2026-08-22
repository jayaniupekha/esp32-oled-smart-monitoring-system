#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 15
#define DHTTYPE DHT22
#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  dht.begin();

  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Display failed!");
    for(;;);
  }
  
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.println("ESP32 SMART SYSTEM");
  display.setCursor(20, 40);
  display.println("Loading UI...");
  display.display();
  delay(2000);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor Read Error!");
    return;
  }

  
  bool isAlert = (temp > 28.0);
  digitalWrite(LED_PIN, isAlert ? HIGH : LOW);

  
  display.clearDisplay();

  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15, 0);
  display.println("IoT DASHBOARD");
  display.drawLine(0, 10, 128, 10, WHITE);

 
  display.setCursor(0, 18);
  display.print("Temp:");
  display.setTextSize(2);
  display.setCursor(45, 15);
  display.print(temp, 1);
  display.setTextSize(1);
  display.print(" C");

  
  display.setTextSize(1);
  display.setCursor(0, 38);
  display.print("Hum :");
  display.setTextSize(2);
  display.setCursor(45, 35);
  display.print(hum, 1);
  display.setTextSize(1);
  display.print(" %");

  
  display.drawLine(0, 52, 128, 52, WHITE);
  display.setCursor(0, 55);
  if(isAlert) {
    display.print("Status: ALERT (LED ON)");
  } else {
    display.print("Status: NORMAL (OFF)");
  }

  display.display();

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" C | Hum: "); Serial.print(hum);
  Serial.println(" %");

  delay(2000);
}
