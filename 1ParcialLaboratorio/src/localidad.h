
#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include <stdio.h>


typedef struct
{
	int idLocalidad;
	char localidad[31];
	int estadoLoc;

}eLocalidad;



void InicializarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades);


int AltaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, int id);


eLocalidad PedirLocalidad(int id);


int BuscarVacioLocalidad(eLocalidad listaLocalidades[], int tamLocalidades);


int BuscarCargadoLocalidad(eLocalidad listaLocalidades[], int tamLocalidades);

int EncontrarLocalidadPorId(eLocalidad listaLocalidades[], int tamLocalidades);

int ModificarLocalidad(eLocalidad listaLocalidades[], int tamLocalidades);















#endif /* LOCALIDAD_H_ */
