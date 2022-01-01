#include <Arduino.h>
#include "SCServo.h"

#define RX1 21
#define TX1 25

SMS_STS st;

void setup()
{
  Serial.begin(115200); // serial for debugging

  Serial1.begin(1000000, SERIAL_8N1, RX1, TX1);
  // Serial1.begin(1000000); // serial for servos
  st.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  Serial.println("start sweeping");
  st.RegWritePosEx(0, 4095, 3400, 50);
  st.RegWritePosEx(1, 4095, 3400, 50);
  st.RegWriteAction();
  delay(1884); //[(P1-P0)/Speed]*1000+[Speed/(Acc*100)]*1000

  st.RegWritePosEx(0, 0, 3400, 50);
  st.RegWritePosEx(1, 0, 3400, 50);
  st.RegWriteAction();
  delay(1884);
}