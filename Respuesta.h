#ifndef RESPUESTA
#define RESPUESTA

#include <string>
#include "Resenia.h"
#include "Usuario.h"

class resenia;
class empleado;

using namespace std;

class respuesta{
    private:
        string resp;
        resenia* res;
        empleado* emp;
        int numeroRespuesta;
    public:
        respuesta(int, string, resenia*, empleado*);
        string getRespuesta();
        resenia* getResenia();
        empleado* getEmpleado();
        int getNumeroRespuesta();
        void eliminarRespuesta();
};

#endif