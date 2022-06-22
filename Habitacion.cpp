#include "Habitacion.h"
#include <string>

#include <iostream>
using namespace std;

habitacion::habitacion(int numero, float precio, int capacidad, hostal* hostalDeHabitacion){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
    this->hostalDeHabitacion = hostalDeHabitacion;

    this->reservas = new colReservas();
}

int habitacion::getNumero(){
    return numero;
}

float habitacion::getPrecio(){
    return precio;
}

int habitacion::getCapacidad(){
    return capacidad;
}

hostal* habitacion::getHostalDeHabitacion(){
    return hostalDeHabitacion;
}

DTHabitacion habitacion::getDTHabitacion(){
    return DTHabitacion(numero, capacidad, precio);
}

void habitacion::agregarReservaACol(reserva* res){
    reservas->insert(pair<int, reserva*>(res->getCodigo(), res));
}

bool habitacion::estaHabDisponible(DTFecha inicio, DTFecha fin){
    colReservas::iterator iterRes = reservas->begin();
    bool reservaSolapa = false;

    while((iterRes != reservas->end()) && (!reservaSolapa)) {
        reservaSolapa = (reservaSolapa || iterRes->second->solapa(inicio, fin));
        iterRes++;
    }

    return !reservaSolapa;
}

colReservas habitacion::getReservasHabitacion(){
    return reservasHabitacion;
}

colDTReservas habitacion::getDTReservasHabitacion(){
    colDTReservas DTReservasHabitacion;
    colReservas::iterator iterRes;

    for (iterRes = reservasHabitacion.begin(); iterRes != reservasHabitacion.end(); iterRes++){
        reserva *r = iterRes->second;
        DTReservasHabitacion.insert(pair<int, DTReserva>(r->getCodigo(), r->getDTReserva()));
    }

    return DTReservasHabitacion;
}

void habitacion::eliminarReservaDeHabitacion(int codigoReserva){
    reservasHabitacion.erase(codigoReserva);
}
