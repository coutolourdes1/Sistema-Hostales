#ifndef IESTADIA
#define IESTADIA

#include "Estadia.h"
#include "Usuario.h"
#include "Reserva.h"
#include "Hostal.h"
#include "DTEstadia.h"
#include "DTInformacionEstadia.h"

#include "DTEstadia.h"
#include "ControladorHostales.h"

#include "ControladorColecciones.h"
#include "ControladorResenia.h"

#include <string>
#include <iterator>
#include <set>
#include <iostream>
using namespace std;

class estadia;

typedef map<int, estadia *> colEstadias; // clave es el numero de estadia
typedef map<int, DTEstadia> mapColEstadias;
typedef map<int, DTInformacionEstadia> mapColInfoEstadia;

class IControladorEstadia
{
public:
    virtual void seleccionarHostal(string) = 0;
    virtual mapColEstadias listarEstadiasFinalizadasHuesped(string) = 0;
    virtual void seleccionarEstadia(int) = 0;
    virtual void agregarCalificacion(string, float, DTFecha) = 0;
    virtual void liberarMemoriaCalificacion() = 0;
    virtual estadia *getEstadiaSeleccionada() = 0;
    virtual mapColEstadias listarEstadias() = 0;
    virtual DTInformacionEstadia informacionEstadia() = 0;
    virtual DTReserva informacionReservaAsociada() = 0;
    virtual int getNuevoNumero() = 0;
    virtual void setEstadiaBuscada(int) = 0;
};

#endif