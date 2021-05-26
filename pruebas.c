#include "lista.h"
#include "pa2mm.h"

#define POSICION_INVALIDA 1000 //valor arbitrario, solo para efectuar todas las pruebas relacionadas con posiciones invalidas.



//CREACION

void DadaUnaListaInexistente_AlCrearLaLista_ResultaUnaListaCreadaSinElementos(){
  
  lista_t* lista = lista_crear();

  pa2m_afirmar(lista != NULL, "Se creó una lista.");
  pa2m_afirmar((lista->nodo_inicio == NULL) && (lista->nodo_fin == NULL) && (lista->cantidad == 0), "La lista creada no tiene elementos.");
  pa2m_afirmar(lista->cantidad == 0, "La cantidad de elementos de la lista es cero.");

  lista_destruir(lista);

}


//UTILIDAD SOBRE LISTAS VACIAS

void DadaListaInexistenteOSinElementos_SiSePreguntaSiLaListaEstaVacia_SeRetornaTrue(){

  lista_t* lista = NULL;
  
  pa2m_afirmar(lista_vacia(lista), "Una lista inexistente es lista vacía.");

  lista = lista_crear();

  pa2m_afirmar(lista_vacia(lista), "Una lista existente sin elementos es lista vacía.");

  lista_destruir(lista);

  printf("\n");

}




void DadaListaVacia_AlPedirElUltimoElemento_SeDevuelveNull(){

  lista_t* lista = NULL;

  pa2m_afirmar(lista_ultimo(lista) == NULL, "Al pedir el último elemento de una lista inexistente se obtiene NULL.");  
  
  lista = lista_crear();

  pa2m_afirmar(lista_ultimo(lista) == NULL, "Al pedir el último elemento de una lista sin elementos se obtiene NULL.");

  lista_destruir(lista);

  printf("\n");

}




void DadaListaVacia_AlPedirCantidadDeElementos_EsaCantidadEsCero(){

  lista_t* lista = NULL;

  pa2m_afirmar(lista_elementos(lista) == 0, "La cantidad de elementos de una lista inexistente es cero.");

  lista = lista_crear();

  pa2m_afirmar(lista_elementos(lista) == 0, "La cantidad de elementos de una lista sin elementos es cero.");

  lista_destruir(lista);

  printf("\n");

}




void DadaListaVacia_AlPedirUnElementoEnCualquierPosicion_SeDevuelveNull(){

  lista_t* lista = NULL;

  pa2m_afirmar(lista_elemento_en_posicion(lista, POSICION_INVALIDA) == NULL, "Al pedir elemento en cualquier posicion de una lista inexistente se obtiene NULL.");  
  
  lista = lista_crear();

  pa2m_afirmar(lista_elemento_en_posicion(lista, POSICION_INVALIDA) == NULL, "Al pedir elemento en cualquier posicion de una lista sin elementos se obtiene NULL.");

  lista_destruir(lista);

  printf("\n");

}






//INSERCION

void DadaListaInexistente_AlIntentarInsertarElemento_NoSePuedeInsertar(){

  lista_t* lista = NULL;
  int elemento = 1;

  int se_inserto = lista_insertar(lista, &elemento);
  pa2m_afirmar( se_inserto == -1 , "No se puede insertar elemento al final de una lista inexistente.");

  se_inserto = lista_insertar_en_posicion(lista, &elemento, POSICION_INVALIDA);
  pa2m_afirmar( se_inserto == -1 , "No se puede insertar elemento en una posición cualquiera de una lista inexistente.");

  printf("\n");

}



void DadoPunteroNullAElemento_AlIntentarInsertarloAUnaLista_NoSePuedeInsertar(){

  lista_t* lista = lista_crear();

  pa2m_afirmar( lista_insertar(lista, NULL) == -1 , "No se puede insertar puntero a NULL como elemento al final de una lista.");
  pa2m_afirmar( lista_insertar_en_posicion(lista, NULL, 1) == -1 , "No se puede insertar puntero a NULL como elemento en ninguna posicion de una lista.");

  lista_destruir(lista);

  printf("\n");

}



void DadaListaSinElementos_AlInsertarleElemento_SeInsertaCorrectamente(){

  lista_t* lista = lista_crear();
  int elemento = 1;

  int se_inserto = lista_insertar(lista, &elemento);
  pa2m_afirmar( (se_inserto == 0) && (lista->nodo_inicio != NULL) , "Se inserta un elemento al final de una lista sin elementos.");
  pa2m_afirmar( lista->cantidad == 1 , "La cantidad de elementos de la lista es 1.");
  pa2m_afirmar((lista->nodo_inicio == lista->nodo_fin) && (lista->nodo_inicio->siguiente == NULL), "El elemento insertado es el único de la lista.");
  pa2m_afirmar( lista->nodo_inicio->elemento == &elemento , "El elemento insertado es el requerido.");

  lista_destruir(lista);

  printf("\n");

  lista = lista_crear();

  se_inserto = lista_insertar_en_posicion(lista, &elemento, POSICION_INVALIDA);
  pa2m_afirmar( (se_inserto == 0) && (lista->nodo_inicio != NULL) , "Se inserta un elemento cuando se pide insertar en posición arbitraria de una lista sin elementos.");
  pa2m_afirmar( lista->cantidad == 1 , "La cantidad de elementos de la lista es 1");
  pa2m_afirmar((lista->nodo_inicio == lista->nodo_fin) && (lista->nodo_inicio->siguiente == NULL), "El elemento insertado es el único de la lista.");
  pa2m_afirmar( lista->nodo_inicio->elemento == &elemento , "El elemento insertado es el requerido.");

  lista_destruir(lista);

  printf("\n");

}




void DadaListaConElementos_AlInsertaleVariosElementosAlFinal_SeInsertanCorrectamente(){

  lista_t* lista = lista_crear();
  int primer_elemento = 1;
  int se_inserto = lista_insertar(lista, &primer_elemento);
  
  char a = 'a' , e = 'e' , i = 'i';

  se_inserto = lista_insertar(lista, &a);
  pa2m_afirmar( se_inserto == 0 , "Se inserta elemento al final de una lista con un elemento.");
  pa2m_afirmar( lista->cantidad == 2 , "La cantidad de elementos de la lista ahora es 2.");
  pa2m_afirmar( lista->nodo_fin->elemento == &a , "El elemento insertado es el requerido.");
  pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El elemento insertado es ahora el último de la lista.");

  printf("\n");

  se_inserto = lista_insertar(lista, &e);
  pa2m_afirmar( se_inserto == 0 , "Se inserta otro elemento al final de la lista.");
  pa2m_afirmar( lista->cantidad == 3 , "La cantidad de elementos de la lista ahora es 3.");
  pa2m_afirmar( lista->nodo_fin->elemento == &e , "El elemento insertado es el requerido.");
  pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El elemento insertado es ahora el último de la lista.");

  printf("\n");

  se_inserto = lista_insertar(lista, &i);
  pa2m_afirmar( se_inserto == 0 , "Se inserta otro elemento al final de la lista.");
  pa2m_afirmar( lista->cantidad == 4 , "La cantidad de elementos de la lista ahora es 4.");
  pa2m_afirmar( lista->nodo_fin->elemento == &i , "El elemento insertado es el requerido.");
  pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El elemento insertado es ahora el último de la lista.");

  lista_destruir(lista);

  printf("\n");

}




void DadaListaConElementos_AlInsertarElementoEnUnaPosicionIntermedia_SeInsertaCorrectamente(){

  lista_t* lista = lista_crear();
  int se_inserto = -1;
  
  char a = 'a' , e = 'e' , i = 'i' , o = 'o' , u = 'u' , x = 'x' , y = 'y';

  // Ver aclaración de lo siguiente en Readme.txt, sección Aclaraciones, linea {????????????????}

  lista_insertar(lista, &a);
  nodo_t* auxiliar_nodo_a = lista->nodo_fin;
  lista_insertar(lista, &e);
  nodo_t* auxiliar_nodo_e = lista->nodo_fin;
  lista_insertar(lista, &i);
  lista_insertar(lista, &o);
  nodo_t* auxiliar_nodo_o = lista->nodo_fin;
  lista_insertar(lista, &u);

  se_inserto = lista_insertar_en_posicion(lista, &x, 1);
  pa2m_afirmar( se_inserto == 0 , "Se inserta un elemento al pedir inserción en posición 1.");
  pa2m_afirmar( lista->cantidad == 6 , "La cantidad de elementos de la lista aumentó en uno.");
  pa2m_afirmar(auxiliar_nodo_a->siguiente->siguiente == auxiliar_nodo_e, "El nuevo elemento tiene como siguiente al que previamente estaba en su posición.");
  pa2m_afirmar( auxiliar_nodo_a->siguiente->elemento == &x , "El elemento insertado es el requerido.");

  printf("\n");

  se_inserto = lista_insertar_en_posicion(lista, &y, 5);
  pa2m_afirmar( se_inserto == 0 , "Se inserta un elemento al pedir inserción en la última posición.");
  pa2m_afirmar( lista->cantidad == 7 , "La cantidad de elementos de la lista aumentó en uno.");
  pa2m_afirmar(auxiliar_nodo_o->siguiente->siguiente == lista->nodo_fin, "El nuevo elemento tiene como siguiente al último de la lista.");
  pa2m_afirmar( auxiliar_nodo_o->siguiente->elemento == &y , "El elemento insertado es el requerido.");

  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConElementos_AlInsertarElementoAlInicio_SeInsertaCorrectamente(){

  lista_t* lista = lista_crear();
  int elemento_previo = 1;
  int elemento_de_prueba = 2;
  int se_inserto = -1;
  lista_insertar(lista, &elemento_previo);
  nodo_t* nodo_fin_previo = lista->nodo_fin;

  se_inserto = lista_insertar_en_posicion(lista, &elemento_de_prueba, 0);
  pa2m_afirmar( se_inserto == 0 , "Se inserta un elemento al pedir inserción al inicio.");
  pa2m_afirmar( lista->nodo_inicio->siguiente->elemento == &elemento_previo, "El elemento siguiente al nuevo es el que era inicio previo a insertar.");
  pa2m_afirmar( lista->nodo_fin == nodo_fin_previo, "El último elemento de la lista sigue siendo el mismo.");
  pa2m_afirmar( lista->nodo_inicio->elemento == &elemento_de_prueba , "El elemento insertado es el requerido.");

  lista_destruir(lista);
  
  printf("\n");

}



/*
void DadaListaConElementos_AlInsertarElementoEnPosicionInvalida_SeInsertaAlFinalDeLaLista(){

  lista_t* lista = lista_crear();
  int se_inserto = -1;



  lista_destruir(lista);
  
  printf("\n");

}




//UTILIDAD SOBRE LISTAS CON ELEMENTOS



void DadaListaConElementos_AlPedirElUltimoElemento_SeDevuelvePunteroAlMismo(){

  lista_t* lista = lista_crear();
  int se_inserto = -1;



  lista_destruir(lista);
  
  printf("\n");

}



void DadaListaConElementos_AlPedirCantidadDeElementos_SeDevuelveLaCantidadCorrecta(){

  lista_t* lista = lista_crear();
  int se_inserto = -1;



  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConElementos_AlPedirUnElementoEnPosicionInvalida_SeDevuelveNull(){

  lista_t* lista = lista_crear();
  int se_inserto = -1;



  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConElementos_AlPedirUnElementoEnPosicionValida_SeDevuelvePunteroAlMismo(){

  lista_t* lista = lista_crear();
  int se_inserto = -1;



  lista_destruir(lista);
  
  printf("\n");

}
*/








int main() {
  
  // Ver detalles de notación en Aclaraciones, Readme.txt 

  pa2m_nuevo_grupo("Pruebas de creación de lista");

    DadaUnaListaInexistente_AlCrearLaLista_ResultaUnaListaCreadaSinElementos();

  pa2m_nuevo_grupo("Pruebas de funciones de utilidad sobre listas vacías");

    DadaListaInexistenteOSinElementos_SiSePreguntaSiLaListaEstaVacia_SeRetornaTrue(); //Ver nuevamente detalles de notación en caso de confusión (Readme.txt)
    DadaListaVacia_AlPedirElUltimoElemento_SeDevuelveNull();
    DadaListaVacia_AlPedirCantidadDeElementos_EsaCantidadEsCero();
    DadaListaVacia_AlPedirUnElementoEnCualquierPosicion_SeDevuelveNull();

  pa2m_nuevo_grupo("Pruebas de inserción en lista vacía");

    DadaListaInexistente_AlIntentarInsertarElemento_NoSePuedeInsertar();
    DadoPunteroNullAElemento_AlIntentarInsertarloAUnaLista_NoSePuedeInsertar();
    DadaListaSinElementos_AlInsertarleElemento_SeInsertaCorrectamente();

  pa2m_nuevo_grupo("Pruebas de inserción en lista con elementos");

    DadaListaConElementos_AlInsertaleVariosElementosAlFinal_SeInsertanCorrectamente();
    DadaListaConElementos_AlInsertarElementoEnUnaPosicionIntermedia_SeInsertaCorrectamente();
    DadaListaConElementos_AlInsertarElementoAlInicio_SeInsertaCorrectamente();
    //DadaListaConElementos_AlInsertarElementoEnPosicionInvalida_SeInsertaAlFinalDeLaLista()
  
  pa2m_nuevo_grupo("Pruebas de funciones de utilidad sobre listas con elementos");

    //DadaListaConElementos_AlPedirElUltimoElemento_SeDevuelvePunteroAlMismo();
    //DadaListaConElementos_AlPedirCantidadDeElementos_SeDevuelveLaCantidadCorrecta();
    //DadaListaConElementos_AlPedirUnElementoEnPosicionInvalida_SeDevuelveNull();
    //DadaListaConElementos_AlPedirUnElementoEnPosicionValida_SeDevuelvePunteroAlMismo();

  pa2m_nuevo_grupo("Pruebas de borrado");



  pa2m_nuevo_grupo("Pruebas de funciones de pila");



  pa2m_nuevo_grupo("Pruebas de funciones de cola");



  pa2m_nuevo_grupo("Pruebas de iteradores");



  return pa2m_mostrar_reporte();

}
