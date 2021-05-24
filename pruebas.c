#include "lista.h"
#include "pa2mm.h"



void DadaUnaListaInexistente_AlCrearLaLista_ResultaUnaListaCreadaVacia(){
  
  lista_t* lista = lista_crear();

  pa2m_afirmar(lista != NULL, "La lista fue correctamente reservada en memoria");
  pa2m_afirmar((lista->nodo_inicio == NULL) && (lista->nodo_fin == NULL) , "La lista creada está vacía");

  lista_destruir(lista);

}




int main() {
  
  // Notación: 
  // Lista inexistente quiere decir: (lista == NULL)
  // Lista vacía se refiere a una (lista != NULL) tal que (lista->nodo_inicio == lista->nodo_fin == NULL);

  pa2m_nuevo_grupo("Pruebas de creación de lista");

  DadaUnaListaInexistente_AlCrearLaLista_ResultaUnaListaCreadaVacia();

  pa2m_nuevo_grupo("Pruebas de inserción en lista");

  //DadaListaInexistente_AlIntentarInsertarElemento_NoSePuedeInsertar();
  //DadaUnaLista_AlIntentarInsertarUnNodoNULL_NoSePuedeInsertar();  
  //DadaListaVacia_AlInsertarleElemento_SeInsertaCorrectamente();
  //DadaListaConElementos_AlInsertaleOtroElementoAlFinal_SeInsertaCorrectamenteAlli();
  //DadaListaConElementos_AlInsertarElementoEnUnaPosicionIntermedia_SeInsertaCorrectamenteAlli();
  //DadaListaConElementos_AlInsertarElementoAlInicio_SeInsertaCorrectamenteAlli();

  return pa2m_mostrar_reporte();
}
