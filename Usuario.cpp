#include "Usuario.h"
#include "DTResenia.h"
#include "DTInformacionNotificaciones.h"
#include <string>
#include <iterator>
#include <map>
#include <iostream>

using namespace std;

usuario::usuario(string nombre, string email, string password)
{
    this->nombre = nombre;
    this->email = email;
    this->password = password;
}

string usuario::getNombre()
{
    return nombre;
}

string usuario::getEmail()
{
    return email;
}

string usuario::getPassword()
{
    return password;
}

/* string usuario::setNombre(string nombre){
    this->nombre = nombre;
}

string usuario::setEmail(string email){
    this->email = email;
}

string usuario::setPassword(string contr){
    this->password = contr;
}
 */
huesped::huesped(string nombre, string email, string password, bool esFinger) : usuario(nombre, email, password)
{
    this->esFinger = esFinger;
}

bool huesped::getEsFinger()
{
    return esFinger;
}

void huesped::agregarReservaACol(reserva *res)
{
    colReservasRealizadas.insert(pair<int, reserva *>(res->getCodigo(), res));
}

void huesped::agregarReservaAPertenecientes(reserva *res)
{
    colReservasQuePertenece.insert(pair<int, reserva *>(res->getCodigo(), res));
}

colReservas huesped::getColReservasQuePertenece()
{
    return colReservasQuePertenece;
}

DTHuesped huesped::getDTHuesped()
{
    string nombre = this->getNombre();
    string email = this->getEmail();
    string password = this->getPassword();

    return DTHuesped(nombre, email, password, esFinger);
}

void huesped::agregarEstadia(estadia *est)
{
    estadiasDelHuesped.insert(pair<int, estadia *>(est->getNumeroEstadia(), est));
}

reserva *huesped::getReserva(int numeroRes)
{
    colReservas reservasQuePertenece = getColReservasQuePertenece();
    colReservas::iterator iterRes = reservasQuePertenece.find(numeroRes);

    if (iterRes != reservasQuePertenece.end())
    {
        return iterRes->second;
    }
    else
    {
        throw std::invalid_argument("El numero de reserva seleccionado no es correcto");
    }
}

colEstadias huesped::getColEstadias()
{
    return estadiasDelHuesped;
}

void huesped::borrarReservaRealizada(int codigoReserva){
    colReservasRealizadas.erase(codigoReserva);
}

void huesped::borrarReservaQuePertenece(int codigoReserva){
    colReservasQuePertenece.erase(codigoReserva);
}

void huesped::borrarEstadia(int numEstadia){
    estadiasDelHuesped.erase(numEstadia);
}

empleado::empleado(string nombre, string email, string password, string cargo) : usuario(nombre, email, password)
{
    this->cargo = cargo;
    colHostales hostalesQueTrabaja;
    this->hostalesQueTrabaja = hostalesQueTrabaja;
    colRespuestas colRespuestasVacio;
    this->respuestasRealizadas = colRespuestasVacio;
    mapInfoNotificaciones mapNotificacionesEmpVacio;
    this->mapNotificacionesEmp = mapNotificacionesEmpVacio;

}

string empleado::getCargo()
{
    return cargo;
}

colHostales empleado::getHostalesQueTrabaja()
{
    return hostalesQueTrabaja;
}

void empleado::agregarHostalQueTrabaja(hostal *h)
{
    hostalesQueTrabaja.insert(pair<string, hostal *>(h->getNombreHostal(), h));
}

mapColHostales empleado::getDTHostalesQueTrabaja()
{
    mapColHostales DTHostalesQueTrabaja;
    colHostales::iterator iterHostal;

    for (iterHostal = hostalesQueTrabaja.begin(); iterHostal != hostalesQueTrabaja.end(); iterHostal++)
    {
        hostal *h = iterHostal->second;
        DTHostalesQueTrabaja.insert(pair<string, DTHostal>(h->getNombreHostal(), h->getDTHostal()));
    }
    return DTHostalesQueTrabaja;
}

DTEmpleado empleado::getDTEmpleado()
{
    string nombre = this->getNombre();
    string email = this->getEmail();
    string password = this->getPassword();

    return DTEmpleado(nombre, email, password, cargo, getDTHostalesQueTrabaja());
}

mapComentariosSinResp empleado::getComentariosSinResp()
{
    mapComentariosSinResp comentariosSinResponder;
    colHostales::iterator iterHostal;
    for(iterHostal = hostalesQueTrabaja.begin(); iterHostal != hostalesQueTrabaja.end(); iterHostal++){
        hostal* h = iterHostal->second;
        mapComentariosSinResp comentariosHostal = h->darComentariosSinResp();
        mapComentariosSinResp::iterator iterComentarios;

        for(iterComentarios = comentariosHostal.begin(); iterComentarios != comentariosHostal.end(); iterComentarios++){
            comentariosSinResponder.insert(pair<int, string> (iterComentarios->first, iterComentarios->second));
        }
    }
    return comentariosSinResponder;
}

void empleado::agregarRespuesta(respuesta* resp){
    respuestasRealizadas.insert(pair<int, respuesta*> (resp->getNumeroRespuesta(), resp));
}

void empleado::eliminarRespuestaDeEmpleado(int numRespuesta){
    respuestasRealizadas.erase(numRespuesta);
}

void empleado::Notify(DTInformacionNotificaciones infoEmpl){
    mapNotificacionesEmp.insert(pair<int, DTInformacionNotificaciones> (infoEmpl.getCodRes(), infoEmpl));
}

mapInfoNotificaciones empleado::mostrarDTInfoNotificaciones(){
    return mapNotificacionesEmp;
}

void empleado::eliminarNotificaciones(){
    mapNotificacionesEmp.clear();
}