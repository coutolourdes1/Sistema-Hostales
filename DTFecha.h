#ifndef DTFECHA
#define DTFECHA

#include <iostream>
using namespace std;

class DTFecha
{
private:
    int dia, mes, anio;
    //int hora;
public:
    DTFecha();
    DTFecha(int, int, int);
    //DTFecha(int, int, int, int);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    //int getHora();
    DTFecha avanzar(int);
    DTFecha retroceder(int);
    int diferencia(DTFecha);
    bool igual(DTFecha);
};

ostream &operator<<(ostream &out, const DTFecha &fecha);

#endif