# miscare
<h3>Movement. Detect motion using a PIR sensor</h3>

## Requirements
### Hardware:
- Standard pyroelectric sensor
- Infrared LED receiver
- Standard LED
- Piezo speaker
- Arduino board (I've used an Arduino Nano)
- (optional) Breadboard (I've used an 830 point one)
- (optional) [LM386 Audio Amplifier](https://www.optimusdigital.ro/en/audio-amplifiers/45-lm385-audio-amplifier.html) if you want to put a louder speaker, I have the wiring configuration in my [speaker-sd](https://github.com/sabinM1/speaker-sd) repo.
### Software:
- Ardiuno IDE
- [IRremote library](https://github.com/z3t0/Arduino-IRremote)
## IMPORTANT!
<b>It is very likely that you need to modify the IRremote library so it can work with <i>tone()</i>. <br> If you get something like ```core.a(Tone.cpp.o): In function `__vector_7'``` when you compile it you will most certainly have to modify it. <br> I've followed the steps listed [here](https://forum.arduino.cc/index.php?topic=120955.msg2613823#msg2613823). To summarize, you will have to do the following steps:</b> <br>
1. Go to your Arduino folder (usually in <i>Documents</i> on Windows)
2. Open the <i>libraries</i> folder
3. Open the <i>IRremote</i> folder (try to reinstall the library if you don't have it)
4. Edit the <i>IRremoteInt.h</i> file with an editor
5. On the line 150 (may vary if the library is another version) you will see ```// Define which timer to use```.
6. You will need to find a line below that has your Arduino type, mine is Nano so I used this one: <br> ```// Arduino Duemilanove, Diecimila, LilyPad, Mini, Fio, Nano, etc ``` <br> ```#else``` <br> ```//#define IR_USE_TIMER1 // tx = pin 9``` <br> ```#define IR_USE_TIMER2     // tx = pin 3```.
7. Comment the line that defines the current timer and uncomment the line you want to use for the new timer. In my case it will be like this: <br> ```#define IR_USE_TIMER1 // tx = pin 9``` <br> ```//#define IR_USE_TIMER2     // tx = pin 3```.
8. Save and restart the Arduino IDE if you still had it open. If you have any problems regarding this topic or other parts of the program please [contact me on Reddit](https://www.reddit.com/user/sabin_M1).
### Pin configuration
In the Arduino program the lines from 3 to 26 are for defining pins, notes and custom arrays.
- LED pin: The LED pin... ₙₒ ₛₕᵢₜ
- IR receive pin: The IR receiver pin
- Speaker pin: The speaker power pin
- Notes used: The notes you will be using for when the motion sensor it activated and detects motion. <sup>[1](#footnote1)</sup>

## Images
[Photo album on Imgur](https://imgur.com/a/BTvhxpK) <br>
[Kinda bad 3D model, open it with Windows 10's 3D viewer if you want an easy solution](https://www.mediafire.com/file/m8dd7rutcftjrwh/Arduino3D.rar/file)


## Note table:
<a name="footnote1">1</a>: Here is a table if you want to use standard notes:

| Define  | Note     | Value |
|---------|----------|-------|
| #define | NOTE_B0  | 31    |
| #define | NOTE_C1  | 33    |
| #define | NOTE_CS1 | 35    |
| #define | NOTE_D1  | 37    |
| #define | NOTE_DS1 | 39    |
| #define | NOTE_E1  | 41    |
| #define | NOTE_F1  | 44    |
| #define | NOTE_FS1 | 46    |
| #define | NOTE_G1  | 49    |
| #define | NOTE_GS1 | 52    |
| #define | NOTE_A1  | 55    |
| #define | NOTE_AS1 | 58    |
| #define | NOTE_B1  | 62    |
| #define | NOTE_C2  | 65    |
| #define | NOTE_CS2 | 69    |
| #define | NOTE_D2  | 73    |
| #define | NOTE_DS2 | 78    |
| #define | NOTE_E2  | 82    |
| #define | NOTE_F2  | 87    |
| #define | NOTE_FS2 | 93    |
| #define | NOTE_G2  | 98    |
| #define | NOTE_GS2 | 104   |
| #define | NOTE_A2  | 110   |
| #define | NOTE_AS2 | 117   |
| #define | NOTE_B2  | 123   |
| #define | NOTE_C3  | 131   |
| #define | NOTE_CS3 | 139   |
| #define | NOTE_D3  | 147   |
| #define | NOTE_DS3 | 156   |
| #define | NOTE_E3  | 165   |
| #define | NOTE_F3  | 175   |
| #define | NOTE_FS3 | 185   |
| #define | NOTE_G3  | 196   |
| #define | NOTE_GS3 | 208   |
| #define | NOTE_A3  | 220   |
| #define | NOTE_AS3 | 233   |
| #define | NOTE_B3  | 247   |
| #define | NOTE_C4  | 262   |
| #define | NOTE_CS4 | 277   |
| #define | NOTE_D4  | 294   |
| #define | NOTE_DS4 | 311   |
| #define | NOTE_E4  | 330   |
| #define | NOTE_F4  | 349   |
| #define | NOTE_FS4 | 370   |
| #define | NOTE_G4  | 392   |
| #define | NOTE_GS4 | 415   |
| #define | NOTE_A4  | 440   |
| #define | NOTE_AS4 | 466   |
| #define | NOTE_B4  | 494   |
| #define | NOTE_C5  | 523   |
| #define | NOTE_CS5 | 554   |
| #define | NOTE_D5  | 587   |
| #define | NOTE_DS5 | 622   |
| #define | NOTE_E5  | 659   |
| #define | NOTE_F5  | 698   |
| #define | NOTE_FS5 | 740   |
| #define | NOTE_G5  | 784   |
| #define | NOTE_GS5 | 831   |
| #define | NOTE_A5  | 880   |
| #define | NOTE_AS5 | 932   |
| #define | NOTE_B5  | 988   |
| #define | NOTE_C6  | 1047  |
| #define | NOTE_CS6 | 1109  |
| #define | NOTE_D6  | 1175  |
| #define | NOTE_DS6 | 1245  |
| #define | NOTE_E6  | 1319  |
| #define | NOTE_F6  | 1397  |
| #define | NOTE_FS6 | 1480  |
| #define | NOTE_G6  | 1568  |
| #define | NOTE_GS6 | 1661  |
| #define | NOTE_A6  | 1760  |
| #define | NOTE_AS6 | 1865  |
| #define | NOTE_B6  | 1976  |
| #define | NOTE_C7  | 2093  |
| #define | NOTE_CS7 | 2217  |
| #define | NOTE_D7  | 2349  |
| #define | NOTE_DS7 | 2489  |
| #define | NOTE_E7  | 2637  |
| #define | NOTE_F7  | 2794  |
| #define | NOTE_FS7 | 2960  |
| #define | NOTE_G7  | 3136  |
| #define | NOTE_GS7 | 3322  |
| #define | NOTE_A7  | 3520  |
| #define | NOTE_AS7 | 3729  |
| #define | NOTE_B7  | 3951  |
| #define | NOTE_C8  | 4186  |
| #define | NOTE_CS8 | 4435  |
| #define | NOTE_D8  | 4699  |
| #define | NOTE_DS8 | 4978  |
