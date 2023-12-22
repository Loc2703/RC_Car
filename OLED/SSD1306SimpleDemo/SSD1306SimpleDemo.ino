#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup()
{
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {  
      Serial.println("SSD1306 allocation failed");
      for(;;);
  }

  delay(2000);
  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,30);
  display.println("Hello World!");
  display.display();


}

void loop()
{
  Serial.print("1 ");
  display.display();
}