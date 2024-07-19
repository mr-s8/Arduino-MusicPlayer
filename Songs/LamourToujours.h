#ifndef LAMOURTOUJOURS_H
#define LAMOURTOUJOURS_H

#include <pitches.h>

const float songSpeed_LamourToujours = 0.7;

int notesLeft_LamourToujours[] = {

    0,
    NOTE_FS5, 0, NOTE_FS5, NOTE_D6,
    NOTE_CS6, 0, NOTE_CS6, 0,
    NOTE_CS6, NOTE_D6, NOTE_B5, 0,
    NOTE_B5, 0, NOTE_B5, NOTE_A5,
    NOTE_B5, 0, NOTE_B5, NOTE_B5,
    NOTE_A5, NOTE_B5, NOTE_A5, NOTE_FS5,

    0

    /*
        ,NOTE_FS5, 0, NOTE_FS5, NOTE_D6,            // saving memory on arduino
        NOTE_CS6, 0, NOTE_CS6, 0,
        NOTE_CS6, NOTE_D6, NOTE_B5, 0,
        NOTE_B5, 0, NOTE_B5, NOTE_A5,
        NOTE_B5, 0, NOTE_B5, NOTE_B5,
        NOTE_A5, NOTE_B5, NOTE_A5, NOTE_FS5};
    */
};

int notesRight_LamourToujours[] = {

    0, // one side sounds better as of now
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0
    /*
    NOTE_D2,
    NOTE_D2, NOTE_D2, NOTE_D2, NOTE_D2,
    NOTE_FS2, NOTE_FS2, NOTE_FS2, NOTE_FS2,
    NOTE_FS2, NOTE_FS2, NOTE_B2, NOTE_B2,
    NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2,
    NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2,
    NOTE_G2, NOTE_G2, NOTE_G2, NOTE_D2,

    NOTE_D2
    */

    /*
    ,NOTE_D2, NOTE_D2, NOTE_D2, NOTE_D2,
    NOTE_FS2, NOTE_FS2, NOTE_FS2, NOTE_FS2,
    NOTE_FS2, NOTE_FS2, NOTE_B2, NOTE_B2,
    NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2,
    NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2,
    NOTE_G2, NOTE_G2, NOTE_G2, NOTE_D2
    */

};

int durations_LamourToujours[] = {

    250,
    250, 50, 125, 125,
    250, 250, 250, 50,
    125, 125, 250, 250,
    250, 50, 125, 125,
    250, 50, 250, 125,
    125, 125, 125, 500,

    50

    /*
        ,250, 50, 125, 125,
        250, 250, 250, 50,
        125, 125, 250, 250,
        250, 50, 125, 125,
        250, 50, 250, 125,
        125, 125, 125, 500
    */
};

const int totalNotes_LamourToujours = sizeof(notesLeft_LamourToujours) / sizeof(notesLeft_LamourToujours[0]);

#endif // LAMOURTOUJOURS_H
