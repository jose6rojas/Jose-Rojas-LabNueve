main:	LabNueve.o Usuario.o Administrador.o Cliente.o Carro.o
	g++ LabNueve.o Usuario.o Administrador.o Cliente.o Carro.o -o lab_nueve

LabNueve.o:	LabNueve.cpp Usuario.h Administrador.h Cliente.h Carro.h
	g++ -c LabNueve.cpp

Usuario.o:	Usuario.h Usuario.cpp
	g++ -c Usuario.cpp

Administrador.o:	Usuario.h Administrador.h Administrador.cpp
	g++ -c Administrador.cpp

Cliente.o:	Usuario.h Cliente.h Cliente.cpp
	g++ -c Cliente.cpp

Carro.o:	Carro.h Carro.cpp
	g++ -c Carro.cpp

Clean:
	rm -f *.o lab_nueve