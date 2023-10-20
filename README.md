# Prehibotics
![Prehilabs](https://imgur.com/3X5ubj2.jpg)
Prehibotics is a project that aims to create and publish diferent libraries for Arduino UNO. Its main purpose is to simplify the  actions required to provide common algorithms to control a variety of simple robots  throughout different tools that permit getting information from sensors in an easier way, as  well as creating output facilities to ease the driving actions

## Instalation for Arduino IDE
1. Download the .zip file in the realease section of this repo or click [here](https://github.com/DIRM2705/Prehibotics/releases)
2. Open the Arduino IDE and press on the sketch menu
![Arduino/Sketch](https://imgur.com/fdywJM1.png)
3. Go to Sketch>Include Library>Include .zip library
![Arduino add lib](https://imgur.com/4jNyYQ5.png)
4. Select the file you have downloaded in step 1 and wait
5. The output bash should show "Installed Library"
6. Now you can use Prehibotics or any of its libraries!


## Libraries
The framework includes the following libraries. However, Prehibotics is still under developement. Thus further libraries will be added in a near future.
* Driver
    * A library to control two motors simultaneously using an H-bridge module or a L293D integrated circuit.
* Ultrasonic
    * Allows to measure distances using the HC-SR04 ultrasonic module

## About the libraries
### Driver
The library driver.h, allows programmers to control two motors simultaneously using an H-bridge. Therefore, it consists of five methods and a constructor defined in the upcoming lines.
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

#### Methods
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

#### Usage
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

### Ultrasonic
Ultrasonic library intends to adopt the use of the HC-SR04 module to measure distances. Easing the calculations needed for this purpose and, simultaneously, adding extra features as common methods implemented in the use of this sensor.

#### Constructor
```cpp
    //trigger: the trigger pin of the HC-SR04 module
    //echo:  the echo pin of the HC-SRO4 module 
    Ultrasonic(unsigned short trigger, unsigned short echo)
```

#### Constants
The speed of sound equals 34300 centimeters per second
```cpp
    const unsigned int CMSPEED = 34300;
```
The speed of sound equals 13511.8110236 inches per second
```cpp
    const unsigned long INSPEED = 13511.8110236;
```

#### Methods

##### Measure
Returns the distance measured in centimeters
```cpp
    //Returns long
    Ultrasonic.Measure();
```

##### Get echo time
Triggers the sensor and returns the pulseIn time obtained by the echo input
```cpp
    //Returns long
    Ultrasonic.GetRawTime();
```

##### Verify if the distance is within a range
Measures the distance and returns a boolean value, true if its within the range setted in the function

The function that return true can be defined as d >= minimum && d <= maximum, where d is the distance measured
```cpp
    //minimum: the smallest distance that will return true
    //maximum: the highest distance that will return true
    Ultrasonic.InRange(unsigned short minimum, unsigned short maximum);
```

## License
[GNU GPL-3.0](https://choosealicense.com/licenses/gpl-3.0/)
