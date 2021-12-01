#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct
{
	int idEditorial;
	char nombre[31];
}eEditorial;


int editorial_oneEditorial(eEditorial* this);

eEditorial* editorial_new();

eEditorial* editorial_newEditorial(char* idEditorialS, char* nombreS);

////////////////////SETTERS////////////////////////////////////

int editorial_setIdEditorial(eEditorial* this, int idEditorial);

int editorial_setNombre(eEditorial* this, char* nombre);

////////////////////GETTERS////////////////////////////////////


int editorial_getIdEditorial(eEditorial* this, int* idEditorial);

int editorial_getNombre(eEditorial* this, char* nombre);








#endif /* EDITORIAL_H_ */
