#include "DTResenia.h"
#include "DTFecha.h"
#include "cargoEmpleado.h"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

DTResenia::DTResenia(int num, int calif, string come, DTFecha fech, int numHab)
{
    this->numero = num;
    this->calificacion = calif;
    this->comentario = come;
    this->fecha = fech;
    this->numHabitacion = numHab;
}

int DTResenia::getNumero() const
{
    return this->numero;
}

int DTResenia::getNumeroHabitacion() const
{
    return this->numHabitacion;
}

int DTResenia::getCalificacion() const
{
    return this->calificacion;
}

string DTResenia::getComentario() const
{
    return this->comentario;
}

DTFecha DTResenia::getFecha() const
{
    return this->fecha;
}

ostream &operator<<(ostream &out, const DTResenia &res)
{
    out << "Numero: " << res.getNumero() << endl;
    out << "Calificacion: " << res.getCalificacion() << endl;
    out << "Comentario: " << res.getComentario() << endl;
    out << "Numero de Habitacion: " << res.getNumeroHabitacion() << endl;
    out << "Fecha: " << res.getFecha() << endl;

    return out;
}
