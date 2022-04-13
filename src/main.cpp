#include <Arduino.h>
#include "SCServo.h"

#ifdef M5ATOM
#define RX1 21
#define TX1 25
#endif

SMS_STS st;

short max_sweep = 4095;
short min_sweep = 0;
unsigned short speed = 3400;
unsigned char acc = 50;

void setup()
{
  // LED_BUILTIN;
  Serial.begin(115200); // serial for debugging
#ifdef M5ATOM
  Serial1.begin(1000000, SERIAL_8N1, RX1, TX1);
#endif
#ifdef XIAO
  Serial1.begin(1000000); // serial for servos
#endif

  st.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  Serial.println("start sweeping");
  st.RegWritePosEx(0, max_sweep, speed, acc);
  st.RegWritePosEx(1, max_sweep, speed, acc);
  st.RegWriteAction();
  delay(1884); //[(P1-P0)/Speed]*1000+[Speed/(Acc*100)]*1000

  st.RegWritePosEx(0, min_sweep, speed, acc);
  st.RegWritePosEx(1, min_sweep, speed, acc);
  st.RegWriteAction();
  delay(1884);
}