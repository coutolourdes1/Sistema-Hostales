#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include "Usuario.h"
#include "DTUsuario.h"
#include "DTHuesped.h"
#include "IControladorColecciones.h"
#include "DTInformacionNotificaciones.h"

#include <string>
#include <set>
#include <map>
using namespace std;

typedef map<string, DTUsuario> mapDTUsuario;

class IControladorUsuario
{
public:
    virtual void setEmailUsuario(string) = 0;
    virtual bool existeEmail(string) = 0;
    virtual void setNombreUsuario(string) = 0;
    virtual void setContraseniaUsuario(string) = 0;
    virtual void setEsFinger(bool) = 0;
    virtual void setCargoEmpleado(string) = 0;
    virtual void confirmarAltaHuesped() = 0;
    virtual void confirmarAltaEmpleado() = 0;
    virtual void cancelarAltaUsuario() = 0;
    virtual void librearMemoriaUsuario() = 0;
    virtual mapDTUsuario listarUsuariosRegistrados() = 0;
    virtual DTUsuario listarUsuario(string) = 0;
    virtual bool esHuesped(string) = 0;
    virtual DTHuesped listarHuesped(string) = 0;
    virtual DTEmpleado listarEmpleado(string) = 0;
};

#endif