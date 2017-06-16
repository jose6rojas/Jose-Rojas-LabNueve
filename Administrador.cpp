// Administrador.cpp

#include "Administrador.h"

Administrador::Administrador() { }
Administrador::Administrador(string nombre, string password, string cargo, string numeroSS) : Usuario(nombre, password)
{
	this -> cargo = cargo;
	this -> numeroSS = numeroSS;
}

// cargo
void Administrador::setCargo(string cargo) { this -> cargo = cargo; }
string Administrador::getCargo() { return cargo; }

// numeroSS
void Administrador::setNumeroSS(string numeroSS) { this -> numeroSS = numeroSS; }
string Administrador::getNumeroSS() { return numeroSS; }