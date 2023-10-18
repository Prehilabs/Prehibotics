#ifndef DRIVER_H
#define DRIVER_H

class Driver
{
private:
    unsigned short  motor1h, 
                    motor1l, 
                    motor2h, 
                    motor2l,
                    speed1,
                    speed2;

    void Motor1(bool hpin, unsigned int speed);
    void Motor2(bool hpin, unsigned int speed);

public:
    Driver(unsigned short hi1, unsigned short lo1, unsigned short hi2, unsigned short lo2, unsigned short PWM1, unsigned short PWM2);
    void Forward(unsigned int speed);
    void Backwards(unsigned int speed);
    void Left(unsigned int speed);
    void Right(unsigned int speed);
    void Stop();
};

#endif