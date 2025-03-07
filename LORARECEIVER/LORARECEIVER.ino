#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED ekran tanımları
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// LoRa pinleri
#define SCK    5  
#define MISO   19  
#define MOSI   27  
#define SS     18   
#define RST    14   
#define DIO0   26   

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // OLED ekran başlat
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("OLED ekran başlatılamadı!");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("LoRa Alıcı Başladı!");
  display.display();
  delay(2000);

  // SPI ve LoRa başlat
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa başlatılamadı!");
    while (1);
  }

  Serial.println("LoRa alıcı modu başladı!");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String receivedData = "";

    while (LoRa.available()) {
      receivedData += (char)LoRa.read();
    }

    Serial.print("Alınan Veri → ");
    Serial.println(receivedData);

    // Veriyi ayır (Sıcaklık ve Nem)
    int commaIndex = receivedData.indexOf(',');
    if (commaIndex == -1) return; // Eğer veri yanlış geldiyse

    float temperature = receivedData.substring(0, commaIndex).toFloat();
    float humidity = receivedData.substring(commaIndex + 1).toFloat();

    // OLED ekrana yazdır
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(10, 10);
    display.print("Sicaklik: ");
   
    display.print(temperature);
    display.print(" C");

    display.setCursor(10, 40);
    display.print("Nem: ");
    display.print(humidity);
    display.print("%");

    display.display(); // Ekranı güncelle
  }
}