#include "buzzer.h"
#include "Arduino.h"
#include "config.h"
#include "pitches.h"
Buzzer::Buzzer(int pin) {
  this->buzzerPin = pin;
  pinMode(buzzerPin, OUTPUT);
}

void Buzzer::playTone(int frequency, int duration) {
  if(duration ==2){
      int gotMelody[] = {
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_C4,

};

// Durate delle note
int gotNoteDurations[] = {
  2, 2, 2, 2, 4, 8, 8,
  2, 2, 2, 2, 4, 8, 8,

};

       for (int thisNote = 0; thisNote < sizeof(gotMelody) / sizeof(int); thisNote++) {
    // Calcola la durata della nota
    int noteDuration = 1000 / gotNoteDurations[thisNote];
    tone(buzzerPin, gotMelody[thisNote], noteDuration);

    // Pausa tra le note
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Ferma la riproduzione della nota
    noTone(buzzerPin);
  }

    }else if(duration==1){
            int tetrisMelody[] = {
        NOTE_E4, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_A3,
      };

      // Durate delle note
      int tetrisNoteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4,

      };
      for (int thisNote = 0; thisNote < sizeof(tetrisMelody) / sizeof(int); thisNote++) {
    // Calcola la durata della nota
    int noteDuration = 1000 / tetrisNoteDurations[thisNote];
    tone(buzzerPin, tetrisMelody[thisNote], noteDuration);

    // Pausa tra le note
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Ferma la riproduzione della nota
    noTone(buzzerPin);
    }
  }else if(duration==3){
    int cantinaMelody[] = {
      NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4,

    };

    // Durate delle note
    int cantinaNoteDurations[] = {
      8, 8, 8, 8, 8, 2, 4,


    };
    for (int thisNote = 0; thisNote < sizeof(cantinaMelody) / sizeof(int); thisNote++) {
    // Calcola la durata della nota
    int noteDuration = 1000 / cantinaNoteDurations[thisNote];
    tone(buzzerPin, cantinaMelody[thisNote], noteDuration);

    // Pausa tra le note
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Ferma la riproduzione della nota
    noTone(buzzerPin);
  }
  }else{
    //Serial.print("NO SONG");
  }

    
}

void Buzzer::switchOff() {
  noTone(buzzerPin);
}
