#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;


    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }


    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodeReturn;
	pNodeReturn = NULL;


	if(this != NULL && nodeIndex > -1 && nodeIndex < this->size)
	{
		pNodeReturn = this->pFirstNode;

		for(int i = 0; i < nodeIndex; i++)
		{
			pNodeReturn = pNodeReturn->pNextNode;
		}
	}
	return pNodeReturn;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* pNewNode;
    pNewNode = (Node*)malloc(sizeof(Node));

    Node* pAuxNewNode;


	if(this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this))
	{
		pNewNode->pElement = pElement;
		pNewNode->pNextNode = NULL;

		if(pNewNode != NULL)
		{
			if(nodeIndex == 0)
			{
				pNewNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNewNode;
			}
			else
			{
				pAuxNewNode = getNode(this, nodeIndex - 1);
				//pNewNode->pNextNode = pAuxNewNode->pNextNode;
				pAuxNewNode->pNextNode = pNewNode;
			}
			returnAux = 0;
			this->size++;
		}
    }
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{




    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int posicion;

    if(this != NULL)
    {
    	posicion = ll_len(this);
    	addNode(this, posicion, pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxNode;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pAuxNode = getNode(this, index);

    	if(pAuxNode->pElement != NULL)
    	{
    		returnAux = pAuxNode->pElement;
    	}

    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pAuxNode = getNode(this, index);
    	pAuxNode->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pUnoNode;
    Node* pDosNode;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pUnoNode = getNode(this, index - 1);
    	pDosNode = getNode(this, index);
    	if(index == 0)
    	{
    		this->pFirstNode = pDosNode->pNextNode;
    	}
    	else
    	{
    		pUnoNode->pNextNode = pDosNode->pNextNode;
    	}
    	free(pDosNode);
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;


    if(this != NULL)
    {
    	for(int i = 0; i < ll_len(this); i++)
    	{
    		ll_remove(this, 0);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	for(int i = 0; i < ll_len(this); i++)
    	{
    		if(ll_get(this, i) == pElement)
    		{
				returnAux = i;
				break;

    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
    	if(this->pFirstNode == NULL)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

	if(this != NULL && index > -1 && index <= ll_len(this))
	{
		returnAux = 0;

		addNode(this, index, pElement);
    }
	return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux;


    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	this->size--;
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;

    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(int i = 0; i < ll_len(this2); i++)
    	{
    		if(ll_contains(this, ll_get(this2, i)) == 0)
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL && from >= 0 && to > from && from < ll_len(this) && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	for(int i = from; i < to; i++)
    	{
			ll_add(cloneArray, ll_get(this, i));
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pAuxElement;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	returnAux = 0;

    	for(int i = 0; i < ll_len(this) - 1; i++)
    	{
    		for(int j = i + 1; j < ll_len(this); j++)
    		{
    			if(order == 0)
    			{
					if(pFunc(ll_get(this, i), ll_get(this, j)) < 0)
					{
						pAuxElement = ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, pAuxElement);
					}
    			}
    			else
    			{
					if(pFunc(ll_get(this, i), ll_get(this, j)) > 1)
					{
						pAuxElement = ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, pAuxElement);
					}
    			}
    		}
    	}
    }


    return returnAux;
}




LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* newLinkedlist;
	newLinkedlist = ll_newLinkedList();

	void* pAuxElement;

	if(this != NULL && fn != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			pAuxElement = ll_get(this, i);

			if(fn(pAuxElement) == 1)
			{
				ll_add(newLinkedlist, pAuxElement);
			}
		}
	}

	return newLinkedlist;
}


LinkedList* ll_map(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* linkedMap;
	linkedMap = ll_newLinkedList();

	eLibro* nuevoLibro;
	void* pAuxElement;

	int id;
	char titulo[31];
	char autor[31];
	int precio;
	int idEditorial;

	int descuento;
	int precioDescuento;

	int retorno;

	if(this != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			pAuxElement = ll_get(this, i);

			retorno = libro_compareEditorial(pAuxElement);

			if(retorno == 1)
			{
				descuento = 20;
			}
			else
			{
				if(retorno == -1)
				{
					descuento = 10;
				}
			}

			if(retorno != 0)
			{
				libro_getId(pAuxElement, &id);
				libro_getTitulo(pAuxElement, titulo);
				libro_getAutor(pAuxElement, autor);
				libro_getPrecio(pAuxElement, &precio);
				libro_getIdEditorial(pAuxElement, &idEditorial);

				descuento = (precio / 100) * descuento;
				precioDescuento = precio - descuento;

				nuevoLibro = libro_newLibroInt(id, titulo, autor, precio, idEditorial);

				libro_setPrecio(nuevoLibro, precioDescuento);

				ll_add(linkedMap, nuevoLibro);
			}
			else
			{
				ll_add(linkedMap, pAuxElement);
			}
		}
	}
	return linkedMap;
}



int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int cantidad;
	int precio;

	cantidad = 0;

	for(int i = 0; i < ll_len(this); i++)
	{
		if(fn(ll_get(this, i)) == 1)
		{
			cantidad++;
		}
		else
		{
			if(fn(ll_get(this, i)) == 2)
			{
				libro_getPrecio(ll_get(this, i), &precio);
				cantidad += precio;
			}
		}
	}
	return cantidad;
}

int ll_countPrecio(LinkedList* this, int (*fn)(void* element))
{
	int total;
	int precio;
	total = 0;

	for(int i = 0; i < ll_len(this); i++)
	{
		if(fn(ll_get(this, i)) == 1)
		{
			libro_getPrecio(ll_get(this, i), &precio);
			total += precio;
		}
	}
	return total;
}

