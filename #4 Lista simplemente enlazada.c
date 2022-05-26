/* Kevin Alejandro Diaz Cantillano
20.479.055-8
#4 Lista simplemente enlazada */

#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
typedef struct Nodo
{
    int dato;
    struct Nodo *sig; // Definicion recursiva
} NODO;

// Estructura de la lista
typedef NODO* LISTA;

//funciones
LISTA lista();
void addEnd (LISTA *list, int n);
void showList (LISTA list);
void sizeList (LISTA list);


int main(int argc, char const *argv[])
{
    LISTA list;
    list = lista();
    addEnd(&list, 1);
    addEnd(&list, 2);
    addEnd(&list, 3);
    addEnd(&list, 4);
    addEnd(&list, 5);
    showList(list);
    sizeList(list);
}

LISTA createNodo (int dato) {
    LISTA nodo;
    nodo = (LISTA)malloc(sizeof(NODO));
    /* ¿Que hace sizeof?
    Reserva el espacio en memoria segun el tipo que especificamos */
    /* ¿Que hace malloc?
    Solicita un bloque de memoria del tamañano suministrado como
    parametro, devolviendo un puntero de la zona de memoria concedida*/

    nodo -> dato = dato; // Guardamos elem en el campo dato del nodo
    nodo -> sig = NULL; // Siguiente no apunta a nada
    
    return nodo;
}

// Creamos una lista vacia
LISTA lista(){
    return NULL;
}

//OPERACIONES

// Tamaño de la lista
void sizeList (LISTA list) { //pasamos la lista por valor
    // Implementamos una variable auxiliar que utilizaremos como contador
    int aux = 0;

    while (list != NULL) { // Contamos todos los nodos
        aux++;
        list = list -> sig;
    }
    printf("\n%d",aux); // imprimir el resultado
}

// Mostramos la lista
void showList (LISTA list) { //pasamos la lista por valor
    if (list != NULL) { // ¿Esta vacia la lista?
        while (list != NULL){
        // Todos los nodos
            printf("%d ", list->dato);
            list = list -> sig;
        }
    } else {
        printf("\nLista vacia");
    }
}

// Añadir un elemento al final de la lista
void addEnd (LISTA *list, int dato) {
    LISTA aux, nodo;
    
    //Preguntamos si la lista esta vacia
    if (*list != NULL){
        aux = *list; //guardamos la posicion del puntero para no perderlo
        //Buscamos el ultimo nodo
        while (aux-> sig != NULL){ //si no tengo aux->sig pierdo la referencia del ultimo nodo
        // aux -> sig hasta el ultimo nodo
            aux = aux -> sig;
        }
        // creo el nodo
        aux->sig = createNodo(dato);
    }
    else {
        nodo = createNodo(dato);
        *list = nodo;
    }
}
