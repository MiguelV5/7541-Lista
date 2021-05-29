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
        En lo que sigue para hablar de los distintos tipos de lista, hago referencia exclusivamente a la 
        implementación de lista por medio de nodos enlazados (implementación de este TDA en particular).
        Algunos de estos tipos de lista son:
         -Lista simplemente enlazada: Cada nodo posee el elemento que almacena y una referencia al nodo siguiente 
          de la lista.
         -Lista doblemente enlazada: Cada nodo posee el elemento que almacena y referencias al nodo siguiente y al
          anterior.
         -Lista circular: Igual a la simplemente enlazada, pero el último nodo de la lista tiene una referencia al
          primer nodo de la misma.
         -Lista circular doblemente enlazada: Como la circular, pero con las características adicionales de la doblemente
          enlazada.

    
▒▒▒▒▒▒▒▒▒▒▒▒  Explicación de implementación:  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    Se omite:
        - Explicación de ciertas funciones o partes de las mismas que no la requieren.
        - Explicación de verificaciones de listas/nodos inexistentes.

    ▒▒▒▒  lista.c  ▒▒▒▒

        --- lista_insertar ---
            Hago que un nodo nuevo almacene el elemento pedido e inicializo su nodo siguiente a NULL porque quiero que
            sea mi nuevo final tras insertarlo.
            Si la lista no tenía elementos, el nodo nuevo va a ser tanto el inicio como el fin de la lista.
            Si ya tenía elementos, 'engancho' ese nodo nuevo como siguiente al final previo, y actualizo el final
            para que tambien sea ese recién insertado. 

        --- lista_insertar_en_posicion ---
            - Si la posición pedida esta por fuera de la lista, inserto al final de la misma con lista_insertar.
            - Si esa posición era el inicio de la lista, creo un nodo nuevo que guarde el elemento y cuyo siguiente
             sea el inicio previo de la lista. Como quiero que el nuevo sea el nuevo inicio, actualizo apuntando el primero
             de la lista al mismo.
            - Si la posición era entre la lista, sin ser el inicio, creo el nodo nuevo y guardo elemento, pero ahora necesito
             posicionarme en un lugar cómodo para poder hacer la inserción. Entonces recorro la lista hasta una posición 
             justamente anterior a la requerida. Una vez el actual es ese anterior, hago que el siguiente del nuevo sea 
             el siguiente de ese anterior (ya que este es el que ORIGINALMENTE estaba en la posición que se pide), y 
             recién ahora puedo actualizar el siguiente del anterior con el nodo nuevo.
             No se puede realizar en orden invertido, porque se perdería la referencia al resto de la lista a partir de la
             posición que se quiere insertar.

        --- lista_borrar ---
            Cuando se quiere borrar al final de una lista que NO tiene un único elemento, se llama a borrar_ultimo_de_multiples,
            la cual:
                - Recorre la lista hasta el nodo anterior al final (que es el que se quiere eliminar).
                (Se cita el readme en la linea 162 porque, el nodo anterior al final va a estar en la posición 
                cantidad -1 -1, siendo (cantidad-1) la ultima posición, por ende otro -1 para que sea la anterior al final.)
                - Una vez está ahí, se guarda en un auxiliar el nodo a eliminar, se elimina, y como se tenía disponible
                el nodo anterior (porque así se recorrió), ese va a pasar a ser el nuevo final de la lista.
            
            NOTAS: Este "borrar_ultimo_de_multiples" puede parecer similar en código a simple vista a la función
            "borrador_elemento_intermedio" que se usa más adelante, sim embargo sus comportamientos NO son el mismo
            y requieren distinción.
            No se me ocurrió como hacer una implementación para borrar el último que no requiera recorrer toda la lista,
            lo cual hace que esto sea de complejidad O(n). Puede ser que usando el iterador externo se pueda, pero se tendría que
            tener implementado y debidamente probado antes.

        --- lista_borrar_de_posicion ---
            - Asi como en lista_insertar_en_posicion, si se da una posición posterior al final se llama a lista_borrar a que 
             se elimine el último elemento.
            Notar que en esto anterior queda contemplado el caso en el que se requiere borrar de la primera posición pero 
            justamente la lista tenia ese ÚNICO elemento. Por este motivo el caso siguiente asume que la lista NO tiene
            uno solo, sino más de un elemento antes de borrar.
            - Si ocurre esto (se pide borrar de posición cero y la lista tiene más de un elemento), se usa un auxiliar
             para 'tener en mano' al nodo inicial, ya que este se quiere actualizar haciendo que 'avance' a ser su 
             propio siguiente. Como antes ya se guardó al inicio viejo, se puede liberar sin problema.
             (Notar que esta implementación para borrar el primero es de complejidad O(1) al ser solo una reasignación).
            - Si se quiere borrar un elemento que no es el inicio ni el final de la lista, se realiza algo similar a
             "borrar_ultimo_de_multiples", ya que se recorre hasta la posición anterior de la que se quiere borrar.
             Luego de eso difieren, pues acá:
                1) Se guarda el nodo a eliminar (que es el siguiente de hasta donde se iteró).
                2) Se REAPUNTA para que el siguiente del anterior sea el siguiente del que se quiere borrar
                    
                    Visualmente:  [anterior]--//X//-->[a_eliminar]---->[siguiente_del_que_se_quiere_borrar]
                    ‎‎                        |_________________________|^ 

                3) Ahora si se puede eliminar el que se quiere sin perder todos sus siguientes.

        --- lista_elemento_en_posicion ---
            Si el elemento que se quiere obtener no es ni el inicio ni el final, se recorre hasta la posición 
            deseada (esta vez NO la anterior) y se devuelve el elemento.
        
        --- funciones de pila ---
            Tomé como implementación insertar y borrar al inicio, ya que por ser pila debe tener comportamiento Last In 
            First Out, y conviene más desapilar del inicio por lo que se mencionó antes acerca de la complejidad
            de borrado al principio de la lista con esta implementación.
            Teniendo esto en cuenta, lista_tope también queda con complejidad O(1), pues se pide siempre el 1er elemento
            de la pila, y no se tiene que recorrer toda con lista_elemento_en_posicion.
            (Como tal las pilas no se deberían poder recorrer, entonces esto se favorece también lógicamente).

        --- funciones de cola ---
            Tomé como implementación insertar al final y borrar al inicio, ya que la cola debe tener comportamiento First In 
            First Out, por lo que, con esta implementación, conviene insertar al final (O(1)) y borrar del
            principio (nuevamente O(1)).
            Con esto mismo en mente, lista_primero también se favorece pues se pide el primer elemento de la lista.
            (Y esto lo hace cómodo de pensar, pues se corresponde justamente el 1ro de la lista con el 1ro de la cola).

        --- Iterador externo ---
            La explicación fué hecha más abajo en la sección de aclaraciones, se detallan consideraciones
            de la implementación de lista_iterador_avanzar y lista_iterador_tiene_siguiente.

        --- Iterador interno ---
            Se recorre la lista hasta que se quede sin elementos, o hasta que la función pasada por el usuario
            para aplicar a cada elemento devuelva false.
            Intenté usar una variable bool que guardara el valor de retorno de la función por cada iteración para 
            evitar ponerla como condición del while, pero esto hace que se cuente una recorrida adicional de lo que
            se quiere cuando la iteración debe cortar por el false de retorno.
            Esto es porque el while no sabe que debe detenerse si la función se llama recién despues de 
            entrar.
            

▒▒▒▒▒▒▒▒▒▒▒▒  Aclaraciones:  ▒▒▒▒▒▒▒▒▒▒▒▒ 

    ▒▒▒▒  Detalles de notación  ▒▒▒▒

        Lista INEXISTENTE hace referencia a un puntero a lista que apunta a NULL:
            (lista_t* lista == NULL)
        Una Lista VACÍA puede referirse a:
            -Una lista INEXISTENTE.
            -Una lista EXISTENTE cuyos nodos de inicio y fin son NULL, y cuya cantidad de
            elementos  es cero.
            Denomino a esta última una "LISTA SIN ELEMENTOS" a lo largo de las pruebas.


    ▒▒▒▒  Sobre separación de grupos de pruebas  ▒▒▒▒

        Decidí separar las pruebas de "funciones de utilidad" (lista_vacia; 
        lista_elementos; lista_ultimo; lista_elemento_en_posicion) en dos
        secciones:
        Una para probarlas exclusivamente sobre listas vacías, y otra para probarlas
        sobre listas con elementos.
        Esto debido a que, para poder realizar pruebas sobre listas con elementos, 
        requería el uso de las funciones de inserción, especialmente la función
        "lista_insertar" que es muy útil y conveniente (considerando que con la
        implementación actual, esta funcion es O(1) siempre). Sin embargo para poder utilizar
        dicha función con toda seguridad, primero se debe asegurar su funcionamiento por medio
        de las pruebas de inserción.
        Es por esto que, recién despues de las mismas, se aplican las pruebas sobre listas CON 
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






        