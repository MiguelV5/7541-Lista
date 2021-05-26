#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




lista_t* lista_crear(){

    lista_t* lista = calloc(1, sizeof(lista_t));
    if(!lista){
        printf("\n\tFallo: No se pudo reservar la lista en memoria\n");
        return NULL;
    }
    
    return lista;
}




int lista_insertar(lista_t* lista, void* elemento){

    if(!lista || !elemento){
        printf("\n\tFallo: Lista o elemento no validos al insertar\n");
        return -1;
    }

    nodo_t* nodo_nuevo = calloc(1, sizeof(nodo_t));
    if(!nodo_nuevo){
        return -1;
    }

    nodo_nuevo->elemento = elemento;
    nodo_nuevo->siguiente = NULL;
    
    if(lista->cantidad == 0){

        lista->nodo_inicio = nodo_nuevo;
        lista->nodo_fin = nodo_nuevo;
        lista->cantidad++;

    }
    else{

        lista->nodo_fin->siguiente = nodo_nuevo;
        lista->nodo_fin = nodo_nuevo;
        lista->cantidad++;

    }

    return 0;

}






/**
 * Inserta un elemento al principio de una lista que ya tenía elementos.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */
int insertar_al_inicio(lista_t* lista, void* elemento){

    nodo_t* nodo_nuevo = calloc(1, sizeof(nodo_t));
    if(!nodo_nuevo){
        return -1;
    }

    nodo_nuevo->elemento = elemento;
    nodo_nuevo->siguiente = lista->nodo_inicio;
    lista->nodo_inicio = nodo_nuevo;

    lista->cantidad++;

    return 0;

}




/**
 * Inserta un elemento en una posición de la lista que no es ni al inicio ni posterior al final.  
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */
int insertar_en_posicion_intermedia(lista_t* lista, void* elemento, size_t posicion){

    nodo_t* nodo_nuevo = calloc(1, sizeof(nodo_t));
    if(!nodo_nuevo){
        return -1;
    }

    nodo_nuevo->elemento = elemento;

    nodo_t* nodo_actual = lista->nodo_inicio;
    size_t posicion_actual = 0;

    while(posicion_actual < (posicion - 1)){

        nodo_actual = nodo_actual->siguiente;
        posicion_actual++;

    }

    nodo_nuevo->siguiente = nodo_actual->siguiente;
    nodo_actual->siguiente = nodo_nuevo;

    lista->cantidad++;

    return 0;

}





int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
    
    int se_inserto = -1;

    if(!lista || !elemento){
        printf("\n\tFallo: Lista o elemento no validos al insertar\n");
        return se_inserto;
    }

    if(posicion >= lista->cantidad){ //La posicion no existe en la lista.

        se_inserto = lista_insertar(lista, elemento);

    }
    else if(posicion == 0){

        se_inserto = insertar_al_inicio(lista, elemento);

    }
    else{

        se_inserto = insertar_en_posicion_intermedia(lista, elemento, posicion);

    }

    return se_inserto;
    
}




int lista_borrar(lista_t* lista){
    return 0;
}




int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    return 0;
}




void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){

    if(lista_vacia(lista)){
        printf("\n\tFallo: Se pide un elemento de una lista vacía\n");
        return NULL;
    }
    else if(posicion >= lista->cantidad){
        printf("\n\tFallo: No existe posición de elemento pedido en la lista\n");
        return NULL;
    }
    
    //if(posicion == (lista->cantidad - 1)){
    //    return lista->nodo_fin->elemento;
    //}
    //else if(posicion == 0){
    //    return lista->nodo_inicio->elemento;
    //}
    //else{
//
    //    nodo_t* nodo_actual = lista->nodo_inicio;
    //    size_t posicion_actual = 0;
//
    //    while(posicion_actual < posicion){
//
    //        nodo_actual = nodo_actual->siguiente;
    //        posicion_actual++;
//
    //    }
//
    //    return nodo_actual->elemento;
//
    //}

    return NULL;

}





bool lista_vacia(lista_t* lista){

    if(!lista){
        return true;
    }

    if((lista->nodo_inicio == NULL) && (lista->nodo_fin == NULL) && (lista->cantidad == 0)){
        return true;
    }
    else{
        return false;
    }

}





void* lista_ultimo(lista_t* lista){
    
    if(lista_vacia(lista)){
        return NULL;
    }
    //else{
    //    return lista->nodo_fin->elemento;
    //}
    return NULL;

}






size_t lista_elementos(lista_t* lista){

    if(lista_vacia(lista)){
        return 0;
    }
    //else{
//
    //    nodo_t* nodo_actual = lista->nodo_inicio;
    //    size_t contador_elementos = 0;
//
    //    while(nodo_actual != NULL){
//
    //        contador_elementos++;
    //        nodo_actual = nodo_actual->siguiente;
//
    //    }
//
    //    return contador_elementos;
//
    //}
    return 0;

}




int lista_apilar(lista_t* lista, void* elemento){
    return 0;
}




int lista_desapilar(lista_t* lista){
    return 0;
}




void* lista_tope(lista_t* lista){
    return NULL;
}




int lista_encolar(lista_t* lista, void* elemento){
    return 0;
}




int lista_desencolar(lista_t* lista){
    return 0;
}




void* lista_primero(lista_t* lista){
    return NULL;
}




void lista_destruir(lista_t* lista){
    
    if(!lista){
        printf("\n\tFallo: No existe la lista a destruir.\n");
        return;
    }
    else{

        nodo_t* nodo_actual = lista->nodo_inicio;
        nodo_t* nodo_previo = NULL;
        size_t i = 0;

        while((i < lista->cantidad) && (nodo_actual != NULL)){

            nodo_previo = nodo_actual;
            nodo_actual = nodo_actual->siguiente;
            free(nodo_previo);
            i++;

        }

        free(lista);

    }

}




lista_iterador_t* lista_iterador_crear(lista_t* lista){
    return NULL;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
    return false;
}




bool lista_iterador_avanzar(lista_iterador_t* iterador){
    return false;
}




void* lista_iterador_elemento_actual(lista_iterador_t* iterador){
    return NULL;
}




void lista_iterador_destruir(lista_iterador_t* iterador){

}




size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){
    return 0;
}
