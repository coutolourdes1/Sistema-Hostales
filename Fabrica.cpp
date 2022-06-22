#include "Fabrica.h"

fabrica* fabrica::instancia = NULL;

fabrica::fabrica(){}

fabrica* fabrica::getInstancia(){
    if(instancia == NULL){
        instancia = new fabrica();
    }

    return instancia;
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