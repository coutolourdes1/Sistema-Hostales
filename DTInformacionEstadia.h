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
#include "DTReserva.h"


class DTInformacionEstadia{
    private: 
        DTHostal h;
        DTEstadia dte;
        DTReserva dtr;
        int codEst;
    public:
        DTInformacionEstadia();
        DTInformacionEstadia(DTHostal, DTEstadia, DTReserva);
        int getCodEst() const;
        DTHostal getDTHostalEstadia() const;
        DTEstadia getDTEstadia() const;
        DTReserva getDTReserva() const;
}; 

ostream &operator<<(ostream &out, const DTInformacionEstadia &infoEst);


#endif
