#include "Estadia.h"
#include "DTFecha.h"
#include "Usuario.h"
#include "Reserva.h"
#include "ControladorEstadia.h"
#include <string>

#include <iostream>
using namespace std;

estadia::estadia(huesped *huesp, reserva *res, DTFecha checkIn)
{
    this->huesp = huesp;
    this->res = res;
    this->checkIn = checkIn;
    this->checkOut = DTFecha();

    numeroEstadia = controladorEstadia::getInstancia()->getNuevoNumero();

    // Asignar checkIn y checkOut con la fecha actual del sistema
}

DTEstadia estadia::getDTEstadia()
{
    return DTEstadia(huesp->getDTHuesped(), checkIn, checkOut, numeroEstadia);
}

int estadia::getNumeroEstadia()
{
    return numeroEstadia;
}

void estadia::setHuesped(huesped *huesp)
{
    this->huesp = huesp;
}

void estadia::setReserva(reserva *res)
{
    this->res = res;
}

reserva *estadia::getReserva()
{
    return res;
}

DTFecha estadia::getCheckin(){
    return checkIn;
}

DTFecha estadia::getCheckOut(){
    return checkOut;
}

void estadia::setCheckout(DTFecha checkout){
    this->checkOut = checkout;
}
void estadia::setFinalizada()
{
    this->finalizada = true;
}

bool estadia::getFinalizada()
{
    return finalizada;
}

resenia *estadia::getResenia()
{
    return reseniaDeEstadia;
}

void estadia::setResenia(resenia *reseni)
{
    reseniaDeEstadia = reseni;
}

void estadia::eliminarEstadia(){
    huesp->borrarEstadia(getNumeroEstadia());
    reseniaDeEstadia->deleteResenia();
    delete reseniaDeEstadia;
}

huesped* estadia::getHuespedEstadia(){
    return huesp;
}

DTHuesped estadia::getDTHuespedEstadia(){
    DTHuesped dth = DTHuesped(huesp->getNombre(), huesp->getEmail(), huesp->getPassword(), huesp->getEsFinger());
    return dth;
}