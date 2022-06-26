#ifndef DTESTADIA
#define DTESTADIA

#include "DTFecha.h"
#include "DTHuesped.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

class DTEstadia
{
private:
    DTHuesped huesped;
    DTFecha CheckIn;
    DTFecha CheckOut;
    int numeroEstadia;
    bool finalizada;

public:
    DTEstadia();
    DTEstadia(DTHuesped, DTFecha, DTFecha, int, bool);
    DTHuesped getHuesped() const;
    DTFecha getCheckIn() const;
    DTFecha getCheckOut() const;
    int getNumero() const;
    bool getFinalizada() const;
    // string getPromo();
    // Resenia getResenia();
    // Reserva getReserva();
    // setReserva(r : ReservaIndividual) // Esto es super raro
};

ostream &operator<<(ostream &out, const DTEstadia &estadia);

#endif