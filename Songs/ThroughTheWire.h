#ifndef THROUGHTHEWIRE_H
#define THROUGHTHEWIRE_H

#include <pitches.h>

const float songSpeed_ThroughTheWire = 0.7;

int notesLeft_ThroughTheWire[] = {
    NOTE_E3, NOTE_F3, NOTE_F3, NOTE_E3,
    NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3,
    NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3,
    0, 0, 0, NOTE_E3,
    NOTE_E3, NOTE_E3, 0, NOTE_F3,
    NOTE_F3, NOTE_F3, NOTE_F3, 0,
    NOTE_G3, NOTE_G3, NOTE_G3, 0,
    NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
    NOTE_E3, NOTE_E3, NOTE_E3, 0,
    NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
    NOTE_E3, 0, NOTE_F3, NOTE_F3,
    NOTE_F3, NOTE_F3, 0, NOTE_A3,
    NOTE_A3, NOTE_A3, NOTE_A3, 0, ////  22:07
    NOTE_E3, NOTE_E3, NOTE_E3, 0,
    NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
    0, NOTE_F3, NOTE_F3, NOTE_F3,
    NOTE_F3, 0, NOTE_G3, NOTE_G3

    /*                                         // saving memory on arduino
    ,   /// 28:17
    NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
    0, NOTE_E3, NOTE_E3, NOTE_E3,
    0, NOTE_F3, NOTE_F3, NOTE_F3,
    0, NOTE_A3, NOTE_E3, NOTE_E3,
    NOTE_E3, NOTE_E3, 0, NOTE_F3,
    NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
    NOTE_F3, NOTE_F3, 0, 0,
    NOTE_G3, NOTE_G3        // 42:23
    */
};

int notesRight_ThroughTheWire[] = {
    NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4,
    NOTE_C5, NOTE_G5, NOTE_A5, NOTE_G5,
    NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5,
    NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4,
    NOTE_F5, 0, NOTE_F5, 0,
    NOTE_F5, 0, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, 0, NOTE_E5,
    NOTE_C5, NOTE_D5, NOTE_E5, 0,
    NOTE_E5, NOTE_G5, NOTE_E5, NOTE_F5,
    NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, ///   22:07
    NOTE_E5, NOTE_A4, NOTE_B4, NOTE_C5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_B4,
    NOTE_C5, NOTE_C5, NOTE_E5, NOTE_D5,
    NOTE_A5, NOTE_G5, NOTE_G5, 0
    /*
    ,   /// 28:17
    NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5,
    NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5,
    NOTE_G5, NOTE_A5, NOTE_G5, NOTE_C6,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5,
    NOTE_C5, NOTE_B4, NOTE_C5, NOTE_C5,
    NOTE_B4, NOTE_A4, 0, NOTE_E5,
    NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5,
    NOTE_C5, 0          // 42:23
    */
};

int durations_ThroughTheWire[] = {
    500, 500, 500, 500,
    1500, 125, 125, 125,
    125, 125, 125, 250,
    125, 125, 100, 200,
    250, 125, 125, 125,
    250, 250, 250, 100,
    200, 125, 200, 50,
    200, 25, 125, 25,
    250, 25, 125, 100,
    100, 200, 25, 300,
    125, 125, 200, 25,
    125, 300, 125, 250,
    125, 300, 125, 125, ////   22:07
    300, 125, 125, 100,
    150, 250, 125, 125,
    125, 125, 250, 250,
    250, 100, 600, 200
    /*
    ,  /// 28:17
    250, 125, 350, 125,
    125, 125, 250, 350,
    125, 250, 125, 350,
    125,  500, 250, 250,
    250, 125, 125, 125,
    125, 400, 125, 250,
    250, 250, 125, 125,
    400, 400              // 42:23
    */
};

const int totalNotes_ThroughTheWire = sizeof(notesLeft_ThroughTheWire) / sizeof(notesLeft_ThroughTheWire[0]);

#endif // THROUGHTHEWIRE_H
