#ifndef CONTROLADORHOSTALES
#define CONTROLADORHOSTALES

#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <set>

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

#include "IControladorHostales.h"

class controladorHostales : public IControladorHostales {
private:
    static controladorHostales *instancia;
    int numHabSeleccionada;
    huesped *huespedSeleccionado;
    hostal *hostalSeleccionado;
    habitacion *habitacionSeleccionada;
    empleado* empleadoSeleccionado;
    estadia* estadiaSeleccionada;

    bool esGrupal;
    DTFecha checkIn, checkOut;
    mapColHabitaciones habitacionesDisp;
    mapColHuespedes otrosHuespedes;
    mapColEmpleados listaEmpleados;
    mapDTEstadia mapaDTEstadia;
    DTFecha checkinEstadia, checkoutEstadia;

    // Atributos para nuevo hostal
    string nombreHostal, direccionHostal, telefonoHostal;

    // Atributos para alta habitacion
    int numeroHabitacion, capacidadHabitacion;
    float precioHabitacion;

    // Atributos para REGISTRAR ESTADIA
    int numReservaSeleccionada;

    map<string, hostal *> *hostales;  // se conecta con Hostales con *
    map<string, resenia *> *resenias; // se conecta con Resenias con * que sea set, o key int
    // map<string, reserva*> *reservas; //se conecta con Reservas con *
    map<bool, empleado *> *empleados; // se conecta con Empleado con *, key bool de no es finger
    // ControladorEstadia *estadias; //se conecta con Controlador estadia con 1
    map<int, habitacion *> *habitaciones; // se conecta con Habitaciones con *
    controladorHostales();

public:
    static controladorHostales *getInstancia();

    // CASO DE USO: CONSULTA HOSTAL
    setNombreHostales obtenerNombresHostalesRegistrados();
    DTInformacionHostal obtenerInformacionHostal(string);
    // TERMINA CONSULTA HOSTAL

    // CASO DE USO: ALTA HABITACION
    mapColDTHostales obtenerHostalesRegistrados();
    void seleccionarHostal(string);
    void setNumeroHabitacion(int);
    void setCapacidadHabitacion(int);
    void setPrecioHabitacion(float);
    void confirmarAltaHabitacion();
    void cancelarAltaHabitacion();
    // liberador de memoria:
    void liberarMemoriaAltaHabitacion();
    // TERMINA ALTA HABITACION

    // Getters para Realizar Reserva
    int getNumHabSeleccionada();
    huesped *getHuespedSeleccionado();
    hostal *getHostalSeleccionado();
    bool getEsGrupal();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    habitacion *getHabitacionSeleccionada();

    // Setters para Realizar Reserva
    void setHuespedSeleccionado(huesped *);
    void setHostalSeleccionado(hostal *);
    void setEsGrupal(bool);
    void setFechas(DTFecha, DTFecha);
    void setHabDisp(mapColHabitaciones);
    void setHabitacionSeleccionada(habitacion *);

    // CASO DE USO: ALTA HOSTAL
    void setNombreHostal(string);
    void setDireccionHostal(string);
    void setTelefonoHostal(string);
    void confirmarAltaHostal();
    void cancelarAltaHostal();
    // liberador de memoria:
    void liberarMemoriaAltaHostal();
    // TERMINA ALTA HOSTAL

    // CASO DE USO: REALIZAR RESERVA
    mapColHostalesCal solicitarListaHostalesCal();
    //seleccionar hostal
    mapColHabitaciones habitacionesDispDeHostal(string, DTFecha, DTFecha, bool);
    void seleccionarHabitacion(int);
    mapDTHuespedes solicitarDTHuespedes();
    void seleccionarHuesped(string);
    void agregarHuesped(string); // Reserva Grupal
    void confirmarReserva(DTFecha);
    void cancelarReserva();
    // liberador de memoria
    void liberarMemoriaReserva();
    // TERMINA REALIZAR RESERVA

    // CASO DE USO: REGISTRAR ESTADIA
    // se usa -> void obtenerHostalesRegistrados()
    // se usa -> void seleccionarHostal(string)
    mapColDTReservas solicitarReservasDisp(string);
    void seleccionarReserva(int);
    void setCheckinEstadia(DTFecha);
    void confirmarEstadia();
    void cancelarEstadia();
    // liberador de memoria
    void liberarMemoriaEstadia();
    // TERMINA REGISTRAR ESTADIA

    // CASO DE USO: TOP 3 HOSTALES
    mapTopTres solicitarTopTresHostales();
    map<int, DTResenia> detallesHostal(string nombre);
    // TERMINA TOP 3 HOSTALES

    //CASO DE USO ASIGNAR EMPLEADO A HOSTAL
    // se usa -> void obtenerHostalesRegistrados()
    // se usa -> void seleccionarHostal(string)
    mapColEmpleados obtenerListaDeEmpleados();
    void setEmpleadoSeleccionado(empleado*);
    void seleccionarEmpleado(string);
    void confirmarAsignacion();
    void cancelarAsignacion();
    // liberador de memoria
    void liberarMemoriaAsignacion();

    // termina asignar empleado a hostal


    //FINALIZAR ESTADIA
    // se usa -> void obtenerHostalesRegistrados()
    // se usa -> void seleccionarHostal(string)
    void setCheckoutEstadia(DTFecha);
    mapDTEstadia mostrarEstadiasHuesped(string);
    void setEstadiaSeleccionada(int);
    void finalizarEstadia();

};

#endif