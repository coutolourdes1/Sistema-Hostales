#include "DTHuesped.h"
#include <string>

#include <iostream>
using namespace std;

DTHuesped::DTHuesped(){
}


DTHuesped::DTHuesped(string name, string email, string password, bool esF) : DTUsuario(name, email, password)
{
    this->esFinger = esF;
}

bool DTHuesped::getEsFinger() const
{
    return this->esFinger;
}

ostream &operator<<(ostream &out, const DTHuesped &huesped){
    out << "Nombre: " << huesped.getNombre() << endl;
    out << "Email: " << huesped.getEmail() << endl;

    if(huesped.getEsFinger()){
        out << "Es Finger";
    } else {
        out << "No es Finger";
    }

    return out;
}