#ifndef ICONTROLADORCOLECCIONES
#define ICONTROLADORCOLECCIONES

#include <string>
#include <iostream>
#include <iterator>
#include <map>

#include "Hostal.h"
#include "Usuario.h"
#include "Resenia.h"
#include "Reserva.h"
#include "Estadia.h"
#include "Respuesta.h"
using namespace std;

class hostal;
class huesped;
class empleado;
class usuario;
class reserva;
class estadia;
class resenia;
class respuesta;

typedef map<string, hostal*> colHostales;
typedef map<int, reserva *> colReservas; // clave es el nombre
typedef map<int, estadia *> colEstadias;    //clave es el numero de estadia
typedef map<string, usuario *> colUsuarios;
typedef map<string, huesped *> colHuespedes;
typedef map<string, empleado *> colEmpleados;
typedef map<int, resenia *> colResenias;
typedef map<int, respuesta *> colRespuestas;



class IControladorColecciones {
    public:
    
    virtual colHostales *getColHostales() = 0;
    virtual colHuespedes *getColHuespedes() = 0;
    virtual colReservas *getColReservas() = 0;
    virtual colEstadias *getColEstadias() = 0;
    virtual colRespuestas *getColRespuestas() = 0;
    virtual colUsuarios *getColUsuarios() = 0;
    virtual colEmpleados *getColEmpleados() = 0;
    virtual colResenias *getColResenias() = 0;
    
};

#endif