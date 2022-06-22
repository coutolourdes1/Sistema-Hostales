#include "DTInformacionNotificaciones.h"

#include <string>
#include <iostream>
using namespace std;

DTInformacionNotificaciones::DTInformacionNotificaciones(){

}

DTInformacionNotificaciones::DTInformacionNotificaciones(int codi,string nombre, int calif, string com){
    this->nombre_autor = nombre;
    this->calificacion_resenia = calif;
    this->comentario_resenia = com;
    this->cod_res = codi;
}

string DTInformacionNotificaciones::getNombreAutor() const{
    return nombre_autor;
}

int DTInformacionNotificaciones::getCalifRes() const{
    return calificacion_resenia;
}

string DTInformacionNotificaciones::getComentRes() const{
    return comentario_resenia;
}

int DTInformacionNotificaciones::getCodRes() const{
    return cod_res;
}

ostream &operator<<(ostream &out, const DTInformacionNotificaciones &infoNot){
    out << "Nombre del Autor: " << infoNot.getNombreAutor() << ", ";
    out << "Comentario: " << infoNot.getComentRes() << ", ";
    out << "Calificacion:" << infoNot.getCalifRes();
    return out;
}
