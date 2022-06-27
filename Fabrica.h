#ifndef FABRICA
#define FABRICA

#include <iostream>
#include "ControladorColecciones.h"
#include "ControladorUsuario.h"
#include "ControladorEstadia.h"
#include "ControladorHostales.h"
#include "ControladorResenia.h"
#include "ControladorReserva.h"
#include "ControladorEmpleados.h"
#include "ControladorDatos.h"

// #include <string>
// #include <iterator>
// #include <map>

class fabrica {
    private:
        static fabrica* instancia;
        fabrica();
    public:
        static fabrica* getInstancia();
        void deleteControladores();
        IControladorColecciones* getControladorColecciones();
        IControladorUsuario* getControladorUsuario();
        IControladorEstadia* getControladorEstadia();
        IControladorHostales* getControladorHostales();
        IControladorResenia* getControladorResenia();
        IControladorReserva* getControladorReserva();
        IControladorEmpleado* getControladorEmpleado();
        controladorDatos* getControladorDatos();
};

#endif