#ifndef RESERVA
#define RESERVA

#include "DTFecha.h"
#include "DTReserva.h"
// #include "DTEstadia.h"
#include "Estadia.h"
#include "Usuario.h"
#include "Habitacion.h"
#include <set>
#include <map>
#include <string>

using namespace std;

class huesped;
class empleado;
class usuario;
class habitacion;

enum estado
{
    abierta,
    cerrada,
    cancelada
};
typedef map<string, huesped*> colHuespedes;
typedef map<int, DTEstadia> colDTEstadias;

class reserva
{
private:
    int codigo;
    DTFecha checkIn, checkOut;
    estado estadoReserva;
    huesped *huesp;
    habitacion *hab;
    // estadia *Est;
    colEstadias est; // coleccion de estadias de la reserva
    DTFecha fechaRealizada;
public:
    // virtual float calcularCosto();
    // virtual DTReserva getReservas(); // Por que esta funcion devuelve lo mismo qie la de getDTReserva() ?
    // reserva();
    reserva(int, DTFecha, DTFecha, huesped *, habitacion *, DTFecha);
    int getCodigo();
    DTFecha getFechaRealizada();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    estado getEstadoReserva();
    huesped *getHuesped();
    virtual DTReserva getDTReserva() = 0;

    // OPERACIONES FINALIZAR ESTADIA
    habitacion* getHabitacion();
    void setEstadoReserva(estado);
    // virtual DTEstadia getDTEstadia();
    // virtual DTReserva getDTReserva();
    bool solapa(DTFecha, DTFecha);
    // void deleteReserva();

    void agregarEstadia(estadia *);
    colEstadias getColEstadias();
    colDTEstadias getColDTEstadias();

    float virtual calcularCosto() = 0;
    void virtual eliminarHuespedes() = 0;
};

class reservaGrupal : public reserva
{
private:
    colHuespedes *otrosHuespedes;
    int canthuespedes;

public:
    // void ReservaGrupal(int, DTFecha, DTFecha, huesped*, habitacion*, huesped**, int);
    reservaGrupal(int, DTFecha, DTFecha, huesped *, habitacion *, colHuespedes, int, DTFecha);
    colHuespedes* getHuespedesReservaGrupal();
    float calcularCosto(){
        return 0;
    };
    void eliminarHuespedes();
    DTReserva getDTReserva();
    // DTReserva getReservas();
    // DTEstadia getDTEstadia();
    // DTReserva getDTReserva();
    // void registrarEstadia(estadia);
    // DTHuesped agregarOtroshuesp(huesped);
    // set<huesped *> gethuespedes();
    // int getCanthuespedes();
    // void deleteReserva();
};

class reservaIndividual : public reserva
{
private:
    bool pagado;
public:
    reservaIndividual(int, DTFecha, DTFecha, huesped *, habitacion *, bool, DTFecha);
    // void setPagado(bool);
    // bool getPagado();
    DTReserva getDTReserva();
    float calcularCosto(){
        return 0;
    };
    void eliminarHuespedes();
    //  DTReserva getReservas();
    //  DTEstadia getDTEstadia();
    //  DTReserva getDTReserva();
    //  void registrarEstadia(estadia);
    //  void deleteReserva();
};

#endif