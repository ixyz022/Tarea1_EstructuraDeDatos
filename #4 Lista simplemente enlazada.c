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
int tamanoLista (NODO *lista); // Tamaño de la lista
void mostrarLista (NODO *lista); // Muestra la lista
void estaVacia (NODO *lista); // Consultar si la lista esta vacia
void insertarFinal(NODO **lista, int elem); // Añadir un elemento al final de la lista
void insertarInicio(NODO **lista, int elem); // Añadir un elemento al inicio de la lista
void eliminarElemento (NODO **lista, int elem, int operacion); // Eliminar un elemento de la lista desde su posicion o valor
void vaciarLista (NODO **lista); // Vaciar la lista
NODO *encontrarElemento(NODO **lista, int elem, int operacion); // Encontrar un elemento desde su posicion o valor

int main(int argc, char const *argv[])
{
    NODO *lista = NULL; // Inicializamos el inicio de nuestra lista
    insertarFinal(&lista, 5);
    insertarInicio(&lista, 4);
    insertarFinal(&lista, 7);
    mostrarLista(lista);
    printf("\nEl tamano de la lista es: %d\n", tamanoLista(lista));
    
    /* operacion: 
    0.- encontrar desde la posicion del elemento
    1.- encontrar desde el valor del elemento*/

    NODO *encontrado = encontrarElemento(&lista,2, 0);

    if (encontrado != 0){
        printf("Se a encontrado el elemento %d\n", encontrado->dato);
    } else {
        printf("No se a encontrado el elemento\n");
    }

    printf("\nELIMINAR");
    eliminarElemento(&lista, 4,1);
    mostrarLista(lista);
    printf("\nEl tamano de la lista es: %d", tamanoLista(lista));

    printf("\nVACIAR");
    vaciarLista(&lista);
    mostrarLista(lista);
    printf("\nEl tamano de la lista es: %d", tamanoLista(lista));

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

int tamanoLista (NODO *lista) { 
    NODO *nAux = lista;
    int contador = 0;
    
    while (nAux != NULL) {
        contador++;
        nAux = nAux -> sig;
    }

    return contador;
}

void mostrarLista (NODO *lista) { 
    if (lista != NULL) {
        NODO *nAux = lista;

        printf("\nNodos dentro de la lista: ");
        while( nAux != NULL)
        {
            printf("%d ", nAux->dato);
            nAux = nAux->sig;
        }
    } else {printf("\nLa lista se encuentra vacia");}
}

void estaVacia (NODO *lista) {
    if (lista == NULL) {
        printf("\nLa lista se encuentra vacia");
    } else {
        printf("\nLa lista se encuentra con almenos un elemento");
    }
}

void vaciarLista (NODO **lista){
    *lista = NULL;
}

void insertarInicio (NODO **lista, int elem) {
    if (*lista != NULL) {
        NODO *nuevo = crearNodo(elem);
        
        nuevo -> sig = *lista;
        *lista = nuevo;
    }
}

void insertarFinal (NODO **lista, int elem) {
    if(*lista != NULL) {
        NODO *nuevo = crearNodo(elem), *nAux = *lista;

        while(nAux->sig != NULL)
        {
            nAux = nAux->sig;
        }
        nAux->sig = nuevo;
    }
    else {
        *lista = crearNodo(elem);
    }
}

NODO *encontrarElemento(NODO **lista, int elem, int operacion) {
    if (*lista != NULL){
        NODO *nAux = *lista;
        int contador = 0;

        while (nAux != NULL) {
            if (contador == elem && operacion == 0){ 
                return nAux;
            } 
            else if (nAux->dato == elem && operacion == 1){
                return nAux;
            }
            contador++;
            nAux = nAux -> sig;
        }
        return 0;  
        }
}

// Eliminar un elemento desde la posicion
void eliminarElemento (NODO **lista, int elem, int operacion) {
    if (*lista != NULL){
        NODO *nAux = *lista, *ant = NULL;
        int contador = 0;
        
        if (operacion == 0){
            while (nAux != NULL && contador != elem) {
            contador++;
            ant = nAux;
            nAux = nAux -> sig;
            }
        }
        else if (operacion == 1) {
            while (nAux != NULL && nAux -> dato != elem) {
            ant = nAux;
            nAux = nAux -> sig;
            }
        }

        if (nAux != NULL) {
            if (ant != NULL){
                ant -> sig = nAux -> sig;        
            }
            else {
                *lista = nAux -> sig;
            }     
            free(nAux);
        }else {printf("\nNo se encontro el elemento");}
    } else {printf("\nNo se puede eliminar");}
}
