#include "pedido.h"



ePedido HacerPedido(ePedido unPedido, int idCliente, int idPedido)
{
	ePedido pedido;

	pedido.idPedido = idPedido;
	pedido.idCliente = idCliente;
	pedido.cantKilos = GetInt("\nCantidad de kilos: ");
	pedido.estado = PENDIENTE;

	return pedido;
}






void InicializarPedidos(ePedido listaPedidos[], int tamPedidos)
{
	if(listaPedidos != NULL && tamPedidos > 0)
	{
		for(int i = 0; i < tamPedidos; i++)
		{
			listaPedidos[i].estado = PEDIDOVACIO;//1 = VACIO \\\ 0 = CARGADO
		}
	}

}

int BuscarPedidoVacio(ePedido listaPedidos[], int tamPedidos)
{
	int indice;
	indice = -1;

	if(listaPedidos != NULL && tamPedidos > 0)
	{
		for(int i = 0; i < tamPedidos; i++)
		{
			if(listaPedidos[i].estado == PEDIDOVACIO)//SI ESTÁ VACIO, RETORNA ESE INDICE
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int EncontrarPedidoPorId(ePedido listaPedidos[], int tamPedidos)
{
	int indice;
	indice = -1;

	int idBusqueda;
	idBusqueda = GetInt("Ingresar ID: ");

	if(listaPedidos != NULL && tamPedidos > 0)
	{
		for(int i = 0; i < tamPedidos; i++)
		{
			if(listaPedidos[i].estado != PEDIDOVACIO && listaPedidos[i].idPedido == idBusqueda)//ENCUENTRA PEDIDO Y DEVUELDE EL INDICE
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int BajaPedido(ePedido listaPedidos[], int tamPedidos)
{
	int indiceBaja;
	int retorno;
	retorno = 0;

	if(listaPedidos != NULL && tamPedidos > 0)
	{
		indiceBaja = EncontrarPedidoPorId(listaPedidos, tamPedidos);

		if(indiceBaja != -1)
		{
			listaPedidos[indiceBaja].estado = PEDIDOVACIO;
			retorno = 1;
		}
	}
	return retorno;
}



















