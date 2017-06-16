// Cliente.cpp

#include "Cliente.h"

Cliente::Cliente() { }
Cliente::Cliente(string nombre, string password, int tipoMembresia) : Usuario(nombre, password)
{
	setTipoMembresia(tipoMembresia);
}

void Cliente::setTipoMembresia(int tipo)
{
	if(tipo == 1)
		tipoMembresia = "Normal";
	else if(tipo == 2)
		tipoMembresia = "Gold";
	else if(tipo == 3)
		tipoMembresia = "Platinum";
	else
		tipoMembresia = "blah";
}
string Cliente::getTipoMembresia() { return tipoMembresia; }