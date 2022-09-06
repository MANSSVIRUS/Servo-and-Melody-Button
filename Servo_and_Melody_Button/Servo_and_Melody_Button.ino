#include <Servo.h>

Servo myServo;
const int buttonPin = 7;  
int buttonState = 0; 
const int buzzerPin = 2;   

int melody[] = {
 233,233,277,311,277,311,349,311,277,233
 
  
};

int noteDurations[] = {
  8,8,8,3,8,8,8,8,8,2
};
int beatsPerMinute = 45;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  // put your main code here, to run repeatedly:
  if (buttonState == HIGH) {
  myServo.write(180);
  delay(1000);
  myServo.write(0);
  delay(1000);
   playSong();
   } else {
}
}
void playSong(){
  // iterate over the notes of the melody:
  int len = sizeof(melody)/sizeof(melody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(1000);
}
