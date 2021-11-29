#include "..\include\duration.h"
#include <stdio.h>
#include <assert.h>

bool Duration::checkAndUpdateAlarm (){
 /*Function checking if the alarm has been met*/
    if (time>=alarm)
   {
    alarm=-1;//alarm has already reached -1, so it can't reach it igen
    alarmHasBeenSet= false;//the alarm turns off
    return true;
   }
  else 
   return false; 
} 
 
int Duration::getDuration()
/*Function counting the current time*/
{
    return time;
}

Duration::Duration()
/*Clock resets*/
{
    time=0;
}

Duration::Duration(int t)
/*Durtaion without counts*/
{
    assert(t>=0);
    time=t;
}

bool Duration::tick()
{
    assert(time>=0);
    time++;
    if (alarmHasBeenSet ==true)
       checkAndUpdateAlarm();
    else
        return false;
}

bool Duration::tick(int dt)
{
  assert(time>=0);
    time =time +dt;
    if (alarmHasBeenSet ==true)
       checkAndUpdateAlarm();
    else
        return false;
}

void Duration::setAlarm(int t)
{
    assert(t>time);
    alarm=t;
    alarmHasBeenSet=true;
}

bool Duration::Checkalarm ()
{
    return alarmHasBeenSet;
}
