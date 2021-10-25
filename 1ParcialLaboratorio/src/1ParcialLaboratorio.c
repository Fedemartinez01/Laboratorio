/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "nexo.h"
#include "pedido.h"
#include "localidad.h"

int main(void) {
	setbuf(stdout, NULL);


	eCliente listaClientes[TAMCLIENTES];
	ePedido listaPedidos[TAMPEDIDOS];
	eLocalidad listaLocalidades[TAMLOCALIDADES];

	InicializarClientes(listaClientes, TAMCLIENTES);
	InicializarPedidos(listaPedidos, TAMPEDIDOS);
	InicializarLocalidades(listaLocalidades, TAMLOCALIDADES);


	int opcionMenu;
	int idClientes;
	int idPedido;

	idClientes = 1;
	idPedido = 100;


	do
	{
		opcionMenu = menu(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS);

		switch(opcionMenu)
		{
		case 1:
			if(AltaCliente(listaClientes, TAMCLIENTES, listaLocalidades, TAMLOCALIDADES, idClientes) == 0)
			{
				printf("\nERROR");
			}
			else
			{
				idClientes++;
			}
			break;
		case 2:
			ImprimirClientes(listaClientes, TAMCLIENTES, listaLocalidades, TAMLOCALIDADES);
			ModificarCliente(listaClientes, TAMCLIENTES);
			break;
		case 3:
			ImprimirClientes(listaClientes, TAMCLIENTES, listaLocalidades, TAMLOCALIDADES);
			BajaCliente(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS);
			break;
		case 4:
			ImprimirClientes(listaClientes, TAMCLIENTES, listaLocalidades, TAMLOCALIDADES);

			if(CrearPedido(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, idPedido) == 0)
			{
			printf("\nERROR");
			}
			else
			{
				idPedido++;
			}

			break;
		case 5:
			ImprimirPedidosPorEstado(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, PENDIENTE);
			if(ProcesarResiduos(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS) == 0)
			{
				printf("\nERROR");
			}

			break;
		case 6:
			ImprimirClientes(listaClientes, TAMCLIENTES, listaLocalidades, TAMLOCALIDADES);
			break;
		case 7:
			ImprimirPedidosPorEstado(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, PENDIENTE);
			break;
		case 8:
			ImprimirPedidosPorEstado(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, COMPLETADO);
			break;
		case 9:
			PedidosPorEstadoYLocalidad(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, PENDIENTE, listaLocalidades, TAMLOCALIDADES);
			break;
		case 10:
			CalcularPromedioDeReciclado(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS);
			break;
		case 11:
			ClienteConCompletados(listaClientes, TAMCLIENTES);
			ClienteConTotales(listaClientes, TAMCLIENTES);
			ClienteConPendientes(listaClientes, TAMCLIENTES);
			break;
		}


	}while(opcionMenu != 11);










	return EXIT_SUCCESS;
}
