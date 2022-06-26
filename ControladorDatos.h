#ifndef CONTROLADORDATOS
#define CONTROLADORDATOS

#include <string>
#include <iostream>
#include <iterator>
#include <map>


using namespace std;

class controladorDatos{

private:
    static controladorDatos *instancia;
    controladorDatos();

public:
    static controladorDatos *getInstancia();
    
    void AgregarHuesped();
    void AgregarEmpleado();
    void AgregarHostales();
    void AgregarHabitaciones();
    void AgregarEmpleadoAHostel();
    void AgregarReservas();
    void AgregarEstadias();
    void AgregarFinalizarEstadia();
    void AgregarCalificacionesEstadia();
    void AgregarComentarCalificacion();


};

#endif