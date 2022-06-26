#include <iostream>
#include <string>
#include <iterator>
#include "DTInformacionHostal.h"

using namespace std;

typedef map<int, DTResenia> colDTResenias;

DTInformacionHostal::DTInformacionHostal(DTHostalCalificado DTh, colDTResenias colDTResenias, float promCal)
{
    this->hostalCalificado = DTh;
    this->resenias = colDTResenias;
    this->promedioCalificaciones = promCal;
}

string DTInformacionHostal::getNombreHostal() const
{
    return hostalCalificado.getNombre();
}

float DTInformacionHostal::getPromedioCalificaciones() const
{
    return promedioCalificaciones;
}

colDTResenias DTInformacionHostal::getDTColResenias() const
{
    return resenias;
}

DTHostalCalificado DTInformacionHostal::getDTHostalCalificado() const
{
    return hostalCalificado;
}

ostream &operator<<(ostream &out, const DTInformacionHostal &infoHostal)
{
    colDTResenias::iterator iterResenia;

    out << "Información del Hostal: " << endl;
    out << infoHostal.getDTHostalCalificado() << endl;

    if(infoHostal.getPromedioCalificaciones() != -1){
        out << "Resenias: " << endl;

        colDTResenias cdt = infoHostal.getDTColResenias();

        for (iterResenia = cdt.begin(); iterResenia != cdt.end(); ++iterResenia)
        {
            out << iterResenia->second << endl;
        }
    } else  {
        out << "El hostal no tiene resenias";
    }

    return out;
}

// DTHostal* DTInformacionHostal::getDTHostal(){
//     return hostal;
// }

// DTResna* DTInformacionHostal::getDTResena(){
//     return resena;
// }
