#include "Hostal.h"
#include "Resenia.h"
#include <string>
#include <iterator>
#include <map>
#include "ControladorColecciones.h"
#include <iostream>
using namespace std;

hostal::hostal(string nombre, string dir, string tel)
{
    this->nombre = nombre;
    this->telefono = tel;
    this->direccion = dir;

    colResenias *resenias = new colResenias();
    this->resenias = resenias;
    this->empDelHostal = new empleadosDelHostal();
    colHabitaciones *habitacionesDelHostal = new colHabitaciones();
    this->habitacionesDelHostal = habitacionesDelHostal;
}

string hostal::getNombreHostal()
{
    return nombre;
}

string hostal::getTelHostal()
{
    return telefono;
}
string hostal::getDireccionHostal()
{
    return direccion;
}

colHabitaciones *hostal::getHabitaciones()
{
    return habitacionesDelHostal;
}

DTHostal hostal::getDTHostal()
{
    return DTHostal(getNombreHostal(), getDireccionHostal(), getTelHostal());
}

void hostal::agregarHabitacion(habitacion *hab)
{
    habitacionesDelHostal->insert(pair<int, habitacion *>(hab->getNumero(), hab));
}

void hostal::agregarEmpleado(empleado *e)
{
    empDelHostal->insert(pair<string, empleado *>(e->getEmail(), e));
}

colResenias *hostal::getColResenias()
{
    return resenias;
}

mapColResenias hostal::getDTResenias()
{
    mapColResenias DTResenias;

    colResenias::iterator iterResenia;
    colResenias *resenias = getColResenias();

    for (iterResenia = resenias->begin(); iterResenia != resenias->end(); iterResenia++)
    {
        DTResenia DTRes = iterResenia->second->getDTResenia();
        DTResenias.insert(pair<int, DTResenia>(DTRes.getNumero(), DTRes));
    }

    return DTResenias;
}

mapColHabitaciones hostal::getHabitacionesDisp(DTFecha checkIn, DTFecha checkOut)
{
    mapColHabitaciones habitaciones;
    colHabitaciones::iterator iterHabs;

    for (iterHabs = habitacionesDelHostal->begin(); iterHabs != habitacionesDelHostal->end(); iterHabs++)
    {
        habitacion *hab = iterHabs->second;

        if (hab->estaHabDisponible(checkIn, checkOut))
        {
            habitaciones.insert(pair<int, DTHabitacion>(hab->getNumero(), hab->getDTHabitacion()));
        }
    }

    return habitaciones;
}

void hostal::agregarAColResenias(resenia *res)
{
    getColResenias()->insert(pair<int, resenia *>(res->getNumero(), res));
}

map<int, string> hostal::darComentariosSinResp()
{
    // Traigo la instancia
    // controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();

    // Traigo la coleccion de resenias y creo un iterador
    colResenias *coleccionResenias = getColResenias();
    colResenias::iterator iterResenias;

    // Creo un map que tendra comentarios
    map<int, string> reseniasSinComen;

    // Recorro la coleccion de resenias y si no tiene respuesta los agrego al map anterior
    for (iterResenias = coleccionResenias->begin(); iterResenias != coleccionResenias->end(); iterResenias++)
    {
        if (!(iterResenias->second->tieneRespuesta())) // Condicion = No existe link entre resenia y respuesta
        {
            reseniasSinComen.insert(pair<int, string>(iterResenias->second->getNumero(), iterResenias->second->getComentario()));
        }
    }
    return reseniasSinComen;
}

DTHostalCalificado hostal::getDTHostalCalificado()
{
    colResenias::iterator iterResenias;

    float promCalificaciones = 0;

    for (iterResenias = resenias->begin(); iterResenias != resenias->end(); iterResenias++)
    {
        promCalificaciones += iterResenias->second->getCalificacion();
    }

    if (resenias->size() > 0)
    {
        promCalificaciones = promCalificaciones / resenias->size();
    }
    else
    {
        promCalificaciones = -1;
    }

    return DTHostalCalificado(getNombreHostal(), getDireccionHostal(), promCalificaciones);
}

void hostal::eliminarResenia(int numResenia){
    resenias->erase(numResenia);
}