#include <Arduino.h>

#include "SCServo.h"

#if defined(ARDUINO_M5Stack_Core_ESP32) || defined(ARDUINO_M5STACK_Core2)
#define M5_DISPLAY
#endif

#ifdef M5_DISPLAY
#include <M5Unified.h>
#endif

// #ifdef SEEED_XIAO_M0
// #define RX1 7
// #define TX1 6
// #endif

#ifdef ARDUINO_M5Stack_ATOM
// https://shinshu-makers.net/shinshu_makers/2021/05/28/%E3%80%90m5%E3%80%91m5atom-lite%E3%81%AEuart%E3%81%A7%E3%83%94%E3%83%B3%E6%8E%A2%E3%81%97%EF%BC%9C%EF%BC%92%EF%BC%91%EF%BC%8C%EF%BC%92%EF%BC%95%E3%81%AF%E4%BD%BF%E3%81%88%E3%81%AA%E3%81%84%EF%BC%9E/
#define RXD 32
#define TXD 26
#elif defined(ARDUINO_M5Stack_Core_ESP32)
// CORE1
#define RXD RX2  // 16
#define TXD TX2  // 17
#elif defined(ARDUINO_M5STACK_Core2)
// CORE2??
#define RXD RX2
#define TXD TX2
#elif defined(ARDUINO_M5Stack_StampS3)
#define RXD 44
#define TXD 43
#endif

SMS_STS st;

short max_sweep = 4095;
short min_sweep = 0;
unsigned short speed = 3400;
unsigned char acc = 50;

void setup() {
#ifdef M5_DISPLAY
  M5.begin();
  M5.Display.setTextSize(3);
#endif
  // LED_BUILTIN;
  Serial.begin(115200);  // serial for debugging
  Serial1.begin(1000000, SERIAL_8N1, RXD, TXD);

  st.pSerial = &Serial1;

  delay(1000);
  for (;;) {
    if (Serial1) {
      Serial.printf("Serial1(%d,%d) is ready\n\r", RXD, TXD);
#ifdef M5_DISPLAY
      M5.Display.setCursor(0, 20);
      M5.Display.printf("Serial1(%d ,%d) is ready", RXD, TXD);
#endif
      break;
    } else {
      Serial.printf("Serial1(%d,%d) is not found\n\r", RXD, TXD);
#ifdef M5_DISPLAY
      M5.Display.setCursor(0, 20);
      M5.Display.printf("Serial1(%d ,%d) is not found", RXD, TXD);
#endif
    }
    delay(1000);
  }
}

void loop() {
  if (Serial1) {
    auto pos1 = st.ReadPos(1);
    if (pos1 < 0) {
      Serial.println("Connection failed with Servo-01");
#ifdef M5_DISPLAY
      M5.Display.clear();
      M5.Display.setCursor(0, 20);
      M5.Display.print("Connection failed with Servo-01");
#endif
    }

    auto pos2 = st.ReadPos(2);
    if (pos2 < 0) {
      Serial.println("Connection failed with Servo-02");
    }

    if (pos1 < 0 && pos2 < 0) {
      // do nothing
    } else {
      Serial.println("start sweeping");
      st.RegWritePosEx(1, max_sweep, speed, acc);
      st.RegWritePosEx(2, max_sweep, speed, acc);
      st.RegWriteAction();
      delay(1884);  //[(P1-P0)/Speed]*1000+[Speed/(Acc*100)]*1000

      st.RegWritePosEx(1, min_sweep, speed, acc);
      st.RegWritePosEx(2, min_sweep, speed, acc);
      st.RegWriteAction();
      delay(1884);
    }
  } else {
    Serial.printf("Serial1(%d,%d) is lost\n\r", RXD, TXD);
#ifdef M5_DISPLAY
    M5.Display.clear();
    M5.Display.setCursor(0, 20);
    M5.Display.printf("Serial1(%d ,%d) is lost", RXD, TXD);
#endif
    Serial1.end();
    delay(100);
    Serial1.begin(1000000, SERIAL_8N1, RXD, TXD);

    delay(1000);
  }
}