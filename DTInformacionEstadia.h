#ifndef DTINFORMACIONESTADIA
#define DTINFORMACIONESTADIA

#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

#include "DTHostal.h"
#include "DTResenia.h"
#include "DTEstadia.h"
#include "DTHabitacion.h"


class DTInformacionEstadia{
    private: 
        DTHostal h;
        DTEstadia dte;
        int cod_reserva;
    public:
        DTInformacionEstadia();
        DTInformacionEstadia(DTHostal, DTEstadia, int);
        int getCodReserva() const;
        DTHostal getDTHostalEstadia() const;
        DTEstadia getDTEstadia() const;
}; 

ostream &operator<<(ostream &out, const DTInformacionEstadia &infoEst);


#endif
