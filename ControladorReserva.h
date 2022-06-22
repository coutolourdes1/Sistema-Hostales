#ifndef CONTROLADORRESERVA
#define CONTROLADORRESERVA

#include <string>
#include <iterator>
#include <map>
#include <iostream>
using namespace std;

#include "IControladorReserva.h"    

class IControladorReserva;

class controladorReserva: public IControladorReserva{
private:
    static controladorReserva* instancia;
    controladorReserva();

    hostal* hostalSeleccionado;
    reserva* reservaSeleccionada;
    mapColReservas reservasHostal;

public:
    static controladorReserva* getInstancia();
    void agregarReserva(reserva*);
    int getNuevoCodigo();

    //CONSULTA RESERVA
    //se llama a controlador hostal
    colConsultaReserva obtenerReservasdelHostal();

    //CASO DE USO: BAJA RESERVA
    // se usa -> obtenerNombresHostalesRegistrados() de controladorHostales para pedir los nombres de los hostales registrados
    void seleccionarHostal(string);
    mapColReservas listarReservasDeHostal();
    void seleccionarNumeroReserva(int);
    void confirmarBajaReserva();
    void cancelarBajaReserva();
    //Luego, desde el main se le hace un delete a la reserva;
    //liberador de memoria
    void liberarMemoriaBajaReserva();
    //Termina BAJA RESERVA
};

#endif