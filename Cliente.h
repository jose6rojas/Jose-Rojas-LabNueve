// Cliente.h

#include <string>
#include "Usuario.h"

using namespace std;

#pragma once

class Cliente : public Usuario
{
	private:
		string tipoMembresia;

	public:
		Cliente();
		Cliente(string, string, int); // nombre, password, tipoMembresia

		void setTipoMembresia(int);
		string getTipoMembresia();
};