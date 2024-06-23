# Gömülü Yazılım Alanında Bilinmesi Gereken Temel Konular:

- Mikroişlemciler ve Mikrodenetleyiciler
- Programlama Dilleri (C, C++)
- Derleme ve Hata Ayıklama
- Donanım-Merkezli Tasarım
- Düşük Güç Tüketimi ve Performans Optimizasyonu
- Gerçek Zamanlı Sistemler
- Donanım Arayüzleri ve Sensörler
- RTOS (Gerçek Zamanlı İşletim Sistemleri)
- Entegre Geliştirme Ortamları (IDE'ler)


# Haberleşme Protokolleri

- UART (Universal Asynchronous Receiver/Transmitter)
- SPI (Serial Peripheral Interface)
- I2C (Inter-Integrated Circuit)
- CAN (Controller Area Network)
- Ethernet
- Bluetooth
- Wi-Fi
- TCP (Transmission Control Protocol)
- UDP (User Datagram Protocol)

## TCP ve UDP Arasındaki Farklar

- Bağlantı-Oriented (TCP) vs. Bağlantı-Oriented Olmayan (UDP)
- Güvenilirlik
- Akış Kontrolü ve Hata Denetimi
- Bağlantı Kurma ve Bağlantı Sonlandırma
- Hız ve Verimlilik


## SPI Haberleşme protokolü

SPI (Serial Peripheral Interface), mikrodenetleyiciler ve diğer entegre devreler arasında yüksek hızlı veri iletimi için kullanılan bir seri haberleşme protokolüdür. SPI, dört ana hat kullanır:

1. **MOSI (Master Out Slave In)**: Master cihazdan Slave cihazına veri gönderir.
2. **MISO (Master In Slave Out)**: Slave cihazdan Master cihaza veri gönderir.
3. **SCLK (Serial Clock)**: Master cihaz tarafından üretilen saat sinyali.
4. **SS (Slave Select)**: Hangi Slave cihazın aktif olduğunu belirleyen sinyal.

SPI, tam çift yönlü (full-duplex) veri iletimi sağlar ve genellikle yüksek hızlarda çalışır. Master cihaz, saat sinyalini kontrol eder ve veri iletimini senkronize eder. Slave cihazlar, SS hattı aracılığıyla seçilir ve veri iletimi gerçekleştirilir. SPI, basit yapısı ve yüksek hızı nedeniyle birçok uygulamada tercih edilir.
