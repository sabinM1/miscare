#include <IRremote.h>

//Led pin
#define LED_PIN 2

//IR receive pin
#define RECV_PIN 4

//Speaker pin
#define SPK_PIN 6
//notes used (see readme if you want to add more)
#define NOTE_A6  1760
#define NOTE_C8  4186
//number of notes that you will play
int MAX_NOTE = 4;
// notes in the melody:
int melody[] = {
  NOTE_A6, NOTE_C8, NOTE_A6, NOTE_C8
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4
};

//Motion sensor pin
#define MISC_PIN 8

IRrecv irrecv(RECV_PIN);
decode_results results;

bool activ = 0;

void speaker()
{
  for (int thisNote = 0; thisNote < MAX_NOTE; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SPK_PIN, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SPK_PIN);
  }
}

void setup() {
  Serial.begin(9600); //9600 baud
   pinMode(LED_PIN, OUTPUT);
   pinMode(MISC_PIN, INPUT);
   irrecv.enableIRIn();
   digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if (results.value == 0xFF9867)  { //detect if the activate code is received, if it is set the value of "activ" to 1
      Serial.println("activated");
      digitalWrite(LED_PIN, HIGH);
      activ = 1;
    } else if (results.value == 0xFFD827) { //detect if the deactivate code is received, if it is set the value of "activ" to 0
      Serial.println("deactivated");
      digitalWrite(LED_PIN, LOW);
      activ = 0;
    }
    irrecv.resume(); // Receive the next value
  }
  
  if (activ)
   if (digitalRead(MISC_PIN))
   {
    speaker();
    Serial.println("a fost activat!");
   }
  
  delay(10); //kinda insignificant
  noTone(SPK_PIN);
  delay(10);
}
