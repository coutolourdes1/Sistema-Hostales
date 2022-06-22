#include <iostream>
#include <string>
#include <iterator>
#include "DTInformacionHostal.h"

using namespace std;

typedef map<int, DTResenia> colDTResenias;

DTInformacionHostal::DTInformacionHostal(DTHostal DTh, colDTResenias colDTResenias, float promCal)
{
    this->hostal = DTh;
    this->resenias = colDTResenias;
    this->promedioCalificaciones = promCal;
}

string DTInformacionHostal::getNombreHostal() const
{
    return hostal.getNombre();
}

float DTInformacionHostal::getPromedioCalificaciones() const
{
    return promedioCalificaciones;
}

colDTResenias DTInformacionHostal::getDTColResenias() const
{
    return resenias;
}

ostream &operator<<(ostream &out, const DTInformacionHostal &infoHostal)
{
    colDTResenias::iterator iterResenia;

    out << "Hostal: " << infoHostal.getNombreHostal() << endl;
    out << "Promedio: " << infoHostal.getPromedioCalificaciones() << endl;

    out << "Resenias: " << endl;

    colDTResenias cdt = infoHostal.getDTColResenias();

    for (iterResenia = cdt.begin(); iterResenia != cdt.end(); ++iterResenia)
    {
        out << "Numero: " << iterResenia->second.getNumero() << endl;
        out << "Calificacion: " << iterResenia->second.getCalificacion() << endl;
        out << "Comentario: " << iterResenia->second.getComentario() << endl;
        out << "Numero Habitacion: " << iterResenia->second.getNumeroHabitacion() << endl;
        out << "Fecha: " << iterResenia->second.getFecha() << endl;
    }

    return out;
}

// DTHostal* DTInformacionHostal::getDTHostal(){
//     return hostal;
// }

// DTResna* DTInformacionHostal::getDTResena(){
//     return resena;
// }
