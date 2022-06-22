#include "DTInformacionReserva.h"

#include <string>
#include <iostream>
using namespace std;

DTInformacionReserva::DTInformacionReserva(){

}

DTInformacionReserva::DTInformacionReserva(map<int, DTReserva> colRes, int hab, set<string> nombresHuespedes){
    this->colDTReservas = colRes;
    this->hab = hab;
    this->nombresHuesp = nombresHuespedes;
}

int DTInformacionReserva::getHab() const{
    return hab;
}

map<int, DTReserva> DTInformacionReserva::getColDTReservas() const{
    return colDTReservas;
}

set<string> DTInformacionReserva::getNombresHuesp() const {
    return nombresHuesp;
}

ostream &operator<<(ostream &out, const DTInformacionReserva &infoRes){

    out << "Numero Habitacion: " << infoRes.getHab() << endl;

    map<int, DTReserva> colRes = infoRes.getColDTReservas();
    map<int, DTReserva>::iterator irRes;
    for (irRes = colRes.begin(); irRes != colRes.end(); ++irRes){
        out << irRes->second << endl;
    }

    set<string> nombres = infoRes.getNombresHuesp();
    set<string>::iterator itNombres;
    for (itNombres = nombres.begin(); itNombres != nombres.end(); ++itNombres){
        out << "Nombre huesped: " << (*itNombres) << endl;
    }
    
    return out;
};