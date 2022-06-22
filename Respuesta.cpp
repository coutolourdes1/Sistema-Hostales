#include "Respuesta.h"
#include <string>

#include <iostream>
using namespace std;

respuesta::respuesta(int numResp, string resp, resenia* res, empleado* emp){
    this->resp = resp;
    this->res = res;
    this->emp = emp;
    this->numeroRespuesta = numResp;
}

string respuesta::getRespuesta(){
    return resp;
}

empleado* respuesta::getEmpleado(){
    return emp;
}

resenia* respuesta::getResenia(){
    return res;
}

int respuesta::getNumeroRespuesta(){
    return numeroRespuesta;
}

void respuesta::eliminarRespuesta(){
    emp->eliminarRespuestaDeEmpleado(getNumeroRespuesta());
}