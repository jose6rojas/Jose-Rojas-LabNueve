// Carro.cpp

#include "Carro.h"

Carro::Carro() { }
Carro::Carro(string placa, string marca, string modelo, string year, double precioAlquiler)
{
	this -> placa = placa;
	this -> marca = marca;
	this -> modelo = modelo;
	this -> year = year;
	this -> precioAlquiler = precioAlquiler;
	estado = false;
}

// placa
void Carro::setPlaca(string placa) { this -> placa = placa; }
string Carro::getPlaca() { return placa; }

// marca
void Carro::setMarca(string marca) { this -> marca = marca; }
string Carro::getMarca() { return marca; }

// modelo
void Carro::setModelo(string modelo) { this -> modelo = modelo; }
string Carro::getModelo() { return modelo; }

// year
void Carro::setYear(string year) { this -> year = year; }
string Carro::getYear() { return year; }

// precioAlquiler
void Carro::setPrecioAlquiler(double precioAlquiler) { this -> precioAlquiler = precioAlquiler; }
double Carro::getPrecioAlquiler() { return precioAlquiler; }

// estado
void Carro::setEstado(bool estado) { this -> estado = estado; }
string Carro::getEstado()
{
	if(estado)
		return "Alquilado";
	else
		return "NoAlquilado";
}

string Carro::toString()
{
	stringstream ss;
	ss << "Placa: " << placa << "\n"
		<< "Marca: " << marca << "\n"
		<< "Modelo: " << modelo << "\n"
		<< "Year: " << year << "\n"
		<< "Precio de Alquiler: Lps. " << precioAlquiler << "\n"
		<< "Estado: " << getEstado() << "\n";
	return ss.str();
}