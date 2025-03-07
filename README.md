
# 🌍 LoRa ile DHT11 Sensör Verisi Gönderimi ve OLED Ekranda Görüntüleme  

Bu proje, **ESP32** kullanarak **LoRa** teknolojisi ile **DHT11 sıcaklık ve nem sensöründen** alınan verileri **kablosuz olarak iletmeyi** ve **OLED ekranda görüntülemeyi** sağlar.  

## 🚀 Proje İçeriği  
🔹 **Verici (Transmitter):** DHT11 sensöründen alınan sıcaklık ve nem verisini **LoRa** üzerinden alıcıya gönderir.  
🔹 **Alıcı (Receiver):** LoRa ile alınan veriyi işler ve **OLED ekran** üzerinde görüntüler.  

---  

## 📦 Gereksinimler  
✅ **ESP32** geliştirme kartı  
✅ **DHT11** sıcaklık & nem sensörü  
✅ **LoRa modülü** (SX1278 gibi)  
✅ **OLED ekran** (I2C protokolü ile)  
✅ **Arduino IDE**  

---

## ⚙️ Kurulum Adımları  

### 🛠 1. Arduino IDE'yi Kurun  
Arduino IDE yüklü değilse, [buradan](https://www.arduino.cc/en/software) indirip yükleyebilirsiniz.  

### 📚 2. Gerekli Kütüphaneleri Yükleyin  
Arduino IDE'de aşağıdaki kütüphaneleri yükleyin:  

- **LoRa** *(by Sandeep Mistry)*  
- **Adafruit SSD1306** *(OLED ekran için)*  
- **Adafruit GFX** *(Grafik işlemleri için)*  
- **Adafruit DHT Sensor Library** *(DHT11 sensörü için)*  

📌 **Kütüphaneleri yüklemek için:**  
1. Arduino IDE’yi açın  
2. **Sketch** > **Include Library** > **Manage Libraries...** sekmesine tıklayın  
3. Yukarıdaki kütüphaneleri aratıp **Install (Yükle)** butonuna basın  

---

## 🔌 Donanım Bağlantıları  

### 📡 **Verici (Transmitter) ESP32 Bağlantıları**  
🔵 **DHT11 Sensörü:**  
| DHT11 Pin | ESP32 Pin |
|-----------|----------|
| **VCC**   | **3.3V**  |
| **GND**   | **GND**   |
| **DATA**  | **GPIO 4** |

🟢 **LoRa Modülü:**  
| LoRa Pin  | ESP32 Pin |
|-----------|----------|
| **SS**    | **GPIO 18** |
| **SCK**   | **GPIO 5**  |
| **MISO**  | **GPIO 19** |
| **MOSI**  | **GPIO 27** |
| **RST**   | **GPIO 14** |
| **DIO0**  | **GPIO 26** |

---

### 📶 **Alıcı (Receiver) ESP32 Bağlantıları**  
🔴 **OLED Ekran (I2C)**  
| OLED Pin | ESP32 Pin |
|----------|----------|
| **VCC**  | **3.3V**  |
| **GND**  | **GND**   |
| **SDA**  | **GPIO 21** |
| **SCL**  | **GPIO 22** |

🟣 **LoRa Modülü:** *(Aynı bağlantılar transmitter ile aynıdır.)*  
| LoRa Pin  | ESP32 Pin |
|-----------|----------|
| **SS**    | **GPIO 18** |
| **SCK**   | **GPIO 5**  |
| **MISO**  | **GPIO 19** |
| **MOSI**  | **GPIO 27** |
| **RST**   | **GPIO 14** |
| **DIO0**  | **GPIO 26** |

---

Bu proje sayesinde, **LoRa haberleşmesi** kullanarak **kablosuz veri aktarımını** kolayca gerçekleştirebilirsiniz. 🚀 🎯
