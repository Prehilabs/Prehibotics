#include "driver.h"
#include "arduino.h"

//Métodos privados
void Driver::Motor1(bool forward, unsigned int speed) //Controlador del motor izquierdo
{
    //Determinar la dirección del giro
    digitalWrite(motor1h, forward);
    digitalWrite(motor1l, !forward);

    //Determinar la velocidad
    analogWrite(speed1, speed);
}

void Driver::Motor2(bool forward, unsigned int speed) //Controlador del motor derecho
{
    //Determinar la dirección del giro
    digitalWrite(motor2h, forward);
    digitalWrite(motor2l, !forward);

    //Determinar la velocidad
    analogWrite(speed2, speed);
}

//Métodos públicos
Driver::Driver(unsigned char hi1, unsigned char lo1, unsigned char hi2, unsigned char lo2, unsigned char PWM1, unsigned char PWM2)
{
    //Declarar pines
    motor1h = hi1;
    motor2h = hi2;
    motor1l = lo1;
    motor2l = lo2;
    speed1 = PWM1;
    speed2 = PWM2;

    //Declarar pines como salidas
    pinMode(motor1h, OUTPUT);
    pinMode(motor2h, OUTPUT);
    pinMode(motor1l, OUTPUT);
    pinMode(motor2l, OUTPUT);
    pinMode(speed1, OUTPUT);
    pinMode(speed2, OUTPUT);
}

//Mover hacia adelante
void Driver::Forward(unsigned int speed)
{
    speed %= 256;
    Motor1(true, speed);
    Motor2(true, speed);
}

//Mover hacia atrás
void Driver::Backwards(unsigned int speed)
{
    speed %= 256;
    Motor1(false, speed);
    Motor2(false, speed);
}

//Girar a la izquierda
void Driver::Left(unsigned int speed)
{
    speed %= 256;
    Motor1(false, speed);
    Motor2(true, speed);
}

//Girar a la derecha
void Driver::Right(unsigned int speed)
{
    speed %= 256;
    Motor1(true, speed);
    Motor2(false, speed);
}

//Parar
void Driver::Stop()
{
    //Apagar todos los pines de los motores
    digitalWrite(motor1h, LOW);
    digitalWrite(motor1l, LOW);
    digitalWrite(motor2h, LOW);
    digitalWrite(motor2l, LOW);

    //Apagar los pines de velocidad
    analogWrite(speed1, 0);
    analogWrite(speed2, 0);
}