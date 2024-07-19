#ifndef SONGS_H
#define SONGS_H

#include "songs/ThroughTheWire.h"
#include "songs/LamourToujours.h"

struct Song
{
    const char *name;
    float speed;
    int *notesLeft;
    int *notesRight;
    int *durations;
    int totalNotes;
};

Song songs[] = {
    {"Through The Wire", songSpeed_ThroughTheWire, notesLeft_ThroughTheWire, notesRight_ThroughTheWire, durations_ThroughTheWire, totalNotes_ThroughTheWire},
    {"Lamour Toujours", songSpeed_LamourToujours, notesLeft_LamourToujours, notesRight_LamourToujours, durations_LamourToujours, totalNotes_LamourToujours}

};

const int totalSongs = sizeof(songs) / sizeof(Song);

#endif
