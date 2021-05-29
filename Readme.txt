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
        momento se modifica o verifica el elemento que requiera insertar.
        Esto excluye entonces al manejo de memoria de dichos elementos, por lo cual debe ser
        administrada a su vez por el usuario (claramente, solo en caso de tener
        elementos almacenados en el Heap).


    ▒▒▒▒  Cita de linea 201, pruebas.c  ▒▒▒▒
        Se tiene:
            [a]->[e]->[i]->[o]->[u]
            [inicio] == [a] ; [fin] == [u]
        Se quiere:
            [a]->[x]->[e]->[i]->[o]->[y]->[u]
        Por lo cual, tras insertar cada uno: 
            -Sigte. a [x] debe ser [e];
            -Sigte. a [o] debe ser [y]; 

    ▒▒▒▒  Orden de pruebas de pila, cola e iterador externo  ▒▒▒▒
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

    ▒▒▒▒  Uso de función lista_elemento_en_posicion en las pruebas  ▒▒▒▒
        A lo largo de las pruebas posteriores a las de dicha función, solía usar
        nodos auxiliares que fueran guardando los elementos que iba insertando en las
        diversas listas de prueba. Sin embargo, pude haberme ahorrado esto usando lista_elemento_en_posicion
        ya que se tenía probada, pero recién durante la realización de las pruebas de
        iteradores caí en cuenta de este detalle.

    ▒▒▒▒  Sobre comportamiento de lista_iterador_tiene_siguiente y lista_iterador_avanzar  ▒▒▒▒
        El nombre "tiene siguiente" puede prestarse a confusión, ya que en realidad la
        función, aparte de verificar iterador vacío, devuelve true SI LE QUEDAN ELEMENTOS por "devolver"
        en una iteración en general, con lo cual siempre se fija en que el elemento ACTUAL exista o no, y 
        en ningún momento se fija en el nodo que le sigue.
        Ejemplificando con el minipruebas.c, se hace la iteración:

            for(it = lista_iterador_crear(lista);    <---- (1)
                lista_iterador_tiene_siguiente(it);    <---- (2)
                lista_iterador_avanzar(it))        <---- (4)
                printf("%c ", *(char*)lista_iterador_elemento_actual(it));   <---- (3)
            printf("\n\n");

        De donde el objetivo es imprimir a b c d, entonces:
        (1) Se crea el iterador, con lo cual el elemento actual ahora es 'a'.
        (2) Con el comportamiento explicado, se fija si existe elemento actual. Lo cual es true. Entonces...
        (3) Imprime 'a'.
        (4) Avanza y devuelve true porque el nuevo elemento actual existe, 
        Volvemos a (2)
        (2) Existe actual ---> true (ahora el actual es 'b').
        (3) Imprime 'b'
        (4) Lo mismo que antes.
            .
            . (Mismo proceso para 'c')
            .
        Volvemos a (2) tras iterar el 'c'
        (2) Existe actual ---> true (ahora el actual es 'd', si tiene_siguiente devolviera false al fijarse en
        que el NODO siguiente es NULL y NO en que el elemento actual existe, acá cortaría la iteración y quedaría
        sin imprimirse el 'd').
        (3) Imprime 'd'
        (4) Avanza por ultima vez, pero devuelve false porque ya estaba en el último elemento.






        