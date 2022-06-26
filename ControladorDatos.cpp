#include "ControladorDatos.h"
#include "ControladorUsuario.h"
#include "ControladorHostales.h"
#include "DTFecha.h"



controladorDatos *controladorDatos::instancia = NULL;

controladorDatos::controladorDatos(){}

controladorDatos *controladorDatos::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new controladorDatos();
    }
    return instancia;
};

void controladorDatos::AgregarHuesped(){

    controladorUsuario *controladorUsuario = controladorUsuario::getInstancia();

    controladorUsuario->setEmailUsuario("Sofia");
    controladorUsuario->setNombreUsuario("sofia@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(true);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("Frodo");
    controladorUsuario->setNombreUsuario("frodo@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(true);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("Sam");
    controladorUsuario->setNombreUsuario("sam@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(false);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("Merry");
    controladorUsuario->setNombreUsuario("merry@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(false);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("Pippin");
    controladorUsuario->setNombreUsuario("pipin@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(false);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("Seba");
    controladorUsuario->setNombreUsuario("seba@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(true);
    controladorUsuario->confirmarAltaHuesped();

}


void controladorDatos::AgregarEmpleado(){

    controladorUsuario *controladorUsuario = controladorUsuario::getInstancia();
    
    //E1
    controladorUsuario->setEmailUsuario("Emilia");
    controladorUsuario->setNombreUsuario("emilia@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setCargoEmpleado("Recepcion");
    controladorUsuario->confirmarAltaEmpleado();

    //E2
    controladorUsuario->setEmailUsuario("Leonardo");
    controladorUsuario->setNombreUsuario("leo@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setCargoEmpleado("Recepcion");
    controladorUsuario->confirmarAltaEmpleado();

    //E3
    controladorUsuario->setEmailUsuario("Alina");
    controladorUsuario->setNombreUsuario("alina@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setCargoEmpleado("Administracion");
    controladorUsuario->confirmarAltaEmpleado();

    //E4
    controladorUsuario->setEmailUsuario("Barliman");
    controladorUsuario->setNombreUsuario("barli@mail.com");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setCargoEmpleado("Recepcion");
    controladorUsuario->confirmarAltaEmpleado();

}

void controladorDatos::AgregarHostales(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();

    controladorHostales->setNombreHostal("La posada del finger");
    controladorHostales->setDireccionHostal("Av de la playa 123, Maldonado");
    controladorHostales->setTelefonoHostal("099111111");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->setNombreHostal("Mochileros");
    controladorHostales->setDireccionHostal("Rambla Costanera 333, Rocha");
    controladorHostales->setTelefonoHostal("42579512");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->setNombreHostal("El Pony Pisador");
    controladorHostales->setDireccionHostal("Bree (preguntar por Gandalf)");
    controladorHostales->setTelefonoHostal("000");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->setNombreHostal("Altos de Fing");
    controladorHostales->setDireccionHostal("Av del Toro 1424");
    controladorHostales->setTelefonoHostal("099892992");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->setNombreHostal("Caverna Lujosa");
    controladorHostales->setDireccionHostal("Amaya 1424");
    controladorHostales->setTelefonoHostal("233233235");
    controladorHostales->confirmarAltaHostal();

}

void controladorDatos::AgregarHabitaciones(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();

    controladorHostales->seleccionarHostal("La posada del finger");
    controladorHostales->setNumeroHabitacion(1);
    controladorHostales->setCapacidadHabitacion(2);
    controladorHostales->setPrecioHabitacion(40);
    controladorHostales->confirmarAltaHabitacion();

    controladorHostales->seleccionarHostal("La posada del finger");
    controladorHostales->setNumeroHabitacion(2);
    controladorHostales->setCapacidadHabitacion(7);
    controladorHostales->setPrecioHabitacion(10);
    controladorHostales->confirmarAltaHabitacion();

    controladorHostales->seleccionarHostal("La posada del finger");
    controladorHostales->setNumeroHabitacion(3);
    controladorHostales->setCapacidadHabitacion(3);
    controladorHostales->setPrecioHabitacion(30);
    controladorHostales->confirmarAltaHabitacion();

    controladorHostales->seleccionarHostal("La posada del finger");
    controladorHostales->setNumeroHabitacion(4);
    controladorHostales->setCapacidadHabitacion(12);
    controladorHostales->setPrecioHabitacion(5);
    controladorHostales->confirmarAltaHabitacion();

    controladorHostales->seleccionarHostal("Caverna Lujosa");
    controladorHostales->setNumeroHabitacion(1);
    controladorHostales->setCapacidadHabitacion(2);
    controladorHostales->setPrecioHabitacion(3);
    controladorHostales->confirmarAltaHabitacion();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    controladorHostales->setNumeroHabitacion(1);
    controladorHostales->setCapacidadHabitacion(5);
    controladorHostales->setPrecioHabitacion(9);
    controladorHostales->confirmarAltaHabitacion();
}

void controladorDatos::AgregarEmpleadoAHostel(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();

    controladorHostales->seleccionarHostal("La posada del finger");
    controladorHostales->seleccionarEmpleado("emilia@mail.com");
    controladorHostales->confirmarAsignacion();

    controladorHostales->seleccionarHostal("Mochileros");
    controladorHostales->seleccionarEmpleado("leo@mail.com");
    controladorHostales->confirmarAsignacion();

    controladorHostales->seleccionarHostal("Mochileros");
    controladorHostales->seleccionarEmpleado("alina@mail.com");
    controladorHostales->confirmarAsignacion();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    controladorHostales->seleccionarEmpleado("barli@mail.com");
    controladorHostales->confirmarAsignacion();

}

void controladorDatos::AgregarReservas(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();

    controladorHostales->seleccionarHostal("La posada del finger");
    DTFecha c_in1 = DTFecha(01, 05, 22);
    DTFecha c_out1 = DTFecha(10, 05, 22);
    controladorHostales->setFechas(c_in1, c_out1);
    controladorHostales->setEsGrupal(false);
    controladorHostales->seleccionarHabitacion(1);
    controladorHostales->seleccionarHuesped("sofia@mail.com");
    controladorHostales->confirmarReserva();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    DTFecha c_in2 = DTFecha(04, 01, 01);
    DTFecha c_out2 = DTFecha(05, 01, 01);
    controladorHostales->setFechas(c_in2, c_out2);
    controladorHostales->setEsGrupal(true);
    controladorHostales->seleccionarHabitacion(1);
    controladorHostales->seleccionarHuesped("frodo@mail.com");
    controladorHostales->agregarHuesped("sam@mail.com");
    controladorHostales->agregarHuesped("merry@mail.com");
    controladorHostales->agregarHuesped("pippin@mail.com");
    controladorHostales->confirmarReserva();
    
    controladorHostales->seleccionarHostal("La posada del finger");
    DTFecha c_in3 = DTFecha(07, 06, 22);
    DTFecha c_out3 = DTFecha(30, 06, 22);
    controladorHostales->setFechas(c_in1, c_out1);
    controladorHostales->setEsGrupal(false);
    controladorHostales->seleccionarHabitacion(3);
    controladorHostales->seleccionarHuesped("sofia@mail.com");
    controladorHostales->confirmarReserva();

    controladorHostales->seleccionarHostal("Caverna Lujosa");
    DTFecha c_in4 = DTFecha(10, 06, 22);
    DTFecha c_out4 = DTFecha(30, 06, 22);
    controladorHostales->setFechas(c_in1, c_out1);
    controladorHostales->setEsGrupal(false);
    controladorHostales->seleccionarHabitacion(1);
    controladorHostales->seleccionarHuesped("seba@mail.com");
    controladorHostales->confirmarReserva();

}

void controladorDatos::AgregarEstadias(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();

    controladorHostales->seleccionarHostal("La posada del finger");
    controladorHostales->setHuespedSeleccionado("sofia@mail.com");
    controladorHostales->seleccionarReserva(1);
    DTFecha cIn1 = DTFecha(01, 05, 22);
    controladorHostales->setCheckinEstadia(cIn1);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    controladorHostales->setHuespedSeleccionado("frodo@mail.com");
    controladorHostales->seleccionarReserva(1);
    DTFecha cIn2 = DTFecha(04, 01, 01);
    controladorHostales->setCheckinEstadia(cIn2);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    controladorHostales->setHuespedSeleccionado("frodo@mail.com");
    controladorHostales->seleccionarReserva(1);
    DTFecha cIn3 = DTFecha(01, 05, 22);
    controladorHostales->setCheckinEstadia(cIn3);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    controladorHostales->setHuespedSeleccionado("frodo@mail.com");
    controladorHostales->seleccionarReserva(1);
    DTFecha cIn4 = DTFecha(01, 05, 22);
    controladorHostales->setCheckinEstadia(cIn4);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    controladorHostales->setHuespedSeleccionado("frodo@mail.com");
    controladorHostales->seleccionarReserva(1);
    DTFecha cIn5 = DTFecha(01, 05, 22);
    controladorHostales->setCheckinEstadia(cIn5);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("Caverna Lujosa");
    controladorHostales->setHuespedSeleccionado("frodo@mail.com");
    controladorHostales->seleccionarReserva(1);
    DTFecha cIn6 = DTFecha(07, 06, 22);
    controladorHostales->setCheckinEstadia(cIn6);
    controladorHostales->confirmarEstadia();

}

void controladorDatos::AgregarFinalizarEstadia(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();
    controladorEstadia *controladorEstadia = controladorEstadia::getInstancia();

    controladorHostales->seleccionarHostal("La posada del finger");
    controladorEstadia->setEstadiaSeleccionada(1);
    DTFecha fin_est1 = DTFecha(10, 05, 22);
    controladorHostales->setCheckoutEstadia(fin_est1);

    controladorHostales->seleccionarHostal("El Pony Pisador");
    controladorEstadia->setEstadiaSeleccionada(1);
    DTFecha fin_est2 = DTFecha(05, 01, 01);
    controladorHostales->setCheckoutEstadia(fin_est2);
    
    controladorHostales->seleccionarHostal("Caverna Lujosa");
    controladorEstadia->setEstadiaSeleccionada(1);
    DTFecha fin_est3 = DTFecha(15, 06, 22);
    controladorHostales->setCheckoutEstadia(fin_est3);
}

void controladorDatos::AgregarCalificacionesEstadia(){


}

void controladorDatos::AgregarComentarCalificacion(){


}

