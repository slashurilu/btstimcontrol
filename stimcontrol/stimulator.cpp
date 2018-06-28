#include "stimulator.h"
//#include "wiringPi.h"

stimulator::stimulator()
{
    /*
    wiringPiSetup () ;
    for(int i=0; i<8; i++)
        pinMode (channels[i], OUTPUT);
        */

}
/*
void stimulator::Send_Parameters(int n, int PulseWidth, int PulseWidthOff, int PulseTrain, Parameter[10])
{
    n_pulses = n; pulsewidth = PulseWidth;
    pulsewidthoff = PulseWidthOff;
    interval_pulsetrain = PulseTrain;
    stim_duration = (int)1000*Parameter[8];
    int zero = 0;     //init count -> Count of non-zero elements
    for (int i = 0; i<8; i++)
    {
        if (g_Stim_Channels[i]!=0){
            Parameter[zero]= Parameter[i];
            nc++;

    int i;
    for (int i=0; i<n_pulses; i++){
        for(){
            if(!=0)
            digitalWrite (channels[1], HIGH);
            else
                break;
        }
        delayMicroseconds (pulsewidth);
        for(){
            if(!=0)
            digitalWrite (channels[1], LOW);
            else
                break;
        }
        delayMicroseconds (pulsewidthoff);
    }
    delay(interval_pulsetrain)
    for (i=0;i<n_pulses;i++){
        for()
            digitalWrite (channels[1], HIGH);
        delayMicroseconds (pulsewidth);
        for()
            digitalWrite (channels[1], LOW);
        delayMicroseconds (pulsewidthoff);
    }
}
*/
