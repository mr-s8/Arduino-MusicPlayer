#include <pitches.h>
#include <IRremote.hpp> // v4
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "Songs.h" // import the notes/songs

const int buzzerPin1 = 6;
const int buzzerPin2 = 5;

const int RECEIVER = 9;

LiquidCrystal_I2C lcd(0x27, 20, 4);

// Hex code for ir signals
const uint32_t POWER_BUTTON = 0xBA45FF00;
const uint32_t PREV_BUTTON = 0xBB44FF00;
const uint32_t NEXT_BUTTON = 0xBC43FF00;
const uint32_t PAUSE_BUTTON = 0xBF40FF00;
const uint32_t STOP = 0xB847FF00;

// variables to store state of the display
int selectedSong = 0;
int selectedMenu = 0;
bool play = false;

void setup()
{
  pinMode(buzzerPin1, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);

  IrReceiver.begin(RECEIVER, ENABLE_LED_FEEDBACK);

  lcd.begin();

  Serial.begin(9600);

  displayChanges(); // initialize display
}

void loop()
{

  if (IrReceiver.decode())
  { // check for ir signals

    Serial.println("received ir");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data

    IrReceiver.resume();                                   // make ir receiver ready again
    handleIRCode(IrReceiver.decodedIRData.decodedRawData); // this function changes the state variables

    displayChanges(); // this function updates the state of the display with the updated state variables
  }
}

// Functions:

void handleIRCode(uint32_t code)
{

  Serial.println("handle ir code");

  if (selectedMenu == 0)
  { // in the start menu, listen for the play button to got to the song menu

    Serial.println("handle ir code: sM = 0");

    switch (code)
    {
    case PAUSE_BUTTON:
      selectedMenu = 1;
      break;
    default:
      break;
    }
  }
  else if (selectedMenu == 1)
  { // in the song menu listen for the play button to play a song

    Serial.println("handle ir code: sM = 1");

    switch (code)
    {
    case STOP: // go back to start menu
      selectedSong = 0;
      selectedMenu = 0;
      break;
    case NEXT_BUTTON: // next song
      selectedSong = (selectedSong + 1) % totalSongs;
      break;
    case PREV_BUTTON: // prev song
      selectedSong = (selectedSong - 1 + totalSongs) % totalSongs;
      break;
    case PAUSE_BUTTON: // play the selected song
      play = !play;    // should be set from false to true always
      break;
    default:
      break;
    }
  }
  else
  {

    return;
  }
  return;
}

void displayChanges()
{

  Serial.println("display changes");

  if (selectedMenu == 0)
  {

    Serial.println("display changes: sM = 0");

    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("Press Play");
    lcd.setCursor(6, 2);
    lcd.print("To Start");
  }
  else if (selectedMenu == 1)
  {

    Serial.println("display changes: sM = 1");

    int startPos = (20 - strlen(songs[selectedSong].name)) / 2;
    lcd.clear();
    lcd.setCursor(startPos, 1);
    lcd.print(songs[selectedSong].name);
    lcd.setCursor(0, 3);
    lcd.print("<");
    lcd.setCursor(19, 3);
    lcd.print(">");

    if (play)
    {

      Serial.println("display changes: play");
      playSong(selectedSong);
    }
  }
  else
  { // should never be the case at this point

    return;
  }
}

void playSong(int currentSong)
{
  Serial.println("playing");

  TIMSK1 = 0; // turn timer for ir interrupts off initially; i do this because the interrupts disturb the frequency of the notes

  delay(200);

  for (int i = 0; i < songs[currentSong].totalNotes; i++)
  {

    // before every note check for 6.7 milliseconds if any button is pressed, if so stop playing
    // 6.7 ms is a value at which the pause is not yet noticeable
    TIMSK1 = 1;
    IrReceiver.begin(RECEIVER, ENABLE_LED_FEEDBACK);
    unsigned long startMicros = micros();
    while (micros() - startMicros < 6700)
    {
      if (IrReceiver.decode())
      {
        Serial.println("received ir while playing");
        play = false;
        IrReceiver.resume();
        return;
      }
    }
    TIMSK1 = 0;

    // play the current note on the buzzers
    const int currentNoteLeft = songs[currentSong].notesLeft[i];
    const int currentNoteRight = songs[currentSong].notesRight[i];
    float wait = songs[currentSong].durations[i] / songs[currentSong].speed;

    if (currentNoteLeft != 0 && currentNoteRight != 0) // if no pause on both sides
    {
      play2Notes(buzzerPin1, buzzerPin2, currentNoteLeft, currentNoteRight, wait);
    }
    else // there is a pause
    {
      if (currentNoteLeft == 0)
      {
        if (currentNoteRight == 0)
        { // both sides pause
          noNote(buzzerPin1, wait);
        }
        else
        { // only right side playing
          playNote(buzzerPin2, currentNoteRight, wait);
        }
      }
      else
      { // only left side playing
        playNote(buzzerPin1, currentNoteLeft, wait);
      }
    }
  }

  // Song has played till end
  play = false;
  IrReceiver.begin(RECEIVER, ENABLE_LED_FEEDBACK);
}

void play2Notes(int pin1, int pin2, int noteFrequency1, int noteFrequency2, int duration)
{

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);

  // calculate frequencies
  int period1 = 1000000 / noteFrequency1;
  int period2 = 1000000 / noteFrequency2;

  // remember starttime
  unsigned long startTime = millis();

  unsigned long start1 = micros();
  unsigned long start2 = micros();
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);

  // check when to turn buzzers on and off for the duration of the note
  while (millis() - startTime < duration)
  {

    if (micros() - start1 >= period1)
    {
      digitalWrite(pin1, LOW);
      start1 = micros();
    }
    else if (micros() - start1 >= period1 / 2)
    {
      digitalWrite(pin1, HIGH);
    }

    if (micros() - start2 >= period2)
    {
      digitalWrite(pin2, LOW);
      start2 = micros();
    }
    else if (micros() - start2 >= period2 / 2)
    {
      digitalWrite(pin2, HIGH);
    }
  }

  // after the note is over, turn both buzzers off
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void playNote(int pin, int noteFrequency, int duration)
{

  pinMode(pin, OUTPUT);

  int period = 1000000 / noteFrequency;

  unsigned long startTime = millis();

  while (millis() - startTime < duration)
  {

    digitalWrite(pin, HIGH);
    delayMicroseconds(period / 2);

    digitalWrite(pin, LOW);
    delayMicroseconds(period / 2);
  }

  digitalWrite(pin, LOW);
}

void noNote(int pin, int duration)
{

  pinMode(pin, OUTPUT);

  unsigned long startTime = millis();

  while (millis() - startTime < duration)
  {

    digitalWrite(pin, LOW);
  }
}

/* TODO:
- make compatible with every lcd display  (16x2 and 20x4)
- only play the hook of each songs for x durations to save memory on arduino
*/
