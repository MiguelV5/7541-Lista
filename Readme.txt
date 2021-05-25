▒▒▒▒▒▒▒▒▒▒▒▒  Introduccion teórica breve  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    Lista:
        Una lista es un tipo de dato abstracto que permite guardar información
        en forma de, valga la redundancia, un listado de datos. Tiene como característica la permitividad al
        acceso y uso de cualquier elemento que pertenezca a la misma, y no impide la modificación
        de estos.
        Una lista tiene distintas implementaciones posibles, entre las cuales algunas son:
         -Listas implementadas con vectores estáticos.
         -Listas implementadas con vectores dinámicos.
         -Listas implementadas por medio de nodos (El TDA de nodos enlazados permite que la lista no tenga 
          que almacenarse de manera contigua en memoria).
        En lo que sigue para hablar de los distintos tipos de lista, hago referencia exclusivamente a la implementación de
        lista por medio de nodos enlazados (implementación de este TDA en particular).
        Algunos tipos de lista conocidos son:
         -Lista simplemente enlazada: Cada nodo posee el elemento que almacena y una referencia al nodo siguiente 
          de la lista.
         -Lista doblemente enlazada: Cada nodo posee el elemento que almacena y referencias al nodo siguiente y al
          anterior.
         -Lista circular: Igual a la simplemente enlazada, pero el último nodo de la lista tiene una referencia al
          primer nodo de la misma.
         -Lista circular doblemente enlazada: Como la circular, pero con las características adicionales de la doblemente
          enlazada.

    
        



▒▒▒▒▒▒▒▒▒▒▒▒  Explicaciones de implementación:  ▒▒▒▒▒▒▒▒▒▒▒▒ 


    ▒▒▒▒    ▒▒▒▒

        ---  ---
            

        ---  ---
            

        ---  ---
            

        ---  ---
            

        ---  ---
            


    ▒▒▒▒    ▒▒▒▒

        ---  ---
            

        ---  ---
            

        ---  ---
            

        ---  ---
            

        ---  ---
            




▒▒▒▒▒▒▒▒▒▒▒▒  Aclaraciones:  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    ▒▒▒▒  Detalles de notación  ▒▒▒▒
        Lista inexistente hace referencia a una lista_t* lista == NULL
        Lista vacía se refiere a una (lista_t* lista != NULL) tal que 
        (lista->nodo_inicio == lista->nodo_fin == NULL);


    ▒▒▒▒  Sobre los elementos pasados por parametro por el usuario.  ▒▒▒▒
        Notar que no se hizo ninguna prueba sobre los elementos pasados por
        el usuario a la hora de insertar en la lista.
        Esto se debe a que los datos que el mismo almacene se asumen como su responsabilidad, y en ningún momento se modifica o verifica el elemento que requiera insertar.
        Esto excluye entonces las pruebas de todo lo relacionado con revisión de
        cualquier puntero NULL de elemento que se pase, y el manejo de memoria de dichos
        elementos debe ser administrada (claramente, solo en caso de tener elementos en Heap),
        a su vez, por el usuario.




    ▒▒▒▒    ▒▒▒▒


        _______________________________________________________________________________