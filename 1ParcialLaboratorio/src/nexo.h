#ifndef NEXO_H_
#define NEXO_H_



#include "cliente.h"
#include "pedido.h"
#include "informes.h"
#include "funciones.h"
#include "localidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMLOCALIDADES 1000

/// Muestra el menu y pide una opcion
/// @param listaClientes
/// @param tamClientes
/// @param listaPedidos
/// @param tamPedidos
/// @return la opcion elegida
int menu(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

/// Busca el cliente y le genera su pedido
/// @param listaClientes
/// @param tamClientes
/// @param listaPedidos
/// @param tamPedidos
/// @param idPedido
/// @return si pudo, 0 sino
int CrearPedido(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int idPedido);

/// Pide una localidad y muestra los pedidos en el estado deseado
/// @param listaClientes
/// @param tamClientes
/// @param listaPedidos
/// @param tamPedidos
/// @param estado
void PedidosPorEstadoYLocalidad(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int estado, eLocalidad listaLocalidades[], int tamLocalidades);



/// Cambia el estado a VACIO del cliente solicitado y elimina sus pedidos
/// @param listaClientes
/// @param tamClientes
/// @return 1 si pudo, 0 sino
int BajaCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

/// En un lugar vacio, carga un cliente
/// @param listaClientes
/// @param tamClientes
/// @param id
/// @return 1 si pudo, 0 sino
int AltaCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, int id);

/// Calcula el promedio de reciclado (cantidad kilos / cantidad clientes)
/// @param listaClientes
/// @param tamClientes
/// @param listaPedidos
/// @param tamPedidos
/// @return 1 si pudo 0 sino
int CalcularPromedioDeReciclado(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);


/// Funcion encargada de separar la cantidad total de kilos en cada plástico especifico
/// @param listaPedidos
/// @param tamPedidos
/// @return 1 si pudo, 0 sino
int ProcesarResiduos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);


int GetLocalidad(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, int id);
/// Genera un cliente
/// @param id
/// @return un cliente
eCliente PedirCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, int id);

#endif /* NEXO_H_ */
