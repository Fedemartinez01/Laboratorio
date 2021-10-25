#include "localidad.h"


void InicializarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades)
{
	if(listaLocalidades != NULL && tamLocalidades > 0)
	{
		for(int i = 0; i < tamLocalidades; i++)
		{
			listaLocalidades[i].estadoLoc = 1;//1 = VACIO \\\ 0 = CARGADO
		}
	}
}



int BuscarVacioLocalidad(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int indice;
	indice = -1;

	if(listaLocalidades != NULL && tamLocalidades > 0)
	{
		for(int i = 0; i < tamLocalidades; i++)
		{
			if(listaLocalidades[i].estadoLoc == 1)//SI ESTÁ VACIO, RETORNA ESE INDICE
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}



int EncontrarLocalidadPorId(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int indice;
	indice = -1;

	int idBusqueda;
	idBusqueda = GetInt("Ingresar ID: ");

	if(listaLocalidades != NULL && tamLocalidades > 0)
	{
		for(int i = 0; i < tamLocalidades; i++)
		{
			if(listaLocalidades[i].estadoLoc == 0 && listaLocalidades[i].idLocalidad == idBusqueda)//ENCUENTRA LUGAR VACIO Y LO DEVUELVE
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}


