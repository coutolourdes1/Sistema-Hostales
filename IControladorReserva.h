#ifndef IRESERVA
#define IRESERVA

#include <string>
#include <iterator>
#include <map>
#include <iostream>
using namespace std;

#include "Reserva.h"
#include "Usuario.h"
#include "DTReserva.h"
#include "DTInformacionReserva.h"
#include "IControladorHostales.h"    

#include "IControladorColecciones.h"
#include "Usuario.h"
#include "Reserva.h"
#include "DTReserva.h"
using namespace std;

class reserva;
class hostal;
class reserva;
class habitacion;
class empleado;

class DTInformacionReserva;
class DTReserva;

typedef map<int, DTInformacionReserva> colConsultaReserva;
typedef map<int, DTReserva> mapColReservas;

class IControladorReserva {
    public:
        virtual void agregarReserva(reserva*) = 0;
        virtual int getNuevoCodigo() = 0;
        virtual colConsultaReserva obtenerReservasdelHostal() = 0;
        virtual void seleccionarHostal(string)= 0;
        virtual mapColReservas listarReservasDeHostal()= 0;
        virtual void seleccionarNumeroReserva(int)= 0;
        virtual void confirmarBajaReserva()= 0;
        virtual void cancelarBajaReserva()= 0;
        virtual void liberarMemoriaBajaReserva()= 0;
};

#endif