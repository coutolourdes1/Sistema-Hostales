#ifndef CONTROLADORCOLECCIONES
#define CONTROLADORCOLECCIONES

#include <string>
#include <iostream>
#include <iterator>
#include <map>

#include "IControladorColecciones.h"

using namespace std;

class controladorColecciones : public IControladorColecciones
{
private:

    static controladorColecciones *instancia;
    colHostales *coleccionHostales;
    colHuespedes *coleccionHuespedes;
    colReservas *coleccionReservas;
    colEstadias *coleccionEstadias;
    colUsuarios *coleccionUsuarios;
    colEmpleados *coleccionEmpleados;
    colRespuestas *coleccionRespuestas;
    colResenias *coleccionResenias;

    controladorColecciones();

public:
    static controladorColecciones *getInstancia();
    colHostales *getColHostales();
    colHuespedes *getColHuespedes();
    colReservas *getColReservas();
    colEstadias *getColEstadias();
    colRespuestas *getColRespuestas();

    colUsuarios *getColUsuarios();
    colEmpleados *getColEmpleados();
    colResenias *getColResenias();
};

#endif