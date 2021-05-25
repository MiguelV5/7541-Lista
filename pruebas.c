#include "lista.h"
#include "pa2mm.h"



void DadaUnaListaInexistente_AlCrearLaLista_ResultaUnaListaCreadaVacia(){
  
  lista_t* lista = lista_crear();

  pa2m_afirmar(lista != NULL, "La lista fue correctamente reservada en memoria.");
  pa2m_afirmar(lista_vacia(lista) , "La lista creada está vacía.");

  lista_destruir(lista);

}



void DadaListaInexistente_SiSePreguntaSiLaListaEstaVacia_SeRetornaFalse(){}






void DadaListaVacia_SiSePreguntaSiLaListaEstaVacia_SeRetornaTrue(){}











void DadaListaInexistente_AlIntentarInsertarElemento_NoSePuedeInsertar(){

  lista_t* lista = NULL;
  int elemento = 1;

  int se_inserto = lista_insertar(lista, &elemento);
  pa2m_afirmar( se_inserto == -1 , "No se puede insertar elemento al final de una lista inexistente.");

  se_inserto = lista_insertar_en_posicion(lista, &elemento, 10); //posición arbitraria
  pa2m_afirmar( se_inserto == -1 , "No se puede insertar elemento en una posición cualquiera de una lista inexistente.");

}



void DadaListaVacia_AlInsertarleElemento_SeInsertaCorrectamente(){

  lista_t* lista = lista_crear();
  int elemento = 1;

  int se_inserto = lista_insertar(lista, &elemento);
  pa2m_afirmar( se_inserto == 0 , "Se inserta un elemento a la lista vacía cuando se pide insertar al final");
  pa2m_afirmar( lista_elementos(lista) == 1 , "La cantidad de elementos de la lista es 1");
  pa2m_afirmar((lista->nodo_inicio == lista->nodo_fin) && (lista->nodo_inicio->siguiente == NULL), "El elemento insertado es el único de la lista");
  pa2m_afirmar( lista->nodo_inicio->elemento == &elemento , "El elemento insertado es el requerido");

  lista_destruir(lista);


  lista = lista_crear();

  se_inserto = lista_insertar_en_posicion(lista, &elemento, 20); //posición arbitraria
  pa2m_afirmar( se_inserto == 0 , "Se inserta un elemento a la lista vacía cuando se pide insertar en posición arbitraria");
  pa2m_afirmar((lista->nodo_inicio == lista->nodo_fin) && (lista->nodo_inicio->siguiente == NULL), "El elemento insertado es el único de la lista");
  pa2m_afirmar( lista->nodo_inicio->elemento == &elemento , "El elemento insertado es el requerido");

  lista_destruir(lista);

}




void DadaListaConElementos_AlInsertaleOtroElementoAlFinal_SeInsertaCorrectamenteAlli(){}



int main() {
  
  // Ver detalles de notación en Readme.txt 

  pa2m_nuevo_grupo("Pruebas de creación de lista");

    DadaUnaListaInexistente_AlCrearLaLista_ResultaUnaListaCreadaVacia();

  pa2m_nuevo_grupo("Pruebas de funciones de utilidad");

    DadaListaInexistente_SiSePreguntaSiLaListaEstaVacia_SeRetornaFalse(); //Tiene más sentido decir que no es vacía, porque directamente no existe, además si devolviera true esto generaría conflicto con la notación antes tomada. //Ver aclaración en Readme.txt
    DadaListaVacia_SiSePreguntaSiLaListaEstaVacia_SeRetornaTrue();
//
    //DadaListaInexistenteOVacia_AlPedirElUltimoElemento_SeDevuelveNULL();
    //DadaListaConElementos_AlPedirElUltimoElemento_SeDevuelvePunteroAlMismo();
//
    //DadaListaInexistenteOVacia_AlPedirCantidadDeElementos_EsaCantidadEsCero();
    //DadaListaConElementos_AlPedirCantidadDeElementos_SeDevuelveEsaCantidadCorrectamente();
//
    //DadaListaInexistenteOVacia_AlPedirUnElementoEnCualquierPosicion_SeDevuelveNULL();
    //DadaListaConElementos_AlPedirUnElementoEnPosicionInvalida_SeDevuelveNULL();
    //DadaListaConElementos_AlPedirUnElementoEnPosicionValida_SeDevuelvePunteroAlMismo();

  pa2m_nuevo_grupo("Pruebas de inserción en lista");

    DadaListaInexistente_AlIntentarInsertarElemento_NoSePuedeInsertar();
    //DadaListaVacia_AlInsertarleElemento_SeInsertaCorrectamente();
    //DadaListaConElementos_AlInsertaleOtroElementoAlFinal_SeInsertaCorrectamenteAlli();
    //DadaListaConElementos_AlInsertarElementoEnUnaPosicionIntermedia_SeInsertaCorrectamenteAlli();
    //DadaListaConElementos_AlInsertarElementoAlInicio_SeInsertaCorrectamenteAlli();

  pa2m_nuevo_grupo("Pruebas de borrado");



  pa2m_nuevo_grupo("Pruebas de funciones de pila");



  pa2m_nuevo_grupo("Pruebas de funciones de cola");



  pa2m_nuevo_grupo("Pruebas de iteradores");



  return pa2m_mostrar_reporte();
}
