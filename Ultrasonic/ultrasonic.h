#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic
{
    private:
        unsigned short trigger, echo;
        void StartTrigger();
    public:
        const unsigned int SOUNDSPEED = 34300;
        Ultrasonic(unsigned short t_pin, unsigned short e_pin);
        long Measure();
        long GetRawTime();
        bool InRange(unsigned short begin, unsigned short end);
};

#endif