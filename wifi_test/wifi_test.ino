#include <SoftwareSerial.h>
SoftwareSerial sSerial(10,11); //(RX,TX)

void setup() {
  Serial.begin(9600);    //硬體序列埠速率 (與軟體同步調整)
  sSerial.begin(115200);  //軟體序列埠速率 (與硬體同步調整)
  sSerial.write("AT+UART_DEF=9600,8,1,0,0\r\n"); 
  sSerial.begin(9600);
  Serial.println("SoftSerial to ESP8266 AT commands test ...");
  }

void loop() {
  if (sSerial.available()) {   //若軟體序列埠 Rx 收到資料 (來自 ESP8266)
    Serial.write(sSerial.read());  //讀取後寫入硬體序列埠 Tx (PC)
    }
  if (Serial.available()) {  //若硬體序列埠 Rx 收到資料 (來自 PC)
    sSerial.write(Serial.read());  //讀取後寫入軟體序列埠 Tx (ESP8266)
    }
  }
