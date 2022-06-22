#ifndef DTINFORMACIONRESERVA
#define DTINFORMACIONRESERVA

#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

#include "DTHostal.h"
#include "DTResenia.h"
#include "DTReserva.h"
#include "DTHabitacion.h"

class DTInformacionReserva{
    private: 
        map<int, DTReserva> colDTReservas;
        int hab;
        set<string> nombresHuesp;
    public:
        DTInformacionReserva();
        DTInformacionReserva(map<int, DTReserva>, int, set<string>);
        int getHab() const;
        map<int, DTReserva> getColDTReservas() const;
        set<string> getNombresHuesp() const;

}; 
ostream &operator<<(ostream &out, const DTInformacionReserva &infoRes);

#endif
