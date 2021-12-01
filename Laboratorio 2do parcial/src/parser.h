
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include "LinkedList.h"
#include "libro.h"
#include "editorial.h"


int parser_libroRead(FILE* pFile, LinkedList* pLibros);

int parser_editorialRead(FILE* pFile, LinkedList* pEditorial);

int parser_minotauroWrite(FILE* pFile, LinkedList* pMinotauro);

int parser_mapWrite(FILE* pFile, LinkedList* pMap);




#endif /* PARSER_H_ */
