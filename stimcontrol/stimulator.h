ifndef STIMULATOR_H
#define STIMULATOR_H
//#include "wiringPi.h"
#include <QThread>

class stimulator// : public QThread
{
public:
    stimulator();
    void quit();
    void run();
    void stop();

private:
    int channels[8]={3,4,5,6,10,12,13,14};
    int pulsewidth;
    int pulsewidthoff;
    int interval_pulsetrain;
    int stim_duration;
};

#endif // STIMULATOR_H
