#include <stdio.h>
#include <stdlib.h>

#include "libro.h"
#include "editorial.h"
#include "LinkedList.h"
#include "funciones.h"
#include "controller.h"


#define LIBRO_CSV "listado.csv"
#define EDITORIAL_CSV "editorial.csv"
#define MINOTAURO_CSV "minotauro.csv"
#define MAP_CSV "mapeado.csv"


int main(void) {
	setbuf(stdout, NULL);

	LinkedList* libros;
	LinkedList* editoriales;

	libros = ll_newLinkedList();
	editoriales = ll_newLinkedList();

	int opcion;
	int flagCargaLibros;
	int flagCargaEditoriales;
	char mensaje[140];
	strcpy(mensaje, "\nDeben cargarse previamente los libros y las editoriales para poder mostrar\n");

	flagCargaLibros = 1;
	flagCargaEditoriales = 1;

	do
	{
		opcion = GetIntRangos("\n1. Cargar libros"
							  "\n2. Cargar editoriales"
							  "\n3. Ordenar libros por autor"
							  "\n4. Imprimir libros."
							  "\n5. Imprimir un listado de los libros de la editorial MINOTAURO."
							  "\n6. Funcion Map"
							  "\n7. Cantidad de libros que cuestan mas de $500"
							  "\n8. Precio total de los libros de la editorial PEARSON"
							  "\n9. Finalizar programa"
							  "\n\nIngresar opcion: ", 1, 9);

			switch(opcion)
			{
			case 1:
				if(flagCargaLibros)
				{
					if(controller_readAndAddLibros(LIBRO_CSV, libros))
					{
						printf("\nLibros cargados con exito!!\n");
					}
					flagCargaLibros = 0;
				}
				else
				{
					printf("\nLos libros ya han sido cargados.\n");
				}

				break;

			case 2:
				if(flagCargaEditoriales)
				{
					if(controller_readAndAddEditoriales(EDITORIAL_CSV, editoriales))
					{
						printf("\nEditoriales cargadas con exito!!\n");
					}
					flagCargaEditoriales = 0;
				}
				else
				{
					printf("\nLas editoriales ya han sido cargadas.\n");
				}
				break;

			case 3:
				if(flagCargaEditoriales == 0 && flagCargaLibros == 0)
				{
					controller_orderLibros(libros, editoriales);
				}
				else
				{
					printf("%s", mensaje);
				}
				break;

			case 4:
				if(flagCargaEditoriales == 0 && flagCargaLibros == 0)
				{
					controller_listLibros(libros, editoriales);
				}
				else
				{
					printf("%s", mensaje);
				}
				break;

			case 5:
				if(flagCargaEditoriales == 0 && flagCargaLibros == 0)
				{
					controller_listLibrosxEditorial(MINOTAURO_CSV, libros, editoriales);
				}
				else
				{
					printf("%s", mensaje);
				}
				break;

			case 6:
				if(flagCargaEditoriales == 0 && flagCargaLibros == 0)
				{
					controller_funcionMap(MAP_CSV, libros, editoriales);
				}
				else
				{
					printf("%s", mensaje);
				}
				break;

			case 7:
				if(flagCargaEditoriales == 0 && flagCargaLibros == 0)
				{
					controller_masDe500(libros);
				}
				else
				{
					printf("%s", mensaje);
				}
				break;

			case 8:
				if(flagCargaEditoriales == 0 && flagCargaLibros == 0)
				{
					controller_precioTotalxEditorial(libros);
				}
				else
				{
					printf("%s", mensaje);
				}
				break;

			case 9:
				printf("===========PROGRAMA FINALIZADO===========");
				ll_deleteLinkedList(editoriales);
				ll_deleteLinkedList(libros);
				break;

			}
		}while(opcion != 9);



	return EXIT_SUCCESS;
}
