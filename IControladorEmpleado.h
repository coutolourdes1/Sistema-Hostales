#ifndef ICONTROLADOREMPLEADO
#define ICONTROLADOREMPLEADO

#include "Usuario.h"
#include "ControladorColecciones.h"
#include "DTInformacionNotificaciones.h"
#include "Resenia.h"
#include "Respuesta.h"
#include "DTEmpleado.h"
#include "DTResenia.h"

#include "Hostal.h"
#include "ControladorHostales.h"
#include "DTHostal.h"

#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iostream>

// controlador empleado
class empleado;
class resenia;

typedef map<int, string> mapComentariosSinResp;
typedef map<string, empleado *> colEmpleados;
typedef map<int, resenia *> colResenias;
typedef map<string, DTEmpleado> mapDTEmpleado;
typedef map<int, DTInformacionNotificaciones> mapInfoNotificaciones;

class IControladorEmpleado
{
public:
    // controlador empleados
    virtual mapComentariosSinResp listaComentariosSinResp(string) = 0;
    virtual void responderResenia(int, string) = 0;
    virtual void liberarMemoriaRespuesta() = 0;
    virtual void setEmpleadoSeleccionado(empleado *) = 0;
    virtual empleado *getEmpleadoSeleccionado() = 0;
    virtual mapDTEmpleado listarEmpleados() = 0;
    virtual void seleccionarEmpleadoANotificar(string) = 0;
    virtual mapInfoNotificaciones getInfoNotificaciones(string) = 0;
    virtual void seleccionarEmpleadoADesNotificar(string) = 0;
};

#endif