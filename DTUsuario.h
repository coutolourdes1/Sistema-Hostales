#ifndef DTUSUARIO
#define DTUSUARIO
#include <string>

using namespace std;

class DTUsuario
{
private:
    string nombre, email, password;

public:
    DTUsuario();
    DTUsuario(string, string, string);
    string getNombre() const;
    string getEmail() const;
    string getPassword() const;
};

ostream &operator<<(ostream &out, const DTUsuario &usuario);

#endif