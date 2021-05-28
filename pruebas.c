#include "lista.h"
#include "pa2mm.h"

#define POSICION_INVALIDA 1000 //valor arbitrario, solo para efectuar todas las pruebas relacionadas con posiciones invalidas.

#define FALLO -1

// CREACION

void DadaUnaListaInexistente_AlCrearLaLista_ResultaUnaListaCreadaSinElementos(){
  
  lista_t* lista = lista_crear();

  pa2m_afirmar(lista != NULL, "Se creó una lista.");
  pa2m_afirmar((lista->nodo_inicio == NULL) && (lista->nodo_fin == NULL) && (lista->cantidad == 0), "La lista creada no tiene elementos.");
  pa2m_afirmar(lista->cantidad == 0, "La cantidad de elementos de la lista es cero.");

  lista_destruir(lista);

}


// FUNCIONES DE UTILIDAD SOBRE LISTAS VACIAS

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






// INSERCION

void DadaListaInexistente_AlIntentarInsertarElemento_NoSePuedeInsertar(){

  lista_t* lista = NULL;
  int elemento = 1;

  int se_inserto = lista_insertar(lista, &elemento);
  pa2m_afirmar( se_inserto == FALLO , "No se puede insertar elemento al final de una lista inexistente.");

  se_inserto = lista_insertar_en_posicion(lista, &elemento, POSICION_INVALIDA);
  pa2m_afirmar( se_inserto == FALLO , "No se puede insertar elemento en una posición cualquiera de una lista inexistente.");

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
  int se_inserto = FALLO;
  
  char a = 'a' , e = 'e' , i = 'i' , o = 'o' , u = 'u' , x = 'x' , y = 'y'; //Elementos de prueba

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
  int se_inserto = FALLO;
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




void DadaListaConElementos_AlInsertarElementoEnPosicionInvalida_SeInsertaAlFinalDeLaLista(){

  lista_t* lista = lista_crear();
  int se_inserto = FALLO;

  char a = 'a' , e = 'e' , i = 'i' , o = 'o';

  lista_insertar(lista, &a);
  lista_insertar(lista, &e);
  lista_insertar(lista, &i);

  se_inserto = lista_insertar_en_posicion(lista, &o, POSICION_INVALIDA);
  pa2m_afirmar( se_inserto == 0 , "Se inserta un elemento al pedir inserción en posición inválida.");
  pa2m_afirmar( lista->nodo_fin->elemento == &o, "El nuevo elemento ahora es el último de la lista.");

  lista_destruir(lista);
  
  printf("\n");

}




// FUNCIONES DE UTILIDAD SOBRE LISTAS CON ELEMENTOS


void DadaListaConElementos_AlPedirElUltimoElemento_SeDevuelvePunteroAlMismo(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' , i = 'i';

  lista_insertar(lista, &a);
  lista_insertar(lista, &e);
  lista_insertar(lista, &i);

  char* ptr_al_ultimo = lista_ultimo(lista);

  pa2m_afirmar(ptr_al_ultimo == &i , "Al pedir último elemento de una lista no vacía, se obtiene el elemento requerido.");

  lista_destruir(lista);
  
  printf("\n");

}



void DadaListaConElementos_AlPedirCantidadDeElementos_SeDevuelveLaCantidadCorrecta(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' , i = 'i';

  lista_insertar(lista, &a);

  size_t cantidad_de_prueba_1 = lista_elementos(lista);

  lista_insertar(lista, &e);

  size_t cantidad_de_prueba_2 = lista_elementos(lista);

  lista_insertar(lista, &i);

  size_t cantidad_de_prueba_3 = lista_elementos(lista);

  bool cantidades_son_correctas = ((cantidad_de_prueba_1 == 1) && (cantidad_de_prueba_2 == 2) && (cantidad_de_prueba_3 == 3));


  pa2m_afirmar( cantidades_son_correctas , "Al contar elementos de una lista no vacía, se obtiene la cantidad correcta.");

  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConElementos_AlPedirUnElementoEnPosicionInvalida_SeDevuelveNull(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' , i = 'i';

  lista_insertar(lista, &a);
  lista_insertar(lista, &e);
  lista_insertar(lista, &i);  

  char* elemento_invalido = lista_elemento_en_posicion(lista, 3);
  pa2m_afirmar(elemento_invalido == NULL, "Al pedir un elemento en posición justamente posterior a la lista se obtiene NULL.");
  elemento_invalido = lista_elemento_en_posicion(lista, POSICION_INVALIDA);
  pa2m_afirmar(elemento_invalido == NULL, "Al pedir un elemento en cualquier posición inválida se obtiene NULL.");

  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConElementos_AlPedirUnElementoEnPosicionValida_SeDevuelvePunteroAlMismo(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' , i = 'i';

  lista_insertar(lista, &a);
  lista_insertar(lista, &e);
  nodo_t* auxiliar_nodo_intermedio = lista->nodo_fin;
  lista_insertar(lista, &i);

  char* elemento_inicio_prueba = lista_elemento_en_posicion(lista, 0);
  char* elemento_intermedio_prueba = lista_elemento_en_posicion(lista, 1);
  char* elemento_fin_prueba = lista_elemento_en_posicion(lista, 2);

  pa2m_afirmar(elemento_inicio_prueba == lista->nodo_inicio->elemento, "Al pedir primer elemento de una lista no vacía se devuelve el elemento correcto.");
  pa2m_afirmar(elemento_intermedio_prueba == auxiliar_nodo_intermedio->elemento , "Al pedir un elemento intermedio de una lista no vacía se devuelve el elemento correcto.");
  pa2m_afirmar(elemento_fin_prueba == lista->nodo_fin->elemento, "Al pedir último elemento de una lista no vacía se devuelve el elemento correcto.");

  lista_destruir(lista);
  
  printf("\n");

}




// BORRADO


void DadaListaVacia_AlIntentarBorrarDelFinal_NoSePuedeBorrar(){

  lista_t* lista = NULL;

  pa2m_afirmar( lista_borrar(lista) == FALLO , "No se puede borrar elemento del final de una lista inexistente.");

  lista = lista_crear();

  pa2m_afirmar( lista_borrar(lista) == FALLO , "No se puede borrar elemento del final de una lista sin elementos.");

  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConUnElemento_AlBorrarDelFinal_ResultaListaSinElementos(){

  lista_t* lista = lista_crear();

  char a = 'a';

  lista_insertar(lista, &a);

  int se_borro = lista_borrar(lista);
  pa2m_afirmar( se_borro == 0 , "Se borra elemento de una lista con un único elemento.");
  pa2m_afirmar( lista->cantidad == 0 , "La cantidad de elementos de la lista ahora es cero.");
  pa2m_afirmar( (lista->nodo_inicio == NULL) && (lista->nodo_fin == NULL) , "Las referencias, tanto a nodo inicial como a nodo final de la lista, ahora son NULL.");

  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConElementos_AlBorrarDelFinal_SeBorraElementoCorrectamente(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' , i = 'i';

  lista_insertar(lista, &a);
  lista_insertar(lista, &e);
  lista_insertar(lista, &i);

  int se_borro = lista_borrar(lista);
  pa2m_afirmar( se_borro == 0 , "Se borra elemento de una lista con varios elementos.");
  pa2m_afirmar( lista->cantidad == 2 , "La cantidad de elementos de la lista disminuye en uno.");
  pa2m_afirmar( lista->nodo_fin->elemento == &e, "El nuevo elemento final de la lista es el que en un principio era penúltimo.");
  pa2m_afirmar( lista->nodo_fin->siguiente == NULL , "El nuevo elemento final de la lista no tiene siguiente.")
 
  printf("\n");

  se_borro = lista_borrar(lista);
  pa2m_afirmar( se_borro == 0 , "Se borra otro elemento de la lista.");
  pa2m_afirmar( lista->cantidad == 1 , "La cantidad de elementos de la lista vuelve a disminuir en uno.");
  pa2m_afirmar( lista->nodo_fin->elemento == &a, "El nuevo elemento final de la lista es el que en un principio era antepenúltimo.");
  pa2m_afirmar( lista->nodo_fin->siguiente == NULL , "El nuevo elemento final de la lista no tiene siguiente.");

  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaVacia_AlIntentarBorrarEnPosicionCualquiera_NoSePuedeBorrar(){

  lista_t* lista = NULL;
  int se_borro = lista_borrar_de_posicion(lista, 0);
  
  pa2m_afirmar( se_borro == FALLO , "No se puede borrar en una posición de una lista inexistente.");

  lista = lista_crear();
  se_borro = lista_borrar_de_posicion(lista, 0);

  pa2m_afirmar( se_borro == FALLO , "No se puede borrar en una posición de una lista sin elementos.");

  lista_destruir(lista);
  
  printf("\n");

}




void DadaListaConElementos_AlBorrarEnPosicionInvalidaOAlFinal_SeIntentaBorrarDelFinal(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' , i = 'i';

  lista_insertar(lista, &a);
  lista_insertar(lista, &e);
  lista_insertar(lista, &i);

  int se_borro = lista_borrar_de_posicion(lista, POSICION_INVALIDA);
  pa2m_afirmar( se_borro == 0 , "Se borra elemento al pedir borrar en posición inválida de una lista no vacía.");
  pa2m_afirmar( lista->cantidad == 2 , "La cantidad de elementos de la lista disminuye en uno.");

  bool era_ultimo_elemento = ((lista->nodo_fin->siguiente == NULL) && (lista->nodo_fin->elemento == &e));

  pa2m_afirmar( era_ultimo_elemento , "El intento a borrar el último elemento de la lista fue exitoso.");
  
  printf("\n");

  se_borro = lista_borrar_de_posicion(lista, 1);
  pa2m_afirmar( se_borro == 0 , "Se borra elemento al pedir borrar en la posición final de una lista no vacía.");
  pa2m_afirmar( lista->cantidad == 1 , "La cantidad de elementos de la lista disminuye en uno.");

  era_ultimo_elemento = ((lista->nodo_fin->siguiente == NULL) && (lista->nodo_fin->elemento == &a));

  pa2m_afirmar( era_ultimo_elemento , "El elemento eliminado era efectivamente el último de la lista.");
 
  printf("\n");

  lista_destruir(lista);

}






void DadaListaConMinimoTresElementos_AlBorrarEnPosicionIntermedia_SeBorraCorrectamente(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' , i = 'i';

  lista_insertar(lista, &a);
  nodo_t* auxiliar_nodo_a = lista->nodo_fin;

  lista_insertar(lista, &e);
  lista_insertar(lista, &i);
  nodo_t* auxiliar_nodo_i = lista->nodo_fin;


  int se_borro = lista_borrar_de_posicion(lista, 1);
  pa2m_afirmar( se_borro == 0 , "Se borra elemento en posición válida distinta del inicio y del final en una lista con varios elementos.");
  pa2m_afirmar( lista->cantidad == 2 , "La cantidad de elementos de la lista disminuye en uno.");
  pa2m_afirmar( auxiliar_nodo_a->siguiente == auxiliar_nodo_i , "El nodo anterior al eliminado ahora tiene por siguiente al que era siguiente del mismo.");

  lista_destruir(lista);
  
  printf("\n");


}





void DadaListaConMinimoDosElementos_AlBorrarAlInicio_SeBorraCorrectamente(){

  lista_t* lista = lista_crear();

  char a = 'a' , e = 'e' ;

  lista_insertar(lista, &a);
  lista_insertar(lista, &e);

  int se_borro = lista_borrar_de_posicion(lista, 0);

  pa2m_afirmar( se_borro == 0 , "Se borra elemento al pedir borrar de posición incial de una lista con elementos.");
  pa2m_afirmar( lista->cantidad == 1 , "La cantidad de elementos de la lista disminuye en uno.");
  pa2m_afirmar( lista->nodo_inicio->elemento == &e, "El nuevo elemento inicial es ahora el que era siguiente al borrado.");
  
  lista_destruir(lista);
  
  printf("\n");

}




// PILA



void DadaPilaInexistente_AlIntentarApilar_NoSePuedeApilar(){

  lista_t* pila = NULL;

  int elemento1 = 1;

  int se_apilo = lista_apilar(pila, &elemento1);

  pa2m_afirmar( se_apilo == FALLO , "No se puede apilar en una pila inexistente.");
  
  printf("\n");

}




void DadaPilaConOSinElementos_AlApilar_SeApilaCorrectamente(){ // *Pila con o sin elementos.

  lista_t* pila = lista_crear();

  char a = 'a' , e = 'e' ;

  int se_apilo = lista_apilar(pila, &a);
  pa2m_afirmar( se_apilo == 0 , "Se apila elemento en una pila sin elementos.");
  pa2m_afirmar( pila->cantidad == 1 , "La cantidad de elementos de la pila aumentó en uno.");

  se_apilo = lista_apilar(pila, &e);
  pa2m_afirmar( se_apilo == 0 , "Se apila otro elemento en la pila.");
  pa2m_afirmar( pila->cantidad == 2 , "La cantidad de elementos de la pila aumentó en uno.");

  lista_destruir(pila);

  printf("\n");

}





void DadaPilaVacia_AlIntentarDesapilar_NoSePuedeDesapilar(){

  lista_t* pila = NULL;

  int se_desapilo = lista_desapilar(pila);

  pa2m_afirmar( se_desapilo == FALLO , "No se puede desapilar de una pila inexistente.");

  pila = lista_crear();

  se_desapilo = lista_desapilar(pila);

  pa2m_afirmar( se_desapilo == FALLO , "No se puede desapilar de una pila sin elementos.");

  lista_destruir(pila);

  printf("\n");

}




void DadaPilaConElementos_AlDesapilar_SeDesapilaCorrectamente(){

  lista_t* pila = lista_crear();

  char a = 'a' , e = 'e' ;

  lista_apilar(pila, &a);
  lista_apilar(pila, &e);

  int se_desapilo = lista_desapilar(pila);
  pa2m_afirmar( se_desapilo == 0 , "Se desapila de una pila con varios elementos.");
  pa2m_afirmar( pila->cantidad == 1 , "La cantidad de elementos de la pila disminuye en uno.");

  printf("\n");

  se_desapilo = lista_desapilar(pila);
  pa2m_afirmar( se_desapilo == 0 , "Se desapila de una pila con un único elemento.");
  pa2m_afirmar( pila->cantidad == 0 , "La cantidad de elementos de la pila disminuye en uno.");
  pa2m_afirmar( pila->nodo_inicio == NULL && pila->nodo_fin == NULL , "La pila queda sin elementos tras desapilar el único elemento.");

  lista_destruir(pila);

  printf("\n");

}





void DadaPilaVacia_AlPedirTope_SeDevuelveNULL(){

  lista_t* pila = NULL;

  void* tope = lista_tope(pila);

  pa2m_afirmar( tope == NULL , "No se puede obtener elemento tope de una pila inexistente.");

  pila = lista_crear();

  tope = lista_tope(pila);

  pa2m_afirmar( tope == NULL , "No se puede obtener elemento tope de una pila sin elementos.");

  lista_destruir(pila);

  printf("\n");

}




void DadaPilaConElementos_AlPedirTopeEnVariadasSituaciones_SeDevuelveElementoTopeCorrectamente(){// Comprobador principal del comportamiento como pila.

  lista_t* pila = lista_crear();

  char a = 'a' , e = 'e' , i = 'i' ;

  lista_apilar(pila, &a);
  char* tope = lista_tope(pila);
  pa2m_afirmar( tope == &a , "El tope de una pila de un elemento es el elemento correcto.");


  lista_apilar(pila, &e);
  tope = lista_tope(pila);
  pa2m_afirmar( tope == &e , "Se apila elemento y ese pasa a ser el nuevo tope.");

  
  lista_apilar(pila, &i);
  tope = lista_tope(pila);
  pa2m_afirmar( tope == &i , "Se apila otro elemento y ese pasa a ser el nuevo tope.");


  lista_desapilar(pila);
  tope = lista_tope(pila);
  pa2m_afirmar( tope == &e , "Se desapila elemento y ahora el tope es el elemento que le seguía 'debajo' (LIFO).");

  lista_desapilar(pila);
  tope = lista_tope(pila);
  pa2m_afirmar( tope == &a , "Se desapila otro elemento y ahora el tope sigue cumpliendo lo anterior.");

  lista_desapilar(pila);
  tope = lista_tope(pila);
  pa2m_afirmar( tope == NULL , "Se desapila último elemento y al quedar lista sin elementos el tope es NULL.");


  lista_destruir(pila);

}





// COLA


void DadaColaInexistente_AlIntentarEncolar_NoSePuedeEncolar(){

  lista_t* cola = NULL;

  int elemento1 = 1;

  int se_encolo = lista_encolar(cola, &elemento1);

  pa2m_afirmar( se_encolo == FALLO , "No se puede encolar en una cola inexistente.");
  
  printf("\n");

}




void DadaColaConOSinElementos_AlEncolar_SeEncolaCorrectamente(){

  lista_t* cola = lista_crear();

  char a = 'a' , e = 'e' ;

  int se_encolo = lista_encolar(cola, &a);
  pa2m_afirmar( se_encolo == 0 , "Se encola elemento en una cola sin elementos.");
  pa2m_afirmar( cola->cantidad == 1 , "La cantidad de elementos de la cola aumentó en uno.");

  se_encolo = lista_encolar(cola, &e);
  pa2m_afirmar( se_encolo == 0 , "Se encola otro elemento.");
  pa2m_afirmar( cola->cantidad == 2 , "La cantidad de elementos de la cola aumentó en uno.");

  lista_destruir(cola);

  printf("\n");

}




void DadaColaVacia_AlIntentarDesencolar_NoSePuedeDesencolar(){

  lista_t* cola = NULL;

  int se_desencolo = lista_desencolar(cola);

  pa2m_afirmar( se_desencolo == FALLO , "No se puede desencolar de una cola inexistente.");

  cola = lista_crear();

  se_desencolo = lista_desencolar(cola);

  pa2m_afirmar( se_desencolo == FALLO , "No se puede desencolar de una cola sin elementos.");

  lista_destruir(cola);

  printf("\n");

}




void DadaColaConElementos_AlDesencolar_SeDesencolaCorrectamente(){

  lista_t* cola = lista_crear();

  char a = 'a' , e = 'e' ;

  lista_encolar(cola, &a);
  lista_encolar(cola, &e);

  int se_desencolo = lista_desencolar(cola);
  pa2m_afirmar( se_desencolo == 0 , "Se desencola elemento de una cola con varios elementos.");
  pa2m_afirmar( cola->cantidad == 1 , "La cantidad de elementos de la cola disminuye en uno.");

  printf("\n");

  se_desencolo = lista_desencolar(cola);
  pa2m_afirmar( se_desencolo == 0 , "Se desencola elemento de una cola con un único elemento.");
  pa2m_afirmar( cola->cantidad == 0 , "La cantidad de elementos de la cola disminuye en uno.");
  pa2m_afirmar( cola->nodo_inicio == NULL && cola->nodo_fin == NULL , "La cola queda sin elementos tras desencolar el único que quedaba.");

  lista_destruir(cola);

  printf("\n");

}




void DadaColaVacia_AlPedirPrimero_SeDevuelveNULL(){ // "PedirPrimero" ==  pedir primer elemento de la cola

  lista_t* cola = NULL;

  void* primero = lista_primero(cola);

  pa2m_afirmar( primero == NULL , "No se puede obtener elemento primero de una cola inexistente.");

  cola = lista_crear();

  primero = lista_primero(cola);

  pa2m_afirmar( primero == NULL , "No se puede obtener elemento primero de una cola sin elementos.");

  lista_destruir(cola);

  printf("\n");

}




void DadaColaConElementos_AlPedirPrimeroEnVariadasSituaciones_SeDevuelveElementoPrimeroCorrectamente(){// Comprobación principal del comportamiento de cola.

  lista_t* cola = lista_crear();
  char a = 'a' , e = 'e' , i = 'i' ;

  lista_encolar(cola, &a);
  char* primero = lista_primero(cola);
  pa2m_afirmar( primero == &a , "El primer elemento de una cola de un elemento es el correcto.");


  lista_encolar(cola, &e);
  primero = lista_primero(cola);
  pa2m_afirmar( primero == &a , "Se encola, pero el primer elemento sigue siendo el mismo de antes.");

  
  lista_encolar(cola, &i);
  primero = lista_primero(cola);
  pa2m_afirmar( primero == &a , "Se encola otro elemento, el primer elemento sigue siendo el mismo.");


  lista_desencolar(cola);
  primero = lista_primero(cola);
  pa2m_afirmar( primero == &e , "Se desencola elemento y ahora el primero es el elemento que le seguía 'en la fila' (FIFO).");

  lista_desencolar(cola);
  primero = lista_primero(cola);
  pa2m_afirmar( primero == &i , "Se desencola otro elemento y ahora el primero cumple nuevamente lo anterior.");

  lista_desencolar(cola);
  primero = lista_primero(cola);
  pa2m_afirmar( primero == NULL , "Se desencola último elemento y al quedar lista sin elementos el primero es NULL.");


  lista_destruir(cola);

}


































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
    DadaListaSinElementos_AlInsertarleElemento_SeInsertaCorrectamente();

  pa2m_nuevo_grupo("Pruebas de inserción en lista con elementos");

    DadaListaConElementos_AlInsertaleVariosElementosAlFinal_SeInsertanCorrectamente();
    DadaListaConElementos_AlInsertarElementoEnUnaPosicionIntermedia_SeInsertaCorrectamente();
    DadaListaConElementos_AlInsertarElementoAlInicio_SeInsertaCorrectamente();
    DadaListaConElementos_AlInsertarElementoEnPosicionInvalida_SeInsertaAlFinalDeLaLista();
  
  pa2m_nuevo_grupo("Pruebas de funciones de utilidad sobre listas con elementos");

    DadaListaConElementos_AlPedirElUltimoElemento_SeDevuelvePunteroAlMismo();
    DadaListaConElementos_AlPedirCantidadDeElementos_SeDevuelveLaCantidadCorrecta();
    DadaListaConElementos_AlPedirUnElementoEnPosicionInvalida_SeDevuelveNull();
    DadaListaConElementos_AlPedirUnElementoEnPosicionValida_SeDevuelvePunteroAlMismo();

  pa2m_nuevo_grupo("Pruebas de borrado");

    DadaListaVacia_AlIntentarBorrarDelFinal_NoSePuedeBorrar();
    DadaListaConUnElemento_AlBorrarDelFinal_ResultaListaSinElementos();
    DadaListaConElementos_AlBorrarDelFinal_SeBorraElementoCorrectamente();
    DadaListaVacia_AlIntentarBorrarEnPosicionCualquiera_NoSePuedeBorrar();
    DadaListaConElementos_AlBorrarEnPosicionInvalidaOAlFinal_SeIntentaBorrarDelFinal();
    DadaListaConMinimoTresElementos_AlBorrarEnPosicionIntermedia_SeBorraCorrectamente();
    DadaListaConMinimoDosElementos_AlBorrarAlInicio_SeBorraCorrectamente();

  pa2m_nuevo_grupo("Pruebas de funciones de pila");
    //APILAR
    DadaPilaInexistente_AlIntentarApilar_NoSePuedeApilar();
    DadaPilaConOSinElementos_AlApilar_SeApilaCorrectamente();
    //DESAPILAR
    DadaPilaVacia_AlIntentarDesapilar_NoSePuedeDesapilar();
    DadaPilaConElementos_AlDesapilar_SeDesapilaCorrectamente();
    //TOPE
    DadaPilaVacia_AlPedirTope_SeDevuelveNULL();
    DadaPilaConElementos_AlPedirTopeEnVariadasSituaciones_SeDevuelveElementoTopeCorrectamente();

  pa2m_nuevo_grupo("Pruebas de funciones de cola");
    //ENCOLAR
    DadaColaInexistente_AlIntentarEncolar_NoSePuedeEncolar();
    DadaColaConOSinElementos_AlEncolar_SeEncolaCorrectamente();
    //DESENCOLAR
    DadaColaVacia_AlIntentarDesencolar_NoSePuedeDesencolar();
    DadaColaConElementos_AlDesencolar_SeDesencolaCorrectamente();
    //PRIMERO
    DadaColaVacia_AlPedirPrimero_SeDevuelveNULL();
    DadaColaConElementos_AlPedirPrimeroEnVariadasSituaciones_SeDevuelveElementoPrimeroCorrectamente();

  pa2m_nuevo_grupo("Pruebas de iterador interno");

    //Dada_Al_Se();
    //Dada_Al_Se();
    //Dada_Al_Se();
    //Dada_Al_Se();

  pa2m_nuevo_grupo("Pruebas de iterador externo");


  return pa2m_mostrar_reporte();

}
