#include "DTEmpleado.h"

#include <string>
#include <iostream>
using namespace std;

DTEmpleado::DTEmpleado(string nombre, string email, string password, string cargo, mapColHostales hostalesQueTrabaja) : DTUsuario(nombre, email, password)
{
    this->cargo = cargo;
    this->hostalesQueTrabaja = hostalesQueTrabaja;
}

mapColHostales DTEmpleado::getHostalesQueTrabaja()
{
    return hostalesQueTrabaja;
}

string DTEmpleado::getCargo() const
{
    return cargo;
}

ostream &operator<<(ostream &out, const DTEmpleado &empleado)
{
    out << "Nombre: " << empleado.getNombre() << endl;
    out << "Email: " << empleado.getEmail() << endl;
    out << "Cargo: " << empleado.getCargo();

    return out;
}
