#ifndef DTRESERVA
#define DTRESERVA

#include <string>
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "DTHuesped.h"
#include "DTHabitacion.h"
//#include "cargoEmpleado.h"
using namespace std;

typedef map<string, DTHuesped> mapColDTHuespedes;

class DTReserva{
    private: 
        int codigo;
        DTFecha checkin, checkout;
        DTHuesped huesped;
        DTHabitacion habitacion;
        DTFecha fechaRealizada;
    public:
        DTReserva();
        DTReserva(int, DTFecha, DTFecha, DTHuesped, DTHabitacion, DTFecha);
        int getCodigo() const;
        DTFecha getFechaRealizada() const;
        DTFecha getCheckin() const;
        DTFecha getCheckout() const;
        DTHabitacion getDTHabitacion() const;
        DTHuesped getDTHuesped() const;
};

class DTReservaGrupal : public DTReserva{
    private:
        mapColDTHuespedes otrosHuespedes;
    public:
        DTReservaGrupal(int, DTFecha, DTFecha, DTHuesped, DTHabitacion, mapColDTHuespedes, DTFecha);
        mapColDTHuespedes getColHuespedes() const;
};

class DTReservaIndividual : public DTReserva{
    private:
        bool pagada;
    public:
        DTReservaIndividual(int, DTFecha, DTFecha, DTHuesped, DTHabitacion, bool, DTFecha);
        bool getEstaPagada() const;
};

ostream &operator<<(ostream &out, const DTReserva &res);
ostream &operator<<(ostream &out, const DTReservaGrupal &resGrupal);
ostream &operator<<(ostream &out, const DTReservaIndividual &resIndividual);

#endif