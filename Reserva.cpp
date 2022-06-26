#include "Reserva.h"
#include "DTReserva.h"
#include <string>

#include <iostream>
using namespace std;

reserva::reserva(int codigo, DTFecha checkIn, DTFecha checkOut, huesped *huesp, habitacion *hab)
{
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->huesp = huesp;
    this->hab = hab;
    this->estadoReserva = abierta;
}

huesped *reserva::getHuesped()
{
    return huesp;
}

reservaGrupal::reservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, huesped *huesp, habitacion *hab, colHuespedes otrosHuespedes, int canthuespedes) : reserva(codigo, checkIn, checkOut, huesp, hab)
{
    this->canthuespedes = canthuespedes;
    this->otrosHuespedes = new colHuespedes;

    colHuespedes::iterator iterHuesp;
    for (iterHuesp = otrosHuespedes.begin(); iterHuesp != otrosHuespedes.end(); iterHuesp++)
    {
        huesped *h = iterHuesp->second;
        this->otrosHuespedes->insert(pair<string, huesped *>(h->getEmail(), h));
    }
    huesped *h = getHuesped();
    this->otrosHuespedes->insert(pair<string, huesped *>(h->getEmail(), h));
}

reservaIndividual::reservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, huesped *huesp, habitacion *hab, bool pagado) : reserva(codigo, checkIn, checkOut, huesp, hab)
{
    this->pagado = pagado;
}

int reserva::getCodigo()
{
    return codigo;
}

DTFecha reserva::getCheckIn()
{
    return checkIn;
}

DTFecha reserva::getCheckOut()
{
    return checkOut;
}

bool reserva::solapa(DTFecha inicio, DTFecha fin)
{
    bool solapaInicio = (inicio.diferencia(checkIn) >= 0) && (inicio.diferencia(checkOut) <= 0);
    bool solapaFin = (fin.diferencia(checkIn) >= 0) && (fin.diferencia(checkOut) <= 0);
    bool solapaTotal = (inicio.diferencia(checkIn) <= 0) && (fin.diferencia(checkOut) >= 0);
    return solapaInicio || solapaFin || solapaTotal;
}

colEstadias reserva::getColEstadias(){
    return est;
}

colDTEstadias reserva::getColDTEstadias(){
    colDTEstadias DTEstadiasReservas;
    colEstadias::iterator itEst;

    for (itEst = est.begin(); itEst != est.end(); itEst++){
        estadia *e = itEst->second;
        DTEstadia dte = e->getDTEstadia();
        DTEstadiasReservas.insert(pair<int, DTEstadia>(e->getNumeroEstadia(), dte));
    }
    return DTEstadiasReservas;

}

DTReserva reservaGrupal::getDTReserva(){
    mapColDTHuespedes otrosHuesp;
    colHuespedes::iterator iterHuesp;
    for(iterHuesp = otrosHuespedes->begin(); iterHuesp != otrosHuespedes->end(); iterHuesp++){
        huesped* h = iterHuesp->second;
        otrosHuesp.insert(pair<string, DTHuesped> (h->getEmail(), h->getDTHuesped()));
    }

    return DTReservaGrupal(getCodigo(), getCheckIn(), getCheckOut(), getHuesped()->getDTHuesped(), getHabitacion()->getDTHabitacion(), otrosHuesp);
}

DTReserva reservaIndividual::getDTReserva(){
    return DTReservaIndividual(getCodigo(), getCheckIn(), getCheckOut(), getHuesped()->getDTHuesped(), getHabitacion()->getDTHabitacion(), pagado);
}

void reserva::agregarEstadia(estadia *est)
{
    int numEstadia = est->getNumeroEstadia();
    this->est.insert(pair<int, estadia *>(numEstadia, est));
}

habitacion* reserva::getHabitacion(){
    return hab;
}

void reserva::setEstadoReserva(estado status){
    this->estadoReserva = status;
}

estado reserva::getEstadoReserva(){
    return estadoReserva;
}

colHuespedes* reservaGrupal::getHuespedesReservaGrupal(){
    return otrosHuespedes;
}

void reservaGrupal::eliminarHuespedes(){
    int codigoReserva = getCodigo();
    colHuespedes::iterator iterHuesp;

    for(iterHuesp = otrosHuespedes->begin(); iterHuesp != otrosHuespedes->end(); iterHuesp++){
        huesped* h = iterHuesp->second;
        h->borrarReservaQuePertenece(codigoReserva);
    }

    getHuesped()->borrarReservaRealizada(codigoReserva);

    delete otrosHuespedes;
}

void reservaIndividual::eliminarHuespedes(){
    int codigoReserva = getCodigo();
    colHuespedes::iterator iterHuesp;
    getHuesped()->borrarReservaRealizada(codigoReserva);
    getHuesped()->borrarReservaQuePertenece(codigoReserva);
}