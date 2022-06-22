#ifndef ESTADIA
#define ESTADIA

#include "DTFecha.h"
// #include "DTHuesped.h"
#include "DTEstadia.h"
#include "Resenia.h"
#include "Reserva.h"
#include "Usuario.h"
#include "ControladorColecciones.h"
#include "ControladorEstadia.h"

#include <map>


class huesped;
class reserva;
class usuario;

//  R 1-* E *-1 H

class estadia
{
private:
    huesped *huesp;
    reserva *res;
    DTFecha checkIn, checkOut;
    int numeroEstadia;
    bool finalizada;
    resenia *reseniaDeEstadia; // link con la resenia cuando se califica la estadia
public:
    estadia(huesped *, reserva *, DTFecha);
    DTEstadia getDTEstadia();
    int getNumeroEstadia();
    void setHuesped(huesped *);
    void setReserva(reserva *);
    void setCheckout(DTFecha);
    reserva *getReserva();
    void setFinalizada();
    bool getFinalizada();
    void eliminarEstadia();
    huesped* getHuespedEstadia();
    DTHuesped getDTHuespedEstadia();
    resenia *getResenia();
    void setResenia(resenia *);
    // DTHuesped getDTHuesped();
    // huesped* getHuesped();
    DTFecha getCheckin();
    DTFecha getCheckOut();
    // string getPromo();
    // DTEstadia getDTEstadia();
    // resenia getResenia(); //preguntar raro
    // reserva getReserva();
    // void setReserva(reservaIndividual);
};
#endif