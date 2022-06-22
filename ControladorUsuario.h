#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iostream>
using namespace std;

#include "IControladorUsuario.h" // Se conecta con interface IUsuario (la implementa)

typedef map<string, DTUsuario> mapDTUsuario;

class controladorUsuario : public IControladorUsuario
{
private:
    static controladorUsuario *instancia;
    string nombreUsuario, emailUsuario, contraUsuario;
    bool esFinger;
    string cargoEmpleado;

public:
    controladorUsuario();
    static controladorUsuario *getInstancia();

    // CASO DE USO ALTA USUARIO
    void setEmailUsuario(string);
    bool existeEmail(string);
    void setNombreUsuario(string);
    void setContraseniaUsuario(string);
    void setEsFinger(bool);
    void setCargoEmpleado(string);
    void confirmarAltaHuesped();
    void confirmarAltaEmpleado();
    void cancelarAltaUsuario();
    void librearMemoriaUsuario();

    // CASO DE USO: CONSULTA USUARIO
    mapDTUsuario listarUsuariosRegistrados();
    DTUsuario listarUsuario(string);

    bool esHuesped(string);
    DTHuesped listarHuesped(string);
    DTEmpleado listarEmpleado(string);
};

#endif