#ifndef DTHUESPED
#define DTHUESPED
#include <string>
#include <iostream>

#include "DTUsuario.h"

using namespace std;

class DTHuesped : public DTUsuario
{
private:
    bool esFinger;

public:
    DTHuesped();
    DTHuesped(string, string, string, bool);
    bool getEsFinger() const;
};

ostream &operator<<(ostream &out, const DTHuesped &huesped);

#endif