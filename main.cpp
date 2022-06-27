#include "IControladorUsuario.h"
#include "IControladorReserva.h"
#include "IControladorHostales.h"
#include "IControladorEstadia.h"
#include "IControladorEmpleado.h"
#include "IControladorColecciones.h"
#include "IControladorResenia.h"
#include "Fabrica.h"

#include "Estadia.h"


int main()
{
  DTFecha fechaActual = DTFecha(1, 1, 2022);
  fabrica *fabrica = fabrica::getInstancia();

  IControladorHostales *controladorHostales = fabrica->getControladorHostales();
  IControladorReserva *controladorReserva = fabrica->getControladorReserva();
  IControladorEstadia *controladorEstadia = fabrica->getControladorEstadia();
  IControladorUsuario *controladorUsuario = fabrica->getControladorUsuario();
  IControladorResenia *controladorResenia = fabrica->getControladorResenia();
  IControladorEmpleado *controladorEmpleado = fabrica->getControladorEmpleado();
  //IControladorColecciones *controladorColecciones = fabrica->getControladorColecciones();
  controladorDatos *controladorDatos = fabrica->getControladorDatos();


    // //Cargamos huespedes
    // controladorUsuario->setEmailUsuario("huesped1@email.com");
    // controladorUsuario->setNombreUsuario("huesped1");
    // controladorUsuario->setContraseniaUsuario("123");
    // controladorUsuario->setEsFinger(true);
    // controladorUsuario->confirmarAltaHuesped();

    // controladorUsuario->setEmailUsuario("huesped2@email.com");
    // controladorUsuario->setNombreUsuario("huesped2");
    // controladorUsuario->setContraseniaUsuario("223");
    // controladorUsuario->setEsFinger(true);
    // controladorUsuario->confirmarAltaHuesped();

    // controladorUsuario->setEmailUsuario("huesped3@email.com");
    // controladorUsuario->setNombreUsuario("huesped3");
    // controladorUsuario->setContraseniaUsuario("323");
    // controladorUsuario->setEsFinger(false);
    // controladorUsuario->confirmarAltaHuesped();

    // controladorUsuario->setEmailUsuario("huesped4@email.com");
    // controladorUsuario->setNombreUsuario("huesped4");
    // controladorUsuario->setContraseniaUsuario("423");
    // controladorUsuario->setEsFinger(false);
    // controladorUsuario->confirmarAltaHuesped();

    // //Cargamos empleados
    // controladorUsuario->setEmailUsuario("empleado1@email.com");
    // controladorUsuario->setNombreUsuario("Empleado1");
    // controladorUsuario->setContraseniaUsuario("123");
    // controladorUsuario->setCargoEmpleado("Administrador");
    // controladorUsuario->confirmarAltaEmpleado();

    // controladorUsuario->setEmailUsuario("empleado2@email.com");
    // controladorUsuario->setNombreUsuario("Empleado2");
    // controladorUsuario->setContraseniaUsuario("223");
    // controladorUsuario->setCargoEmpleado("Limpiador");
    // controladorUsuario->confirmarAltaEmpleado();

    // controladorUsuario->setEmailUsuario("empleado3@email.com");
    // controladorUsuario->setNombreUsuario("Empleado3");
    // controladorUsuario->setContraseniaUsuario("323");
    // controladorUsuario->setCargoEmpleado("CargoPrueba");
    // controladorUsuario->confirmarAltaEmpleado();

    // controladorUsuario->setEmailUsuario("empleado4@email.com");
    // controladorUsuario->setNombreUsuario("Empleado4");
    // controladorUsuario->setContraseniaUsuario("423");
    // controladorUsuario->setCargoEmpleado("Gerente");
    // controladorUsuario->confirmarAltaEmpleado();

    // //Carga hostales
    // controladorHostales->setNombreHostal("hostal1");
    // controladorHostales->setDireccionHostal("direccion1");
    // controladorHostales->setTelefonoHostal("telefono1");
    // controladorHostales->confirmarAltaHostal();
    // //Habitacion del hostal 1
    // controladorHostales->seleccionarHostal("hostal1");
    // controladorHostales->setNumeroHabitacion(1);
    // controladorHostales->setCapacidadHabitacion(10);
    // controladorHostales->setPrecioHabitacion(1000);
    // controladorHostales->confirmarAltaHabitacion();
    // //Habitacion del hostal 1
    // controladorHostales->seleccionarHostal("hostal1");
    // controladorHostales->setNumeroHabitacion(4);
    // controladorHostales->setCapacidadHabitacion(10);
    // controladorHostales->setPrecioHabitacion(1000);
    // controladorHostales->confirmarAltaHabitacion();
    // //Realizar reserva hostal1 habitacion numero 1:
    // controladorHostales->habitacionesDispDeHostal("hostal1", DTFecha(1, 1, 2022), DTFecha(10, 1, 2022), true);
    // controladorHostales->seleccionarHabitacion(1);
    // controladorHostales->seleccionarHuesped("huesped1@email.com");
    // controladorHostales->agregarHuesped("huesped2@email.com");
    // controladorHostales->agregarHuesped("huesped3@email.com");
    // controladorHostales->confirmarReserva(fechaActual);
    // //Realizar reserva hostal1 habitacion numero 4:
    // controladorHostales->habitacionesDispDeHostal("hostal1", DTFecha(1, 1, 2023), DTFecha(10, 1, 2023), false);
    // controladorHostales->seleccionarHabitacion(4);
    // controladorHostales->seleccionarHuesped("huesped1@email.com");
    // controladorHostales->confirmarReserva(fechaActual);
    // //Registrar Estadia
    // controladorHostales->solicitarReservasDisp("huesped1@email.com");
    // controladorHostales->seleccionarReserva(1);
    // controladorHostales->setCheckinEstadia(DTFecha(1, 1, 2022));
    // controladorHostales->confirmarEstadia();
    // //Registrar Estadia
    // controladorHostales->solicitarReservasDisp("huesped1@email.com");
    // controladorHostales->seleccionarReserva(2);
    // controladorHostales->setCheckinEstadia(DTFecha(1, 5, 2022));
    // controladorHostales->confirmarEstadia();
    // //Finalizar estadia
    // controladorHostales->seleccionarHostal("hostal1");
    // controladorHostales->mostrarEstadiasHuesped("huesped1@email.com");
    // controladorHostales->setEstadiaSeleccionada(1);
    // controladorHostales->setCheckoutEstadia(DTFecha(10, 1, 2022));
    // controladorHostales->finalizarEstadia();



    // controladorHostales->setNombreHostal("hostal2");
    // controladorHostales->setDireccionHostal("direccion2");
    // controladorHostales->setTelefonoHostal("telefono2");
    // controladorHostales->confirmarAltaHostal();
    // //Habitacion del hostal 2
    // controladorHostales->seleccionarHostal("hostal2");
    // controladorHostales->setNumeroHabitacion(2);
    // controladorHostales->setCapacidadHabitacion(20);
    // controladorHostales->setPrecioHabitacion(2000);
    // controladorHostales->confirmarAltaHabitacion();
    // //Realizar reserva hostal2 habitacion numero 2:
    // controladorHostales->habitacionesDispDeHostal("hostal2", DTFecha(1, 1, 2023), DTFecha(10, 1, 2023), false);
    // controladorHostales->seleccionarHabitacion(2);
    // controladorHostales->seleccionarHuesped("huesped4@email.com");
    // controladorHostales->confirmarReserva(fechaActual);
    // //Registrar Estadia
    // controladorHostales->solicitarReservasDisp("huesped4@email.com");
    // controladorHostales->seleccionarReserva(3);
    // controladorHostales->setCheckinEstadia(DTFecha(1, 1, 2022));
    // controladorHostales->confirmarEstadia();
    // //Finalizar estadia
    // controladorHostales->seleccionarHostal("hostal2");
    // controladorHostales->mostrarEstadiasHuesped("huesped4@email.com");
    // controladorHostales->setEstadiaSeleccionada(3);
    // controladorHostales->setCheckoutEstadia(DTFecha(10, 1, 2022));
    // controladorHostales->finalizarEstadia();


    // controladorHostales->setNombreHostal("hostal3");
    // controladorHostales->setDireccionHostal("direccion3");
    // controladorHostales->setTelefonoHostal("telefono3");
    // controladorHostales->confirmarAltaHostal();
    // //Habitacion del hostal 3
    // controladorHostales->seleccionarHostal("hostal3");
    // controladorHostales->setNumeroHabitacion(3);
    // controladorHostales->setCapacidadHabitacion(30);
    // controladorHostales->setPrecioHabitacion(3000);
    // controladorHostales->confirmarAltaHabitacion();

  

  int mvar1;
  do
  {
    cout << "0. Cargar datos. \n";
    cout << "1. Alta Usuario. \n";
    cout << "2. Alta Hostal. \n";
    cout << "3. Alta Habitacion. \n";
    cout << "4. Asignar Empleado a Hostal. \n";
    cout << "5. Realizar Reserva. \n";
    cout << "6. Consultar Top tres de hostales. \n";
    cout << "7. Registar Estadia. \n";
    cout << "8. Finalizar Estadia. \n";
    cout << "9. Calificar Estadia. \n";
    cout << "10. Comentar Calificacion. \n";
    cout << "11. Consulta de Usuario. \n";
    cout << "12. Consulta de Hostal. \n";
    cout << "13. Consulta de Reserva. \n";
    cout << "14. Consulta de Estadia. \n";
    cout << "15. Baja Reserva. \n";
    cout << "16. Suscribirse a Notificaciones. \n";
    cout << "17. Consulta de Notificaciones. \n";
    cout << "18. Eliminar suscripcion. \n";
    cout << "19. Cargar fecha del sistema. \n";
    cout << "20. Salir. \n";
    cin >> mvar1;
    switch (mvar1)
    {
    case 0:
    {
      controladorDatos->AgregarHuesped();
      controladorDatos->AgregarEmpleado();
      controladorDatos->AgregarHostales();
      controladorDatos->AgregarHabitaciones();
      controladorDatos->AgregarEmpleadoAHostel(); 
      controladorDatos->AgregarReservas(); 
      controladorDatos->AgregarEstadias(); 
      controladorDatos->AgregarFinalizarEstadia(); 
      controladorDatos->AgregarCalificacionesEstadia();
      controladorDatos->AgregarComentarCalificacion();
      cout << "Datos de prueba cargados correctamente" << endl;
      
      break;
    } 
    case 1: // ALTA USUARIO
    {
      string email;
      string nombre;
      string constrasena;
      cout << "Ingrese el email del usuario \n";
      cin >> email;
      while (controladorUsuario->existeEmail(email))
      {
        cout << "El email ingresado ya se encontraba en el sistema, ingrese otro:  \n";
        cin >> email;
      }
      controladorUsuario->setEmailUsuario(email);
      cout << "Ingrese el nombre del usuario \n";
      cin >> nombre;
      controladorUsuario->setNombreUsuario(nombre);
      cout << "Ingrese la constrasena del usuario \n";
      cin >> constrasena;
      controladorUsuario->setContraseniaUsuario(constrasena);
      int huesped_empleado;
      cout << "Seleccione el tipo de usuario a registrar:" << endl;
      cout << "1- Huesped. " << endl;
      cout << "2- Empleado. " << endl;
      cin >> huesped_empleado;
      bool confirmar;
      switch (huesped_empleado)
      {
      case 1:
      {
        bool EsFinger;
        cout << "El huesped es Finger (1->SI, 0->No). \n";
        cin >> EsFinger;
        controladorUsuario->setEsFinger(EsFinger);
        cout << "Desea confirmar el alta del Huesped (1->SI, 0->No). \n";
        cin >> confirmar;
        if (confirmar)
        {
          controladorUsuario->confirmarAltaHuesped();
        }
        else
        {
          controladorUsuario->cancelarAltaUsuario();
        }
        break;
      }
      case 2:
      {
        string cargo;
        cout << "Ingrese el cargo del empleado \n";
        cin >> cargo;
        controladorUsuario->setCargoEmpleado(cargo);
        cout << "Desea confirmar el alta del Empleado (1->SI, 0->No). \n";
        cin >> confirmar;
        if (confirmar)
        {
          controladorUsuario->confirmarAltaEmpleado();
        }
        else
        {
          controladorUsuario->cancelarAltaUsuario();
        }
      }
      break;
      }
      break;
    }
    case 2: // ALTA HOSTAL
    {
      string nombreHostal;
      string direccionHostal;
      string telefonoHostal;
      bool confirmar;
      cout << "Ingrese nombre del Hostal a registrar: \n";
      cin.ignore();
      getline (cin, nombreHostal);
      controladorHostales->setNombreHostal(nombreHostal);
      cout << "Ingrese la direccion del Hostal a registrar: \n";
      cin.ignore();
      getline (cin, direccionHostal);
      controladorHostales->setDireccionHostal(direccionHostal);
      cout << "Ingrese el telefono del Hostal a registrar: \n";
      cin >> telefonoHostal;
      controladorHostales->setTelefonoHostal(telefonoHostal);
      cout << "Desea confirmar el alta del Hostal (1->SI, 0->No). \n";
      cin >> confirmar;
      if (confirmar)
      {
        controladorHostales->confirmarAltaHostal();
      }
      else
      {
        controladorHostales->cancelarAltaHostal();
      }
      break;
    }
    case 3: // ALTA HABITACION
    {
      mapColDTHostales hostales = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator iterHostal;

      for (iterHostal = hostales.begin(); iterHostal != hostales.end(); iterHostal++)
      {
        cout << iterHostal->second;
      }

      string nombreHostal;
      cout << "Ingrese el nombre del hostal: ";
      cin.ignore();
      getline (cin, nombreHostal);
      controladorHostales->seleccionarHostal(nombreHostal);

      int numHab;
      cout << "Ingrese el numero de la nueva habitacion: ";
      cin >> numHab;
      controladorHostales->setNumeroHabitacion(numHab);

      int capacidadHab;
      cout << "Ingrese la capacidad de la nueva habitacion: ";
      cin >> capacidadHab;
      controladorHostales->setCapacidadHabitacion(capacidadHab);

      float precioHab;
      cout << "Ingrese el precio de la nueva habitacion: ";
      cin >> precioHab;
      controladorHostales->setPrecioHabitacion(precioHab);

      int confirmar;
      cout << "Desea confirmar la nueva habitacion? (0 -> NO, 1 -> SI)";
      cin >> confirmar;
      if (confirmar == 1)
      {
        controladorHostales->confirmarAltaHabitacion();
        cout << "La habitacion se agregó correctamente." << endl;
      }
      else
      {
        controladorHostales->cancelarAltaHabitacion();
      }

      break;
    }
    case 4: // ASIGNAR EMPLEADO A HOSTAL
    {
      cout << "A continuacion listaremos los hostales registrados en el sistema: \n";
      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;
      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }
      string hostalSeleccionado;
      cout << "Seleccione el hostal escribiendo su nombre: \n";
      cin.ignore();
      getline (cin, hostalSeleccionado);
      controladorHostales->seleccionarHostal(hostalSeleccionado);

      cout << "A continuacion listaremos los empleados que todavia no fueron asignados al Hostal seleccionado: \n";
      mapColEmpleados colDTEmp = controladorHostales->obtenerListaDeEmpleados();
      mapColEmpleados::iterator itcolDTEmp;
      for (itcolDTEmp = colDTEmp.begin(); itcolDTEmp != colDTEmp.end(); itcolDTEmp++)
      {
        DTEmpleado dtemp = itcolDTEmp->second;
        cout << dtemp << endl;
      }
      string empleadoSeleccionado;
      cout << "Seleccione un empleado ingresando su email: \n";
      cin >> empleadoSeleccionado;
      controladorHostales->seleccionarEmpleado(empleadoSeleccionado);
      bool confirmar;
      cout << "Desea confirmar la asignacion del empleado al hostal (1->SI, 0->No). \n";
      cin >> confirmar;
      if (confirmar)
      {
        controladorHostales->confirmarAsignacion();
      }
      else
      {
        controladorHostales->cancelarAsignacion();
      }

      break;
    }
    case 5: // REALIZAR RESERVA
    {
      cout << "HOSTALES REGISTRADOS DEL SISTEMA:" << endl;
      mapColHostalesCal hostalesDelSistema = controladorHostales->solicitarListaHostalesCal();
      mapColHostalesCal::iterator iterHostal;

      for (iterHostal = hostalesDelSistema.begin(); iterHostal != hostalesDelSistema.end(); iterHostal++)
      {
        cout << iterHostal->second << endl;
      }

      string nombreHostal;
      int dia, mes, anio;

      cout << "Ingrese nombre del hostal: ";
      cin.ignore();
      getline (cin, nombreHostal);

      cout << "Ingrese dia de checkIn: ";
      cin >> dia;

      cout << "Ingrese mes de checkIn: ";
      cin >> mes;

      cout << "Ingrese anio de checkIn: ";
      cin >> anio;

      DTFecha checkIn = DTFecha(dia, mes, anio);

      cout << "Ingrese dia de checkOut: ";
      cin >> dia;

      cout << "Ingrese mes de checkOut: ";
      cin >> mes;

      cout << "Ingrese anio de checkOut: ";
      cin >> anio;

      DTFecha checkOut = DTFecha(dia, mes, anio);

      int tipoRes;
      cout << "Ingrese tipo de reserva (0 -> Individual, 1 -> Grupal): ";
      cin >> tipoRes;
      bool esGrupal = false;
      if (tipoRes == 1)
        esGrupal = true;

      mapColHabitaciones habDisp = controladorHostales->habitacionesDispDeHostal(nombreHostal, checkIn, checkOut, esGrupal);
      mapColHabitaciones::iterator iterHab;
      cout << "HABITACIONES DISPONIBLES:" << endl;
      for (iterHab = habDisp.begin(); iterHab != habDisp.end(); ++iterHab)
      {
        cout << iterHab->second << endl;
      }

      int habSeleccionada;
      cout << "Seleccione un numero de habitación: ";
      cin >> habSeleccionada;
      controladorHostales->seleccionarHabitacion(habSeleccionada);

      cout << "HUESPEDES REGISTRADOS:" << endl;
      mapDTHuespedes huespedesRegistrados = controladorHostales->solicitarDTHuespedes();
      mapDTHuespedes::iterator iterHuesp;

      for (iterHuesp = huespedesRegistrados.begin(); iterHuesp != huespedesRegistrados.end(); iterHuesp++)
      {
        cout << iterHuesp->second << endl;
      }

      string emailHuesped;
      cout << "Ingrese el email del huesped que desea seleccionar:" << endl;
      cin >> emailHuesped;
      controladorHostales->seleccionarHuesped(emailHuesped);

      if (esGrupal)
      {
        int ingresarOtro;
        cout << "Desea ingresar otro huesped? (0 -> NO, 1 -> SI): ";
        cin >> ingresarOtro;

        while (ingresarOtro == 1)
        {
          string emailOtroHuesp;
          cout << "Ingrese el email del huesped que desea agregar:" << endl;
          cin >> emailOtroHuesp;
          controladorHostales->agregarHuesped(emailOtroHuesp);

          cout << "Desea ingresar otro huesped? (0 -> NO, 1 -> SI): ";
          cin >> ingresarOtro;
        }
      }

      int confirmar;
      cout << "Desea confirmar la reserva? (0 -> NO, 1 -> SI): ";
      cin >> confirmar;

      if (confirmar == 1)
      {
        controladorHostales->confirmarReserva(fechaActual);
        cout << "Su reserva ha sido agregada con éxito.\n";
      }
      else
      {
        controladorHostales->cancelarReserva();
      }
      break;
    }
    case 6: // Consulta Top Tres Hostales
    {
      mapTopTres topTresHostales = controladorHostales->solicitarTopTresHostales();
      mapTopTres::iterator iterHostal;

      for (iterHostal = topTresHostales.begin(); iterHostal != topTresHostales.end(); iterHostal++)
      {
        cout << iterHostal->first << ") " << iterHostal->second << endl;
      }

      string nombreHostal;
      cout << "Ingrese el nombre del hostal que desde consultar: ";
      cin.ignore();
      getline (cin, nombreHostal);
      map<int, DTResenia> reseniasHostal = controladorHostales->detallesHostal(nombreHostal);
      map<int, DTResenia>::iterator iterRes;

      cout << "RESEÑAS DEL HOSTAL " << nombreHostal << ":" << endl;

      if (reseniasHostal.size() == 0)
      {
        cout << "El hostal no tiene reseñas." << endl;
      }
      else
      {
        for (iterRes = reseniasHostal.begin(); iterRes != reseniasHostal.end(); iterRes++)
        {
          cout << iterRes->second << endl;
        }
      }
      break;
    }
    case 7: // REGISTRAR ESTADIA
    {

      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;
      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }
      string hostalSeleccionado;
      cout << "Seleccione el hostal escribiendo su nombre: \n";
      cin.ignore();
      getline (cin, hostalSeleccionado);
      controladorHostales->seleccionarHostal(hostalSeleccionado);
      cout << "Ingrese su email del huesped para registrar su estadia: \n";
      string emailHuesped;
      cin >> emailHuesped;
      mapColDTReservas colDTRes = controladorHostales->solicitarReservasDisp(emailHuesped);
      mapColDTReservas::iterator itColDTRes;
      for (itColDTRes = colDTRes.begin(); itColDTRes != colDTRes.end(); itColDTRes++)
      {
        DTReserva dtres = itColDTRes->second;
        cout << dtres;
      }
      cout << "Seleccione una reserva para registrar su estadia: \n";
      int numeroReserva;
      cin >> numeroReserva;
      controladorHostales->seleccionarReserva(numeroReserva);
      DTFecha fecha = fechaActual;
      controladorHostales->setCheckinEstadia(fecha);
      cout << "Desea confirmar estadia? (0 -> NO, 1 -> SI ): \n";
      bool confirmar;
      cin >> confirmar;
      if (confirmar)
      {
        controladorHostales->confirmarEstadia();
      }
      else
      {
        controladorHostales->cancelarEstadia();
      }
      break;
    }
    case 8: // FINALIZAR ESTADIA
    {
      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;
      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }
      string hostalSeleccionado;
      cout << "Seleccione el hostal escribiendo su nombre: \n";
      cin.ignore();
      getline (cin, hostalSeleccionado);
      controladorHostales->seleccionarHostal(hostalSeleccionado);
      cout << "Ingrese su email del huesped para finalizar su estadia: \n";
      string emailHuesped;
      cin >> emailHuesped;
      mapDTEstadia mapEst = controladorHostales->mostrarEstadiasHuesped(emailHuesped);
      mapDTEstadia::iterator itMapEst;

      if(mapEst.size() == 0){
        cout << "El huesped no tiene estadias registradas sin finalizar" << endl;
      } else {
        for (itMapEst = mapEst.begin(); itMapEst != mapEst.end(); itMapEst++)
        {
          DTEstadia dtest = itMapEst->second;
          cout << dtest << endl;
        }
        cout << "Seleccione la estadia ingresando su codigo: \n";
        int codigoEstadia;
        cin >> codigoEstadia;
        controladorHostales->setEstadiaSeleccionada(codigoEstadia);
        DTFecha fecha = fechaActual;
        controladorHostales->setCheckoutEstadia(fecha);
        controladorHostales->finalizarEstadia();
      }
      break;
    }
    case 9: // calificar estadia
    {
      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;

      cout << "Hostales Registrados: " << endl;

      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }

      string hostalSeleccionado;

      cout << "Selecciona un Hostal: ";
      cin.ignore();
      getline (cin, hostalSeleccionado);
      controladorEstadia->seleccionarHostal(hostalSeleccionado);

      string emailHuesped;
      cout << "Ingrese Email del Huesped que desea ver Estadias: ";
      cin >> emailHuesped;
      mapColEstadias estadias = controladorEstadia->listarEstadiasFinalizadasHuesped(emailHuesped);
      mapColEstadias::iterator itColEst;

      if (estadias.size() == 0)
      {
        cout << "El huesped no tiene estadias finalizadas" << endl;
      }
      else
      {
        cout << "Estadias Finalizadas: " << endl;
        for (itColEst = estadias.begin(); itColEst != estadias.end(); itColEst++)
        {
          DTEstadia dtest = itColEst->second;
          cout << dtest << endl;
        }
        cout << "Seleccione numero de estadia: ";

        int numEst;
        cin >> numEst;
        controladorEstadia->seleccionarEstadia(numEst);
        string res;
        float cal;
        cout << "Ingrese Resenia: ";
        cin.ignore();
        getline (cin, res);

        cout << "Ingrese Calificacion: ";
        cin >> cal;

        DTFecha fecha = fechaActual;
        controladorEstadia->agregarCalificacion(res, cal, fecha);

        cout << "Calificacion realizada correctamente!" << endl;
      }

      break;
    }
    case 10: // COMENTAR CALIFICACION
    {
      string email;
      cout << "Ingrese email del empleado: " << endl;
      cin >> email;

      map<int, string> comentarios = controladorEmpleado->listaComentariosSinResp(email);
      map<int, string>::iterator iterComent;

      if(comentarios.size() != 0){
        cout << "Comentarios sin Responder del Empleado: " << endl;

        for (iterComent = comentarios.begin(); iterComent != comentarios.end(); iterComent++)
        {
          cout << iterComent->first << " - ";
          cout << iterComent->second << endl;
        }

        string respuesta;
        int numeroDeComentario;
        cout << "Ingrese Numero de Comentario a Responder: " << endl;
        cin >> numeroDeComentario;
        cout << "Ingrese la Respuesta: " << endl;
        cin.ignore();
        getline (cin, respuesta);

        controladorEmpleado->responderResenia(numeroDeComentario, respuesta);
        cout << "Se ha guardado la respuesta" << endl;
      } else {
        cout << "Todos los comentarios están respondidos" << endl;
      }

      break;
    }
    case 11: // CONSULTA USUARIO
    {
      string email;
      mapDTUsuario usuarios = controladorUsuario->listarUsuariosRegistrados();
      mapDTUsuario ::iterator iterUsuario;

      cout << "Usuarios Registrados: " << endl;

      for (iterUsuario = usuarios.begin(); iterUsuario != usuarios.end(); iterUsuario++)
      {
        cout << iterUsuario->second;
      }

      cout << "Ingrese el email del usuario a consultar: \n";
      cin >> email;

      if (controladorUsuario->esHuesped(email))
      {
        cout << controladorUsuario->listarHuesped(email) << endl;
      }
      else
      {
        cout << controladorUsuario->listarEmpleado(email) << endl;
      }

      break;
    }
    case 12: // CONSULTA HOSTAL
    {
      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;
      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }
      string hostalSeleccionado;
      cout << "Seleccione el hostal escribiendo su nombre: \n";
      cin.ignore();
      getline (cin, hostalSeleccionado);
      DTInformacionHostal dtinfohos = controladorHostales->obtenerInformacionHostal(hostalSeleccionado);
      cout << dtinfohos << endl;

      break;
    }
    case 13: // CONSULTA RESERVA
    {
      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;
      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }
      string hostalSeleccionado;
      cout << "Seleccione el hostal escribiendo su nombre: \n";
      cin.ignore();
      getline (cin, hostalSeleccionado);
      controladorHostales->seleccionarHostal(hostalSeleccionado);
      colConsultaReserva colRes = controladorReserva->obtenerReservasdelHostal();
      colConsultaReserva::iterator itColRes;
      
      if (colRes.size() != 0){
        cout << "A continuacion listamos las reservas de dicho hostal: \n";
        for (itColRes = colRes.begin(); itColRes != colRes.end(); itColRes++)
      {
        DTInformacionReserva dtinfo = itColRes->second;
        cout << dtinfo;
      }
      } else {
        cout << "No hay reservas para el hostal seleccionado" << endl;
      }

      break;
    }
    case 14: // CONSULTA ESTADIA
    {
      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;
      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }
      string hostalSeleccionado;
      cout << "Seleccione el hostal escribiendo su nombre: \n";
      cin.ignore();
      getline (cin, hostalSeleccionado);
      controladorHostales->seleccionarHostal(hostalSeleccionado);
      cout << "Listaremos las estadias registradas en ese hostal: \n";
      mapColEstadias colEstadias = controladorEstadia->listarEstadias();
      mapColEstadias::iterator iterColEst;
      for (iterColEst = colEstadias.begin(); iterColEst != colEstadias.end(); iterColEst++)
      {
        DTEstadia dtest = iterColEst->second;
        cout << dtest << endl;
      }
      cout << "Seleccione la estadia ingresando el codigo de la misma: \n";
      int codigo;
      cin >> codigo;
      controladorEstadia->setEstadiaBuscada(codigo);
      DTInformacionEstadia dtinfoest = controladorEstadia->informacionEstadia();
      // mapColInfoEstadia::iterator itMapColInfoEst;
      cout << "A continuacion se lista la informacion de la estadia: \n";
      // for (itMapColInfoEst = mapColInfoEst.begin(); itMapColInfoEst != mapColInfoEst.end(); itMapColInfoEst++)
      // {
      //   DTInformacionEstadia dtinfoest = itMapColInfoEst->second;
      cout << dtinfoest << endl;
      // }
      break;
    }
    case 15: // baja reserva
    {
      cout << "A continuacion listaremos los hostales registrados en el sistema: \n";
      mapColDTHostales colDThos = controladorHostales->obtenerHostalesRegistrados();
      mapColDTHostales::iterator itColDThos;
      for (itColDThos = colDThos.begin(); itColDThos != colDThos.end(); itColDThos++)
      {
        DTHostal dthos = itColDThos->second;
        cout << dthos;
      }
      string hostalSeleccionado;
      cout << "Seleccione un hostal ingresando su nombre: " << endl;
      cin.ignore();
      getline (cin, hostalSeleccionado);
      controladorReserva->seleccionarHostal(hostalSeleccionado);
      
      cout << "A continuacion listaremos las reservas del hostal seleccionado: \n";
      mapColReservas colDTRes = controladorReserva->listarReservasDeHostal();
      mapColReservas::iterator itRes;
      for (itRes = colDTRes.begin(); itRes != colDTRes.end(); itRes++)
      {
        DTReserva dtres = itRes->second;
        cout << dtres;
      }
      int numRes;
      cout << "Seleccionar numero de reserva: \n";
      cin >> numRes;
      controladorReserva->seleccionarNumeroReserva(numRes);
      cout << "Desea confirmar la baja de la reserva? (1-Si 2-No): \n";
      bool confirmar;
      cin >> confirmar;
      if (confirmar)
      {
        controladorReserva->confirmarBajaReserva();
      }
      else
      {
        controladorReserva->cancelarBajaReserva();
      }
      break;
    }
    case 16: // suscribirse a not
    {
      cout << "A listaremos todos los empleados registrados en el sistema: \n";
      mapDTEmpleado colEmp = controladorEmpleado->listarEmpleados();
      mapDTEmpleado::iterator colDTEmple;
      for (colDTEmple = colEmp.begin(); colDTEmple != colEmp.end(); colDTEmple++)
      {
        DTEmpleado dte = colDTEmple->second;
        cout << dte << endl;
      }
      cout << "Seleccione un empleado a recibir notificaciones, ingresando su email: \n";
      string emailEmpleado;
      cin >> emailEmpleado;
      controladorEmpleado->seleccionarEmpleadoANotificar(emailEmpleado);
      cout << "El empleado se ha suscripto de manera exitosa! \n";
      break;
    }
    case 17: // consulta not
    {
      cout << "Listaremos todos los empleados que estan suscriptos a recibir notificaciones: \n";
      mapDTEmpleado colDTEmpSuscriptos = controladorResenia->getEmpleadosObservadores();
      mapDTEmpleado::iterator iterColDTEmpSuscriptos;

      if(colDTEmpSuscriptos.size() != 0){
        for (iterColDTEmpSuscriptos = colDTEmpSuscriptos.begin(); iterColDTEmpSuscriptos != colDTEmpSuscriptos.end(); iterColDTEmpSuscriptos++)
        {
          cout << iterColDTEmpSuscriptos->second << endl;
        }
        string email_emp;
        cout << "Ingrese el email del empleado seleccionado: \n";
        cin >> email_emp;
        mapInfoNotificaciones colnoti = controladorEmpleado->getInfoNotificaciones(email_emp);
        mapInfoNotificaciones::iterator aux;
        if(colnoti.size() > 0){
          for (aux = colnoti.begin(); aux != colnoti.end(); aux++)
          {
              DTInformacionNotificaciones dtnfo = aux->second;
              cout << dtnfo <<endl;
          }
        }else{
          cout << "No existen notificaciones para el empleado seleccionado. \n";
        }
      } else {
        cout << "No hay empleados suscriptos" << endl;
      }

      break;
    }
    case 18: // eliminar sus
    {
      cout << "Listaremos todos los empleados que estan suscriptos a recibir notificaciones: \n";
      mapDTEmpleado colDTEmpSuscriptos = controladorResenia->getEmpleadosObservadores();
      mapDTEmpleado::iterator iterColDTEmpSuscriptos;
      if(colDTEmpSuscriptos.size() != 0){
        for (iterColDTEmpSuscriptos = colDTEmpSuscriptos.begin(); iterColDTEmpSuscriptos != colDTEmpSuscriptos.end(); iterColDTEmpSuscriptos++)
        {
          cout << iterColDTEmpSuscriptos->second << endl;
        }
        cout << "Seleccione un empleado a eliminar notificaciones, ingresando su email: \n";
        string emailEmpleado;
        cin >> emailEmpleado;
        controladorEmpleado->seleccionarEmpleadoADesNotificar(emailEmpleado);
      } else {
        cout << "No hay empleados suscriptos" << endl;
      }
      break;
    }
    case 19:{
      int dia, mes, anio;
      cout << "Ingrese el dia actual al sistema: ";
      cin >> dia;

      cout << "Ingrese el mes actual al sistema: ";
      cin >> mes;

      cout << "Ingrese el anio actual al sistema: ";
      cin >> anio;

      fechaActual = DTFecha(dia, mes, anio);

      cout << "La fecha ha sido actualizada a: " << fechaActual << endl;
      
      break;
    }
    case 20:
    {

      break;
    }
    }
  } while (mvar1 != 20);
  return 0;
}