#include "ControladorColecciones.h"
#include <string>
#include <iterator>
#include <map>
#include <iostream>
using namespace std;

// colHostal* controladorColecciones::coleccionHostal = new colHostal;
// colEmpleados* controladorColecciones::coleccionEmpleados = new colEmpleados;
// colHuesped* controladorColecciones::coleccionHuesped = new colHuesped;

controladorColecciones* controladorColecciones::instancia = NULL;

controladorColecciones* controladorColecciones::getInstancia(){
    if(instancia == NULL){
        instancia = new controladorColecciones();
    }

    return instancia;
}

controladorColecciones::controladorColecciones(){
    colUsuarios* coleccionUsuarios = new colUsuarios;
    colHuespedes* coleccionHuespedes = new colHuespedes;
    colEmpleados* coleccionEmpleados = new colEmpleados;
    colHostales* coleccionHostales = new colHostales;
    colReservas* coleccionReservas = new colReservas;
    colEstadias* coleccionEstadias = new colEstadias;
    colResenias* coleccionResenias = new colResenias;
    colRespuestas* coleccionRespuestas = new colRespuestas;
    this->coleccionUsuarios = coleccionUsuarios;
    this->coleccionHuespedes = coleccionHuespedes;
    this->coleccionEmpleados = coleccionEmpleados;
    this->coleccionHostales = coleccionHostales;
    this->coleccionReservas = coleccionReservas;
    this->coleccionEstadias = coleccionEstadias;
    this->coleccionResenias = coleccionResenias;
    this->coleccionRespuestas = coleccionRespuestas;
};

// coleccion de hostales
colHostales* controladorColecciones::getColHostales(){
    return coleccionHostales;
};

colEmpleados* controladorColecciones::getColEmpleados(){
    return coleccionEmpleados;
};

colHuespedes* controladorColecciones::getColHuespedes(){
    return coleccionHuespedes;
};

colUsuarios* controladorColecciones::getColUsuarios(){
    return coleccionUsuarios;
}

colReservas* controladorColecciones::getColReservas(){
    return coleccionReservas;
}

colEstadias* controladorColecciones::getColEstadias(){
    return coleccionEstadias;
}

colResenias* controladorColecciones::getColResenias(){
    return coleccionResenias;
}

colRespuestas* controladorColecciones::getColRespuestas(){
    return coleccionRespuestas;
}

// colHabitaciones* controladorColecciones::getColHabitaciones(){
//     return coleccionHabitaciones;
// }