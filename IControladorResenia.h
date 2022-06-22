#ifndef ICONTROLADORRESENIA
#define ICONTROLADORRESENIA

#include <iostream>

#include "DTInformacionNotificaciones.h"
#include "Estadia.h"
#include "ControladorEstadia.h"   // Depende del ControladorEstadia
#include "ControladorEmpleados.h" // Depende del ControladorEmpleados
#include "IObserver.h" 

using namespace std;

class IControladorResenia {
    public:
    void agregarResenia(int, string, DTFecha, estadia*, hostal*);    
    void agregarObservador(IObserver *obs);
    void eliminarObservador(IObserver *obs);
};

#endif