#ifndef USUARIO
#define USUARIO

// #include "Habitacion.h"
#include "Hostal.h"
#include "Reserva.h"
#include "Estadia.h"
#include "Respuesta.h"
#include <map>
// #include "DTFecha.h"
#include "DTEmpleado.h"
#include "DTHostal.h"
#include "ControladorColecciones.h"
#include "ControladorEmpleados.h"
#include "DTHuesped.h"
#include "DTInformacionNotificaciones.h"
#include "IObserver.h"
//#include "EstadoReserva.h"
using namespace std;

#include <set>

class hostal;
class reserva;
class estadia;
class respuesta;

typedef map<int, reserva *> colReservas;
typedef map<string, hostal *> colHostales;
typedef map<int, estadia *> colEstadias;
typedef map<int, respuesta *> colRespuestas;
typedef map<int, DTInformacionNotificaciones> mapInfoNotificaciones;
typedef map<int, string> mapComentariosSinResp;


class usuario
{
private:
    string nombre, email, password;

public:
    usuario();
    usuario(string, string, string);
    virtual string getNombre();
    virtual string getEmail();
    virtual string getPassword();
};

class huesped : public usuario
{
private:
    bool esFinger;
    colEstadias estadiasDelHuesped;
    colReservas colReservasRealizadas;
    colReservas colReservasQuePertenece;

public:
    huesped();
    huesped(string, string, string, bool);
    bool getEsFinger();
    void agregarReservaACol(reserva *);
    void agregarReservaAPertenecientes(reserva *); // Solo para caso de reservas grupales
    colReservas getColReservasQuePertenece();
    reserva *getReserva(int);
    DTHuesped getDTHuesped();
    colEstadias getColEstadias();

    void agregarEstadia(estadia *);

    //Auxiliar caso de uso: Baja de Reserva
    void borrarReservaRealizada(int);
    void borrarReservaQuePertenece(int);
    void borrarEstadia(int);

    // map<int, estadia *> *getEstadiasHuesp();
    // Operacion necesaria para Consulta de Usuario
    // set<DTReserva> *obtenerReservasHuesped();
    // void agregarEstadia(DTEstadia);
    // CREO QUE VAN DESTRUCTORES
};

class empleado : public IObserver, public usuario{
private:
    string cargo;
    hostal *h;
    // map<string, cargo*> cargos;
    colHostales hostalesQueTrabaja;
    colRespuestas respuestasRealizadas;
    colResenias* ReseniasSuscripcion;
    mapInfoNotificaciones mapNotificacionesEmp;


public:
    empleado();
    empleado(string, string, string, string);
    string getCargo();
    // hostal *getHostalQueTrabaja();
    colHostales getHostalesQueTrabaja();
    mapColHostales getDTHostalesQueTrabaja();
    DTEmpleado getDTEmpleado();
    void agregarHostalQueTrabaja(hostal *);
    void eliminarRespuestaDeEmpleado(int);
    //Iobserver
    void Notify(DTInformacionNotificaciones);

    //consulta notificaciones
    mapInfoNotificaciones mostrarDTInfoNotificaciones(); //retorna
    void eliminarNotificaciones(); //las borra

    // Operacion necesaria para Comentar Calificacion
    mapComentariosSinResp getComentariosSinResp();
    void agregarRespuesta(respuesta*);


};

#endif