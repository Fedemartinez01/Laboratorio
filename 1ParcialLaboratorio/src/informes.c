#include "informes.h"



void ImprimirUnCliente(eCliente unCliente, eLocalidad unaLocalidad)
{

	printf("| %-3d | %-21s | %-9s | %-21s | %-21s | %-10d |\n", unCliente.id, unCliente.nombreEmpresa, unCliente.cuit, unCliente.direccion, unaLocalidad.localidad, unCliente.cantidadPedidosPendientes);
}

void ImprimirClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	if(listaClientes != NULL && tamClientes > 0)
	{
		printf("------------------------------------------------------------------------------------------------------------\n");
		printf("| ID  |        EMPRESA        |     CUIT      |       DIRECCION       |        LOCALIDAD      | PENDIENTES |\n");
		printf("------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO)
			{
				for(int j = 0; j < tamLocalidades; j++)
				{
					if(listaClientes[i].id == listaLocalidades[j].idLocalidad && listaLocalidades[j].estadoLoc == 0)
					{
						ImprimirUnCliente(listaClientes[i], listaLocalidades[j]);
					}
				}

			}
		}
		printf("------------------------------------------------------------------------------------------------------------\n");

	}
}





void ImprimirPedidosPorEstado(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int estado)
{
	if(listaPedidos != NULL && tamPedidos > 0)
	{
		printf("---------------------------------------------------------\n");
		printf("|  ID |     CUIT      |       DIRECCION       |  KILOS  |\n");
		printf("---------------------------------------------------------\n");

		for(int i = 0; i < tamClientes; i++)
		{
			for(int j = 0; j < tamPedidos; j++)
			{
				if(listaPedidos[j].idCliente == listaClientes[i].id && listaPedidos[j].estado == estado && listaClientes[i].estado == CARGADO)
				{
					ImprimirUnPedido(listaPedidos[j], listaClientes[i]);
				}

			}
		}
		printf("---------------------------------------------------------\n");
	}
}

void ImprimirUnPedido(ePedido unPedido, eCliente unCliente)
{
	printf("| %-3d | %-9s | %-21s | %-7d |\n", unPedido.idPedido, unCliente.cuit, unCliente.direccion, unPedido.cantKilos);
}

void ClienteConPendientes(eCliente listaClientes[], int tamClientes)
{
	int maximo;
	int flag;
	int cantidadClientes;
	cantidadClientes = 0;

	flag = 0;

	for(int i = 0; i < tamClientes; i++)
	{
		if(listaClientes[i].estado == CARGADO)
		{
			if(listaClientes[i].cantidadPedidosPendientes > maximo && flag == 0)
			{
				maximo = listaClientes[i].cantidadPedidosPendientes;
				flag = 1;
			}
			else
			{
				if(listaClientes[i].cantidadPedidosPendientes > maximo)
				{
					maximo = listaClientes[i].cantidadPedidosPendientes;
				}
			}
		}
	}

	if(cantidadClientes > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO && listaClientes[i].cantidadPedidosPendientes == maximo)
			{
				cantidadClientes++;
			}
		}
		printf("\nCantidad de clientes con mas pedidos pendientes: %d, con %d pedidos pendientes", cantidadClientes, maximo);

	}

}

void ClienteConCompletados(eCliente listaClientes[], int tamClientes)
{
	int maximo;
	int flag;
	int cantidadClientes;
	cantidadClientes = 0;

	flag = 0;

	for(int i = 0; i < tamClientes; i++)
	{
		if(listaClientes[i].estado == CARGADO)
		{
			if(listaClientes[i].cantidadPedidosCompletados > maximo && flag == 0)
			{
				maximo = listaClientes[i].cantidadPedidosCompletados;
				flag = 1;
			}
			else
			{
				if(listaClientes[i].cantidadPedidosCompletados > maximo)
				{
					maximo = listaClientes[i].cantidadPedidosCompletados;

				}
			}
		}
	}

	if(cantidadClientes > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO && listaClientes[i].cantidadPedidosCompletados == maximo)
			{
				cantidadClientes++;
			}
		}

		printf("\nCantidad de clientes con mas pedidos completados: %d, con %d pedidos pendientes", cantidadClientes, maximo);

	}

}

void ClienteConTotales(eCliente listaClientes[], int tamClientes)
{
	int maximo;
	int flag;
	int cantidadClientes;
	cantidadClientes = 0;

	flag = 0;

	for(int i = 0; i < tamClientes; i++)
	{
		if(listaClientes[i].estado == CARGADO)
		{
			if(listaClientes[i].cantidadTotalPedidos > maximo && flag == 0)
			{
				maximo = listaClientes[i].cantidadTotalPedidos;
				flag = 1;
			}
			else
			{
				if(listaClientes[i].cantidadTotalPedidos > maximo)
				{
					maximo = listaClientes[i].cantidadTotalPedidos;
				}
			}
		}
	}

	if(cantidadClientes > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO && listaClientes[i].cantidadTotalPedidos == maximo)
			{
				cantidadClientes++;
			}
			printf("\nCantidad de clientes con mas pedidos totaels: %d, con %d pedidos pendientes", cantidadClientes, maximo);

		}
	}

}








