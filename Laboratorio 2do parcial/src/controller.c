#include "controller.h"




int controller_readAndAddLibros(char* path, LinkedList* pLinkedLibros)
{

	int retorno;
	retorno = 0;

	FILE* pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		parser_libroRead(pFile, pLinkedLibros);

		retorno = 1;
	}
	fclose(pFile);
	return retorno;
}

int controller_readAndAddEditoriales(char* path, LinkedList* pLinkedEditoriales)
{
	int retorno;
	retorno = 0;

	FILE* pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		parser_editorialRead(pFile, pLinkedEditoriales);
		retorno = 1;
	}
	fclose(pFile);
	return retorno;
}

int controller_orderLibros(LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales)
{
	int retorno;
	retorno = 0;

	if(pLinkedLibros != NULL)
	{
		ll_sort(pLinkedLibros, libro_compareAutor, 0);
		controller_listLibros(pLinkedLibros, pLinkedEditoriales);
		retorno = 1;
	}
	return retorno;
}

int controller_listLibros(LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales)
{
	int retorno;
	retorno = 0;

	eLibro* miLibro;
	eEditorial* miEditorial;

	if(pLinkedEditoriales != NULL && pLinkedLibros != NULL)
	{
		printf("---------------------------------------------------------------------------------------------------\n");
		printf("|   ID |         TITULO        |              AUTOR              | PRECIO |       EDITORIAL       |\n");
		printf("|------|-----------------------|---------------------------------|--------|-----------------------|\n");
		for(int i = 0; i < ll_len(pLinkedLibros); i++)
		{
			miLibro = (eLibro*)ll_get(pLinkedLibros, i);

			for(int j = 0; j < ll_len(pLinkedEditoriales); j++)
			{
				miEditorial = (eEditorial*)ll_get(pLinkedEditoriales, j);
				if(miLibro->idEditorial == miEditorial->idEditorial)
				{
					libro_oneLibro(miLibro, miEditorial->nombre);
					retorno = 1;
				}
			}
		}
		printf("---------------------------------------------------------------------------------------------------\n");
	}
	return retorno;
}


int controller_listLibrosxEditorial(char* path, LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales)
{
	int retorno;
	retorno = 0;

	LinkedList* listaFiltrada;

	FILE* pFile;

	pFile = fopen(path, "w");

	if(pLinkedEditoriales != NULL && pLinkedLibros != NULL && pFile != NULL)
	{
		retorno = 1;
		listaFiltrada = ll_filter(pLinkedLibros, fn);

		controller_listLibros(listaFiltrada, pLinkedEditoriales);
		parser_minotauroWrite(pFile, listaFiltrada);
		retorno = 1;
	}
	fclose(pFile);

	return retorno;
}

int controller_funcionMap(char* path, LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales)
{
	int retorno;
	retorno = 0;

	LinkedList* listaMap;

	FILE* pFile;

	pFile = fopen(path, "w");

	if(pLinkedEditoriales != NULL && pLinkedLibros != NULL && pFile != NULL)
	{

		retorno = 1;
		listaMap = ll_map(pLinkedLibros, libro_compareEditorial);


		controller_listLibros(listaMap, pLinkedEditoriales);

		parser_mapWrite(pFile, listaMap);

		retorno = 1;
	}
	fclose(pFile);

	return retorno;
}

int fn(void* element)
{
	int retorno;
	retorno = 0;

	eLibro* pLibro;
	pLibro = (eLibro*)element;

	if(pLibro->idEditorial == 4)
	{
		retorno = 1;
	}
	return retorno;
}

int filtrarPorEditorial(void* pElement)
{
	int retorno;
	int idThisEditorial;
	retorno = 0;

	eLibro* pLibro;
	pLibro = (eLibro*)pElement;

	libro_getIdEditorial(pLibro, &idThisEditorial);

	if(idThisEditorial == 3)
	{
		retorno = 2;
	}
	return retorno;
}

///////////////////////////////////////////////
///////////////////////////////////////////////
//////////////////PRUEBA///////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
int fn_superanPrecio(void* element)
{
	int retorno;
	retorno = 0;

	eLibro* pLibro;
	pLibro = (eLibro*)element;

	if(pLibro->precio > 499)
	{
		retorno = 1;
	}

	return retorno;
}


int controller_listLibrosSuperanXPrecio(LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales)
{
	int retorno;
	retorno = 0;

	LinkedList* listaFiltrada;

	if(pLinkedEditoriales != NULL && pLinkedLibros != NULL)
	{
		retorno = 1;
		listaFiltrada = ll_filter(pLinkedLibros, fn_superanPrecio);

		controller_listLibros(listaFiltrada, pLinkedEditoriales);
	}

	return retorno;
}

int controller_masDe500(LinkedList* pLinkedLibros)
{
	int retorno;
	int cantidadMasDe500;
	retorno = 0;

	if(pLinkedLibros != NULL)
	{
		retorno = 1;
		cantidadMasDe500 = ll_count(pLinkedLibros, fn_superanPrecio);
		printf("\n%d libros superan los $500\n", cantidadMasDe500);
	}
	return retorno;
}

int controller_precioTotalxEditorial(LinkedList* pLinkedLibros)
{
	int retorno;
	int precioTotal;

	retorno = 0;

	if(pLinkedLibros != NULL)
	{
		retorno = 1;
		precioTotal = ll_count(pLinkedLibros, filtrarPorEditorial);
		printf("\nEl precio total de las editoriales PEARSON es de %d\n", precioTotal);
	}
	return retorno;
}

