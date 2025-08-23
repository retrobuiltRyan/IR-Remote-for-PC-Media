# IR-Remote-for-PC-Media
Custom PCB + code for multi app media PC control with generic IR remote. Use an Arduino Pro Micro or RP2040 Pro Micro to decode an IR remote, assign macros. 
Control your PC with a USB HID (keyboard) device using an IR remote.

![P1110614](https://github.com/user-attachments/assets/a394f5b0-f464-4afe-bd9c-43775ce63493)

![P1110598](https://github.com/user-attachments/assets/977a2281-069d-4ccd-84ab-e45d4f6305c5)


### Bill of Materials

| Reference         | Value                | Qty | Cost Each | Line Total | DigiKey P/N         | AliExpress Link                                                                 |
|------------------|----------------------|-----|------------|-------------|----------------------|----------------------------------------------------------------------------------|
| C1, C2, C3, C4, C5| 0.1uF 50V            | 5   | $0.07      | $0.35       | 1276-1068-1-ND        |                                                                                  |
| D1, D2, D3, D4, D5| WS2812B              | 5   | $0.10      | $0.50       |                      | [AliExpress](https://www.aliexpress.us/item/3256802466699315.html)             |
| J3               | OLED 1.3" 128x64     | 1   | $4.59      | $4.59       |                      | [AliExpress](https://www.aliexpress.us/item/3256806824217573.html)             |
| R1               | 220 ohm              | 1   | $0.02      | $0.02       | 311-220FRCT-ND        |                                                                                  |
| SW1              | SW Push Button       | 1   | $0.12      | $0.12       | CKN12221-1-ND         |                                                                                  |
| U1               | Pro Micro ATMEGA 32u4| 1   | $4.29      | $4.29       |                      | [AliExpress](https://www.aliexpress.us/item/3256807158682738.html)             |
| PCB              | JLCPCB               | 1   | $0.30      | $0.30       |                      |                                                                                  |
| IR Receiver      | IR RX                | 1   | $0.11      | $0.11       |                      | [AliExpress](https://www.aliexpress.us/item/3256804608870666.html)             |
| Remote           | Roku Media Remote    | 1   | $2.67      | $2.67       |                      | [AliExpress](https://www.aliexpress.us/item/3256807266003591.html)             |

**Total Cost: $12.95**

I like this remote- it's cheap and has firm clickyl buttons. 
<img width="1256" height="761" alt="roku remote aliexpress 2" src="https://github.com/user-attachments/assets/1b206e3d-dd41-48a7-b378-617f651b4be6" />
Note: (The example code will not work if your main TV is a roku TV; you'll need to decode and program with a different remote than your TV). 
