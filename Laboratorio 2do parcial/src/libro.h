#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
	int id;
	char titulo[31];
	char autor[31];
	int precio;
	int descuentoPrecio;
	int idEditorial;
}eLibro;


int libro_compareEditorial(void* libro1);

int libro_oneLibro(eLibro* this, char* nombreEditorial);

int libro_compareAutor(void* libro1, void* libro2);

eLibro* libro_new();

eLibro* libro_newLibro(char* idS, char* tituloS, char* autorR, char* precioS, char* idEditorialS);

eLibro* libro_newLibroInt(int idS, char* tituloS, char* autorR, int precioS, int idEditorialS);

////////////////////SETTERS////////////////////////////////////

int libro_setId(eLibro* this, int id);

int libro_setTitulo(eLibro* this, char* titulo);

int libro_setAutor(eLibro* this, char* autor);

int libro_setPrecio(eLibro* this, int precio);

int libro_setPrecioDes(eLibro* this, int precioD);

int libro_setIdEditorial(eLibro* this, int idEditorial);

////////////////////GETTERS////////////////////////////////////

int libro_getId(eLibro* this, int* id);

int libro_getTitulo(eLibro* this, char* titulo);

int libro_getAutor(eLibro* this, char* autor);

int libro_getPrecio(eLibro* this, int* precio);

int libro_getPrecioDes(eLibro* this, int* precioD);

int libro_getIdEditorial(eLibro* this, int* idEditorial);






#endif /* LIBRO_H_ */
