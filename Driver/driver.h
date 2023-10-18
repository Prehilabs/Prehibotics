#ifndef DRIVER_H
#define DRIVER_H

class Driver
{
    private:
        unsigned char  motor1h, 
                        motor1l, 
                        motor2h, 
                        motor2l,
                        speed1,
                        speed2;

        void Motor1(bool hpin, unsigned int speed);
        void Motor2(bool hpin, unsigned int speed);

    public:
        Driver(unsigned char hi1, unsigned char lo1, unsigned char hi2, unsigned char lo2, unsigned char PWM1, unsigned char PWM2);
        void Forward(unsigned int speed);
        void Backwards(unsigned int speed);
        void Left(unsigned int speed);
        void Right(unsigned int speed);
        void Stop();
    };

#endif