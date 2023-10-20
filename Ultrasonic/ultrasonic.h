#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic
{
    private:
        unsigned short trigger, echo;
        void StartTrigger();
    public:
        const unsigned int CMSPEED = 34300;
        const unsigned long INSPEED = 13511.8110236;
        Ultrasonic(unsigned short t_pin, unsigned short e_pin);
        long Measure(bool cm);
        long GetRawTime();
        bool InRange(unsigned short begin, unsigned short end);
};

#endif