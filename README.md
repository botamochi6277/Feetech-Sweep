# Feetech Sweep

Test to drive feetech ttl servo motors with sweeping.
M5Atom Lite controls [STS3215](https://akizukidenshi.com/catalog/g/gM-16312/) with [FE-URT-1](https://akizukidenshi.com/catalog/g/gM-16295/), interface board.

## Connection

FE-URT-1 would have wrong silk annotations about RXD and TXD.

| M5Atom  | --  |  FE-URT-1  |
| :-----: | :-: | :--------: |
|   5V    | --  |     5V     |
|   GND   | --  |    GND     |
| 21 (RX) | --  | RXD (Silk) |
| 25 (TX) | --  | TXD (Silk) |
