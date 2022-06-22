#ifndef CONTROLADORESTADIA
#define CONTROLADORESTADIA

#include <string>
#include <iterator>
#include <map>
#include <iostream>
using namespace std;

#include "IControladorEstadia.h"

class controladorEstadia : public IControladorEstadia{
private:
    static controladorEstadia *instancia;
    controladorEstadia();

    hostal *hostalSeleccionado;
    huesped *huespedSeleccionado;

    estadia *estadiaSeleccionada;

public:
    static controladorEstadia *getInstancia();

    // CASO DE USO: CALIFICAR ESTADIA
    //  se usa -> controladorHostales::listarHostalesRegistrdos();
    void seleccionarHostal(string);
    mapColEstadias listarEstadiasFinalizadasHuesped(string);
    void seleccionarEstadia(int);
    void agregarCalificacion(string, float, DTFecha);
    // liberador de memoria
    void liberarMemoriaCalificacion();
    // CALIFICAR ESTADIA

    //Getters para CALIFICAR ESTADIA
    estadia *getEstadiaSeleccionada();

    // CASO DE USO CONSULTA ESTADIA 
    mapColEstadias listarEstadias();
    //void seleccionarEstadia(int);
    mapColInfoEstadia informacionEstadia();
    DTReserva informacionReservaAsociada();

    int getNuevoNumero();
};

#endif