#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class Ultrasonic
{
    private:
        unsigned short trigger, echo;
        double speed = 34300;
        unsigned int timeout = 20000;
        void StartTrigger();
    public:
        Ultrasonic(unsigned short t_pin, unsigned short e_pin);
        long Measure();
        long GetRawTime();
        void SetTimeout(long time);
        void SetSpeed(double _speed);
        bool InRange(unsigned short begin, unsigned short end);
};

#endif