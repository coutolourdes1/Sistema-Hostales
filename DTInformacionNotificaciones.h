#ifndef DTINFORMACIONNOTIFICACIONES
#define DTINFORMACIONNOTIFICACIONES

#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

/* #include "DTHostal.h"
#include "DTResenia.h"
#include "DTReserva.h"
#include "DTHabitacion.h" */

class DTInformacionNotificaciones{
    private: 
        string nombre_autor;
        int calificacion_resenia;
        string comentario_resenia;
        int cod_res;
    public:
        DTInformacionNotificaciones();
        DTInformacionNotificaciones(int, string, int, string);
        string getNombreAutor() const;
        int getCodRes() const;
        int getCalifRes() const;
        string getComentRes() const; 
}; 

ostream &operator<<(ostream &out, const DTInformacionNotificaciones &infoNot);


#endif