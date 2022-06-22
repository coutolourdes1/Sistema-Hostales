#ifndef DTEMPLEADO
#define DTEMPLEADO

#include <string>
#include <iostream>
#include <map>
using namespace std;

#include "DTHostal.h"
#include "DTUsuario.h"

typedef map<string, DTHostal> mapColHostales;

class DTEmpleado: public DTUsuario {
    private: 
        string cargo;
        mapColHostales hostalesQueTrabaja;
    public: 
        DTEmpleado(string,string,string,string,mapColHostales);
        string getCargo() const;
        mapColHostales getHostalesQueTrabaja();
}; 

ostream &operator<<(ostream &out, const DTEmpleado &hab);

#endif
