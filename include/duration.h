#ifndef _DURATION_CLASS_H_
#define _DURATION_CLASS_H_
#include <assert.h>
#include <stdio.h>

class Duration
{
private:
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool checkAndUpdateAlarm ();

public:
 //constructors
    Duration();
    Duration(int t);

 //methods
    int getDuration();
    bool tick();
    bool tick (int dt);
    void setAlarm(int t);
    bool Checkalarm ();

};
#endif