#ifndef DTHABITACION
#define DTHABITACION

#include <iostream>
using namespace std;

class DTHabitacion{
    private: 
        int numero, capacidad;
        float precio;
    public: 
        DTHabitacion();
        DTHabitacion(int, int, float);
        int getNumero() const;
        int getCapacidad() const;
        float getPrecio() const;
};

ostream &operator<<(ostream &out, const DTHabitacion &hab);

#endif

    