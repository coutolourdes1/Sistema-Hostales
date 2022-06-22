#include "DTHostal.h"
#include <string>
#include <iostream>
using namespace std;

DTHostal::DTHostal() {}

DTHostal::DTHostal(string nombre, string direccion, string telefono)
{
  this->nombre = nombre;
  this->direccion = direccion;
  this->telefono = telefono;
}

string DTHostal::getNombre() const
{
  return this->nombre;
}

string DTHostal::getDireccion() const
{
  return this->direccion;
}

string DTHostal::getTelefono() const
{
  return this->telefono;
}

ostream &operator<<(ostream &out, const DTHostal &hostal)
{
  out << "Nombre: " << hostal.getNombre() << endl;
  out << "Direccion: " << hostal.getDireccion() << endl;
  out << "Telefono: " << hostal.getTelefono() << endl;

  return out;
}
