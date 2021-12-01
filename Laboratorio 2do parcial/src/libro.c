#include "libro.h"


int libro_oneLibro(eLibro* this, char* nombreEditorial)
{
	int retorno;
	retorno = 0;

	int id;
	char titulo[31];
	char autor[31];
	int precio;
	int descuento;

	if(this != NULL)
	{

		libro_getId(this, &id);
		libro_getTitulo(this, titulo);
		libro_getAutor(this, autor);
		libro_getPrecio(this, &precio);
		libro_getPrecioDes(this, &descuento);


		printf("|%5d | %21s | %31s | %6d | %21s |\n", id, titulo, autor, precio, nombreEditorial);
		retorno = 1;
	}
	return retorno;
}

int libro_compareAutor(void* libro1, void* libro2)
{
	int retorno;
	retorno = 0;

	char nombre1[31];
	char nombre2[31];

	if(libro1 != NULL && libro2 != NULL)
	{
		eLibro* primerLibro;
		eLibro* segundoLibro;

		primerLibro = (eLibro*)libro1;
		segundoLibro = (eLibro*)libro2;

		libro_getAutor(primerLibro, nombre1);
		libro_getAutor(segundoLibro, nombre2);

		retorno = strcmp(nombre1, nombre2);
	}
	return retorno;
}

int libro_compareEditorial(void* libro1)
{
	int retorno;
	retorno = 0;

	int id1;
	int precio;

	if(libro1 != NULL)
	{
		eLibro* primerLibro;

		primerLibro = (eLibro*)libro1;

		libro_getIdEditorial(primerLibro, &id1);
		libro_getPrecio(primerLibro, &precio);

		if(id1 == 1 && precio > 299)
		{
			retorno = 1;
		}
		else
		{
			if(id1 == 2 && precio < 201)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

eLibro* libro_new()
{
	eLibro* unLibro;
	unLibro = (eLibro*)malloc(sizeof(eLibro));

	return unLibro;
}

eLibro* libro_newLibro(char* idS, char* tituloS, char* autorR, char* precioS, char* idEditorialS)
{
	eLibro* unLibro;
	unLibro = libro_new();

	if(unLibro != NULL)
	{
		libro_setId(unLibro, atoi(idS));
		libro_setTitulo(unLibro, tituloS);
		libro_setAutor(unLibro, autorR);
		libro_setPrecio(unLibro, atoi(precioS));
		libro_setIdEditorial(unLibro, atoi(idEditorialS));
	}
	return unLibro;
}

eLibro* libro_newLibroInt(int idS, char* tituloS, char* autorR, int precioS, int idEditorialS)
{
	eLibro* unLibro;
	unLibro = libro_new();

	if(unLibro != NULL)
	{
		libro_setId(unLibro, idS);
		libro_setTitulo(unLibro, tituloS);
		libro_setAutor(unLibro, autorR);
		libro_setPrecio(unLibro, precioS);
		libro_setIdEditorial(unLibro, idEditorialS);
	}
	return unLibro;
}

///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////


int libro_setId(eLibro* this, int id)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int libro_setTitulo(eLibro* this, char* titulo)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		strcpy(this->titulo, titulo);
		retorno = 1;
	}
	return retorno;
}

int libro_setAutor(eLibro* this, char* autor)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		strcpy(this->autor, autor);
		retorno = 1;
	}
	return retorno;
}

int libro_setPrecio(eLibro* this, int precio)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}
int libro_setPrecioDes(eLibro* this, int precioD)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		this->descuentoPrecio = precioD;
		retorno = 1;
	}
	return retorno;
}

int libro_setIdEditorial(eLibro* this, int idEditorial)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		this->idEditorial = idEditorial;
		retorno = 1;
	}
	return retorno;
}


///////////////////////GETTERS////////////////////////////////////
///////////////////////GETTERS////////////////////////////////////
///////////////////////GETTERS////////////////////////////////////
///////////////////////GETTERS////////////////////////////////////
///////////////////////GETTERS////////////////////////////////////
///////////////////////GETTERS////////////////////////////////////
///////////////////////GETTERS////////////////////////////////////


int libro_getId(eLibro* this, int* id)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int libro_getTitulo(eLibro* this, char* titulo)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		strcpy(titulo, this->titulo);
		retorno = 1;
	}
	return retorno;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		strcpy(autor, this->autor);
		retorno = 1;
	}
	return retorno;
}

int libro_getPrecio(eLibro* this, int* precio)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int libro_getPrecioDes(eLibro* this, int* precioD)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		*precioD = this->descuentoPrecio;
		retorno = 1;
	}
	return retorno;
}

int libro_getIdEditorial(eLibro* this, int* idEditorial)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 1;
	}
	return retorno;
}


