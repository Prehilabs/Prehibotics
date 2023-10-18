#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "arduino.h"

class Ultrasonic
{
    private:
        unsigned short trigger, echo;
        void StartTrigger();
    public:
        Ultrasonic(unsigned short t_pin, unsigned short e_pin);
        long Measure();
};

#endif