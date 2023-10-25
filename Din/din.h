#ifndef DIN_H
#define DIN_H

class Din
{
    private:
        unsigned char pin;
    public:
        Din(unsigned char _pin);
        bool GetInput();
        void WaitUntilChange();
        void WaitUntilChange(bool state);
};

#endif