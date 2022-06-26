#ifndef CONTROLADORRESENIA
#define CONTROLADORRESENIA

#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iostream>
using namespace std;

#include "IControladorResenia.h" // Depende del ControladorEmpleados
//#include "IEstadia.h"             // Depende de la interface IEstadia (la implementa)
//#include "IUsuario.h"             // Depende de la interface IUsuario (la implementa)

class controladorResenia : public IControladorResenia {
private:
    set<IObserver*> observadores;
    static controladorResenia *instancia;
    controladorResenia();
    void notificarObservadores(DTInformacionNotificaciones);
    // map<int, estadia *> *estadias; // Se conecta con la clase Estadia (muchos), clave = numeroEsadia(int)

public:
    static controladorResenia *getInstancia();
    void agregarResenia(int, string, DTFecha, estadia*, hostal*);    
    void agregarObservador(IObserver *obs);
    void eliminarObservador(IObserver *obs);
     map<string,DTEmpleado> getEmpleadosObservadores();
};

#endif