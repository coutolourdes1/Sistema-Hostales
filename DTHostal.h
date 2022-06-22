#ifndef DTHOSTAL
#define DTHOSTAL

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class DTHostal
{
private:
    string nombre, telefono, direccion;

public:
    DTHostal();
    DTHostal(string, string, string);
    string getNombre() const;
    string getDireccion() const;
    string getTelefono() const;
};

#endif

ostream &operator<<(ostream &out, const DTHostal &hostal);
