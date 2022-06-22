#include "DTInformacionEstadia.h"

#include <string>
#include <iostream>
using namespace std;

DTInformacionEstadia::DTInformacionEstadia(){

}


DTInformacionEstadia::DTInformacionEstadia(DTHostal dthos, DTEstadia dtest, int cod){
    this->h = dthos;
    this->dte = dtest;
    this->cod_reserva = cod;
}


int DTInformacionEstadia::getCodReserva() const{
    return cod_reserva;
}

DTHostal DTInformacionEstadia::getDTHostalEstadia() const{
    return h;
}

DTEstadia DTInformacionEstadia::getDTEstadia() const{
    return dte;
}

ostream &operator<<(ostream &out, const DTInformacionEstadia &infoEst){
    
    out << "Numero de reserva: " << infoEst.getCodReserva() << endl;
    
    out << infoEst.getDTHostalEstadia() << endl;
    out << infoEst.getDTEstadia();

    return out;
}

