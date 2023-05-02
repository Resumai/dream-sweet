const int BUZZER_PIN = 8;
const int BUTTON_PIN = 2;

int buttonState = 0;

// Song speed
int bmp = 125;

// Note sizes
int whole = 60000 / bmp;
int half = 60000 / bmp / 2;
int quarter = 60000 / bmp / 4;

// Notes and their frequencies
int note_C2 = 65;
int note_G2 = 98;
int note_Ab2 = 103; 
int note_Eb3 = 155;
int note_C3 = 130;
int note_G3 = 196;
int note_Ab3 = 206;
int note_Bb3 = 233;
int note_C4 = 261;
int note_D4 = 293;
int note_Eb4 = 310;
int note_F4 = 349;

// Intro note list - can use array, because all notes of same length in intro
int intro[] = {note_C2,  note_C2, 
              note_C4,  note_C4,
              note_Eb3, note_Eb4,
              note_C3,  note_C4,
              note_Ab2, note_Ab2,
              note_Ab3, note_C4,
              note_G2,  note_G3,
              note_Bb3, note_C4};

// Calculate how many elements in array
int size = sizeof(intro) / sizeof(intro[0]);

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  if(buttonState == 1){
    // Play intro, 32 measures
    for(int i = 0; i <= 4 - 1; i++){
        slap_intro();
        }
    // Play rest, 32 measures
    slap_tune();
  }
  delay(1000);
}

void buzz(int note, int note_length){
    tone(BUZZER_PIN, note);
    delay(note_length);
    noTone(BUZZER_PIN); 
}

void slap_intro(){
  for(int i = 0; i < size; i++){
    buzz(intro[i], half);
  }
}

void slap_tune(){
  // 8 measures
  buzz(note_C2, whole);
  buzz(note_Eb4, whole);
  buzz(note_Eb4, whole);
  buzz(note_C4, half);
  buzz(note_Eb4, whole);
  buzz(note_Eb4, whole);
  buzz(note_Eb4, whole);
  buzz(note_D4, whole);
  buzz(note_G2, half);

  // 8 measures
  buzz(note_Eb4, half);
  buzz(note_Eb4, half);
  buzz(note_C4, half);
  buzz(note_Eb4, whole+half);
  buzz(note_C4, whole);
  buzz(note_Eb4, half);
  buzz(note_F4, whole+half);
  buzz(note_Eb4, half);
  buzz(note_D4, half);
  buzz(note_G2, half);
  buzz(note_C4, half);

  // 8 measures
  buzz(note_Eb4, half);
  buzz(note_Eb4, half);
  buzz(note_C4, half);
  buzz(note_Eb4, whole+half);
  buzz(note_Eb4, half);
  buzz(note_C4, half);
  buzz(note_Eb4, half);
  buzz(note_Eb4, whole);
  buzz(note_Eb4, half);
  buzz(note_D4, whole);
  buzz(note_G2, whole);

  // 8 measures
  buzz(note_Eb4, whole);
  buzz(note_C4, half);
  buzz(note_Eb4, whole);
  buzz(note_C4, whole+half);
  buzz(note_Eb4, half);
  buzz(note_Eb4, half);
  buzz(note_F4, half);
  buzz(note_Eb4, whole);
  buzz(note_D4, whole);
  buzz(note_G2, half);
}

// Applause