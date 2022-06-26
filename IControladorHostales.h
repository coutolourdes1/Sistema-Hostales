#ifndef ICONTROLADORHOSTAL
#define ICONTROLADORHOSTAL

#include "DTHostalCalificado.h"
#include "Hostal.h"
#include "Resenia.h"
#include "DTHuesped.h"
#include "DTHostal.h"
#include "DTEmpleado.h"
#include "DTHostalCalificado.h"
#include "Usuario.h"
#include "DTInformacionHostal.h"
#include "ControladorReserva.h"
#include "ControladorColecciones.h"
#include "DTEstadia.h"

#include "Estadia.h"
#include "DTUsuario.h"
#include "DTFecha.h"


#include <string>
#include <set>
using namespace std;

class huesped;
class hostal;
class habitacion;
class empleado;
class estadia;
class resenia;


typedef set<string> setEmails;
typedef set<string> setNombreHostales;
typedef set<int> numHabs;
typedef map<string, DTHostal> mapColDTHostales;
typedef map<int, DTReserva> mapColDTReservas;
typedef map<string, huesped *> mapColHuespedes;
typedef map<int, DTHabitacion> mapColHabitaciones;
typedef map<string, DTHostalCalificado> mapColHostalesCal;
typedef map<string, DTEmpleado> mapColEmpleados;
typedef map<int,DTEstadia> mapDTEstadia;
typedef map<string, DTHuesped> mapDTHuespedes;
typedef map<int, string> mapTopTres;


class IControladorHostales {
    public:
    
    virtual setNombreHostales obtenerNombresHostalesRegistrados() = 0;
    virtual DTInformacionHostal obtenerInformacionHostal(string) = 0;

    virtual mapColDTHostales obtenerHostalesRegistrados() = 0;
    virtual void seleccionarHostal(string) = 0;
    virtual void setNumeroHabitacion(int)= 0;
    virtual void setCapacidadHabitacion(int) = 0;
    virtual void setPrecioHabitacion(float) = 0;
    virtual void confirmarAltaHabitacion() = 0;
    virtual void cancelarAltaHabitacion() = 0;
    virtual void liberarMemoriaAltaHabitacion() = 0;

    virtual int getNumHabSeleccionada() = 0;
    virtual huesped *getHuespedSeleccionado() = 0;
    virtual hostal *getHostalSeleccionado() = 0;
    virtual bool getEsGrupal() = 0;
    virtual DTFecha getCheckIn() = 0;
    virtual DTFecha getCheckOut() = 0;
    virtual habitacion *getHabitacionSeleccionada() = 0;

    virtual void setHuespedSeleccionado(huesped *) = 0;
    virtual void setHostalSeleccionado(hostal *) = 0;
    virtual void setEsGrupal(bool) = 0;
    virtual void setFechas(DTFecha, DTFecha) = 0;
    virtual void setHabDisp(mapColHabitaciones) = 0;
    virtual void setHabitacionSeleccionada(habitacion *) = 0;

    virtual void setNombreHostal(string) = 0;
    virtual void setDireccionHostal(string) = 0;
    virtual void setTelefonoHostal(string) = 0;
    virtual void confirmarAltaHostal() = 0;
    virtual void cancelarAltaHostal() = 0;
    virtual void liberarMemoriaAltaHostal() = 0;

    virtual mapColHostalesCal solicitarListaHostalesCal() = 0;
    virtual mapColHabitaciones habitacionesDispDeHostal(string, DTFecha, DTFecha, bool) = 0;
    virtual void seleccionarHabitacion(int) = 0;
    virtual mapDTHuespedes solicitarDTHuespedes() = 0;
    virtual void seleccionarHuesped(string) = 0;
    virtual void agregarHuesped(string) = 0;
    virtual void confirmarReserva() = 0;
    virtual void cancelarReserva() = 0;
    virtual void liberarMemoriaReserva() = 0;

    virtual mapColDTReservas solicitarReservasDisp(string) = 0;
    virtual void seleccionarReserva(int) = 0;
    virtual void setCheckinEstadia(DTFecha) = 0;
    virtual void confirmarEstadia() = 0;
    virtual void cancelarEstadia() = 0;
    virtual void liberarMemoriaEstadia() = 0;
    
    virtual mapTopTres solicitarTopTresHostales() = 0;
    virtual map<int, DTResenia> detallesHostal(string) = 0;

    virtual mapColEmpleados obtenerListaDeEmpleados() = 0;
    virtual void setEmpleadoSeleccionado(empleado*) = 0;
    virtual void seleccionarEmpleado(string) = 0;
    virtual void confirmarAsignacion() = 0;
    virtual void cancelarAsignacion() = 0;
    virtual void liberarMemoriaAsignacion() = 0;


    virtual void setCheckoutEstadia(DTFecha) = 0;
    virtual mapDTEstadia mostrarEstadiasHuesped(string) = 0;
    virtual void setEstadiaSeleccionada(int) = 0;
    virtual void finalizarEstadia() = 0;

};

#endif