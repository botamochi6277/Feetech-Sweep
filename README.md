# Feetech Sweep

![badge](https://github.com/botamochi6277/Feetech-Sweep/actions/workflows/ci-platformio.yml/badge.svg)

Test to drive feetech ttl servo motors with sweeping.
M5Atom Lite controls [STS3215](https://akizukidenshi.com/catalog/g/gM-16312/) with [FE-URT-1](https://akizukidenshi.com/catalog/g/gM-16295/), interface board.

## Usage

1-Clone this repository:

```zsh
git clone  https://github.com/botamochi6277/Feetech-Sweep.git
```

2-Install SCServo library

```zsh
./download_scservo.sh
```

3-Build with PlatformIO

## Connection

FE-URT-1 would have wrong silk annotations about RXD and TXD.

| M5Atom  | --  |  FE-URT-1  |
| :-----: | :-: | :--------: |
|   5V    | --  |     5V     |
|   GND   | --  |    GND     |
| 21 (RX) | --  | RXD (Silk) |
| 25 (TX) | --  | TXD (Silk) |
