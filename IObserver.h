#ifndef IOBSERVER
#define IOBSERVER

#include "DTInformacionNotificaciones.h"

using namespace std;


class IObserver {
    public:
        virtual void Notify(DTInformacionNotificaciones) = 0;
};

#endif
