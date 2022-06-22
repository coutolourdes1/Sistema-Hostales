#include "DTHuesped.h"
#include <string>

#include <iostream>
using namespace std;

DTUsuario::DTUsuario()
{
}

DTUsuario::DTUsuario(string name, string email, string password)
{
    this->nombre = name;
    this->email = email;
    this->password = password;
}

string DTUsuario::getNombre() const
{
    return nombre;
}

string DTUsuario::getEmail() const
{
    return email;
}

string DTUsuario::getPassword() const
{
    return password;
}

ostream &operator<<(ostream &out, const DTUsuario &usuario)
{
    out << "Nombre: " << usuario.getNombre() << endl;
    out << "Email: " << usuario.getEmail() << endl;

    return out;
}