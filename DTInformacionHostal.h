#ifndef DTINFORMACIONHOSTAL
#define DTINFORMACIONHOSTAL
#include "DTHostal.h"
#include "DTResenia.h"
#include "DTHabitacion.h"
#include "DTHostalCalificado.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

// #include "DTResenaAmpliada.h"
typedef map<int, DTResenia> colDTResenias;

class DTInformacionHostal
{
private:
    DTHostalCalificado hostalCalificado;
    colDTResenias resenias;
    float promedioCalificaciones;

    // DTHostal* hostal;
    // DTResena* resena;
    // DTHostal* hostales;
    // DTResenaAmpliada* resenaAmpliada;
public:
    DTInformacionHostal(DTHostalCalificado, colDTResenias, float);
    string getNombreHostal() const;
    DTHostalCalificado getDTHostalCalificado() const; 
    float getPromedioCalificaciones() const;

    colDTResenias getDTColResenias() const;
    // DTHostal* getDTHostal();
    // DTResena* getDTResena();

    // DTHostal getDTHostal();
    // DTResenaAmpliada getDTResenaAmpliada();
};

#endif

ostream &operator<<(ostream &out, const DTInformacionHostal &infoHostal);
