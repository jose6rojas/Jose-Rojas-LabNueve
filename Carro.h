// Carro.h

#include <string>
#include <sstream>

using namespace std;

#pragma once

class Carro
{
	private:
		string placa;
		string marca;
		string modelo;
		string year;
		double precioAlquiler;
		bool estado;

	public:
		Carro();
		Carro(string, string, string, string, double); // placa, marca, modelo, year, precioAlquiler

		// placa
		void setPlaca(string);
		string getPlaca();
		// marca
		void setMarca(string);
		string getMarca();
		// modelo
		void setModelo(string);
		string getModelo();
		// year
		void setYear(string);
		string getYear();
		// precioAlquiler
		void setPrecioAlquiler(double);
		double getPrecioAlquiler();
		// alquilado
		void setEstado(bool);
		string getEstado();

		string toString();
};