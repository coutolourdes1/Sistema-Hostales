#include "ControladorDatos.h"
#include "ControladorUsuario.h"
#include "ControladorHostales.h"
#include "ControladorEstadia.h"
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

    controladorUsuario->setEmailUsuario("sofia@mail.com");
    controladorUsuario->setNombreUsuario("Sofia");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(true);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("frodo@mail.com");
    controladorUsuario->setNombreUsuario("Frodo");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(true);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("sam@mail.com");
    controladorUsuario->setNombreUsuario("Sam");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(false);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("merry@mail.com");
    controladorUsuario->setNombreUsuario("Merry");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(false);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("pipin@mail.com");
    controladorUsuario->setNombreUsuario("Pipin");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(false);
    controladorUsuario->confirmarAltaHuesped();

    controladorUsuario->setEmailUsuario("seba@mail.com");
    controladorUsuario->setNombreUsuario("Seba");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setEsFinger(true);
    controladorUsuario->confirmarAltaHuesped();

}


void controladorDatos::AgregarEmpleado(){

    controladorUsuario *controladorUsuario = controladorUsuario::getInstancia();
    
    //E1
    controladorUsuario->setEmailUsuario("emilia@mail.com");
    controladorUsuario->setNombreUsuario("Emilia");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setCargoEmpleado("Recepcion");
    controladorUsuario->confirmarAltaEmpleado();

    //E2
    controladorUsuario->setEmailUsuario("leo@mail.com");
    controladorUsuario->setNombreUsuario("Leo");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setCargoEmpleado("Recepcion");
    controladorUsuario->confirmarAltaEmpleado();

    //E3
    controladorUsuario->setEmailUsuario("alina@mail.com");
    controladorUsuario->setNombreUsuario("Alina");
    controladorUsuario->setContraseniaUsuario("123");
    controladorUsuario->setCargoEmpleado("Administracion");
    controladorUsuario->confirmarAltaEmpleado();

    //E4
    controladorUsuario->setEmailUsuario("barli@mail.com");
    controladorUsuario->setNombreUsuario("Barlin");
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

    //R1
    string hostal = "La posada del finger";
    DTFecha c_in1 = DTFecha(01, 05, 2022);
    DTFecha c_out1 = DTFecha(10, 05, 2022);
    bool esgrupal = false;
    controladorHostales->setFechas(c_in1, c_out1);
    mapColHabitaciones aux = controladorHostales->habitacionesDispDeHostal(hostal, c_in1, c_out1, esgrupal);
    controladorHostales->seleccionarHabitacion(1);
    controladorHostales->seleccionarHuesped("sofia@mail.com");
    controladorHostales->confirmarReserva();
    
    //R2
    string hostal2 = "El Pony Pisador";
    DTFecha c_in2 = DTFecha(04, 01, 2001);
    DTFecha c_out2 = DTFecha(05, 01, 2001);
    bool esgrupal2 = true;
    controladorHostales->setFechas(c_in2, c_out2);
    mapColHabitaciones aux2 = controladorHostales->habitacionesDispDeHostal(hostal2, c_in2, c_out2, esgrupal2);
    controladorHostales->seleccionarHabitacion(1);
    controladorHostales->seleccionarHuesped("frodo@mail.com");
    controladorHostales->agregarHuesped("sam@mail.com");
    controladorHostales->agregarHuesped("merry@mail.com");
    controladorHostales->agregarHuesped("pipin@mail.com");
    controladorHostales->confirmarReserva();
    
    //R3
    string hostal3 = "La posada del finger";
    DTFecha c_in3 = DTFecha(07, 06, 2022);
    DTFecha c_out3 = DTFecha(30, 06, 2022);
    bool esgrupal3 = false;
    controladorHostales->setFechas(c_in1, c_out1);
    mapColHabitaciones aux3 = controladorHostales->habitacionesDispDeHostal(hostal3, c_in3, c_out3, esgrupal3);
    controladorHostales->seleccionarHabitacion(3);
    controladorHostales->seleccionarHuesped("sofia@mail.com");
    controladorHostales->confirmarReserva();

    //R4
    string hostal4 = "Caverna Lujosa";
    DTFecha c_in4 = DTFecha(10, 06, 2022);
    DTFecha c_out4 = DTFecha(30, 06, 2022);
    bool esgrupal4 = false;    
    controladorHostales->setFechas(c_in1, c_out1);
    mapColHabitaciones aux4 = controladorHostales->habitacionesDispDeHostal(hostal4, c_in3, c_out3, esgrupal4);
    controladorHostales->seleccionarHabitacion(1);
    controladorHostales->seleccionarHuesped("seba@mail.com");
    controladorHostales->confirmarReserva();

}

void controladorDatos::AgregarEstadias(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();

    controladorHostales->seleccionarHostal("La posada del finger");
    string email1 ="sofia@mail.com";
    mapColDTReservas colDTRes = controladorHostales->solicitarReservasDisp(email1);
    controladorHostales->seleccionarReserva(1);
    DTFecha cIn1 = DTFecha(01, 05, 2022);
    controladorHostales->setCheckinEstadia(cIn1);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    string email2 ="frodo@mail.com";
    mapColDTReservas colDTRes2 = controladorHostales->solicitarReservasDisp(email2);
    controladorHostales->seleccionarReserva(2);
    DTFecha cIn2 = DTFecha(04, 01, 2001);
    controladorHostales->setCheckinEstadia(cIn2);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    string email3 = "frodo@mail.com";
    mapColDTReservas colDTRes3 = controladorHostales->solicitarReservasDisp(email3);
    controladorHostales->seleccionarReserva(2);
    DTFecha cIn3 = DTFecha(04, 01, 2001);
    controladorHostales->setCheckinEstadia(cIn3);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    string email4 = "frodo@mail.com";
    mapColDTReservas colDTRes4 = controladorHostales->solicitarReservasDisp(email4);
    controladorHostales->seleccionarReserva(2);
    DTFecha cIn4 = DTFecha(04, 01, 2001);
    controladorHostales->setCheckinEstadia(cIn4);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("El Pony Pisador");
    string email5 = "frodo@mail.com";
    mapColDTReservas colDTRes5 = controladorHostales->solicitarReservasDisp(email5);
    controladorHostales->seleccionarReserva(2);
    DTFecha cIn5 = DTFecha(04, 01, 2001);
    controladorHostales->setCheckinEstadia(cIn5);
    controladorHostales->confirmarEstadia();

    controladorHostales->seleccionarHostal("Caverna Lujosa");
    string email6 = "seba@mail.com";
    mapColDTReservas colDTRes6 = controladorHostales->solicitarReservasDisp(email6);
    controladorHostales->seleccionarReserva(4);
    DTFecha cIn6 = DTFecha(07, 06, 2022);
    controladorHostales->setCheckinEstadia(cIn6);
    controladorHostales->confirmarEstadia();

}

void controladorDatos::AgregarFinalizarEstadia(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();
    controladorEstadia *controladorEstadia = controladorEstadia::getInstancia();

    controladorHostales->seleccionarHostal("La posada del finger");
    string huesped1 = "sofia@mail.com";
    mapDTEstadia mapEst1 = controladorHostales->mostrarEstadiasHuesped(huesped1);
    controladorHostales->setEstadiaSeleccionada(1);
    DTFecha fin_est1 = DTFecha(10, 05, 2022);
    controladorHostales->setCheckoutEstadia(fin_est1);

    controladorHostales->seleccionarHostal("El Pony Pisador");
    string huesped2 = "frodo@mail.com";
    mapDTEstadia mapEst2 = controladorHostales->mostrarEstadiasHuesped(huesped2);
    controladorHostales->setEstadiaSeleccionada(2);
    DTFecha fin_est2 = DTFecha(05, 01, 2001);
    controladorHostales->setCheckoutEstadia(fin_est2);

    controladorHostales->seleccionarHostal("Caverna Lujosa");
    string huesped3 = "seba@mail.com";
    mapDTEstadia mapEst3 = controladorHostales->mostrarEstadiasHuesped(huesped3);
    controladorHostales->setEstadiaSeleccionada(6);
    DTFecha fin_est3 = DTFecha(15, 06, 2022);
    controladorHostales->setCheckoutEstadia(fin_est3); 
}

void controladorDatos::AgregarCalificacionesEstadia(){

    controladorHostales *controladorHostales = controladorHostales::getInstancia();
    controladorEstadia *controladorEstadia = controladorEstadia::getInstancia();
 
    controladorHostales->seleccionarHostal("La posada del finger");
    string mail1 = "sofia@mail.com";
    mapColEstadias estadias = controladorEstadia->listarEstadiasFinalizadasHuesped(mail1);
    controladorEstadia->seleccionarEstadia(1);
    string res1 = "Un poco raro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía la del lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo";
    float cal1 = 3;
    DTFecha f_cal1 = DTFecha(11, 05, 2022);
    controladorEstadia->agregarCalificacion(res1, cal1, f_cal1);

    controladorHostales->seleccionarHostal("El pony pisador");
    string mail2 = "frodo@mail.com";
    mapColEstadias estadias1 = controladorEstadia->listarEstadiasFinalizadasHuesped(mail2);
    controladorEstadia->seleccionarEstadia(1);
    string res2 = "Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos";
    float cal2 = 2;
    DTFecha f_cal2 = DTFecha(05,01, 2001);
    controladorEstadia->agregarCalificacion(res2, cal2, f_cal2);

    controladorHostales->seleccionarHostal("Caverna lujosa");
    string mail3 = "seba@mail.com";
    mapColEstadias estadias1 = controladorEstadia->listarEstadiasFinalizadasHuesped(mail2);
    controladorEstadia->seleccionarEstadia(1);
    string res3 = "Había pulgas en la habitacion. Que lugar más mamarracho!!";
    float cal3 = 1;
    DTFecha f_cal3 = DTFecha(15, 06, 2022);
    controladorEstadia->agregarCalificacion(res3, cal3, f_cal3);

}

void controladorDatos::AgregarComentarCalificacion(){
    

}

