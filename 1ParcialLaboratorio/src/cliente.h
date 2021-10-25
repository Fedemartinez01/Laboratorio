#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include "funciones.h"

#define CARGADO 0
#define VACIO 1


typedef struct
{
	int id;
	char nombreEmpresa[51];
	char cuit[15];
	char direccion[31];
	int idLocalidadCliente;
	int cantidadPedidosPendientes;
	int cantidadPedidosCompletados;
	int cantidadTotalPedidos;
	int estado;
}eCliente;

/// Inicializa la lista de clientes en VACIO
/// @param listaClientes
/// @param tamClientes
void InicializarClientes(eCliente listaClientes[], int tamClientes);





/// Busca el primer VACIO
/// @param listaClientes
/// @param tamClientes
/// @return el primer VACIO, o -1 si no encontro VACIO
int BuscarVacio(eCliente listaClientes[], int tamClientes);

/// Busca el primer CARGADO
/// @param listaClientes
/// @param tamClientes
/// @return el primer CARGADO, o -1 si no encontro CARGADO
int BuscarCargado(eCliente listaClientes[], int tamClientes);

/// Busca un cliente por id
/// @param listaClientes
/// @param tamClientes
/// @return el indice del cliente encontrado, o -1 si no lo encontró
int EncontrarClientePorId(eCliente listaClientes[], int tamClientes);


/// Modifica la direccion y localidad del cliente buscado por ID
/// @param listaClientes
/// @param tamClientes
/// @return si pudo, 0 sino
int ModificarCliente(eCliente listaClientes[], int tamClientes);















#endif /* CLIENTE_H_ */
