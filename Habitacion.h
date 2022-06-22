#ifndef HABITACION
#define HABITACION

#include "DTHabitacion.h"
#include "DTFecha.h"
#include "DTHuesped.h"
#include "Reserva.h"
#include "Hostal.h"

#include <map>
class reserva;
class hostal;

typedef map<int, reserva*> colReservas;
typedef map<int, DTReserva> colDTReservas;

class habitacion{
    private:
        int numero, capacidad;
        float precio;

        colReservas reservasHabitacion;
        colReservas* reservas;
        hostal* hostalDeHabitacion;
    public:
        habitacion(int, float, int, hostal*);
        int getNumero();
        int getCapacidad();
        float getPrecio();
        bool estaHabDisponible(DTFecha, DTFecha);
        DTHabitacion getDTHabitacion();
        void agregarReservaACol(reserva*);
        hostal* getHostalDeHabitacion();
        colReservas getReservasHabitacion();
        colDTReservas getDTReservasHabitacion();
        void eliminarReservaDeHabitacion(int);
        // reservaGrupal* crearReservaGrupal(DTHuesped, DTFecha, DTFecha);
        // reservaIndividual* crearReservaIndividual(DTHuesped, DTFecha, DTFecha);
};

#endif