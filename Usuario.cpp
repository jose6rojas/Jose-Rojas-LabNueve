// Usuario.cpp

#include "Usuario.h"

Usuario::Usuario() { }
Usuario::Usuario(string nombre, string password)
{
	this -> nombre = nombre;
	this -> password = password;
}

// nombre
void Usuario::setNombre(string nombre) { this -> nombre = nombre; }
string Usuario::getNombre() { return nombre; }

// password
void Usuario::setPassword(string password) { this -> password = password; }
string Usuario::getPassword() { return password; }