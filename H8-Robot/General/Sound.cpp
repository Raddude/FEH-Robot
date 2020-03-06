/*  Sound.cpp
 *  Author: Jake Marchewitz
 *  Creation Date: 2/10/20
 *
 *  Purpose: This file is basically a meme where I make the proteus sing the ice cream truck song.
 *
 *  Superclasses: None.
 *  Subclasses: None.
 *  Used in: main.cpp.
 */

#include <cmath>
#include <FEHBuzzer.h>
#include "Sound.h"
#include "Time.h"

#define TEMPO 120
#define BEAT_LENGTH TEMPO/60
#define MEASURES 10.0
#define SONG_LENGTH BEAT_LENGTH * 4.0 * MEASURES
#define PAUSE_LENGTH 0.25

Sound sound;







Sound::Sound()
{

}







/*  This method plays the ice cream truck jingle for me
 */
void Sound::iceCreamJingle()
{
    //Do
    if (fmod(time.getCurrentTime(), SONG_LENGTH) <= 1.0*BEAT_LENGTH)
    {
        Buzzer.Tone(FEHBuzzer::E5);
    }

    //your
    else if (fmod(time.getCurrentTime(), SONG_LENGTH) <= 1.5*BEAT_LENGTH)
    {
        Buzzer.Tone(FEHBuzzer::D5);
    }

    //ears
    else if (fmod(time.getCurrentTime(), SONG_LENGTH) <= 2*BEAT_LENGTH)
    {
        Buzzer.Tone(FEHBuzzer::C5);
    }
}
