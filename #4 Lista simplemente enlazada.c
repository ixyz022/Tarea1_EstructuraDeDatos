/* Kevin Alejandro Diaz Cantillano
20.479.055-8
#4 Lista simplemente enlazada */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructura de un nodo
typedef struct nodo
{
    int dato;
    struct nodo *sig; // Definicion recursiva
} NODO;

//funciones
NODO *crearNodo(int elem); // Funcion que retorna un nuevo NODO
void tamanoLista (NODO *cabeza); // Tamaño de la lista
void mostrarLista (NODO *cabeza); // Muestra la lista
bool estaVacia (NODO *cabeza); // Consultar si la lista esta vacia
void insertarFinal(NODO **cabeza, int elem); // Añadir un elemento al final de la lista
void insertarInicio(NODO **cabeza, int elem); // Añadir un elemento al inicio de la lista
bool encontrarElemento(NODO *cabeza, int elem); // ¿Se encuentra el elemento?


int main(int argc, char const *argv[])
{
    NODO *cabeza = NULL; // Inicializamos el inicio de nuestra lista
    insertarFinal(&cabeza, 5);
    insertarInicio(&cabeza, 4);
    insertarFinal(&cabeza, 9);
    mostrarLista(cabeza);
    tamanoLista(cabeza);
    
    if (encontrarElemento(cabeza,5)){
        printf("Se a encontrado el elemento");
    } else {
        printf("No se a encontrado el elemento");
    }
}

/* Como requisito inicial necesitamos disponer de la funcion
que nos permita crerar los nodos que posteriormente seran 
insertados */

NODO *crearNodo (int elem) {
    NODO *nuevo = NULL; // Creamos el elemento nodo vacio

    nuevo = (NODO*)malloc(sizeof(NODO));
    /* ¿Que hace sizeof?
    Reserva el espacio en memoria segun el tipo que especificamos */
    /* ¿Que hace malloc?
    Solicita un bloque de memoria del tamañano suministrado como
    parametro, devolviendo un puntero de la zona de memoria concedida*/

    nuevo -> dato = elem; // Guardamos elem en el campo dato del nodo
    nuevo -> sig = NULL; // Siguiente no apunta a nada

    return nuevo; // Retornamos un elemento nodo
}

//OPERACIONES

void tamanoLista (NODO *cabeza) { 
    NODO *nAux = cabeza;
    int contador = 0;
    
    while (nAux != NULL) {
        contador++;
        nAux = nAux -> sig;
    }

    printf("\nEl tamano de la lista es: %d\n", contador);
}

void mostrarLista (NODO *cabeza) { 
    NODO *nAux = cabeza;

    while( nAux != NULL)
    {
        printf("%d ", nAux->dato);
        nAux = nAux->sig;
    }
}

bool estaVacia (NODO *cabeza) {
    if (cabeza == NULL) {
        return true;
    } else {
        return false;
    }
}

void insertarInicio (NODO **cabeza, int elem) {
    if (*cabeza != NULL) {
        NODO *nuevo = crearNodo(elem);
        
        nuevo -> sig = *cabeza;
        *cabeza = nuevo;
    }
}

void insertarFinal (NODO **cabeza, int elem) {
    if(*cabeza != NULL) {
        NODO *nuevo = crearNodo(elem), *nAux = *cabeza;

        while(nAux->sig != NULL)
        {
            nAux = nAux->sig;
        }
        nAux->sig = nuevo;
    }
    else {
        *cabeza = crearNodo(elem);
    }

}

bool encontrarElemento(NODO *cabeza, int elem) {
    NODO *nAux = cabeza;

    while (nAux != NULL) {
        if (nAux -> dato == elem){
            return true;
        }
        nAux = nAux ->sig;
    }
    return false;  
}

// Eliminar un elemento desde la posicion