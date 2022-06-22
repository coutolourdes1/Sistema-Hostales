#include "ControladorEmpleados.h"

#include <string>
#include <iterator>
#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

controladorEmpleado *controladorEmpleado::instancia = NULL;

controladorEmpleado::controladorEmpleado() {}

controladorEmpleado *controladorEmpleado::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new controladorEmpleado();
    }

    return instancia;
}

void controladorEmpleado::setEmpleadoSeleccionado(empleado* emp)
{
    empleadoSeleccionado = emp;
}

empleado* controladorEmpleado::getEmpleadoSeleccionado()
{
    return empleadoSeleccionado;
}

mapComentariosSinResp controladorEmpleado::listaComentariosSinResp(string email)
{
    // Traigo la instancia
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();

    // Traigo la coleccion de empleados y creo un iterador
    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator iterEmp;

    // Buscar en la coleccion el empleado con dicho email
    iterEmp = coleccionEmpleados->find(email);

    if(iterEmp == coleccionEmpleados->end()){
        throw std::invalid_argument("El email ingresado no es correcto");
    }

    empleado *e = iterEmp->second;
    setEmpleadoSeleccionado(e);

    // Pedir comentarios sin respuesta a la clase empleado
    mapComentariosSinResp comentariosSinResp = e->getComentariosSinResp();

    return comentariosSinResp;
}

void controladorEmpleado::responderResenia(int numResenia, string comentarioResp){
    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colResenias* coleccionResenias = controladorColecciones->getColResenias();
    colResenias::iterator iterResenia = coleccionResenias->find(numResenia);

    if(iterResenia == coleccionResenias->end()){
        throw std::invalid_argument("La reseña seleccionada no es correcta");
    }
    resenia* res = iterResenia->second;
    empleado* empleadoSeleccionado = getEmpleadoSeleccionado();

    colRespuestas* coleccionRespuestas = controladorColecciones->getColRespuestas();

    int nuevoNumRespuesta;
    if(coleccionRespuestas->size() == 0){
        nuevoNumRespuesta = 1;
    } else {
        colRespuestas::iterator iterRespuesta = coleccionRespuestas->end();
        iterRespuesta--;

        nuevoNumRespuesta = iterRespuesta->second->getNumeroRespuesta() + 1;
    }

    respuesta* resp = new respuesta(nuevoNumRespuesta, comentarioResp, res, empleadoSeleccionado);

    res->setRespuesta(resp);
    empleadoSeleccionado->agregarRespuesta(resp);

    coleccionRespuestas->insert(pair<int, respuesta*> (resp->getNumeroRespuesta(), resp));

    liberarMemoriaRespuesta();
}

void controladorEmpleado::liberarMemoriaRespuesta(){
    setEmpleadoSeleccionado(NULL);
}




// CASO DE USO SUSCRIBIRSE A NOTIFICACIONES

mapDTEmpleado controladorEmpleado::listarEmpleados(){
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados* coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator itEmp;

    mapDTEmpleado listaEmp;

    for (itEmp = coleccionEmpleados->begin(); itEmp != coleccionEmpleados->end(); ++itEmp){
        empleado* aux = itEmp->second;
        listaEmp.insert(pair<string, DTEmpleado>(aux->getEmail(),aux->getDTEmpleado()));
    }

    return listaEmp;
}


void controladorEmpleado::seleccionarEmpleadoANotificar(string email_empleado){
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados* coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator itEmp;
    itEmp = coleccionEmpleados->find(email_empleado);
    empleado* e = itEmp->second;
    controladorResenia *controladorResenia = controladorResenia::getInstancia();
    controladorResenia->agregarObservador(e);
}

//CASO DE USO CONSULTA DE NOTIFICACIONES

mapInfoNotificaciones controladorEmpleado::getInfoNotificaciones(string email){

    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados* coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator itEmp;
    itEmp = coleccionEmpleados->find(email);
    empleado* e = itEmp->second;

    mapInfoNotificaciones retornoNotificaciones = e->mostrarDTInfoNotificaciones();
    e->eliminarNotificaciones();
    
    return retornoNotificaciones;
    
} 


// CASO DE USO ELIMINAR SUSCRIPCION
void controladorEmpleado::seleccionarEmpleadoADesNotificar(string email_empleado){
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados* coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator itEmp;
    itEmp = coleccionEmpleados->find(email_empleado);
    empleado* e = itEmp->second;
    controladorResenia *controladorResenia = controladorResenia::getInstancia();
    controladorResenia->eliminarObservador(e);
}  