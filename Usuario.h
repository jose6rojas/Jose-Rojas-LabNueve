// Usuario.h

#include <string>

using namespace std;

#pragma once

class Usuario
{
	protected:
		string nombre;
		string password;

	public:
		Usuario();
		Usuario(string, string); // nombre, password

		// nombre
		void setNombre(string);
		string getNombre();
		// password
		void setPassword(string);
		string getPassword();
};