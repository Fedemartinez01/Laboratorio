#include "cliente.h"


void InicializarClientes(eCliente listaClientes[], int tamClientes)
{
	if(listaClientes != NULL && tamClientes > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			listaClientes[i].estado = 1;//1 = VACIO \\\ 0 = CARGADO
		}
	}

}






int ModificarCliente(eCliente listaClientes[], int tamClientes)
{
	int indiceModificar;
	int retorno;
	retorno = 0;


	if(listaClientes != NULL && tamClientes > 0)
	{
		indiceModificar = EncontrarClientePorId(listaClientes, tamClientes);
		if(indiceModificar != -1)
		{
			GetDireccion("\nDireccion", listaClientes[indiceModificar].direccion);
			//GetString("\nLocalidad: ", listaClientes[indiceModificar].localidad);
			retorno = 1;
		}
	}
	return retorno;
}

int BuscarVacio(eCliente listaClientes[], int tamClientes)
{
	int indice;
	indice = -1;

	if(listaClientes != NULL && tamClientes > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == VACIO)//SI ESTÁ VACIO, RETORNA ESE INDICE
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int BuscarCargado(eCliente listaClientes[], int tamClientes)
{
	int indice;
	indice = -1;

	if(listaClientes != NULL && tamClientes > 0)
	{
		for(int i = 0 ; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int EncontrarClientePorId(eCliente listaClientes[], int tamClientes)
{
	int indice;
	indice = -1;

	int idBusqueda;
	idBusqueda = GetInt("Ingresar ID: ");

	if(listaClientes != NULL && tamClientes > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO && listaClientes[i].id == idBusqueda)//ENCUENTRA LUGAR VACIO Y LO DEVUELVE
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}






