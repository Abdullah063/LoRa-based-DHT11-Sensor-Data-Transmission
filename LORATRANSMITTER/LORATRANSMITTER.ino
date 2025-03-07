#include <SPI.h>
#include <LoRa.h>
#include <DHT.h>

// DHT11 tanımları
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LoRa pinleri (ESP32 için)
#define SCK    5  
#define MISO   19  
#define MOSI   27  
#define SS     18   
#define RST    14   
#define DIO0   26   

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // DHT11 başlat
  dht.begin();

  // SPI ve LoRa başlat
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa başlatılamadı!");
    while (1);
  }

  Serial.println("LoRa verici modu başladı!");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 okuma hatası!");
    return;
  }

  // Gönderilecek veri paketi
  String message = String(temperature) + "," + String(humidity);
  
  Serial.print("Gönderilen Veri → ");
  Serial.println(message);

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  delay(2000); // 2 saniye bekle
}