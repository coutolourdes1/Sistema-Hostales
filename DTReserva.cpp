#include "DTReserva.h"
#include "DTFecha.h"

#include <string>
#include <iostream>
using namespace std;

DTReserva::DTReserva(){}

DTReserva::DTReserva(int cod, DTFecha checkin, DTFecha checkout, DTHuesped huesp, DTHabitacion hab, DTFecha realizada){
    this->codigo = cod;
    this->checkin = checkin;
    this->checkout = checkout;
    this->huesped = huesp;
    this->habitacion = hab;
    this->fechaRealizada = realizada;
}

int DTReserva::getCodigo() const{
    return codigo;
}

DTFecha DTReserva::getFechaRealizada() const{
    return fechaRealizada;
}

DTFecha DTReserva::getCheckin() const{
    return checkin;
}

DTFecha DTReserva::getCheckout() const{
    return checkout;
}

DTHuesped DTReserva::getDTHuesped() const {
    return huesped;
}

DTHabitacion DTReserva::getDTHabitacion() const {
    return habitacion;
}

mapColDTHuespedes DTReservaGrupal::getColHuespedes() const {
    return otrosHuespedes;
}

DTReservaGrupal::DTReservaGrupal(int cod, DTFecha checkIn, DTFecha checkout, DTHuesped huesp, DTHabitacion hab, mapColDTHuespedes otrosHuesp, DTFecha realizada) : DTReserva(cod, checkIn, checkout, huesp, hab, realizada){
    this->otrosHuespedes = otrosHuesp;
}

bool DTReservaIndividual::getEstaPagada() const {
    return pagada;
}

DTReservaIndividual::DTReservaIndividual(int cod, DTFecha checkIn, DTFecha checkout, DTHuesped huesp, DTHabitacion hab, bool estaPagada, DTFecha realizada) : DTReserva(cod, checkIn, checkout, huesp, hab, realizada){
    this->pagada = estaPagada;
}

ostream &operator<<(ostream &out, const DTReservaGrupal &resGrupal){
    out << "Tipo de reserva: GRUPAL" << endl;
    out << "Código Reserva: " << resGrupal.getCodigo() << endl;
    out << "CheckIn: " << resGrupal.getCheckin() << endl;
    out << "CheckOut: " << resGrupal.getCheckout() << endl;
    out << "Datos de la habitacion: " << endl << resGrupal.getDTHabitacion() << endl;
    out << "Datos del huesped que la realizó: " << endl << resGrupal.getDTHuesped() << endl;
    out << "Fecha de creación de la reserva: " << resGrupal.getFechaRealizada() << endl;
    out << "Datos de los huespedes incluidos en la reserva: " << endl;

    mapColDTHuespedes otrosHuesp = resGrupal.getColHuespedes();
    mapColDTHuespedes::iterator iterHuesp;

    for (iterHuesp = otrosHuesp.begin(); iterHuesp != otrosHuesp.end(); iterHuesp++){
        out << iterHuesp->second << endl;
    }

    return out;
}

ostream &operator<<(ostream &out, const DTReservaIndividual &resIndividual){
    out << "Tipo de reserva: INDIVIDUAL" << endl;
    out << "Código Reserva: " << resIndividual.getCodigo() << endl;
    out << "CheckIn: " << resIndividual.getCheckin() << endl;
    out << "CheckOut: " << resIndividual.getCheckout() << endl;
    out << "Datos Habitacion: " << endl << resIndividual.getDTHabitacion() << endl;
    out << "Datos Huesped que la realizó: " << endl << resIndividual.getDTHuesped() << endl;
    out << "Fecha de creación de la reserva: " << resIndividual.getFechaRealizada() << endl;
    out << "Pagada: ";

    if(resIndividual.getEstaPagada()){
        out << "Si";
    } else {
        out << "No";
    }

    return out;
}

ostream &operator<<(ostream &out, const DTReserva &res){
    out << "Código Reserva: " << res.getCodigo() << endl;
    out << "CheckIn: " << res.getCheckin() << endl;
    out << "CheckOut: " << res.getCheckout() << endl;
    out << "Datos Habitacion: " << endl << res.getDTHabitacion() << endl;
    out << "Fecha de creación de la reserva: " << res.getFechaRealizada() << endl;
    out << "Datos Huesped que la realizó: " << endl << res.getDTHuesped() << endl;

    return out;
}