MODULOS = Fabrica Usuario Hostal Resenia Habitacion Reserva Estadia Respuesta DTHostal DTHostalCalificado DTUsuario DTEmpleado DTHuesped DTResenia DTReserva DTFecha DTHabitacion ControladorColecciones ControladorUsuario ControladorHostales ControladorReserva ControladorResenia ControladorEstadia ControladorEmpleados DTInformacionReserva DTInformacionHostal DTInformacionEstadia DTEstadia DTInformacionNotificaciones

CC = g++
LD = -g -Wall
MC = -c

ODIR = .

OBJ = $(MODULOS:%=$(ODIR)/%.o)

main: $(OBJ) main.cpp
	$(CC) $(LD) $(OBJ) main.cpp -o main

./Fabrica.o: ./Fabrica.h ./Fabrica.cpp
	$(CC) $(LD) $(MC) ./Fabrica.cpp -o ./Fabrica.o

./Usuario.o: ./Usuario.h ./Usuario.cpp
	$(CC) $(LD) $(MC) ./Usuario.cpp -o ./Usuario.o

./Hostal.o: ./Hostal.h ./Hostal.cpp
	$(CC) $(LD) $(MC) ./Hostal.cpp -o ./Hostal.o

./Resenia.o: ./Resenia.h ./Resenia.cpp
	$(CC) $(LD) $(MC) ./Resenia.cpp -o ./Resenia.o

./Habitacion.o: ./Habitacion.h ./Habitacion.cpp
	$(CC) $(LD) $(MC) ./Habitacion.cpp -o ./Habitacion.o

./Reserva.o: ./Reserva.h ./Reserva.cpp
	$(CC) $(LD) $(MC) ./Reserva.cpp -o ./Reserva.o

./Estadia.o: ./Estadia.h ./Estadia.cpp
	$(CC) $(LD) $(MC) ./Estadia.cpp -o ./Estadia.o

./Respuesta.o: ./Respuesta.h ./Respuesta.cpp
	$(CC) $(LD) $(MC) ./Respuesta.cpp -o ./Respuesta.o

./DTHostal.o: ./DTHostal.h ./DTHostal.cpp
	$(CC) $(LD) $(MC) ./DTHostal.cpp -o ./DTHostal.o

./DTHostalCalificado.o: ./DTHostalCalificado.h ./DTHostalCalificado.cpp
	$(CC) $(LD) $(MC) ./DTHostalCalificado.cpp -o ./DTHostalCalificado.o

./DTUsuario.o: ./DTUsuario.h ./DTUsuario.cpp
	$(CC) $(LD) $(MC) ./DTUsuario.cpp -o ./DTUsuario.o

./DTEmpleado.o: ./DTEmpleado.h ./DTEmpleado.cpp
	$(CC) $(LD) $(MC) ./DTEmpleado.cpp -o ./DTEmpleado.o

./DTHuesped.o: ./DTHuesped.h ./DTHuesped.cpp
	$(CC) $(LD) $(MC) ./DTHuesped.cpp -o ./DTHuesped.o

./DTResenia.o: ./DTResenia.h ./DTResenia.cpp
	$(CC) $(LD) $(MC) ./DTResenia.cpp -o ./DTResenia.o

./DTReserva.o: ./DTReserva.h ./DTReserva.cpp
	$(CC) $(LD) $(MC) ./DTReserva.cpp -o ./DTReserva.o

./DTFecha.o: ./DTFecha.h ./DTFecha.cpp
	$(CC) $(LD) $(MC) ./DTFecha.cpp -o ./DTFecha.o

./DTHabitacion.o: ./DTHabitacion.h ./DTHabitacion.cpp
	$(CC) $(LD) $(MC) ./DTHabitacion.cpp -o ./DTHabitacion.o

./ControladorColecciones.o: ./ControladorColecciones.h ./ControladorColecciones.cpp
	$(CC) $(LD) $(MC) ./ControladorColecciones.cpp -o ./ControladorColecciones.o

./ControladorUsuario.o: ./ControladorUsuario.h ./ControladorUsuario.cpp
	$(CC) $(LD) $(MC) ./ControladorUsuario.cpp -o ./ControladorUsuario.o

./ControladorHostales.o: ./ControladorHostales.h ./ControladorHostales.cpp
	$(CC) $(LD) $(MC) ./ControladorHostales.cpp -o ./ControladorHostales.o

./ControladorReserva.o: ./ControladorReserva.h ./ControladorReserva.cpp
	$(CC) $(LD) $(MC) ./ControladorReserva.cpp -o ./ControladorReserva.o

./ControladorResenia.o: ./ControladorResenia.h ./ControladorResenia.cpp
	$(CC) $(LD) $(MC) ./ControladorResenia.cpp -o ./ControladorResenia.o

./ControladorEstadia.o: ./ControladorEstadia.h ./ControladorEstadia.cpp
	$(CC) $(LD) $(MC) ./ControladorEstadia.cpp -o ./ControladorEstadia.o

./ControladorEmpleados.o: ./ControladorEmpleados.h ./ControladorEmpleados.cpp
	$(CC) $(LD) $(MC) ./ControladorEmpleados.cpp -o ./ControladorEmpleados.o

./DTInformacionReserva.o: ./DTInformacionReserva.h ./DTInformacionReserva.cpp
	$(CC) $(LD) $(MC) ./DTInformacionReserva.cpp -o ./DTInformacionReserva.o

./DTInformacionHostal.o: ./DTInformacionHostal.h ./DTInformacionHostal.cpp
	$(CC) $(LD) $(MC) ./DTInformacionHostal.cpp -o ./DTInformacionHostal.o

./DTInformacionEstadia.o: ./DTInformacionEstadia.h ./DTInformacionEstadia.cpp
	$(CC) $(LD) $(MC) ./DTInformacionEstadia.cpp -o ./DTInformacionEstadia.o

./DTEstadia.o: ./DTEstadia.h ./DTEstadia.cpp
	$(CC) $(LD) $(MC) ./DTEstadia.cpp -o ./DTEstadia.o

./DTInformacionNotificaciones.o: ./DTInformacionNotificaciones.h ./DTInformacionNotificaciones.cpp
	$(CC) $(LD) $(MC) ./DTInformacionNotificaciones.cpp -o ./DTInformacionNotificaciones.o

clean:
	rm -f $(OBJ) main

rebuild:
	make clean
	make