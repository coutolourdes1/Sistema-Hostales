#ifndef RESENIAS
#define RESENIAS

#include "DTResenia.h"
// #include "DTNotificacion.h"
#include "DTFecha.h"
#include "Estadia.h"
#include "Hostal.h"
#include "Respuesta.h"

class estadia;
class hostal;
class respuesta;

class resenia
{

private:
    string comentario;
    int calificacion, numero; // EN EL DCD DECIA HABITACIONES PERO NO ES MUY LOGICO
    DTFecha fecha;
    estadia *estadiaResenia;
    hostal *hostalDeLaResenia;
    respuesta *resp;

public:
    resenia(int, int, string, DTFecha, estadia*, hostal*);
    DTResenia getDTResenia();
    int getCalificacion();
    // string getDireccion();
    string getComentario();
    int getNumero();
    // int getHabitacion();
    DTResenia *getDTResena();
    void setCalificacion(); // quite el enum  como parametro porque no compila
    // void setMensaje(string);
    // void getCalificacion();  esta repetido
    // void getMensaje();
    // bool noTieneRespuesta();
    bool tieneRespuesta();
    // DTResenia *setResenia();
    void setReseniaARespuesta();
    void setRespuesta(respuesta*);
    respuesta* getRespuesta();

    void deleteResenia();
    // DTNotificacion* getDTNotificacion();
};
#endif