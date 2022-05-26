/*  Manejo de una lista simplemente enlazada
    Asael García
    18/09/2015
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} NODO;

NODO* CrearNodo(int dato);
int InsertarInicio(NODO **cabeza, int dato);
int InsertarFinal(NODO **cabeza, int dato);
void ImprimirLista(NODO *cabeza);
int EstaVacia(NODO *cabeza);
int ExisteElemento(NODO *cabeza, int dato);


int main()
{
    NODO *cabeza = NULL;
    int res;

    InsertarInicio(&cabeza, 5);
    InsertarInicio(&cabeza, 4);
    InsertarFinal(&cabeza, 6);
    InsertarFinal(&cabeza, 7);
    ImprimirLista(cabeza);
    res = ExisteElemento(cabeza, 4);

    if(res == 1)
        printf("\nEl elemento esta en la lista...");
    else
        printf("\nEl elemento no se encuentra en la lista...");

    return 0;
}

//Función para crear un nuevo nodo de la lista
NODO* CrearNodo(int dato)
{
    NODO *nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));
    if( nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
    }

    return nuevo;
}

//Función para insertar un nodo al principio de la lista
int InsertarInicio(NODO **cabeza, int dato)
{
    NODO* nuevo = NULL;

    nuevo = CrearNodo(dato);
    if( nuevo != NULL )
    {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        return 1;
    }

    return 0;
}

//Función para imprimir todos los datos de la lista
void ImprimirLista(NODO *cabeza)
{
    NODO *nAux = cabeza;

    while( nAux != NULL)
    {
        printf("%d ", nAux->dato);
        nAux = nAux->siguiente;
    }
}

//Función para insertar un nodo al final de la lista
int InsertarFinal(NODO **cabeza, int dato)
{
    NODO* nuevo = NULL, *nAux = *cabeza;

    nuevo = CrearNodo(dato);
    if( nuevo != NULL)
    {
        while(nAux->siguiente != NULL)
        {
            nAux = nAux->siguiente;
        }
        nAux->siguiente = nuevo;
        return 1;
    }
    return 0;
}

//Función para verificar si una lista está vacía
int EstaVacia(NODO *cabeza)
{
    if ( cabeza == NULL)
        return 1;
    else
        return 0;
}

//Función para verificar si existe un elemento en la lista
int ExisteElemento(NODO *cabeza, int dato)
{
    NODO *nAux = cabeza;

    while( nAux != NULL )
    {
        if(nAux->dato == dato)
            return 1;
        nAux = nAux->siguiente;
    }
    return 0;
}
