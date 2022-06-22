#ifndef DTRESENIA
#define DTRESENIA

#include "DTFecha.h"
//#include "cargoEmpleado.h"
#include <string>
#include <iostream>
using namespace std;

class DTResenia
{
private:
    int numero;
    int calificacion;
    string comentario;
    DTFecha fecha;
    int numHabitacion;

public:
    DTResenia();
    DTResenia(int, int, string, DTFecha, int);
    int getNumero() const;
    int getNumeroHabitacion() const;
    int getCalificacion() const;
    string getComentario() const;
    DTFecha getFecha() const;
};

ostream &operator<<(ostream &out, const DTResenia &resenia);

#endif