#ifndef HOSTAL
#define HOSTAL

#include "DTHostal.h"
#include "DTHabitacion.h"
//#include "DataTypes/DTResenia.h"
// #include "Estadia.h"
#include "Habitacion.h"
#include "Resenia.h"
#include "DTResenia.h"
#include "Usuario.h"
#include "DTHostalCalificado.h"
#include "ControladorColecciones.h"
#include "ControladorEmpleados.h"

#include <string>
#include <iostream>
#include <map>
using namespace std;

class habitacion;

typedef map<int, resenia *> colResenias;
typedef map<int, habitacion *> colHabitaciones;
typedef map<int, DTHabitacion> mapColHabitaciones;
typedef map<int, DTResenia> mapColResenias;
typedef map<string, empleado *> empleadosDelHostal;
typedef map<int, string> mapComentariosSinResp;


class hostal
{
private:
    string nombre, telefono;
    string direccion;
    colHabitaciones *habitacionesDelHostal;
    empleadosDelHostal *empDelHostal;
    colResenias *resenias;

public:
    hostal(string, string, string);

    DTHostal getDTHostal();
    string getNombreHostal();
    string getTelHostal();
    string getDireccionHostal();
    colHabitaciones *getHabitaciones();
    mapColHabitaciones getHabitacionesDisp(DTFecha, DTFecha);
    mapColResenias getDTResenias();
    void eliminarResenia(int);

    DTHostalCalificado getDTHostalCalificado();
    // void printHostal();
    void agregarHabitacion(habitacion *);
    void agregarEmpleado(empleado *);

    // Operacion necesaria para Comentar Calificacion
    mapComentariosSinResp darComentariosSinResp();

    // DTHostal getDTHostal();
    // DTHostal getHostal(string);
    // set<estadia> estadiasHostalFinalizadas(string);
    // map<string, DTResenia> getDTReservasSinResp();
    // int getPromCal();
    colResenias *getColResenias();
    void agregarAColResenias(resenia *);
};

#endif