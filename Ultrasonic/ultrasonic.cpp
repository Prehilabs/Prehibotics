#include "ultrasonic.h"
#include "arduino.h"

//Métodos privados
void Ultrasonic::StartTrigger() //Gestión del pulso ultrasónico
{
    //Emitir un pulso de 10 microsegundos
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
}

//Métodos públicos
Ultrasonic::Ultrasonic(unsigned short t_pin, unsigned short e_pin) //Constructor de clase
{
    //Asignar pines
    trigger = t_pin;
    echo = e_pin;

    //Definir pines IO
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
}

long Ultrasonic::Measure() //Medir distancia
{
    double time = GetRawTime(); //Obtener tiempo de eco
    time *= 0.000001; //Convertir microsegundos a segundos

    return (speed * time)/2; //Retornar distancia    
}

//Devolver tiempo de eco
long Ultrasonic::GetRawTime()
{
    StartTrigger();
    return pulseIn(echo, HIGH, timeout);
}

//Verificar si la distancia se encuentra dentro de un rango
bool Ultrasonic::InRange(unsigned short begin, unsigned short end)
{
    if(begin > end) return false;
    long distance = Measure();
    return distance >= begin && distance <= end;
}

//Cambiar el valor de Timeout
void Ultrasonic::SetTimeout(long time)
{
    timeout = time;
}

//Cambiar el valor de speed
void Ultrasonic::SetSpeed(double _speed)
{
    speed = _speed;
}