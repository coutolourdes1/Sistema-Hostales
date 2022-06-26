#include "DTInformacionEstadia.h"

#include <string>
#include <iostream>
using namespace std;

DTInformacionEstadia::DTInformacionEstadia(){

}


DTInformacionEstadia::DTInformacionEstadia(DTHostal dthos, DTEstadia dtest, DTReserva dtres){
    this->h = dthos;
    this->dte = dtest;
    this->dtr = dtres;
    this->codEst = dtest.getNumero();
}


int DTInformacionEstadia::getCodEst() const{
    return codEst;
}

DTHostal DTInformacionEstadia::getDTHostalEstadia() const{
    return h;
}

DTEstadia DTInformacionEstadia::getDTEstadia() const{
    return dte;
}

DTReserva DTInformacionEstadia::getDTReserva() const{
    return dtr;
}

ostream &operator<<(ostream &out, const DTInformacionEstadia &infoEst){
    
    out << "Información de la reserva asociada: " << endl << infoEst.getDTReserva() << endl;
    
    out << "Información del hostal asociado: " << endl << infoEst.getDTHostalEstadia() << endl;
    out << "Información de la estadia: " << endl << infoEst.getDTEstadia() << endl;

    return out;
}

