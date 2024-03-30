#ifndef DRIVER_H
#define DRIVER_H

class Driver
{
    private:
        byte  motor1h, 
                        motor1l, 
                        motor2h, 
                        motor2l,
                        speed1,
                        speed2;

        void Motor1(bool hpin, byte speed);
        void Motor2(bool hpin, byte speed);

    public:
        Driver(byte hi1, byte lo1, byte hi2, byte lo2, byte PWM1, byte PWM2);
        void Forward(byte speed);
        void Backwards(byte speed);
        void Left(byte speed);
        void Right(byte speed);
        void Stop();
    };

#endif