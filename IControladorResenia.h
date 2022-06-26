#ifndef ICONTROLADORRESENIA
#define ICONTROLADORRESENIA

#include <iostream>

#include "DTInformacionNotificaciones.h"
#include "Estadia.h"
#include "ControladorEstadia.h"   // Depende del ControladorEstadia
#include "ControladorEmpleados.h" // Depende del ControladorEmpleados
#include "IObserver.h" 
#include "DTEmpleado.h"

using namespace std;

class IControladorResenia {
    public:
    virtual void agregarResenia(int, string, DTFecha, estadia*, hostal*) = 0;    
    virtual void agregarObservador(IObserver *obs) = 0 ;
    virtual void eliminarObservador(IObserver *obs) = 0 ;
    virtual  map<string,DTEmpleado> getEmpleadosObservadores() = 0;
};

#endif