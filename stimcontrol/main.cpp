#include "stimcontrol.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QThread>
#include <pigpio.h>

void  displayChange(int gpio, int level, uint32_t tick)
{
   QThread::msleep(10);
   int powervalue;
   if(level == 1){
       //QThread::msleep(100);
       QFile file("/sys/class/backlight/rpi_backlight/bl_power");
       // Trying to open in ReadOnly and Text mode
       if(!file.open(QFile::ReadOnly | QFile::Text))
       {
           return;
       }
       QTextStream in(&file);
       QString line = in.readAll();
       file.flush();
       file.close();
       powervalue = line.toInt();
       if(powervalue){
        system("sudo sh -c \"echo 0 > /sys/class/backlight/rpi_backlight/bl_power\"");
       } else {
        system("sudo sh -c \"echo 1 > /sys/class/backlight/rpi_backlight/bl_power\"");
       }
   }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    stimcontrol w;
    w.show();
    if (gpioInitialise() >= 0){
        gpioSetAlertFunc(27, displayChange);
    }
    return a.exec();
}
