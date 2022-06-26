#include "DTHostalCalificado.h"
#include "ControladorColecciones.h"

DTHostalCalificado::DTHostalCalificado(){}

DTHostalCalificado::DTHostalCalificado(string nombre, string direccion, float promedioCalificaciones){
    this->nombre = nombre;
    this->direccion = direccion;
    this->promedioCalificaciones = promedioCalificaciones;
};

string DTHostalCalificado::getNombre() const{
    return nombre;
}

string DTHostalCalificado::getDireccion() const{
    return direccion;
}

float DTHostalCalificado::getPromedioCalificaciones() const{
    return promedioCalificaciones;
}

ostream &operator<<(ostream &out, const DTHostalCalificado &hosCal){

    out << "Nombre: " << hosCal.getNombre() << endl;
    out << "Direccion: " << hosCal.getDireccion() << endl;
    out << "Promedio de Calificaciones: ";

    if(hosCal.getPromedioCalificaciones() == -1){
        out << "El hostal no tiene calificaciones" << endl;
    } else {
        out << hosCal.getPromedioCalificaciones() << endl;
    }

    return out;
}
