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

long Ultrasonic::Measure(bool cm = true) //Medir distancia
{
    long time = GetRawTime(); //Obtener tiempo de eco
    time *= 0.000001; //Convertir microsegundos a segundos

    //Si se necesita la distancia en cm
    if(cm)
    {
        return CMSPEED * time; //Retornar distancia en cm
    }
    else
    {
        return INSPEED * time; //Retornar distancia en pulgadas
    }
    
}

//Devolver tiempo de eco
long Ultrasonic::GetRawTime()
{
    StartTrigger();
    return pulseIn(echo, HIGH);
}

//Verificar si la distancia se encuentra dentro de un rango
bool Ultrasonic::InRange(unsigned short begin, unsigned short end)
{
    if(begin > end) return false;
    long distance = Measure();
    return distance >= begin && distance <= end;
}