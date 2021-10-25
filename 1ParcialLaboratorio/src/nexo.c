#include "nexo.h"


int menu(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int opcionMenu;
	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0)
	{
		if(BuscarVacio(listaClientes, tamClientes) == -1)//está lleno
		{
			opcionMenu = GetIntRangos("\n1 Alta cliente (no disponible)"
									  "\n2 Modificar datos cliente"
									  "\n3 Baja cliente"
									  "\n4 Crear pedido de recoleccion"
									  "\n5 Procesar residuos"
									  "\n6 Imprimir clientes"
									  "\n7 Imprimir pedidos pendiendes"
									  "\n8 Imprimir pedidos procesados"
									  "\n9 Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad"
									  "\n10 Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)"
									  "\n11 Informes de clientes con sus pedidos"
									  "\n12 Salir"
									  "\n\nIngresar opcion: ", 2, 12);
		}
		else
		{
			if(BuscarCargado(listaClientes, tamClientes) == -1)//está vacio
			{
				do
				{
					opcionMenu = GetIntRangos("\n1 Alta cliente"
											  "\n2 Modificar datos cliente (no disponible)"
											  "\n3 Baja cliente (no disponible)"
											  "\n4 Crear pedido de recoleccion (no disponible)"
											  "\n5 Procesar residuos (no disponible)"
											  "\n6 Imprimir clientes (no disponible)"
											  "\n7 Imprimir pedidos pendiendes (no disponible)"
											  "\n8 Imprimir pedidos procesados (no disponible)"
											  "\n9 Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad (no disponible)"
											  "\n10 Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes) (no disponible)"
										    "\n11 Informes de clientes con sus pedidos"
											 "\n12 Salir"
											  "\n\nIngresar opcion: ", 1, 12);
				}while(opcionMenu != 1 && opcionMenu != 11);

			}
			else//no esta lleno ni vacio
			{
				opcionMenu = GetIntRangos("\n1 Alta cliente"
										  "\n2 Modificar datos cliente"
										  "\n3 Baja cliente"
										  "\n4 Crear pedido de recoleccion"
										  "\n5 Procesar residuos"
										  "\n6 Imprimir clientes"
										  "\n7 Imprimir pedidos pendiendes"
										  "\n8 Imprimir pedidos procesados"
										  "\n9 Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad"
										  "\n10 Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)"
											"\n11 Informes de clientes con sus pedidos"
											 "\n12 Salir"
										  "\n\nIngresar opcion: ", 1, 12);
			}
		}
	}
	return opcionMenu;
}



int CrearPedido(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int idPedido)
{
	int retorno;
	int existeID;
	int indicePedido;
	int idCliente;

	retorno = 0;

	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0)
	{
		existeID = EncontrarClientePorId(listaClientes, tamClientes);
		if(existeID != -1)// SI EL CLIENTE EXISTE...
		{
			idCliente = listaClientes[existeID].id;
			indicePedido = BuscarPedidoVacio(listaPedidos, tamPedidos);
			if(indicePedido != -1)
			{
				listaPedidos[indicePedido] = HacerPedido(listaPedidos[indicePedido], idCliente, idPedido);
				listaClientes[existeID].cantidadPedidosPendientes++;
				listaClientes[existeID].cantidadTotalPedidos++;
				retorno = 1;

			}
		}
	}
	return retorno;
}

void PedidosPorEstadoYLocalidad(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int estado, eLocalidad listaLocalidades[], int tamLocalidades)
{
	char localidadBuscar[31];
	int cantidadPendientes;
	int idBuscar;
	cantidadPendientes = 0;

	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0)
	{
		GetString("\nLocalidad: ", localidadBuscar);

		for(int i = 0; i < tamClientes; i++)
		{
			for(int j = 0; j < tamLocalidades; j++)
			{
				if(strcmp(listaLocalidades[j].localidad, localidadBuscar) == 0)
				{

						idBuscar = listaClientes[i].id;
						for(int j = 0; j < tamPedidos; j++)
						{
							if(idBuscar == listaPedidos[j].idCliente && listaPedidos[j].estado == PENDIENTE)
							{
								cantidadPendientes++;
							}
						}
				}
			}
		}

		printf("\nCantidad de pedidos en %s: %d",localidadBuscar, cantidadPendientes);
	}
}





int BajaCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int indiceBaja;
	int confirmarBaja;
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0)
	{
		indiceBaja = EncontrarClientePorId(listaClientes, tamClientes);

		if(indiceBaja != -1)
		{
			confirmarBaja = GetIntRangos("\n¿Desea confirmar la baja?\nSe eliminaran todos los pedidos del cliente\n1. SI | 2. NO: ", 1, 2);
			if(confirmarBaja == 1)
			{
				listaClientes[indiceBaja].estado = VACIO;
				for(int i = 0; i < tamPedidos; i++)
				{
					if(listaPedidos[i].idCliente == listaClientes[indiceBaja].id)
					{
						listaPedidos[i].estado = PEDIDOVACIO;
					}
				}
				retorno = 1;
			}

		}
	}
	return retorno;
}

int AltaCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, int id)
{
	int indiceAlta;
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tamClientes > 0)
	{
		indiceAlta = BuscarVacio(listaClientes, tamClientes);
		if(indiceAlta != -1)
		{
			listaClientes[indiceAlta] = PedirCliente(listaClientes, tamClientes, listaLocalidades, tamLocalidades, id);
			retorno = 1;
		}
	}

	if(retorno == 1)
	{
		printf("\nAlta exitosa\nID: %d\n", id);
	}
	return retorno;
}


int CalcularPromedioDeReciclado(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno;
	int cantidadClientes;
	float cantidadTotalPolipropileno;

	float promedioReciclado;


	cantidadClientes = 0;
	cantidadTotalPolipropileno = 0;


	retorno = 0;

	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].estado == CARGADO)
			{
				cantidadClientes++;
				for(int j = 0; j < tamPedidos; j++)
				{
					if(listaPedidos[j].estado == COMPLETADO && listaPedidos[j].cantPP > 0 && listaPedidos[j].idCliente == listaClientes[i].id)
					{
						cantidadTotalPolipropileno += listaPedidos[i].cantPP;
						retorno = 1;
					}
				}
			}
		}
	}

	promedioReciclado = cantidadTotalPolipropileno / cantidadClientes;
	printf("\nEl promedio de kilos de polipropileno reciclado promedio por cliente es: %.2f", promedioReciclado);
	return retorno;
}


int ProcesarResiduos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno;
	int indicePedido;
	int cantTotalKilos;
	retorno = 0;

	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0)
	{
		indicePedido = EncontrarPedidoPorId(listaPedidos, tamPedidos);
		if(indicePedido != -1 && listaPedidos[indicePedido].estado == PENDIENTE)
		{
			cantTotalKilos = listaPedidos[indicePedido].cantKilos;

			printf("\n------Ingresar cantidad de kilos------");

			listaPedidos[indicePedido].cantHDPE = GetIntRangos("\nHDPE: ", 0, cantTotalKilos);
			cantTotalKilos -= listaPedidos[indicePedido].cantHDPE;

			if(cantTotalKilos > 0)
			{
				listaPedidos[indicePedido].cantLDPE = GetIntRangos("\nLDPE: ", 0, cantTotalKilos);
				cantTotalKilos -= listaPedidos[indicePedido].cantLDPE;

				if(cantTotalKilos > 0)
				{
					listaPedidos[indicePedido].cantPP = GetIntRangos("\nPP: ", 0, cantTotalKilos);
					cantTotalKilos -= listaPedidos[indicePedido].cantPP;
				}
			}

			if(cantTotalKilos > 0)
			{
				printf("\nKilos de plástico desechados: %d", cantTotalKilos);
			}
			else
			{
				printf("\nPlástico clasificado exitosamente!");
			}

			listaPedidos[indicePedido].estado = COMPLETADO;

			for(int i = 0; i < tamClientes; i++)
			{
				if(listaPedidos[indicePedido].idCliente == listaClientes[i].id && listaClientes[i].estado == CARGADO)
				{
					listaClientes[i].cantidadPedidosPendientes--;
					listaClientes[i].cantidadPedidosCompletados++;
					break;
				}
			}
			retorno = 1;
		}
	}
	return retorno;
}




int GetLocalidad(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, int id)
{
	int retorno;
	int indiceLocalidad;
	retorno = 0;
	if(listaClientes != NULL && tamClientes > 0 && listaLocalidades != NULL && tamLocalidades > 0)
	{
		for(int i = 0; i < tamClientes; i++)
		{
			if(listaClientes[i].id == id)
			{

				indiceLocalidad = BuscarVacioLocalidad(listaLocalidades, tamLocalidades);
				if(indiceLocalidad != -1)
				{
					listaLocalidades[indiceLocalidad].idLocalidad = id;
					GetString("\nLocalidad: ", listaLocalidades[indiceLocalidad].localidad);
					retorno = 1;
					listaLocalidades[indiceLocalidad].estadoLoc = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


eCliente PedirCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, int id)
{
	eCliente cliente;

	cliente.id = id;
	GetString("\nNombre de la empresa: ", cliente.nombreEmpresa);
	GetCuit("\nCuit: ", cliente.cuit);
	GetDireccion("\nDireccion: ", cliente.direccion);

	GetLocalidad(listaClientes, tamClientes, listaLocalidades, tamLocalidades, id);

	cliente.estado = CARGADO;
	cliente.cantidadPedidosPendientes = 0;
	cliente.cantidadPedidosCompletados = 0;
	cliente.cantidadTotalPedidos = 0;

	return cliente;
}









