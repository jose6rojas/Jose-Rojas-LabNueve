// viernes, 16 de junio de 2017
// Laboratorio IX - Programacion III
// Jose Carlos Rojas Herrera - 11541234

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
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

	cout << "sup nigga?" << endl;

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
				placa << obtenerLetra(num3);
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