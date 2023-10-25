#include "arduino.h"
#include "Din.h"

//Métodos públicos
Din::Din(unsigned char _pin) //Constructor
{
    //Asignar pin de entrada
    pin = _pin;   
    //Definir entrada
    pinMode(pin, INPUT);
}

bool Din::GetInput() //Entrada del botón
{
    return digitalRead(pin);
}

void Din::WaitUntilChange() //Esperar a que cambie el input del botón de LOW a HIGH o de HIGH a LOW
{
    bool i_state = GetInput(); //Obtener estado inicial
    bool c_state = i_state; //Estado actual

    while (c_state == i_state) //Mientras está en ese estado "detener" la ejecución
    {
        c_state = GetInput();
    }
}

void Din::WaitUntilChange(bool state) //Esperar a que el input cambie a un estado específico
{
    //Esperar a estar en el estado contrario
    while (GetInput() == state)
    {
        continue;
    }

    delayMicroseconds(25); //Esperar 25 microsegundos

    //Esperar a obtener el estado deseado
    while (GetInput() != state)
    {
        continue;
    }
}