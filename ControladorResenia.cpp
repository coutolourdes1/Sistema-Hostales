#include "ControladorResenia.h"
#include "IObserver.h"
#include "DTInformacionNotificaciones.h"  
#include "DTEmpleado.h"

#include <string>
#include <iterator>
#include <map>
#include <iostream>
#include <set>
using namespace std;

controladorResenia* controladorResenia::instancia = NULL;

controladorResenia::controladorResenia(){}

controladorResenia* controladorResenia::getInstancia(){
    if(instancia == NULL){
        instancia = new controladorResenia();
    }

    return instancia;
}

void controladorResenia::agregarResenia(int calificacion, string comentario, DTFecha fecha, estadia* est, hostal* hostalSeleccionado){
    //Conseguir nuevo numero resenia
    controladorColecciones*controladorColecciones = controladorColecciones::getInstancia();
    colResenias* coleccionResenias = controladorColecciones->getColResenias();

    int nuevoNumero;
    if(coleccionResenias->size() == 0){
        nuevoNumero = 1;
    } else {
        colResenias::iterator iterResenia;
        iterResenia = coleccionResenias->end();
        iterResenia--;
        nuevoNumero = iterResenia->second->getNumero() + 1;
    }

    cout <<  "El nuevo numero de la resenia es: " << nuevoNumero << endl;
    resenia *res = new resenia(nuevoNumero, calificacion, comentario, fecha, est, hostalSeleccionado);
    est->setResenia(res);
    hostalSeleccionado->agregarAColResenias(res);

    //Agrego a la coleccion global de resenias
    coleccionResenias->insert(pair<int, resenia*> (res->getNumero(), res));


    DTInformacionNotificaciones infoNot = DTInformacionNotificaciones(res->getNumero(), est->getHuespedEstadia()->getNombre(),calificacion, comentario);
    notificarObservadores(infoNot);
};


void controladorResenia::notificarObservadores(DTInformacionNotificaciones infoN){
    set<IObserver*>::iterator itObs;
    for(itObs = observadores.begin(); itObs != observadores.end(); ++itObs){
        (*itObs)->Notify(infoN);
    }
}

void controladorResenia::agregarObservador(IObserver *obs){
    observadores.insert(obs);
}

void controladorResenia::eliminarObservador(IObserver *obs){
   observadores.erase(obs);
}


 map<string,DTEmpleado> controladorResenia::getEmpleadosObservadores(){
    map<string,DTEmpleado> dtempleadosSuscriptos;
    set<IObserver*>::iterator iterObs;
    
    for(iterObs = observadores.begin(); iterObs != observadores.end(); ++iterObs){
        empleado* emp = dynamic_cast<empleado*>(*iterObs);
        if (emp!= NULL){
            dtempleadosSuscriptos.insert(pair<string,DTEmpleado>(emp->getEmail(),emp->getDTEmpleado()));
        }
    };
    return dtempleadosSuscriptos;
}
