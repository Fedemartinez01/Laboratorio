#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include "cliente.h"
#include "pedido.h"
#include "localidad.h"

#define CARGADO 0
#define VACIO 1

/// Imprime un cliente
/// @param unCliente
void ImprimirUnCliente(eCliente unCliente, eLocalidad unaLocalidad);

/// Imprime todos los clientes
/// @param listaClientes
/// @param tamClientes
void ImprimirClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

/// Imprime los pedidos segun el estado
/// @param listaClientes
/// @param tamClientes
/// @param listaPedidos
/// @param tamPedidos
/// @param estado
void ImprimirPedidosPorEstado(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int estado);

/// Imprime un pedido
/// @param unPedido
/// @param unCliente
void ImprimirUnPedido(ePedido unPedido, eCliente unCliente);

/// cantidad de clientes con mas pendientes
/// @param listaClientes
/// @param tamClientes
void ClienteConPendientes(eCliente listaClientes[], int tamClientes);

/// cantidad de clientes con mas completados
/// @param listaClientes
/// @param tamClientes
void ClienteConCompletados(eCliente listaClientes[], int tamClientes);

/// cantidad de clientes con mas totales
/// @param listaClientes
/// @param tamClientes
void ClienteConTotales(eCliente listaClientes[], int tamClientes);









#endif /* INFORMES_H_ */
