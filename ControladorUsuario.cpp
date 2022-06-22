#include "ControladorUsuario.h"

using namespace std;

controladorUsuario *controladorUsuario::instancia = NULL;

controladorUsuario::controladorUsuario() {}

controladorUsuario *controladorUsuario::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new controladorUsuario();
    }

    return instancia;
}

// ----------------------- operaciones ALTA USUARIO -------------------

void controladorUsuario::setEmailUsuario(string email)
{
    this->emailUsuario = email;
}

void controladorUsuario::setNombreUsuario(string nombre)
{
    this->nombreUsuario = nombre;
}

void controladorUsuario::setContraseniaUsuario(string contrasenia)
{
    this->contraUsuario = contrasenia;
}

void controladorUsuario::setEsFinger(bool esF)
{
    this->esFinger = esF;
}

void controladorUsuario::setCargoEmpleado(string cargo)
{
    this->cargoEmpleado = cargo;
}

bool controladorUsuario::existeEmail(string emailUsuario)
{

    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator itE;
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator itH;

    itH = coleccionHuespedes->find(emailUsuario);
    itE = coleccionEmpleados->find(emailUsuario);

    bool existeEmail = true;

    if (itH == coleccionHuespedes->end() && (itE == coleccionEmpleados->end()))
    {
        existeEmail = false;
    }
    return existeEmail;
}

void controladorUsuario::confirmarAltaHuesped()
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();

    huesped *hues = new huesped(nombreUsuario, emailUsuario, contraUsuario, esFinger);
    coleccionHuespedes->insert(pair<string, huesped *>(emailUsuario, hues));

    colUsuarios *coleccionUsuarios = controladorColecciones->getColUsuarios();
    coleccionUsuarios->insert(pair<string, usuario *>(emailUsuario, hues));

    librearMemoriaUsuario();
}

void controladorUsuario::confirmarAltaEmpleado()
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();

    empleado *emp = new empleado(nombreUsuario, emailUsuario, contraUsuario, cargoEmpleado);
    coleccionEmpleados->insert(pair<string, empleado *>(emailUsuario, emp));

    colUsuarios *coleccionUsuarios = controladorColecciones->getColUsuarios();
    coleccionUsuarios->insert(pair<string, usuario *>(emailUsuario, emp));

    librearMemoriaUsuario();
}

void controladorUsuario::cancelarAltaUsuario()
{
    librearMemoriaUsuario();
}

void controladorUsuario::librearMemoriaUsuario()
{
    setEmailUsuario("");
    setNombreUsuario("");
    setContraseniaUsuario("");
    setCargoEmpleado("");
    setEsFinger(false);
}

// Operacion de Consulta de Usuario
mapDTUsuario controladorUsuario::listarUsuariosRegistrados()
{
    // Traer las colecciones de Empleados y Huespedes
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();

    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator iterEmp;
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator iterHuesp;

    mapDTUsuario usuariosRegistrados;

    // Mostrar Empleados Registrados
    if (coleccionEmpleados->size() > 0)
    {
        for (iterEmp = coleccionEmpleados->begin(); iterEmp != coleccionEmpleados->end(); ++iterEmp)
        {
            empleado *e = iterEmp->second;
            DTUsuario usuario = e->getDTEmpleado();
            usuariosRegistrados.insert(pair<string, DTUsuario>(usuario.getEmail(), usuario));
        }
    }

    // // Mostrar Huespedes Registrados
    if (coleccionHuespedes->size() > 0)
    {
        for (iterHuesp = coleccionHuespedes->begin(); iterHuesp != coleccionHuespedes->end(); ++iterHuesp)
        {
            huesped *h = iterHuesp->second;
            DTUsuario usuario = h->getDTHuesped();
            usuariosRegistrados.insert(pair<string, DTUsuario>(usuario.getEmail(), usuario));
        }
    }

    if (usuariosRegistrados.size() == 0)
    {
        throw std::runtime_error("No hay usuarios registrados");
    }

    return usuariosRegistrados;
}

// Operacion de Consulta de Usuario
DTUsuario controladorUsuario::listarUsuario(string email)
{
    // Traer las colecciones de Empleados y Huespedes
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator iterEmp;
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator iterHuesp;
    // agregar a la coleccion Usuarios

    // Buscar en la Coleccion de Empelados el email
    iterEmp = coleccionEmpleados->find(email);

    if (iterEmp == coleccionEmpleados->end()) // El email no corresponde a un empleado
    {
        iterHuesp = coleccionHuespedes->find(email);

        if (iterHuesp == coleccionHuespedes->end()) // El email no corresponde a un empleado ni a un huesped
        {
            throw std::runtime_error("El usuario con el email ingresado no existe");
        }
        else
        {
            DTUsuario DTHuesped = iterHuesp->second->getDTHuesped();
            return DTHuesped;
        }
    }
    else
    {
        DTUsuario DTEmpleado = iterEmp->second->getDTEmpleado();
        return DTEmpleado;
    }
}

bool controladorUsuario::esHuesped(string email)
{

    bool esHuesped = false;

    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colUsuarios *coleccionUsuario = controladorColecciones->getColUsuarios();
    colUsuarios::iterator iterUsu;

    iterUsu = coleccionUsuario->find(email);

    huesped *huesp = dynamic_cast<huesped *>(iterUsu->second);

    if (huesp != NULL)
    {
        esHuesped = true;
    }

    return esHuesped;
}

DTHuesped controladorUsuario::listarHuesped(string email)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator iterHuesp;

    iterHuesp = coleccionHuespedes->find(email);
    DTHuesped dtHuesped = iterHuesp->second->getDTHuesped();

    return dtHuesped;
}

DTEmpleado controladorUsuario::listarEmpleado(string email)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator iterEmp;

    iterEmp = coleccionEmpleados->find(email);
    DTEmpleado dtEmpleado = iterEmp->second->getDTEmpleado();

    return dtEmpleado;
}