#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
char auth[] = "SOMvC5FqPc-1rHLo5V9_-66PUkURLkpi";
char ssid[] = "DTM E-SMART";
char pass[] = "0919890938";
BlynkTimer timer;
WidgetRTC rtc;
void clockDisplay(){
  char bufTime[] = "00:00:00";
  char bufDate[] = "00/00/0000";
  sprintf(bufTime,"%02i:%02i:%02i",hour(),minute(),second());
  sprintf(bufDate,"%02i/%02i/%04i",day(),month(),year());
  display.clearDisplay(); 
  display.setTextSize(1);       
  display.setCursor(0,15);             
  display.println(bufDate);
  display.setTextSize(2);
  display.setCursor(0,50);             
  display.println(bufTime);
  display.display();
}
BLYNK_CONNECTED() {
  rtc.begin();
}
void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);
  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(20,15);             
  display.println("Welcom to");
  display.setCursor(0,40);             
  display.println("DTM E-SMART");
  display.display();
  delay(2000); 
  Blynk.begin(auth, ssid, pass);
  setSyncInterval(10 * 60);
  timer.setInterval(1000L, clockDisplay);
}
void loop() {
  Blynk.run();
  timer.run();
}
