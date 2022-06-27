#include "ControladorEstadia.h"

#include <map>
#include <set>
#include <iterator>
#include <string>

using namespace std;

controladorEstadia *controladorEstadia::instancia = NULL;

controladorEstadia::controladorEstadia()
{
}

controladorEstadia *controladorEstadia::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new controladorEstadia();
    }

    return instancia;
}

int controladorEstadia::getNuevoNumero()
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEstadias *coleccionEstadias = controladorColecciones->getColEstadias();

    if (coleccionEstadias->size() == 0)
    {
        return 1;
    }
    else
    {
        colEstadias::iterator iterEstadia;
        iterEstadia = coleccionEstadias->end();
        iterEstadia--;
        return iterEstadia->second->getNumeroEstadia() + 1;
    }
}


//CASO DE USO: CALIFICAR ESTADIA

void controladorEstadia::seleccionarHostal(string nombreHostal)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHostales *coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator iterHostal = coleccionHostales->find(nombreHostal);

    if (iterHostal != coleccionHostales->end())
    {
        this->hostalSeleccionado = iterHostal->second;
    }
    else
    {
        throw std::invalid_argument("El hostal seleccionado no es correcto");
    }
}

mapColEstadias controladorEstadia::listarEstadiasFinalizadasHuesped(string emailHuesped)
{
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colHuespedes *coleccionHuespedes = controladorColecciones->getColHuespedes();
    colHuespedes::iterator iterHuesped = coleccionHuespedes->find(emailHuesped);

    if (iterHuesped != coleccionHuespedes->end())
    {
        huesped *huespedSeleccionado = iterHuesped->second;
        setHuespedSeleccionado(huespedSeleccionado);
        colEstadias estadiasDelHuesped = huespedSeleccionado->getColEstadias();
        colEstadias::iterator iterEstadia;

        mapColEstadias DTEstadiasFinalizadas;

        for (iterEstadia = estadiasDelHuesped.begin(); iterEstadia != estadiasDelHuesped.end(); iterEstadia++)
        {
            estadia *est = iterEstadia->second;
            if (est->getFinalizada())
            {
                DTEstadiasFinalizadas.insert(pair<int, DTEstadia>(est->getNumeroEstadia(), est->getDTEstadia()));
            }
        }

        if (DTEstadiasFinalizadas.size() == 0)
        {
            throw std::runtime_error("El huesped no tiene estadias finalizadas");
        }

        return DTEstadiasFinalizadas;
    }
    else
    {
        throw std::invalid_argument("El email seleccionado no es correcto");
    }
}

estadia *controladorEstadia::getEstadiaSeleccionada()
{
    return estadiaSeleccionada;
}

void controladorEstadia::setHuespedSeleccionado(huesped * huesp){
    this->huespedSeleccionado = huesp;
}

void controladorEstadia::seleccionarEstadia(int numEstadia)
{
    colEstadias estadiasDeHuesped = huespedSeleccionado->getColEstadias();
    colEstadias::iterator iterEstadia = estadiasDeHuesped.find(numEstadia);

    if(iterEstadia != estadiasDeHuesped.end()){
        estadiaSeleccionada = iterEstadia->second;
    } else {
        throw std::invalid_argument("La estadia seleccionado no es correcta");
    }
}

void controladorEstadia::setEstadiaBuscada(int numEst){
    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colEstadias* coleccionEstadias = controladorColecciones->getColEstadias();
    colEstadias::iterator iterEst = coleccionEstadias->find(numEst);

    if(iterEst != coleccionEstadias->end()){
        estadiaSeleccionada = iterEst->second;
    } else {
        throw std::invalid_argument("La estadia seleccionado no es correcta");
    }
}

void controladorEstadia::agregarCalificacion(string comentario, float calificacion, DTFecha fecha)
{
    estadia *estadia = getEstadiaSeleccionada();

    // Agregar nuevo numero a resenia en el primer campo del constructor de la resenia
    controladorResenia* controladorResenia = controladorResenia::getInstancia();
    controladorResenia->agregarResenia(calificacion, comentario, fecha, estadia, hostalSeleccionado);

    liberarMemoriaCalificacion();
}

void controladorEstadia::liberarMemoriaCalificacion(){
    hostalSeleccionado = NULL;
    estadiaSeleccionada = NULL;
}


//CONSULTA ESTADIA 

mapColEstadias controladorEstadia::listarEstadias(){

    mapColEstadias coleccionesEstadias;

    controladorHostales* controladorHostal = controladorHostales::getInstancia();
    hostal* hostal_seleccionado = controladorHostal->getHostalSeleccionado();

    colHabitaciones *colHabHostal = hostal_seleccionado->getHabitaciones();
    colHabitaciones::iterator itHab;
    for (itHab = colHabHostal->begin(); itHab != colHabHostal->end(); itHab++){
        habitacion* hab = itHab->second;
        colReservas ReservasHab = hab->getReservasHabitacion();
        colReservas::iterator itReserva;
        for (itReserva = ReservasHab.begin(); itReserva != ReservasHab.end(); itReserva++){
            reserva* resHab = itReserva->second;
            colDTEstadias colDTe = resHab->getColDTEstadias();
            colDTEstadias::iterator itDTEst;
            for (itDTEst = colDTe.begin(); itDTEst != colDTe.end(); itDTEst++){
                DTEstadia est_dt = itDTEst->second;

                coleccionesEstadias.insert(pair<int, DTEstadia>(est_dt.getNumero(),est_dt));
            }
        }
    }
    return coleccionesEstadias;
}

DTInformacionEstadia controladorEstadia::informacionEstadia(){

    mapColInfoEstadia infoEstadia;
    controladorHostales* controladorHostal = controladorHostales::getInstancia();
    hostal* hostal_seleccionado = controladorHostal->getHostalSeleccionado();

    DTHostal dth = hostal_seleccionado->getDTHostal();
    DTEstadia dte = estadiaSeleccionada->getDTEstadia();
    DTReserva dtr = estadiaSeleccionada->getReserva()->getDTReserva();
    // int codEst = estadiaSeleccionada->getReserva()->getCodigo();

    DTInformacionEstadia info = DTInformacionEstadia(dth, dte, dtr);
    // infoEstadia.insert(pair<int, DTInformacionEstadia>(codEst,info));
    
    return info;

}


DTReserva controladorEstadia::informacionReservaAsociada(){
    reserva* res = estadiaSeleccionada->getReserva();
    DTReserva infoRes = res->getDTReserva();

    return infoRes;
}



// set<DTEstadia>* estadiasFinalizadas(string email){
//     colHuesped* coleccionHuesped = controladorColecciones::getColHuesped();
//     colHuesped::iterator iter;
//     iter = coleccionHuesped->find(email);
//     map<int, estadia*>* auxEstadia = iter->second->getEstadiasHuesp();
//     map<int, estadia*>::iterator iterEst;
//     set<DTEstadia>* auxDTEst;
//     for(iterEst = auxEstadia->begin(); iterEst != auxEstadia->end(); ++iterEst){
//         auxDTEst->insert(iterEst->second->getDTEstadia());
//     }
//     return auxDTEst;
// }

// estadia* seleccionarEstadia(int codigo){
//     colEstadia* coleccionEstadia = controladorColecciones::getColEstadia();
//     colEstadia::iterator iter;
//     iter = coleccionEstadia->find(codigo);
//     return iter->second;
// }
