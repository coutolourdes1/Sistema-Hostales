#ifndef CONTROLADOREMPLEADOS
#define CONTROLADOREMPLEADOS

#include "Usuario.h"
#include "ControladorColecciones.h"
#include "DTInformacionNotificaciones.h"
#include "Resenia.h"
#include "Respuesta.h"
#include "DTEmpleado.h"
#include "DTResenia.h"

#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iostream>
#include "IControladorEmpleado.h" 

using namespace std;

class controladorEmpleado : public IControladorEmpleado{
private:
    static controladorEmpleado *instancia;
    controladorEmpleado();

    empleado* empleadoSeleccionado;
public:
    static controladorEmpleado *getInstancia();

    //CASO DE USO: COMENTAR (Responder) CALIFICACION
    mapComentariosSinResp listaComentariosSinResp(string);
    void responderResenia(int, string);
    //desctructor
    void liberarMemoriaRespuesta();
    //Termina COMENTAR CALIFICACION

    //Setters COMENTAR CALIFICACION
    void setEmpleadoSeleccionado(empleado*);
    empleado* getEmpleadoSeleccionado();

    //CASO DE USO SUSCRIBIRSE A NOTIFICACIONES
    mapDTEmpleado listarEmpleados();
    void seleccionarEmpleadoANotificar(string);

    //CASO DE USO CONSULTA NOTIFICACIONES
    //mapDTEmpleado listarEmpleados();
    mapInfoNotificaciones getInfoNotificaciones(string);

    //CASO DE USO ELIMINAR SUSCRIPCION
    //mapDTEmpleado listarEmpleados();
    void seleccionarEmpleadoADesNotificar(string);
};

#endif