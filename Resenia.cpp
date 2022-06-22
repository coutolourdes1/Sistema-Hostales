#include "Resenia.h"
#include <string>

#include <iostream>
using namespace std;

resenia::resenia(int numero, int calificacion, string comentario, DTFecha fecha, estadia *estadia, hostal* hostal)
{
    this->numero = numero;
    this->calificacion = calificacion;
    this->comentario = comentario;
    this->fecha = fecha;
    this->estadiaResenia = estadia;
    this->hostalDeLaResenia = hostal;
    this->resp = NULL;
}

int resenia::getCalificacion()
{
    return calificacion;
}

string resenia::getComentario()
{
    return comentario;
}

int resenia::getNumero(){
    return numero;
}

DTResenia resenia::getDTResenia()
{
    int numHabitacion = estadiaResenia->getReserva()->getHabitacion()->getNumero();
    return DTResenia(numero, calificacion, comentario, fecha, numHabitacion);
}

bool resenia::tieneRespuesta(){
    return resp != NULL;
}

void resenia::setRespuesta(respuesta* resp){
    this->resp = resp;
}

respuesta* resenia::getRespuesta(){
    return resp;
}

void resenia::deleteResenia(){
    hostalDeLaResenia->eliminarResenia(getNumero());
    resp->eliminarRespuesta();
    delete resp;
}