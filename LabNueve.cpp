// viernes, 16 de junio de 2017
// Laboratorio IX - Programacion III
// Jose Carlos Rojas Herrera - 11541234

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Carro.h"
#include "Usuario.h"
#include "Administrador.h"
#include "Cliente.h"

using namespace std;

string obtenerLetra(int);
string generarPlaca();

int main(int argc, char const *argv[])
{
	srand(time(0));

	vector<Usuario*> usuarios;
	vector<Carro*> carros;

	Administrador* test = new Administrador("Ana", "lanawhite", "Instructora", "12345");
	usuarios.push_back(test);

	// Carga los vectores

	// Administradores.txt
	ifstream archivoAdmins("Administradores.txt");
	string nombre_admin, password_admin, cargo_admin, numeroSS_admin;
	Administrador* admin;
	while(archivoAdmins >> nombre_admin >> password_admin >> cargo_admin >> numeroSS_admin)
	{
		admin = new Administrador();

		admin -> setNombre(nombre_admin);
		admin -> setPassword(password_admin);
		admin -> setCargo(cargo_admin);
		admin -> setNumeroSS(numeroSS_admin);

		usuarios.push_back(admin);
	}

	// Clientes.txt
	ifstream archivoClientes("Clientes.txt");
	string nombre_clt, password_clt, tipoMembresia_clt;
	Cliente* clt;
	while(archivoClientes >> nombre_clt >> password_clt >> tipoMembresia_clt)
	{
		clt = new Cliente();

		clt -> setNombre(nombre_clt);
		clt -> setPassword(password_clt);

		if(tipoMembresia_clt == "Normal")
			clt -> setTipoMembresia(1);
		else if(tipoMembresia_clt == "Gold")
			clt -> setTipoMembresia(2);
		else if(tipoMembresia_clt == "Premium")
			clt -> setTipoMembresia(3);
		else
			clt -> setTipoMembresia(1);

		usuarios.push_back(clt);
	}
	cout << "Usuarios cargados correctamente." << endl;

	// Carros.txt
	ifstream archivoCarros("Carros.txt");
	string placa_car, marca_car, modelo_car, year_car;
	double precioAlquiler_car;
	string estado_car;
	Carro* Car;
	while(archivoCarros >> placa_car >> marca_car >> modelo_car >> year_car >> precioAlquiler_car >> estado_car)
	{
		Car = new Carro();

		Car -> setPlaca(placa_car);
		Car -> setMarca(marca_car);
		Car -> setModelo(modelo_car);
		Car -> setYear(year_car);
		Car -> setPrecioAlquiler(precioAlquiler_car);
		if(estado_car == "Alquilado")
			Car -> setEstado(true);
		else
			Car -> setEstado(false);

		carros.push_back(Car);
	}
	cout << "Carros cargados correctamente." << endl << endl;

	int opcion_principal = 0;
	while (opcion_principal != 3)
	{
		cout << "Lab. 9 - Menu Principal" << "\n";
		cout << "1. Registrar Usuario" << "\n";
		cout << "2. Iniciar Sesion" << "\n";
		cout << "3. Salir" << "\n";
		cout << "4. Verificar Usuarios" << "\n";
		cout << "5. Generar Reporte" << "\n";
		cout << "Escoja una opcion: ";
		cin >> opcion_principal;

		if(opcion_principal == 1) // Registrar Usuario
		{
			string nombre, password;
			cout << endl << "Ingrese un nombre: ";
			cin >> nombre;
			cout << "Ingrese una password: ";
			cin >> password;

			int opcion_1;
			cout << endl << "Registrar Usuario" << endl;
			cout << "\t1. Administrador" << endl;
			cout << "\t2. Cliente" << endl;
			cout << "\t3. Salir" << endl;
			cout << "\tEscoja una opcion: ";
			cin >> opcion_1;

			if(opcion_1 == 1) // Administrador
			{
				string cargo, numeroSS;
				cout << endl << "\tIngrese su cargo: ";
				cin >> cargo;
				cout << "\tIngrese su numero de seguro social: ";
				cin >> numeroSS;

				Administrador* Admin = new Administrador(nombre, password, cargo, numeroSS);
				usuarios.push_back(Admin);
				
				// Guarda el Usuario
				ofstream archivo("Administradores.txt", std::ios_base::app);
				archivo << Admin -> getNombre() << ' ';
				archivo << Admin -> getPassword() << ' ';
				archivo	<< Admin -> getCargo() << ' ';
				archivo << Admin -> getNumeroSS() << endl;
				archivo.close();

				cout << endl << "Administrador registrado correctamente." << endl << endl;
			}
			else if(opcion_1 == 2) // Cliente
			{
				int tipo;
				cout << endl << "\tCliente - Tipo" << endl;
				cout << "\t1. Normal" << endl;
				cout << "\t2. Gold" << endl;
				cout << "\t3. Premium" << endl;
				cout << "\tEscoga un tipo: ";
				cin >> tipo;

				Cliente* Clt = new Cliente(nombre, password, tipo);
				usuarios.push_back(Clt);
				
				// Guarda el Usuario
				ofstream archivo("Clientes.txt", std::ios_base::app);
				archivo << Clt -> getNombre() << ' ';
				archivo << Clt -> getPassword() << ' ';
				archivo << Clt -> getTipoMembresia() << endl;

				cout << endl << "Cliente registrado correctamente." << endl << endl;
			}
			else if(opcion_1 == 3) { }
			else
				cout << endl << "Debe escoger una opcion valida." << endl << endl;
		}
		else if(opcion_principal == 2) // Iniciar Sesion
		{
			string nombre, password;

			int opcion_2;
			cout << endl << "Iniciar Sesion" << endl;
			cout << "1. Administrador" << endl;
			cout << "2. Cliente" << endl;
			cout << "3. Salir" << endl;
			cout << "Escoja una opcion: ";
			cin >> opcion_2;

			if(opcion_2 == 1) // Administrador
			{
				Administrador* admin;

				cout << endl << "Ingrese su nombre: ";
				cin >> nombre;
				cout << "Ingrese su password: ";
				cin >> password;

				int cont = 0;
				for (int i = 0; i < usuarios.size(); i++)
				 {
				 	if((nombre == usuarios[i] -> getNombre()) && (password == usuarios[i] -> getPassword()))
				 	{
				 		cont++;
				 		int opcion_admin;
				 		cout << endl << "Bienvenido/a, " << nombre << endl;
				 		cout << "1. Agregar Carro" << endl;
				 		cout << "2. Modificar Carro" << endl;
				 		cout << "3. Listar Carros" << endl;
				 		cout << "4. Eliminar Carro" << endl;
				 		cout << "5. Salir" << endl;
				 		cout << "Escoja una opcion: ";
				 		cin >> opcion_admin;

				 		if(opcion_admin == 1) // Agregar Carro
				 		{
				 			string placa, marca, modelo, year;
				 			double precioAlquiler;
				 			bool estado;

				 			// placa
				 			placa = generarPlaca();

				 			// marca
				 			cout << endl << "Ingrese la marca: ";
				 			cin >> marca;

				 			// modelo
				 			cout << "Ingrese el modelo: ";
				 			cin >> modelo;

				 			// year
				 			cout << "Ingrese el year: ";
				 			cin >> year;

				 			// precioAlquiler
				 			cout << "Ingrese el precio de alquiler (Lps.): ";
				 			cin >> precioAlquiler;

				 			// estado
				 			/* int status;
				 			cout << endl << "Agregar Carro - Estado" << endl;
				 			cout << "1. Alquilado" << endl;
				 			cout << "2. No Alquilado" << endl;
				 			cout << "Escoja una opcion: ";
				 			cin >> status;
				 			if(status == 1)
				 				estado = true;
				 			else if(status == 2)
				 				estado = false;
				 			else
				 				estado = true; */

				 			Carro* car = new Carro(placa, marca, modelo, year, precioAlquiler);
				 			carros.push_back(car);

				 			// Guarda el Carro
				 			ofstream archivo("Carros.txt", std::ios_base::app);
							archivo << car -> getPlaca() << ' ';
							archivo << car -> getMarca() << ' ';
							archivo << car -> getModelo() << ' ';
							archivo << car -> getYear() << ' ';
							archivo << car -> getPrecioAlquiler() << ' ';
							archivo << car -> getEstado() << endl;

							cout << endl << "Carro registrado correctamente." << endl << endl;
				 		}
				 		else if(opcion_admin == 2) // Modificar Carro
				 		{
				 		}
				 		else if(opcion_admin == 3) // Listar Carros
				 		{
				 			string car;
				 			cout << endl << "Carros" << endl;
				 			for(int i = 0; i < carros.size(); i++)
				 			{
				 				cout << "Carro #" << i << endl;
				 				car = carros[i] -> toString();
				 				cout << car << endl;
				 			}
				 		}
				 		else if(opcion_admin == 4) // Eliminar Carro
				 		{
				 		}
				 		else if(opcion_admin == 5) { cout << endl; } // Salir
				 		else
				 			cout << endl << "Debe escoger una opcion valida." << endl << endl;
				 	}
				 }
				 if(cont < 1)
				 {
				 	cout << endl << "Su nombre o contrasena es invalido/a." << endl << endl;
				 }
			}
			else if(opcion_2 == 2) // Cliente
			{
				string nombre, password;
				cout << endl << "Ingrese su nombre: ";
				cin >> nombre;
				cout << "Ingrese su password: ";
				cin >> password;

				Cliente* clt;
				int cont = 0;
				for(int i = 0; i < usuarios.size(); i++)
				{
					if((nombre == usuarios[i] -> getNombre()) && (password == usuarios[i] -> getPassword()))
					{
						cont++;
						clt = static_cast<Cliente*> (usuarios[i]);
					}
				}

				if(cont < 1)
				{
					cout << endl << "Su nombre o contrasena es invalido/a." << endl << endl;
				}
				else
				{
					string car;
					cout << endl << "Carros" << endl;
					for(int i = 0; i < carros.size(); i++)
				 	{
				 		cout << "Carro #" << i << endl;
				 		car = carros[i] -> toString();
				 		cout << car << endl << endl;
				 	}

				 	int pos;
				 	cout << "Escoja el indice del Carro que desea alquilar: ";
				 	cin >> pos;
				 	if(pos < 0 || pos >= carros.size())
				 	{
				 		cout << endl << "Debe escoger un valor valido." << endl << endl;
				 	}
				 	else
				 	{
				 		Carro* C = carros[pos];
				 		C -> setEstado(false);

				 		/* string name;
				 		name = clt -> getNombre();
				 		stringstream ss;
				 		ss << name << ".txt"; */
				 		ofstream factura("Facturas.txt", std::ios_base::app);
				 		factura << "Cliente: " << clt -> getNombre() << endl;
				 		factura << "Carro alquilado:" << endl;
				 		factura << C -> toString() << endl;
				 		factura.close();
				 	}
				}
			}
			else if(opcion_2 == 3) { } // Salir
			else
				cout << endl << "Debe escoger una opcion valida." << endl << endl;
		}
		else if(opcion_principal == 3) { }
		else if(opcion_principal == 4) // Verificar Usuarios
		{
			cout << endl << "Usuarios" << endl;
			for(int i = 0; i < usuarios.size(); i++)
			{
				cout << "\tUsuario #" << i << endl;
				cout << "\t" << usuarios[i] -> getNombre() << endl;
				cout << "\t" << usuarios[i] -> getPassword() << endl << endl;
			}
		}
		else if(opcion_principal == 5) // Generar Reporte
		{
			string car;
			stringstream reporte;
			reporte << "Carros" << endl << endl;
			for(int i = 0; i < carros.size(); i++)
			{
				reporte << "Carro #" << i << endl;
				car = carros[i] -> toString();
				reporte << car << endl;
			}

			// Guarda el reporte en un archivo de texto
			ofstream archivo("Reporte.txt", std::ios_base::app);
			archivo << reporte.str() << endl;
			archivo.close();

			cout << endl << "Reporte generado correctamente." << endl << endl;
		}
		else
			cout << endl << "Debe escoger una opcion valida." << endl << endl;
	}

	// Liberando memoria
	for(int i = 0; i < usuarios.size(); i++)
		delete usuarios[i];
	usuarios.clear();

	for(int i = 0; i < carros.size(); i++)
		delete carros[i];
	carros.clear();
	
	return 0;
}

string obtenerLetra(int num)
{
	if(num == 1)
		return "A";
	else if(num == 2)
		return "B";
	else if(num == 3)
		return "C";
	else if(num == 4)
		return "D";
	else if(num == 5)
		return "E";
	else if(num == 6)
		return "F";
	else if(num == 7)
		return "G";
	else if(num == 8)
		return "H";
	else if(num == 9)
		return "I";
	else if(num == 10)
		return "J";
	else if(num == 11)
		return "K";
	else if(num == 12)
		return "L";
	else if(num == 13)
		return "M";
	else if(num == 14)
		return "N";
	else if(num == 15)
		return "O";
	else if(num == 16)
		return "P";
	else if(num == 17)
		return "Q";
	else if(num == 18)
		return "R";
	else if(num == 19)
		return "S";
	else if(num == 20)
		return "T";
	else if(num == 21)
		return "U";
	else if(num == 22)
		return "V";
	else if(num == 23)
		return "W";
	else if(num == 24)
		return "X";
	else if(num == 25)
		return "Y";
	else if(num == 26)
		return "Z";
	else
		return "blah";
}

string generarPlaca()
{
	stringstream placa;

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0;
	for(int i = 1; i <= 7; i++)
	{
		if(i <= 3)
		{
			if(i == 1)
			{
				num1 = (rand() % 26) + 1;
				placa << obtenerLetra(num1);
			}
			else if(i == 2)
			{
				num2 = (rand() % 26) + 1;
				placa << obtenerLetra(num2);
			}
			else
			{
				num3 = (rand() % 26) + 1;
				placa << obtenerLetra(num3) << "-";
			}

		}
		else
		{
			if(i == 4)
			{
				num4 = (rand() % 9) + 1;
				placa << num4;
			}
			else if(i == 5)
			{
				num5 = (rand() % 9) + 1;
				placa << num5;
			}
			else if(i == 6)
			{
				num6 = (rand() % 9) + 1;
				placa << num6;
			}
			else if(i == 7)
			{
				num7 = (rand() % 9) + 1;
				placa << num7;
			}
		}
	}

	return placa.str();
}