#include "parser.h"






int parser_libroRead(FILE* pFile, LinkedList* pLibros)
{
	int retorno;
	retorno = 0;

	char id[5];
	char titulo[51];
	char autor[51];
	char precio[6];
	char idEditorial[5];

	int len;

	if(pFile != NULL && pLibros != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, titulo, autor, precio, idEditorial);//FALSA LECTURA

		while(!feof(pFile))
		{
			if(feof(pFile))
			{
				break;
			}

			len = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, titulo, autor, precio, idEditorial);

			if(len == 5)
			{
				eLibro* miLibro;
				miLibro = libro_newLibro(id, titulo, autor, precio, idEditorial);
				ll_add(pLibros, miLibro);
			}
		}
	}
	return retorno;
}


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

int parser_editorialRead(FILE* pFile, LinkedList* pEditorial)
{
	int retorno;
	retorno = 0;

	char idEditorial[5];
	char nombre[31];

	int len;

	if(pFile != NULL && pEditorial != NULL)
	{
		fscanf(pFile, "%[^,], %[^\n]\n", idEditorial, nombre);//FALSA LECTURA

		while(!feof(pFile))
		{
			if(feof(pFile))
			{
				break;
			}

			len = fscanf(pFile, "%[^,], %[^\n]\n", idEditorial, nombre);

			if(len == 2)
			{
				eEditorial* miEditorial;
				miEditorial = editorial_newEditorial(idEditorial, nombre);
				ll_add(pEditorial, miEditorial);

			}
			else
			{
				break;
			}
		}
	}
	return retorno;
}


int parser_minotauroWrite(FILE* pFile, LinkedList* pMinotauro)
{
	int retorno;

	int id;
	char titulo[51];
	char autor[51];
	int precio;

	retorno = 0;

	eLibro* libro;

	if(pFile != NULL && pMinotauro != NULL)
	{
		fprintf(pFile,"id,titulo,autor,precio,editorial\n");

		for(int i = 0; i < ll_len(pMinotauro); i++)
		{
			libro = (eLibro*)ll_get(pMinotauro, i);

			libro_getId(libro, &id);
			libro_getTitulo(libro, titulo);
			libro_getAutor(libro, autor);
			libro_getPrecio(libro, &precio);

			fprintf(pFile, "%d,%s,%s,%d,MINOTAURO\n", id, titulo, autor, precio);
			retorno = 1;
		}
	}

	return retorno;
}

int parser_mapWrite(FILE* pFile, LinkedList* pMap)
{
	int retorno;

	int id;
	char titulo[51];
	char autor[51];
	int precio;
	int idEditorial;

	retorno = 0;

	eLibro* libro;

	if(pFile != NULL && pMap != NULL)
	{
		fprintf(pFile,"id,titulo,autor,precio,idEditorial\n");

		for(int i = 0; i < ll_len(pMap); i++)
		{
			libro = (eLibro*)ll_get(pMap, i);

			libro_getId(libro, &id);
			libro_getTitulo(libro, titulo);
			libro_getAutor(libro, autor);
			libro_getPrecio(libro, &precio);
			libro_getIdEditorial(libro, &idEditorial);

			fprintf(pFile, "%d,%s,%s,%d,%d\n", id, titulo, autor, precio, idEditorial);
			retorno = 1;
		}
	}

	return retorno;
}
