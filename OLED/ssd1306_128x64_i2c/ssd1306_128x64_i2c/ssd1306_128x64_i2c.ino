#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  // Khởi tạo màn hình OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  // if(!display.begin(SSD1306_I2C_ADDRESS, SDA, SCL)) {
  //   Serial.println(F("SSD1306 initialization failed"));
  //   for(;;);
  // }

  // Delay để chắc chắn rằng màn hình OLED đã kết nối
  delay(2000);

  // Xóa màn hình
  display.clearDisplay();
  display.display();

  // Hiển thị văn bản
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Hello, OLED!");

  display.display();
}

void loop() {
  // Code chính của bạn ở đây
}
