#ifndef CONTROLLER_H_
#define CONTROLLER_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "libro.h"
#include "editorial.h"
#include "LinkedList.h"
#include "funciones.h"
#include "parser.h"

int controller_precioTotalxEditorial(LinkedList* pLinkedLibros);

int filtrarPorEditorial(void* pElement);

int controller_masDe500(LinkedList* pLinkedLibros);

int controller_funcionMap(char* path, LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales);

int controller_readAndAddLibros(char* path, LinkedList* pLinkedLibros);

int controller_readAndAddEditoriales(char* path, LinkedList* pLinkedEditoriales);

int controller_orderLibros(LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales);

int controller_listLibros(LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales);

int controller_listLibrosxEditorial(char* path, LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales);

int fn(void* element);


///////////////////////////////////////////////
/// ///////////////////////////////////////////////
/// ///////////////////////////////////////////////
/// ///////////////////////////////////////////////
/// ///////////////////////////////////////////////
/// ///////////////////////////////////////////////
int fn_superanPrecio(void* element);

int controller_listLibrosSuperanXPrecio(LinkedList* pLinkedLibros, LinkedList* pLinkedEditoriales);


#endif /* CONTROLLER_H_ */
