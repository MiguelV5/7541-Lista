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
        Lista INEXISTENTE hace referencia a un puntero a lista que apunta a NULL:
            (lista_t* lista == NULL)
        Una Lista VACÍA puede referirse a:
            -Una lista INEXISTENTE.
            -Una lista EXISTENTE cuyos nodos de inicio y fin son NULL, y cuya cantidad de
            elementos  es cero.
            Denomino a esta última "LISTA SIN ELEMENTOS".

    ▒▒▒▒  Sobre separación de grupos de pruebas  ▒▒▒▒
        Decidí separar las pruebas de "funciones de utilidad" (lista_vacia; 
        lista_elementos; lista_ultimo; lista_elemento_en_posicion) en dos
        secciones:
        Una para probarlas exclusivamente sobre listas vacías, y otra para probarlas
        sobre listas con elementos.
        Esto debido a que, para poder realizar pruebas sobre listas con elementos, 
        requería el uso de las funciones de inserción, especialmente la función
        "lista_insertar" que es muy útil y conveniente (también considerando que con la
        implementación actual, esta funcion es O(1) siempre, caso contrario de
        "lista_insertar_en_posicion"). Sin embargo para poder utilizar
        dicha función con toda seguridad, primero se debe asegurar su funcionamiento por medio
        de las pruebas de inserción.
        Es por esto que, recién despues de las mismas, se aplican las pruebas sobre listas con 
        elementos para funciones de utilidad.


    ▒▒▒▒  Sobre los elementos pasados por parametro por el usuario.  ▒▒▒▒
        Los datos que el usuario almacene se asumen como su responsabilidad, y en ningún
        momento se modifica o verifica el elemento que requiera insertar, salvo si es NULL o no.
        Esto excluye entonces al manejo de memoria de dichos elementos, por lo cual debe ser
        administrada a su vez por el usuario (claramente, solo en caso de tener
        elementos almacenados en el Heap).


    ▒▒▒▒  Cita de linea 215, pruebas.c  ▒▒▒▒
        Se tiene:
            [a]->[e]->[i]->[o]->[u]
            [inicio] == [a] ; [fin] == [u]
        Se quiere:
            [a]->[x]->[e]->[i]->[o]->[y]->[u]
        Por lo cual, tras insertar cada uno: 
            -Sigte. a [x] debe ser [e];
            -Sigte. a [o] debe ser [y]; 

    ▒▒▒▒  Orden de pruebas de pila  ▒▒▒▒
        Me causó inseguridad decidir qué orden debía tomar al implementar las pruebas
        de pila, ya que:
        Si testeaba primero las funciones apilar y desapilar, no era posible asegurar el 
        correcto funcionamiento de la función lista_tope, por ende no podía emplearse
        para probar que, por ejemplo, los elementos apilados fueran los topes nuevos, y
        que al desapilar los topes nuevos pasaran a ser los elementos efectivamente 
        "anteriores" a los ex-topes.
        Sin embargo, si se testeaba primero la función lista_tope para evitar lo anterior,
        estaba en una situación similar ya que en un principio las pruebas NO deberían saber
        absolutamente nada de la implementación de pila, por ende para poder probar lista_tope
        debía utilizar apilar y desapilar, y descartar uso de lista_insertar que no permite
        evaluar el comportamiento como pila.
        Luego caí en cuenta, y concluí entonces que la mejor opción era la 1ra (probar primero
        apilar y desapilar), ya que son las que le dan el comportamiento de pila a la misma, y
        luego en las pruebas de lista_tope testear efectivamente dicho comportamiento.
        Un razonamiento similar fué aplicado para las funciones de cola.


        