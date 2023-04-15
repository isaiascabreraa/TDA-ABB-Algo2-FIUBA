# TDA-ABB-Algo2-FIUBA

ÁRBOL BINARIO DE BÚSQUEDA
Se pide implementar un Árbol Binario de Búsqueda (ABB) en el lenguaje de programación C. Para ello se brindan las firmas de las funciones públicas a implementar y se deja a criterio de lalumno la creación de las funciones privadas del TDA para el correcto funcionamiento del ABB, cumpliendo con las buenas prácticas de programación.

Adicionalmente se pide la creación de un iterador interno que sea capaz de realizar diferentes recorridos en el árbol y una función que guarda la información almacenada del árbol en un vector.

El TDA entregado deberá compilar y pasar las pruebas dispuestas por la cátedra (Chanutron't) sin errores, adicionalmente estas pruebas deberán ser ejecutadas sin pérdida de memoria.

A modo de ejemplo, se brindará al alumno un archivo simple de ejemplo. Este archivo no es mas que un programa mínimo de ejemplo de utilización del TDA a implementar y es provisto sólo a fines ilustrativos como una ayuda extra para entender el funcionamiento del mismo. No es necesario modificar ni entregar el archivo de ejemplo, pero si la implementación es correcta, debería correr con valgrind sin errores de memoria.

Para la resolución de este trabajo se recomienda utilizar una metodología orientada a pruebas. A tal fin, se incluye un archivo pruebas.c que debe ser completado con las pruebas pertinentes de cada una de las diferentes primitivas del TDA. El archivo de pruebas forma parte de la entrega y por lo tanto de la nota final. Aún mas importante, las pruebas van a resultar fundamentales para lograr no solamente una implementación correcta, si no también una experiencia de desarrollo menos turbulenta.

ACLARACIONES DE LA IMPLEMENTACIÓN
Esta implementación de ABB incluye una función de comparación que permite insertar cualquier tipo de puntero en el mismo. El ABB no tiene idea de qué es lo que almacena el usuario, simplemente es un contenedor de datos que sigue reglas definidas. Mediante el comparador, el ABB es capaz de establecer la relación de orden de los diferentes punteros sin necesidad de contar con información extra. **Los comparadores devuelven 0, >0 o <0 según la relación de los elementos comparados (no 0, 1, -1).

Otra característica distintiva de esta implementación es el uso de funciones de destrucción. Ya que el ABB no es mas que un contenedor de datos y no conoce nada acerca del contenido del mismo, y dado que en C quien reserva la memoria es el responsable de liberarla, las funciones de destrucción permite al usuario delegarle esta responsabilidad al ABB. De esta forma, cuando el árbol es destruido, la función provista por el usuario es aplicada a cada elemento almacenado para que sea liberado correctamente. La función de destrucción puede ser NULL para indicar que no se debe hacer nada especial con los elementos.

Por último, las pruebas de Chanutron't pueden llegar a suponer que la implementación acomoda los elementos menores del ABB del lado izquierdo y los mayores del lado derecho. También puede suponer que al borrar nodos con hijos no nulos se reemplaza dicho nodo con el predecesor inorden.

CONSEJOS PARA LA ELABORACIÓN DEL TRABAJO
Intenta comprender primero el funcionamiento de los nodos enlazados. Propone un arbol con elementos y dibujá a mano (lápiz y papel) varias operaciones de inserción y eliminación. Dibujá cada uno de los nodos con sus punteros y datos. Una vez hecho el dibujo, intenta aplicar sobre el mismo cada una de las operaciones propuestas para el TDA. Poder dibujar el problema exitosamente y entender cómo funciona va a ser fundamental a la hora de la implementación.

Empezá la implementación de cada primitiva escribiendo una prueba. A la hora de escribir cada prueba preguntate primero cuál es el comportamiento correcto de la primitiva en cuestión. Elaborá una prueba en base a ese conocimiento. Luego implementá el código de la primitiva que satisfaga esa prueba. Por último preguntate qué casos erróneos conoces y qué posibles entradas pueden hacer que la primitiva falle. Implementá pruebas para estos casos y si es necesario, modificá la implementación para que el funcionamiento sea el correcto.

Recordá al escribir pruebas: no se busca en el código de pruebas la encapsulación ni simplificación de las mismas, no es incorrecto tener pruebas con código repetitivo. Las pruebas son una especificación del comportamiento deseado de las primitivas. Como tal, deben ser fáciles de leer y entender su objetivo.

En general, para todo el código: utilizá nombres claros de variables y funciones auxiliares. Una variable con el nombre cantidad_elementos_recorridos o incluso cantidad es mucho mas claro que una variable con el nombre n, cant, o rec. Intentá darle un significado el nombre de cada variable, dentro de lo posible (por supuesto, quedan excluidos casos como i, j, etc para bucles y cosas así).

NO escribas código a lo loco sin compilar cada tanto. Implementá la solución de a poco y compilando a cada paso. Dejar la compilación para el final es uno de los peores errores que podés cometer. Para la compilación del trabajo se provee un Makefile. Utilizá el comando make frecuentemente para compilar y correr el programa.

NO avances en la implementación si quedan errores sin resolver en alguna prueba. Cada vez que escribas una prueba implementá toda la funcionalidad necesaria para que funcione correctamente. Esto incluye liberar memoria y accesos inválidos a la misma. Solamente una vez que hayas logrado que la prueba pase exitosamente es que podés comenzar a escribir la próxima prueba para continuar el trabajo.

NO está permitido modificar los archivos .h. Se pueden hacer modificaciones al makefile, pero recordá que el trabajo será compilado por el sistema de entregas con las cabeceras y el makefile original.

ENTREGA
La entrega deberá contar con todos los archivos que se adjuntan (todo lo necesario para compilar y correr correctamente) y las pruebas que demuestran que su implementación funciona. Dichos archivos deberán formar parte de un único archivo .zip el cual será entregado a través de la plataforma de corrección automática Chanutron't.

El archivo comprimido deberá contar, además de los archivos del TDA, con un informe que contenga la siguiente información:

Explicá teóricamente qué es un árbol, un árbol binario y un árbol binario de búsqueda y por qué es importante la distinción. Explicá cómo funcionan las operaciones de inserción, eliminación y búsqueda en cada caso ayudándote con diagramas.
Explicá cómo funcionan las partes importantes del código (inserciones, eliminaciones e iteradores). No expliques línea por línea lo que hiciste, la explicación tiene que poder ayudar a entender lo que implementaste. Por ejemplo: explicar algún movimiento complejo de punteros que hagas o por qué tal primitiva está hecha de forma recursiva o iterativa, etc.
CRITERIOS MÍNIMOS DE CORRECCIÓN
GENERAL
 Cada malloc tiene su verificación
 Libera(cierra) memoria(archivos) en los casos de error
 Reallocs sobre punteros auxiliares
 No hay fragmentos de código comentado sin usar
 No hay printfs donde no es necesario
 Los entregables compilan y corren sin error
 Verifica los punteros recibidos en las funciones públicas
 No hay variables globales
 No reserva memoria cuando no es necesario
 Usa constantes y tienen sentido.
ESTILO
 El estilo es el apropiado
 Los nombres de función me dicen lo que hacen
 No hay variables con nombre confuso
PRUEBAS
 Corren sin error y pasan
 Son fáciles de leer y entender qué hacen
 Cantidad razonable
Si prueba lo necesario no importa que sean pocas
Si son excesivas sin motivo no es bueno
 No hace printf para verificar el resultado visualmente
ABB
 Los iteradores internos no utilizan las funciones de transformación a vector.
 Al eliminar elementos, se recorre la rama una sola vez.
2. LISTA DE VERIFICACIÓN DE PRUEBAS DE ABB RECOMENDADAS POR ABRIL
2.1 CREACIÓN
 Se prueba que no se pueda crear un abb con una función comparadora nula
 Se prueba crear un abb válido y verificar que empieza vacío
2.2 INSERCIÓN
 Se prueba que no se pueda insertar en un árbol nulo
 Se prueba insertar un elemento que tenga información NULL-0-false
 Se prueba insertar un elemento como hoja
 Se prueba insertar un elemento como raíz
 Se prueba insertar un elemento que no está en el árbol
 Se prueba insertar un elemento repetido
2.3 ELIMINACIÓN
 Se prueba que no se pueda quitar de un árbol nulo
 Se prueba que no se pueda quitar de un árbol vacío
 Se prueba quitar un elemento con hijos
 Se prueba quitar un elemento sin hijos
 Se prueba quitar la raíz con hijos
 Se prueba quitar la raíz sin hijos
 Se prueba quitar un elemento que tenga información NULL-0-false
 Se prueba que no se pueda eliminar un elemento que no se encuentra en el árbol
2.4 BÚSQUEDA
 Se prueba que no se pueda buscar en un árbol nulo
 Se prueba que no se pueda buscar en un árbol vacío
 Se prueba buscar un elemento que no está en el árbol
 Se prueba buscar un elemento que está en el árbol
 Se prueba buscar un elemento que tenga información NULL-0-false
2.5 TAMAÑO Y VACÍO
 Se prueba que un abb inválido (nulo) tiene tamaño 0

 Se prueba que un abb vacío tiene tamaño 0

 Se prueba que si al agregar elementos al abb, el tamaño aumenta

 Se prueba que al eliminar elementos del abb, el tamaño disminuya

 Se prueba que un abb inválido está vacío

 Se prueba que un abb vacío está vacío

 Se prueba que un abb con elementos no está vacío

2.6 RECORRER CON ARRAYS
 Se prueba mandar un árbol nulo
 Se prueba mandar un array nulo
 Se prueba mandar un array con tamaño 0
 Se prueba mandar un array con un tamaño menor a la cantidad de elementos y llenar el array
 Se prueba mandar un array con un tamaño mayor a la cantidad de elementos y no llenar el array
2.7 ITERADOR INTERNO
 Se prueba que no se puede iterar un árbol nulo
 Se prueba que no se puede iterar con una función nula
 Se prueba que se puede iterar con un aux nulo
 Se prueba cortar la iteración antes de terminar de recorrer todos los elementos
 Se prueba recorrer todo el árbol
