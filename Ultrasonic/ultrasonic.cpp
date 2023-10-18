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
    StartTrigger(); //Emitir pulso ultrasónico
    long time = pulseIn(echo, HIGH); //Calcular tiempo de eco
    time *= 0.000001; //Convertir microsegundos a segundos

    /*
     * V del sonido = 34300 cm/s
     * 1s ---- 34300cm
     * xs ---- 34300x/1s
     * Simplificando 34300 * time es la formula de la distancia en centimetros
    */
    return SOUNDSPEED * time;
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
    long distance = Measure();
    return distance >= begin && distance <= end;
}