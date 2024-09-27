# Feetech Sweep

![badge](https://github.com/botamochi6277/Feetech-Sweep/actions/workflows/ci-platformio.yml/badge.svg)

Test to drive feetech ttl servo motors with [M5Atom](https://docs.m5stack.com/#/en/core/atom_lite) or [Seeed XIAO](https://www.seeedstudio.com/Seeeduino-XIAO-Arduino-Microcontroller-SAMD21-Cortex-M0+-p-4426.html).
These control [STS3215](https://akizukidenshi.com/catalog/g/gM-16312/) with [FE-URT-1](https://akizukidenshi.com/catalog/g/gM-16295/), interface board.

## Usage

1. Clone this repository:

```zsh
git clone  https://github.com/botamochi6277/Feetech-Sweep.git
```

2. Install SCServo library

```zsh
./download_scservo.sh
```

3. Build and Upload with PlatformIO

## Connection

FE-URT-1 would have wrong silk annotations about RXD and TXD.

### M5Stack Core1

|  Core1   |  --   |  FE-URT-1  |
| :------: | :---: | :--------: |
|    5V    |  --   |     5V     |
|   GND    |  --   |    GND     |
| D16 (RX) |  --   | RXD (Silk) |
| D17 (TX) |  --   | TXD (Silk) |

### M5Stack Core2

|  Core1   |  --   |  FE-URT-1  |
| :------: | :---: | :--------: |
|    5V    |  --   |     5V     |
|   GND    |  --   |    GND     |
| D13 (RX) |  --   | RXD (Silk) |
| D14 (TX) |  --   | TXD (Silk) |

### M5Atom

| M5Atom  |  --   |  FE-URT-1  |
| :-----: | :---: | :--------: |
|   5V    |  --   |     5V     |
|   GND   |  --   |    GND     |
| 26 (RX) |  --   | RXD (Silk) |
| 32 (TX) |  --   | TXD (Silk) |

### XIAO

|  XIAO   |  --   |  FE-URT-1  |
| :-----: | :---: | :--------: |
|   5V    |  --   |     5V     |
|   GND   |  --   |    GND     |
| D7 (RX) |  --   | RXD (Silk) |
| D6 (TX) |  --   | TXD (Silk) |

---

## w/o FE-URT-1

You can control servos with the circuit using MAX485 in [AKIZUKI document](https://akizukidenshi.com/goodsaffix/feetech_digital_servo_20220729.pdf).

### M5Stack Core1

ESP32's signal level is 3.3V. You need to connect VCC of MAX485 and ESP32's 3.3V pin.

|  Core1   |  --   | MAX485 |
| :------: | :---: | :----: |
|   3.3V   |  --   |  VCC   |
|   GND    |  --   |  GND   |
| D16 (RX) |  --   |   RO   |
| D17 (TX) |  --   |   DI   |
