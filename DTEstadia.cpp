#include "DTEstadia.h"
#include "DTFecha.h"
#include "DTHuesped.h"
#include <string>
#include <iostream>

using namespace std;

class DTHuesped;

DTEstadia::DTEstadia()
{
}

DTEstadia::DTEstadia(DTHuesped huesp, DTFecha checkin, DTFecha checkout, int num, bool finalizada)
{
    this->huesped = huesp;
    this->CheckIn = checkin;
    this->CheckOut = checkout;
    this->numeroEstadia = num;
    this->finalizada = finalizada;
}

DTHuesped DTEstadia::getHuesped() const
{
    return this->huesped;
}

DTFecha DTEstadia::getCheckIn() const
{
    return this->CheckIn;
}

DTFecha DTEstadia::getCheckOut() const
{
    return this->CheckOut;
}

int DTEstadia::getNumero() const
{
    return this->numeroEstadia;
}

bool DTEstadia::getFinalizada() const
{
    return this->finalizada;
}

ostream &operator<<(ostream &out, const DTEstadia &estadia)
{
    out << "Numero: " << estadia.getNumero() << endl;
    out << "Huesped: " << estadia.getHuesped() << endl;
    out << "CheckIn: " << estadia.getCheckIn() << endl;

    if(estadia.getFinalizada()){
        out << "CheckOut: " << estadia.getCheckOut();
    } else {
        out << "Estadia aún sin finalizar";
    }

    return out;
}
