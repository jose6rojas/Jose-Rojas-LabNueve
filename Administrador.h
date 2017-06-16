// Administrador.h

#include <string>
#include "Usuario.h"

using namespace std;

#pragma once

class Administrador : public Usuario
{
	private:
		string cargo;
		string numeroSS;

	public:
		Administrador();
		Administrador(string, string, string, string); // nombre, password, cargo, numeroSS

		// cargo
		void setCargo(string);
		string getCargo();
		// numeroSS
		void setNumeroSS(string);
		string getNumeroSS();
};