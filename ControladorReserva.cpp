#include "ControladorReserva.h"

#include <string>
#include <iterator>
#include <map>
#include <iostream>
using namespace std;

controladorReserva* controladorReserva::instancia = NULL;

controladorReserva::controladorReserva(){}

controladorReserva* controladorReserva::getInstancia(){
    if(instancia==NULL){
        instancia = new controladorReserva();
    }

    return instancia;
}


int controladorReserva::getNuevoCodigo(){
    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colReservas* coleccionReservas = controladorColecciones->getColReservas();

    if(coleccionReservas->size() == 0){
        return 1;
    } else {
        colReservas::iterator iterReseva;
        iterReseva = coleccionReservas->end();
        iterReseva--;
        return iterReseva->second->getCodigo() + 1;
    }
}

void controladorReserva::agregarReserva(reserva* res){
    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colReservas* coleccionReservas = controladorColecciones->getColReservas();

    coleccionReservas->insert(pair<int, reserva*>(res->getCodigo(), res));
}

// CASO DE USO CONSULTA RESERVA

colConsultaReserva controladorReserva::obtenerReservasdelHostal(){

    colConsultaReserva datosReserva;
    controladorHostales* controladorHostal = controladorHostales::getInstancia();
    hostal* hostal_seleccionado = controladorHostal->getHostalSeleccionado();

    int num_hab = 0;
    set<string> nombres; 
    colDTReservas res_hab;
    
    colHabitaciones *colHabHostal = hostal_seleccionado->getHabitaciones();
    colHabitaciones::iterator itHab;
    for (itHab = colHabHostal->begin(); itHab != colHabHostal->end(); itHab++){
        habitacion* hab = itHab->second;
        num_hab = hab->getNumero();
        res_hab = hab->getDTReservasHabitacion();
        colReservas ReservasHab = hab->getReservasHabitacion();
        colReservas::iterator itReserva;
        for (itReserva = ReservasHab.begin(); itReserva != ReservasHab.end(); itReserva++){
            reserva* res = itReserva->second;
            reservaGrupal* resGrupal = dynamic_cast<reservaGrupal*>(res);
            if(resGrupal != 0){
                colHuespedes* huespedesGrupal = resGrupal->getHuespedesReservaGrupal();
                colHuespedes::iterator itHues;
                for (itHues = huespedesGrupal->begin(); itHues != huespedesGrupal->end(); itHues++){
                    nombres.insert(itHues->second->getNombre());   
                } 
            }
        }
    }
    DTInformacionReserva info = DTInformacionReserva(res_hab, num_hab, nombres );
    datosReserva.insert(pair<int, DTInformacionReserva>(num_hab, info)); 

    return datosReserva;
}


// CASO DE USO: BAJA RESERVA

void controladorReserva::seleccionarHostal(string nombreHostal){
    controladorColecciones* controladorColecciones = controladorColecciones::getInstancia();
    colHostales* coleccionHostales = controladorColecciones->getColHostales();
    colHostales::iterator iterHostales = coleccionHostales->find(nombreHostal);

    if(iterHostales == coleccionHostales->end()){
        throw std::invalid_argument("El hostal seleccionado no es correcto");
    }

    hostalSeleccionado = iterHostales->second;
}

mapColReservas controladorReserva::listarReservasDeHostal(){
    colHabitaciones* habitacionesDelHostal = hostalSeleccionado->getHabitaciones();
    colHabitaciones::iterator iterHab;

    mapColReservas reservasDelHostal;

    for(iterHab = habitacionesDelHostal->begin(); iterHab != habitacionesDelHostal->end(); iterHab++){
        habitacion* hab = iterHab->second;
        colDTReservas reservasHabitacion = hab->getDTReservasHabitacion();
        colDTReservas::iterator iterDTRes;

        for (iterDTRes = reservasHabitacion.begin(); iterDTRes != reservasHabitacion.end(); iterDTRes++){
            DTReserva dtRes = iterDTRes->second;
            reservasDelHostal.insert(pair<int, DTReserva> (dtRes.getCodigo(), dtRes));
        }
    }

    if(reservasDelHostal.size() == 0){
        throw std::runtime_error("No hay reservas en el hostal seleccionado");
    }

    this->reservasHostal = reservasDelHostal;
    return reservasDelHostal;
}

void controladorReserva::seleccionarNumeroReserva(int numReserva){
    mapColReservas::iterator iterDTRes = reservasHostal.find(numReserva);
    
    if(iterDTRes == reservasHostal.end()){
        throw std::invalid_argument("La reserva seleccionada no es correcta");
    }

    controladorColecciones *controladorColecciones = controladorColecciones::getInstancia();
    colReservas* coleccionReservas = controladorColecciones->getColReservas();
    colReservas::iterator iterRes = coleccionReservas->find(numReserva);

    if(iterRes == coleccionReservas->end()){
        throw std::invalid_argument("La reserva seleccionada no es correcta");
    }

    reservaSeleccionada = iterRes->second;
}

void controladorReserva::confirmarBajaReserva(){
    reservaSeleccionada->eliminarHuespedes();
    int codigoReserva = reservaSeleccionada->getCodigo(); 
    reservaSeleccionada->getHabitacion()->eliminarReservaDeHabitacion(codigoReserva);
    
    colEstadias estadiasReserva = reservaSeleccionada->getColEstadias();
    colEstadias::iterator iterEstadia;

    for(iterEstadia = estadiasReserva.begin(); iterEstadia != estadiasReserva.end(); iterEstadia++){
        estadia* est = iterEstadia->second;
        est->eliminarEstadia();
        delete est;
    }
    
    liberarMemoriaBajaReserva();
}

void controladorReserva::cancelarBajaReserva(){
    liberarMemoriaBajaReserva();
}

void controladorReserva::liberarMemoriaBajaReserva(){
    hostalSeleccionado = NULL;
    reservaSeleccionada = NULL;
}



//Termina BAJA RESERVA