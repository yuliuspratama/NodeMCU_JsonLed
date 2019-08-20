# NodeMCU_JsonLed
LED yang bisa menyala dengan menggukan Json sebagai indikator nya

1. Tutorial Untuk dapat memprogram NodeMCU dengan IDE Arduino dapat di lihat pada link berikut
 https://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/

2. library dapat di cari dalam IDE arduino -> Tools -> manage libraries

3. install library "ArduinoJson" version 5 pada ide arduino


4. pada baris ke 6 dan ke 7 Masukkan Nama SSID WiFi dan PASSWORD WiFi di dalam tanda " "
5...
6. Baris ke 51 di dalam tanda "" dapat di isikan alamat web middleware server
7. dalam baris 78 angka dapat di sesuaikan jumlah client untuk berganti ke LED merah
8. dalam baris 84 angka dapat di sesuaikan jumlah client untuk berganti ke LED kuning
9. dalam baris 89 angka dapat di sesuaikan jumlah client untuk berganti ke LED Hijau

Untuk Upload program
1. pada Tools -> Board di ubah "Generic ESP8266 Module"
2. pilih port yang sudah terpasang NodeMCU
3. pilih icon "->" untuk upload
