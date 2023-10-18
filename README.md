# Prehibotics
Prehibotics is a framework for Arduino UNO. Its main purpose is to simplify the  actions required to provide common algorithms to control a variety of simple robots  throughout different tools that permit getting information from sensors in an easier way, as  well as creating output facilities to ease the driving actions

## Instalation 
missing image

## Libraries
The framework includes the following libraries. However, Prehibotics is still under developement. Thus further libraries will be added in a near future.
* Driver
    *A library to control two motors simultaneously using an H-bridge module or a L293D integrated circuit.
* Ultrasonic
    * Allows to measure distances using the HC-SR04 ultrasonic module

## Usage
### Driver
The library “driver.h”, allows programmers to control two motors simultaneously using an H-bridge. Therefore, it consists of five methods and a constructor defined in the upcoming paragraphs.
#### Constructor
```cpp
Driver(unsigned short hi1, unsigned short lo1, unsigned short hi2, unsigned short lo2, unsigned short PWM1, unsigned short PWM2);
//hi1: H-Bridge input 1 pin
//lo1: H-Bridge input 2 pin
//hi2: H-Bridge input 3 pin
//lo2: H-Bridge input 4 pin
//PWM1: H-Bridge enable 1&2 pin
//PWM2: H-Bridge enable 3&4 pin
```

### Methods
```cpp
/*
 *Turns to HIGH pins 1 and 3 of the H-Bridge
 *Turns to LOW pins 2 and 4 of the H-Bridge
 *The speed parameter sets the analog output for pins enable 1&2 and enable 3&4
*/
Driver.Forward(unsigned int speed);

/*
 *Turns to HIGH pins 2 and 4 of the H-Bridge
 *Turns to LOW pins 1 and 3 of the H-Bridge
 *Writes an analog output between 0 and 255 in pins enable 1&2 and enable 3&4
*/
Driver.Backwards(unsigned int speed);

/*
 *Turns to HIGH pins 1 and 4 of the H-Bridge
 *Turns to LOW pins 2 and 3 of the H-Bridge
 *The speed parameter sets the analog output for pins enable 1&2 and enable 3&4
*/
Driver.Right(unsigned int speed);

/*
 *Turns to HIGH pins 2 and 3 of the H-Bridge
 *Turns to LOW pins 1 and 4 of the H-Bridge
 *The speed parameter sets the analog output for pins enable 1&2 and enable 3&4
*/
Driver.Left(unsigned int speed);

/*
 *Turns to LOW pins 1-4 of the H-Bridge
 *Writes an analog output of 0 in pins enable 1&2 and enable 3&4
*/
Driver.Stop();
```

### Usage
```cpp
    #include <driver.h>

    //Create the driver object
    Driver car(2,3,4,7,5,6);

    void setup()
    {

    }

    void loop()
    {
        //Moves the robot forward at a speed of 100/255
        car.Forward(100);
        delay(2000);
        //Moves the robot backwards at a speed of 255/255
        car.Backwards(255);
        delay(2000);
        //Rotates motor1 clockwise and motor2 counterclockwise at a speed of 50/255
        car.Right(50);
        delay(2000);
        //Rotates motor2 clockwise and motor1 counterclockwise at a speed of 170/255
        car.Left(170);
        delay(2000);
        //Stops the robot completely
        car.stop();
        delay(5000);
    }
```
