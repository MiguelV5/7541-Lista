#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




lista_t* lista_crear(){

    lista_t* lista = calloc(1, sizeof(lista_t));
    if(!lista){
        return NULL;
    }
    
    return lista;
}




int lista_insertar(lista_t* lista, void* elemento){

    if(!lista){
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

    }

    return 0;
}




int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
    
    if(!lista){
        return -1;
    }

    return -1;
    
}




int lista_borrar(lista_t* lista){
    return 0;
}




int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    return 0;
}




void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
    return NULL;
}




void* lista_ultimo(lista_t* lista){
    return NULL;
}




bool lista_vacia(lista_t* lista){

    if(!lista){
        return false;
    }

    if((lista->nodo_inicio == NULL) && (lista->nodo_fin == NULL)){
        return true;
    }
    else{
        return false;
    }

}




size_t lista_elementos(lista_t* lista){
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
    else if(lista_vacia(lista)){
        free(lista);
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
