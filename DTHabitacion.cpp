#include "DTHabitacion.h"

#include <string>
#include <iostream>
using namespace std;

DTHabitacion::DTHabitacion(){

}

DTHabitacion::DTHabitacion(int num, int cap, float precio){
    this->numero = num;
    this->capacidad = cap;
    this->precio = precio;
}

int DTHabitacion::getNumero() const {
    return numero;
}

int DTHabitacion::getCapacidad() const {
    return capacidad;
}

float DTHabitacion::getPrecio() const {
    return precio;
}

ostream &operator<<(ostream &out, const DTHabitacion &hab){
    int numero = hab.getNumero();
    out << "Numero: " << numero << ", ";
    out << "capacidad: " << hab.getCapacidad() << ", ";
    out << "precio: $" << hab.getPrecio();

    return out;
}

