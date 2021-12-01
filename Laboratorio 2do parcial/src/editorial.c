#include "editorial.h"





int editorial_oneEditorial(eEditorial* this)
{
	int retorno;
	retorno = 0;

	int idEditorial;
	char nombre[31];

	if(this != NULL)
	{
		editorial_getIdEditorial(this, &idEditorial);
		editorial_getNombre(this, nombre);

		printf("|%5d | %21s |", idEditorial, nombre);
		retorno = 1;
	}
	return retorno;
}



eEditorial* editorial_new()
{
	eEditorial* unaEditorial;
	unaEditorial = (eEditorial*)malloc(sizeof(eEditorial));

	return unaEditorial;
}


eEditorial* editorial_newEditorial(char* idEditorialS, char* nombreS)
{
	eEditorial* unaEditorial;
	unaEditorial = editorial_new();

	if(unaEditorial != NULL)
	{
		editorial_setIdEditorial(unaEditorial, atoi(idEditorialS));
		editorial_setNombre(unaEditorial, nombreS);
	}
	return unaEditorial;
}






///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////
///////////////////////SETTERS////////////////////////////////////



int editorial_setIdEditorial(eEditorial* this, int idEditorial)
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

int editorial_setNombre(eEditorial* this, char* nombre)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
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

int editorial_getIdEditorial(eEditorial* this, int* idEditorial)
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

int editorial_getNombre(eEditorial* this, char* nombre)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}
