#include "Fabrica.h"

fabrica* fabrica::instancia = NULL;

fabrica::fabrica(){}

fabrica* fabrica::getInstancia(){
    if(instancia == NULL){
        instancia = new fabrica();
    }

    return instancia;
}

void fabrica::deleteControladores(){
    delete controladorColecciones::getInstancia();
    delete controladorUsuario::getInstancia();
    delete controladorEstadia::getInstancia();
    delete controladorHostales::getInstancia();
    delete controladorResenia::getInstancia();
    delete controladorReserva::getInstancia();
    delete controladorEmpleado::getInstancia();
    delete controladorDatos::getInstancia();
}

IControladorColecciones* fabrica::getControladorColecciones(){
    return controladorColecciones::getInstancia();
}

IControladorUsuario* fabrica::getControladorUsuario(){
    return controladorUsuario::getInstancia();
}

IControladorEstadia* fabrica::getControladorEstadia(){
    return controladorEstadia::getInstancia();
}

IControladorHostales* fabrica::getControladorHostales(){
    return controladorHostales::getInstancia();
}

IControladorResenia* fabrica::getControladorResenia(){
    return controladorResenia::getInstancia();
}

IControladorReserva* fabrica::getControladorReserva(){
    return controladorReserva::getInstancia();
}

IControladorEmpleado* fabrica::getControladorEmpleado(){
    return controladorEmpleado::getInstancia();
}

controladorDatos* fabrica::getControladorDatos(){
    return controladorDatos::getInstancia();
}