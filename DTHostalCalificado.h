#ifndef DTHOSTALCALIFICADO
#define DTHOSTALCALIFICADO

#include <string>
#include <iostream>
#include <iterator>
#include <set>

#include "DTHostal.h"
#include "DTResenia.h"

using namespace std;

class DTHostalCalificado{
    private: 
        string nombre, direccion;
        float promedioCalificaciones;
    public: 
        DTHostalCalificado();
        DTHostalCalificado(string, string, float);
        string getNombre() const;
        string getDireccion() const;
        float getPromedioCalificaciones() const;
};

ostream &operator<<(ostream &out, const DTHostalCalificado &hosCal);


#endif
