# Prehibotics
![Prehilabs](https://imgur.com/3X5ubj2.jpg)
Prehibotics is a project that aims to create and publish diferent libraries for Arduino UNO. Its main purpose is to simplify the  actions required to provide common algorithms to control a variety of simple robots  throughout different tools that permit getting information from sensors in an easier way, as  well as creating output facilities to ease the driving actions

## Instalation for Arduino IDE
1. Download the .zip file in the realease section of this repo or click [here](https://github.com/DIRM2705/Prehibotics/releases)
2. Open the Arduino IDE and press on the sketch menu
![Arduino/Sketch](https://imgur.com/fdywJM1.png)
3. Go to Sketch>Include Library>Include .zip library
![Arduino add lib](https://imgur.com/Giok7I9.png)
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
//hi1: H-Bridge input 1 pin
//lo1: H-Bridge input 2 pin
//hi2: H-Bridge input 3 pin
//lo2: H-Bridge input 4 pin
//PWM1: H-Bridge enable 1&2 pin
//PWM2: H-Bridge enable 3&4 pin
Driver(unsigned char hi1, unsigned char lo1, unsigned char hi2, unsigned char lo2, unsigned char PWM1, unsigned char PWM2);
```

#### Methods

##### Move forward
* Turns pins 1 and 3 of the H-Bridge to HIGH
* Turns pins 2 and 4 of the H-Bridge to LOW
* The speed parameter sets the analog output for pins enable 1&2 and enable 3&4
```cpp
//The speed paramater is a number between 0 and 255
Driver.Forward(unsigned char speed);
```

##### Move backwards
* Turns pins 2 and 4 of the H-Bridge to HIGH
* Turns pins 1 and 3 of the H-Bridge to LOW
* The speed parameter sets the analog output for pins enable 1&2 and enable 3&4
```cpp
//The speed parameter is a number between 0 and 255
Driver.Backwards(unsigned char speed);
```
##### Rotate right
* Turns pins 1 and 4 of the H-Bridge to HIGH
* Turns pins 2 and 3 of the H-Bridge to LOW
* The speed parameter sets the analog output for pins enable 1&2 and enable 3&4
```cpp
//The speed parameter is a number between 0 and 255
Driver.Right(unsigned char speed);
```

##### Rotate left
* Turns pins 2 and 3 of the H-Bridge to HIGH
* Turns pins 1 and 4 of the H-Bridge to LOW
* The speed parameter sets the analog output for pins enable 1&2 and enable 3&4
```cpp
//The speed parameter is a number between 0 and 255
Driver.Left(unsigned char speed);
```

##### Stop
* Turns pins 1-4 of the H-Bridge to LOW
* Writes an analog output of 0 for pins enable 1&2 and enable 3&4
```cpp
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
* The speed of sound equals 34300 centimeters per second
```cpp
    const unsigned int CMSPEED = 34300;
```
* The speed of sound equals 13511.8110236 inches per second
```cpp
    const unsigned long INSPEED = 13511.8110236;
```

#### Methods

##### Measure
* Returns the distance measured in centimeters
```cpp
    //Returns long
    /*
        If the cm parameter is true, the measure will be return in centimeters
        otherwise the result will be returned in inches
    */
    Ultrasonic.Measure(bool cm = true);
```

##### Get echo time
* Triggers the sensor and returns the pulseIn time obtained by the echo input
```cpp
    //Returns long
    Ultrasonic.GetRawTime();
```

##### Verify if the distance is within a range
* Measures the distance and returns wether it is within the range setted in the function or not
    * Both minimum and maximum parameters should be in centimeters
* The function that return true can be defined as d >= minimum && d <= maximum, where d is the distance measured
```cpp
    //Returns bool
    //minimum: the smallest distance that will return true
    //maximum: the highest distance that will return true
    Ultrasonic.InRange(unsigned short minimum, unsigned short maximum);
```

#### Usage
```cpp
    //Import the library
    #include<ultrasonic.h>

    //Create ultrasonic object
    Ultrasonic sensor(5,6);

    void setup()
    {
        Serial.begin(9600);
    }

    void loop()
    {
        //Measure distance in centimeters
        long cm = sensor.Measure();

        //Measure distance in inches
        long in = sensor.Measure(false);

        //If the distance is between 5 and 20 centimeters
        if(sensor.InRange(5, 20))
        {
            //Get the raw time
            long time = sensor.GetRawTime();

            //Print time and speeds
            Serial.print("time: ");
            Serial.print(time);
            Serial.print(" Speed in CM: ");
            Serial.print(sensor.CMSPEED);
            Serial.print(" Speed in IN: ");
            Serial.println(sensor.INSPEED);
        }
        else
        {
            //print distances

            Serial.print("Distance in CM : ");
            Serial.print(cm);
            Serial.print(" Distance in IN: ");
            Serial.println(in);
        }
    }
```

## License
[GNU GPL-3.0](https://choosealicense.com/licenses/gpl-3.0/)
