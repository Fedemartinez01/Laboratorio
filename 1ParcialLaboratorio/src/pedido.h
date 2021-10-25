#ifndef PEDIDO_H_
#define PEDIDO_H_

#define COMPLETADO 2
#define PENDIENTE 1
#define PEDIDOVACIO 0

#include "funciones.h"

typedef struct
{
	int idPedido;
	int idCliente;
	int cantKilos;

	int tipoPlastico;
	int cantHDPE;
	int cantLDPE;
	int cantPP;

	int estado;
}ePedido;

/// Hace un pedido
/// @param unPedido
/// @param idCliente
/// @param idPedido
/// @return un pedido
ePedido HacerPedido(ePedido unPedido, int idCliente, int idPedido);

/// Inicializa la lista de pedidos en PEDIDOVACIO
/// @param listaPedidos
/// @param tamPedidos
void InicializarPedidos(ePedido listaPedidos[], int tamPedidos);

/// Busca en la lista de pedidos el primer vacio
/// @param listaPedidos
/// @param tamPedidos
/// @return el primer indice vacio, o -1 si no encuentra ningun vacio
int BuscarPedidoVacio(ePedido listaPedidos[], int tamPedidos);

/// Busca un pedido por id, verificando que el estado no sea PEDIDOVACIO
/// @param listaPedidos
/// @param tamPedidos
/// @return el indice del pedido encontrado o -1 si no lo encontró
int EncontrarPedidoPorId(ePedido listaPedidos[], int tamPedidos);

/// Busca el pedido a dar de baja y le cambia el estado a PEDIDOVACIO
/// @param listaPedidos
/// @param tamPedidos
/// @return 1 si pudo, 0 sino
int BajaPedido(ePedido listaPedidos[], int tamPedidos);




#endif /* PEDIDO_H_ */
