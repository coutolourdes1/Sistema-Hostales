#include "Hostal.h"
#include "Usuario.h"
// #include "Habitacion.h"
#include "ControladorHostales.h"
#include "ControladorReserva.h"
#include "ControladorColecciones.h"
#include "DTHostal.h"
#include "DTEstadia.h"
#include "Estadia.h"
#include "DTUsuario.h"
#include "DTFecha.h"
// #include "DTHabitacion.h"
// #include "DTResenia.h"
// #include "Resenia.h"


#include <string>
#include <iterator>
#include <map>
#include <iostream>
#include <stdio.h>


using namespace std;

controladorHostales *controladorHostales::instancia = NULL;

controladorHostales::controladorHostales()
{
    huespedSeleccionado = NULL;
    hostalSeleccionado = NULL;
    mapColHuespedes otrosHuespedes;
    this->otrosHuespedes = otrosHuespedes;
}

controladorHostales *controladorHostales::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new controladorHostales();
    }
    return instancia;
};

void controladorHostales::setHuespedSeleccionado(huesped *huesped)
{
    huespedSeleccionado = huesped;
}

void controladorHostales::setHostalSeleccionado(hostal *hostal)
{
    hostalSeleccionado = hostal;
}

void controladorHostales::setEsGrupal(bool esGrupal)
{
    this->esGrupal = esGrupal;
}

void controladorHostales::setFechas(DTFecha checkIn, DTFecha checkOut)
{
    this->checkIn = checkIn;
    this->checkOut = checkOut;
}

void controladorHostales::setHabDisp(mapColHabitaciones habDisp)
{
    habitacionesDisp = habDisp;
}

void controladorHostales::setHabitacionSeleccionada(habitacion *habitacion)
{
    habitacionSeleccionada = habitacion;
}

int controladorHostales::getNumHabSeleccionada()
{
    return numHabSeleccionada;
}

huesped *controladorHostales::getHuespedSeleccionado()
{
    return huespedSeleccionado;
}

hostal *controladorHostales::getHostalSeleccionado()
{
    return hostalSeleccionado;
}

bool controladorHostales::getEsGrupal()
{
    return esGrupal;
}

DTFecha controladorHostales::getCheckIn()
{
    return checkIn;
}

DTFecha controladorHostales::getCheckOut()
{
    return checkOut;
}

habitacion *controladorHostales::getHabitacionSeleccionada()
{
    return habitacionSeleccionada;
}


// CASO DE USO: CONSULTA HOSTAL
setNombreHostales controladorHostales::obtenerNombresHostalesRegistrados(){
    setNombreHostales nombres;

    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales *coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator it;

    mapColDTHostales coleccionDTHostales;

    if(coleccionHostales->size() == 0){
        throw std::runtime_error("No hay hostales registrados");
    }

    for (it = coleccionHostales->begin(); it != coleccionHostales->end(); it++)
    {
        hostal *h = it->second;
        nombres.insert(h->getNombreHostal());
    }

    return nombres;
}

DTInformacionHostal controladorHostales::obtenerInformacionHostal(string nombreHostal){
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales* coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator iterHostal = coleccionHostales->find(nombreHostal);

    if(iterHostal != coleccionHostales->end()){
        hostal* h = iterHostal->second;
        return DTInformacionHostal(h->getDTHostalCalificado(), h->getDTResenias(), h->getDTHostalCalificado().getPromedioCalificaciones());
    } else {
        throw std::invalid_argument("El nombre del hostal seleccionado no es correcto");
    }
}

//TERMINA CONSULTA HOSTAL


// CASO DE USO: ALTA HOSTEL
void controladorHostales::setNombreHostal(string nombre)
{
    nombreHostal = nombre;
}

void controladorHostales::setDireccionHostal(string direccion)
{
    direccionHostal = direccion;
}

void controladorHostales::setTelefonoHostal(string telefono)
{
    telefonoHostal = telefono;
}

void controladorHostales::confirmarAltaHostal()
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales *coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator iterHostal;

    iterHostal = coleccionHostales->find(nombreHostal);

    if (iterHostal == coleccionHostales->end())
    { // El nombre está disponible
        hostal *h = new hostal(nombreHostal, direccionHostal, telefonoHostal);
        coleccionHostales->insert(pair<string, hostal *>(nombreHostal, h));
    }
    else
    {
        throw std::invalid_argument("El nombre del hostal no está disponible");
    }
    liberarMemoriaAltaHostal();
}

void controladorHostales::cancelarAltaHostal()
{
    liberarMemoriaAltaHostal();
}

void controladorHostales::liberarMemoriaAltaHostal()
{
    setNombreHostal("");
    setDireccionHostal("");
    setTelefonoHostal("");
}

// -----------------------   operaciones para Alta Habitacion

void controladorHostales::setNumeroHabitacion(int num)
{
    numeroHabitacion = num;
}

void controladorHostales::setCapacidadHabitacion(int cap)
{
    capacidadHabitacion = cap;
}

void controladorHostales::setPrecioHabitacion(float precio)
{
    precioHabitacion = precio;
}

mapColDTHostales controladorHostales::obtenerHostalesRegistrados()
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales *coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator it;

    mapColDTHostales coleccionDTHostales;

    for (it = coleccionHostales->begin(); it != coleccionHostales->end(); it++)
    {
        hostal *h = it->second;
        DTHostal dth = DTHostal(h->getNombreHostal(), h->getTelHostal(), h->getDireccionHostal());
        coleccionDTHostales.insert(pair<string, DTHostal>(h->getNombreHostal(), dth));
    }
    return coleccionDTHostales;
};

void controladorHostales::seleccionarHostal(string nombre_seleccionado)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales *coleccionHostales = controladorColecciones->getColHostales();

    colHostales::iterator it;
    it = coleccionHostales->find(nombre_seleccionado);
    setHostalSeleccionado(it->second);
}

void controladorHostales::confirmarAltaHabitacion()
{
    hostal *h = hostalSeleccionado;
    colHabitaciones *colHabHostal = h->getHabitaciones();
    colHabitaciones::iterator it;
    it = colHabHostal->find(numeroHabitacion);

    if (it == colHabHostal->end())
    {
        habitacion *hab = new habitacion(numeroHabitacion, precioHabitacion, capacidadHabitacion, h);
        h->agregarHabitacion(hab);
    }
    else
    {
        throw std::invalid_argument("La habitacion ya se encuentra ingresada en ese Hostel");
    }
    liberarMemoriaAltaHabitacion();
}

void controladorHostales::cancelarAltaHabitacion()
{
    liberarMemoriaAltaHabitacion();
}

void controladorHostales::liberarMemoriaAltaHabitacion()
{
    setHostalSeleccionado(NULL);
    setNumeroHabitacion(0);
    setCapacidadHabitacion(0);
    setPrecioHabitacion(0.0);
}

// CASO DE USO: REALIZAR RESERVA
mapColHostalesCal controladorHostales::solicitarListaHostalesCal()
{
    mapColHostalesCal hostales;
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();

    colHostales *coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator iterHostal;

    if (coleccionHostales->size() > 0)
    {
        for (iterHostal = coleccionHostales->begin(); iterHostal != coleccionHostales->end(); iterHostal++)
        {
            hostal *h = iterHostal->second;
            DTHostalCalificado hostal = h->getDTHostalCalificado();
            hostales.insert(pair<string, DTHostalCalificado>(hostal.getNombre(), hostal));
        }
    }
    else
    {
        throw std::runtime_error("No hay hostales registrados en el sistema");
    }

    return hostales;
};

mapColHabitaciones controladorHostales::habitacionesDispDeHostal(string nombre, DTFecha checkIn, DTFecha checkOut, bool esGrupal)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();

    colHostales *coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator iterHostal = coleccionHostales->find(nombre);

    hostal *hostalElegido;
    if (iterHostal != coleccionHostales->end())
    {
        hostalElegido = iterHostal->second;
    }
    else
    {
        throw std::invalid_argument("El hostal seleccionado no existe");
    }

    setHostalSeleccionado(hostalElegido);
    setEsGrupal(esGrupal);

    mapColHabitaciones habitacionesDispDelHostal = hostalSeleccionado->getHabitacionesDisp(checkIn, checkOut);

    if (habitacionesDispDelHostal.size() == 0)
    {
        throw std::runtime_error("No hay habitaciones disponibles para el rango de fechas seleccionado");
    }
    else
    {
        setHabDisp(habitacionesDispDelHostal);
        setFechas(checkIn, checkOut);
        return habitacionesDispDelHostal;
    }
}

void controladorHostales::seleccionarHabitacion(int numHab)
{
    mapColHabitaciones::iterator iterHab;
    iterHab = habitacionesDisp.find(numHab);
    if (iterHab == habitacionesDisp.end())
    {
        throw std::runtime_error("El numero de habitación seleccionado no es correcto");
    }
    else
    {
        habitacion *habitacionSeleccionada = hostalSeleccionado->getHabitaciones()->find(numHab)->second;
        setHabitacionSeleccionada(habitacionSeleccionada);
    }
}

mapDTHuespedes controladorHostales::solicitarDTHuespedes(){
    mapDTHuespedes huespedesRegistrados;
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHuespedes* huespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator iterHuesp;

    for(iterHuesp = huespedes->begin(); iterHuesp != huespedes->end(); iterHuesp++){
        DTHuesped dtHuesp = iterHuesp->second->getDTHuesped();
        huespedesRegistrados.insert(pair<string, DTHuesped> (dtHuesp.getEmail(), dtHuesp));
    }

    return huespedesRegistrados;
}

void controladorHostales::seleccionarHuesped(string email)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator iterHuesp = coleccionHuespedes->find(email);

    if (iterHuesp != coleccionHuespedes->end())
    {
        huesped *huespedSeleccionado = iterHuesp->second;
        setHuespedSeleccionado(huespedSeleccionado);
    }
    else
    {
        throw std::runtime_error("No existe huesped con ese email");
    }
}

void controladorHostales::agregarHuesped(string email)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHuespedes *coleccionHuesped = controladorColecciones->getColHuespedes();

    colHuespedes::iterator iterHuesp;
    iterHuesp = coleccionHuesped->find(email);

    if (iterHuesp != coleccionHuesped->end())
    {
        huesped *huesp = iterHuesp->second;
        otrosHuespedes.insert(pair<string, huesped *>(email, huesp));
    }
    else
    {
        throw std::runtime_error("El email ingresado no es correcto");
    }
}

void controladorHostales::confirmarReserva()
{
    controladorReserva* controladorReserva = controladorReserva::getInstancia();
    int nuevoCodigo = controladorReserva->getNuevoCodigo();
    huesped *huespedSeleccionado = getHuespedSeleccionado();
    reserva *nuevaReserva;
    habitacion *habSeleccionada = getHabitacionSeleccionada();

    if (getEsGrupal())
    {
        agregarHuesped(huespedSeleccionado->getEmail());
        nuevaReserva = new reservaGrupal(nuevoCodigo, getCheckIn(), getCheckOut(), huespedSeleccionado, habSeleccionada, otrosHuespedes, otrosHuespedes.size());

        // for en otrosHuespedes y agregarle a cada huesped la habilitacion a la reserva
        mapColHuespedes::iterator iterHuesp;
        for (iterHuesp = otrosHuespedes.begin(); iterHuesp != otrosHuespedes.end(); iterHuesp++)
        {
            iterHuesp->second->agregarReservaAPertenecientes(nuevaReserva);
        }
    }
    else
    {
        nuevaReserva = new reservaIndividual(nuevoCodigo, getCheckIn(), getCheckOut(), huespedSeleccionado, habSeleccionada, false);
        huespedSeleccionado->agregarReservaAPertenecientes(nuevaReserva);
    }

    controladorReserva->agregarReserva(nuevaReserva);   //Agrego la reserva a la coleccion global de reservas
    huespedSeleccionado->agregarReservaACol(nuevaReserva);
    habSeleccionada->agregarReservaACol(nuevaReserva);
    liberarMemoriaReserva();
}

void controladorHostales::cancelarReserva()
{
    liberarMemoriaReserva();
}

void controladorHostales::liberarMemoriaReserva()
{
    setHuespedSeleccionado(NULL);
    setHostalSeleccionado(NULL);
    setEsGrupal(false);
    setFechas(DTFecha(), DTFecha());
    habitacionesDisp.clear();
    otrosHuespedes.clear();
    setHabitacionSeleccionada(NULL);
}

// TERMINA REALIZAR RESERVA

//---------------------------------------- CASO DE USO: REGISTRAR ESTADIA

mapColDTReservas controladorHostales::solicitarReservasDisp(string email)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    huesped *huespedSeleccionado = controladorColecciones->getColHuespedes()->find(email)->second;

    mapColDTReservas DTReservasDelHuesped;

    colReservas reservasDelHuesped = huespedSeleccionado->getColReservasQuePertenece();
    colReservas::iterator iterRes;

    for (iterRes = reservasDelHuesped.begin(); iterRes != reservasDelHuesped.end(); iterRes++)
    {
        reserva *res = iterRes->second;
        DTReservasDelHuesped.insert(pair<int, DTReserva>(res->getCodigo(), res->getDTReserva()));
    }

    setHuespedSeleccionado(huespedSeleccionado);

    return DTReservasDelHuesped;
}

void controladorHostales::seleccionarReserva(int numeroReserva)
{
    numReservaSeleccionada = numeroReserva;
}


void controladorHostales::setCheckinEstadia(DTFecha fecha){
    this->checkinEstadia = fecha;
}

void controladorHostales::confirmarEstadia()
{
    huesped *huesp = huespedSeleccionado;

    // Traer el puntero a la instancia de la reserva seleccionada por el huesped
    // reserva *reservaSeleccionada = controladorColecciones->getColReservas()->find(numeroReserva)->second;

    reserva *reservaSeleccionada = huesp->getReserva(numReservaSeleccionada);   //Uso el metodo getReserva(int) del

    // Crear la instancia estadia
    estadia *nuevaEstadia = new estadia(huesp, reservaSeleccionada,checkinEstadia);

    //Links HACIA la estadia:
        // Agregar a la coleccion de estadias de la reserva
        reservaSeleccionada->agregarEstadia(nuevaEstadia);
        reservaSeleccionada->setEstadoReserva(cerrada);

        // Agregar estadia al huesped
        huesp->agregarEstadia(nuevaEstadia);

        //  Agregamos la estadia a la coleccion de estadias
        controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
        controladorColecciones->getColEstadias()->insert(pair<int, estadia *>(nuevaEstadia->getNumeroEstadia(), nuevaEstadia));
    //

    //Links DESDE la estadia:
        // Crear un link de estadia al huesped
        nuevaEstadia->setHuesped(huespedSeleccionado);

        // Crear un link desde la estadia a la reserva
        nuevaEstadia->setReserva(reservaSeleccionada);
    //

    liberarMemoriaEstadia();
}

void controladorHostales::cancelarEstadia(){
    liberarMemoriaEstadia();
}

void controladorHostales::liberarMemoriaEstadia(){
    numReservaSeleccionada = 0;
}

// TERMINA REGISTRAR ESTADIA


// CASO DE USO: SOLICITAR TOP 3 HOSTALES
mapTopTres controladorHostales::solicitarTopTresHostales()
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales *coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator iterHost;

    // Conjunto de top tres hostales a retornar
    mapTopTres topTresHostales;

    // Map que tendrá (nombre, promedioCalificacion) de todos los hostales
    map<string, float> promediosHostales;
    map<string, float>::iterator iterPromHost;

    // String con nombre de Hostal con mayor promCal
    string h1;

    // Variable auxiliar para comparar los promCal
    int mayor = -1;

    int aux = 0;

    for (iterHost = coleccionHostales->begin(); iterHost != coleccionHostales->end(); iterHost++)
    {
        hostal *h = iterHost->second;
        float promCalificaciones = h->getDTHostalCalificado().getPromedioCalificaciones();
        promediosHostales.insert(pair<string, float>(h->getNombreHostal(), promCalificaciones));
    }

    while (aux != 3)
    {
        for (iterPromHost = promediosHostales.begin(); iterPromHost != promediosHostales.end(); iterPromHost++)
        {
            if (iterPromHost->second >= mayor)
            {
                h1 = iterPromHost->first;
                mayor = iterPromHost->second;
            }
        }

        promediosHostales.erase(h1);
        topTresHostales.insert(pair<int, string> (aux + 1, h1));
        mayor = -1;
        aux++;
    }

    return topTresHostales;
}

map<int, DTResenia> controladorHostales::detallesHostal(string nombre)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales *coleccionHostales = controladorColecciones->getColHostales();

    colHostales::iterator iterHost;

    hostal *h = coleccionHostales->find(nombre)->second;

    map<int, DTResenia> resenias = h->getDTResenias();

    return resenias;
}

// CASO DE USO: ASIGNAR EMPLEADO A HOSTAL

mapColEmpleados controladorHostales::obtenerListaDeEmpleados(){

    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator iterEmp;

    mapColEmpleados empleadosNoAsignados;

    hostal *h = hostalSeleccionado;

    for (iterEmp = coleccionEmpleados->begin(); iterEmp != coleccionEmpleados->end(); iterEmp++){
        empleado* empleadoElegido = iterEmp->second;
        //accedo a la coleccion de hostales del empleado
        colHostales hostalesDelEmpleado = empleadoElegido->getHostalesQueTrabaja();
        //itero sobre la coleccion de hostales del empleado
        colHostales::iterator itHos;
        itHos = hostalesDelEmpleado.find(h->getNombreHostal());

        if(itHos == hostalesDelEmpleado.end()){
            empleadosNoAsignados.insert(pair<string, DTEmpleado>(empleadoElegido->getEmail(), empleadoElegido->getDTEmpleado()));
        }
    }
    return empleadosNoAsignados;
}

void controladorHostales::setEmpleadoSeleccionado(empleado* empl)
{
    empleadoSeleccionado = empl;
}


void controladorHostales::seleccionarEmpleado(string empleado_seleccionado){

    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colEmpleados *coleccionEmpleados = controladorColecciones->getColEmpleados();
    colEmpleados::iterator iterEmp;

    iterEmp = coleccionEmpleados->find(empleado_seleccionado);
    setEmpleadoSeleccionado(iterEmp->second);
}


void controladorHostales::confirmarAsignacion(){
    hostal *h = hostalSeleccionado;
    empleado* e = empleadoSeleccionado;
    h->agregarEmpleado(e);
    e->agregarHostalQueTrabaja(h);
    liberarMemoriaAsignacion();
}

void controladorHostales::cancelarAsignacion(){
    liberarMemoriaAsignacion();
}

void controladorHostales::liberarMemoriaAsignacion(){
    setHostalSeleccionado(NULL);
    setEmpleadoSeleccionado(NULL);
}

//--------------------------------- CASO DE USO FINALIZAR ESTADIA


void controladorHostales::setCheckoutEstadia(DTFecha checkout){
    this->checkoutEstadia = checkout;
}
//MUESTRA TODAS LAS ESTADIAS -ABIERTAS- DE ESE HUESPED EN EL HOSTAL QUE SELECCIONO
mapDTEstadia controladorHostales::mostrarEstadiasHuesped(string email){
    hostal* hos = getHostalSeleccionado();
    string nombreHostal = hos->getNombreHostal();
    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator iterHues;

    iterHues = coleccionHuespedes->find(email);
    huesped* hues = iterHues->second;
    colEstadias estadiasDelHuesped = hues->getColEstadias();
    colEstadias::iterator iterEst;

    mapDTEstadia mapEstadias;

    for(iterEst = estadiasDelHuesped.begin(); iterEst != estadiasDelHuesped.end(); iterEst++){
        estadia* estActual = iterEst->second;
        if(!(estActual->getFinalizada())){
            mapEstadias.insert(pair<int, DTEstadia> (estActual->getNumeroEstadia(), estActual->getDTEstadia()));
        }
    }
    return mapEstadias;

    // colReservas reservasDelHuesped = hues->getColReservasQuePertenece();
    // colReservas::iterator iterRes;

    // mapDTEstadia mapEstadias;
    // DTEstadia estadias_huesped;
    // for (iterRes = reservasDelHuesped.begin(); iterRes != reservasDelHuesped.end(); iterRes++){
    //     reserva* res = iterRes->second;
    //     habitacion* hab = res->getHabitacion();
    //     if(hab->getHostalDeHabitacion()->getNombreHostal() == hos->getNombreHostal()){
    //         if(res->getEstadoReserva() == abierta){
    //             colEstadias colEst = res->getColEstadias();
    //             colEstadias::iterator iterEst;
    //             for (iterEst = colEst.begin(); iterEst != colEst.end(); iterEst++){
    //                 estadia* est = iterEst->second;
    //                 estadias_huesped = DTEstadia(hues->getDTHuesped(), est->getCheckin(), est->getCheckOut(), est->getNumeroEstadia());
    //                 mapEstadias.insert(pair<int,DTEstadia>(est->getNumeroEstadia(), estadias_huesped));
    //             }
    //         }
    //     }
    // }
}


void controladorHostales::setEstadiaSeleccionada(int codigoEstadia){
    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colEstadias* coleccionEstadias = controladorColecciones->getColEstadias();
    colEstadias::iterator iterEst;
    iterEst = coleccionEstadias->find(codigoEstadia);
    this->estadiaSeleccionada = iterEst->second;
}

void controladorHostales::finalizarEstadia(){
    estadia* estAfinalizar = estadiaSeleccionada;
    estAfinalizar->setCheckout(checkoutEstadia);
    estAfinalizar->setFinalizada();
}


// // Operaciones Alta Hostel la primer funcion podria ser solicitarListaHostales
// map<string, DTHostal*>* controladorHostales::obtenerHostalesRegistrados(){
//     colHostal* coleccionHostales = controladorColecciones::getColHostal();
//     DTHostal* dthos = coleccionHostales.getDTHostal()
//     return ;
// };

// string controladorHostales::seleccionarHostal(string nombreHostalSeleccionado){
//     return nombreHostalSeleccionado
// }

// void controladorHostales::agregarDatosHabitacion(int num, float precio, int capacidad){
//     colHabitaciones* colHab = controladorColecciones::getColHab();
//     colHabitaciones::iterator iterador;

//     iterador = colHab->find(num);

//     if(iterador == colHab->end()){
//         DTHabitacion* dthab_nueva = new DTHabitacion(num,capacidad,precio);
//     }

// }

// void controladorHostales::confirmarAlta(){

// }
// =======
// // void controladorHostales::ingresarOtrosHuespedes(setEmails emails){
// //     setEmails::iterator iterEmail;

// //     colHuesped *coleccionHuespedes = controladorColecciones::getColHuesped();

// //     for(iterEmail = emails.begin(); iterEmail != emails.end(); iterEmail){
// //         string email = (*iterEmail);
// //         huesped* h = coleccionHuespedes->find(email)->second;
// //     }
// // }

// void controladorHostales::ingresarOtrosHuespedes(setEmails emails){
//     this->emailOtrosHuespedes = emails;
// }
// >>>>>>> f02dd234b81d6daeb4ed3ba6f20809f85d59979c
