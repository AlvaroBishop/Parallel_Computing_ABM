# CAPÍTULO 3: MODELO DE EJECUCIÓN CUDA
## **Introducción al Modelo de Ejecución de CUDA**

El modelo de ejecución de CUDA proporciona una vista operativa de cómo se ejecutan las instrucciones en una arquitectura de cómputo específica. Muestra una vista abstracta de la arquitectura paralela de la GPU, lo que permite a los desarrolladores razonar sobre la concurrencia de hilos.

La jerarquía de hilos implica cómo se organizan y ejecutan los hilos en la GPU, incluyendo la forma en que se agrupan en bloques y cuadrículas.Esta jerarquía es crucial para escribir código eficiente que aproveche al máximo el paralelismo de la GPU. 

### Resumen de la Arquitectura de la GPU
La arquitectura de la GPU se basa en una matriz escalable de Multiprocesadores de Transmisión (SM, por sus siglas en inglés). Cada SM está diseñado para admitir la ejecución concurrente de cientos de hilos. Cuando se lanza una cuadrícula de núcleos (kernel grid), los bloques de hilos de esa cuadrícula de núcleos se distribuyen entre los SM disponibles para su ejecución. 

### La Arquitectura Fermi
La arquitectura Fermi es una arquitectura de cómputo GPU que fue la primera en ofrecer las características necesarias para aplicaciones de cómputo de alto rendimiento (HPC) exigentes. Cuenta con hasta 512 núcleos aceleradores llamados CUDA cores, organizados en 16 multiprocesadores de transmisión (SM) con 32 CUDA cores cada uno. Fermi también tiene seis interfaces de memoria GDDR5 DRAM de 384 bits que admiten hasta 6 GB de memoria global a bordo. Incluye un motor GigaThread para distribuir bloques de hilos a los programadores de warps de SM. Fermi admite la ejecución simultánea de núcleos, lo que permite ejecutar varios núcleos en el dispositivo al mismo tiempo.

La arquitectura Fermi se destacó por su enfoque en aplicaciones de cómputo de alto rendimiento, como la simulación científica, la investigación biomédica y los gráficos 3D avanzados. Además, la capacidad de ejecución concurrente de núcleos es una característica clave que permite que múltiples tareas se ejecuten de manera simultánea en la GPU, lo que es fundamental para la aceleración de aplicaciones paralelas en HPC.

### La Arquitectura Kepler
La arquitectura de la GPU Kepler, lanzada en el otoño de 2012, es una arquitectura de cómputo de alto rendimiento rápida y altamente eficiente. Introduce varias innovaciones importantes, incluyendo multiprocesadores de transmisión (SM) mejorados, paralelismo dinámico e Hyper-Q.

El paralelismo dinámico es una característica clave introducida con las GPU Kepler. Permite que la GPU lance dinámicamente nuevas cuadrículas y permite que cualquier núcleo lance otro núcleo. Esta característica simplifica la creación y optimización de patrones de ejecución recursivos y dependientes de datos.

En general, la arquitectura Kepler proporciona un mejor rendimiento, eficiencia energética y programabilidad, lo que la convierte en una elección valiosa para aplicaciones de cómputo de alto rendimiento. Esta arquitectura fue un paso importante en la evolución de las GPU, brindando a los desarrolladores más herramientas y capacidades para abordar tareas de cómputo intensivas.

### Optimización Dirigida por Perfilado
La Optimización Dirigida por Perfilado es el proceso de analizar el rendimiento de un programa mediante la medición de diversos factores, como la complejidad temporal o espacial del código de la aplicación, el uso de instrucciones específicas y la frecuencia y duración de las llamadas a funciones.

Al utilizar herramientas de perfilado, los desarrolladores pueden identificar cuellos de botella de rendimiento y obtener información sobre cómo se utilizan los recursos de cómputo en la programación de CUDA. Herramientas de perfilado como nvvp y nvprof proporcionan una profunda comprensión del rendimiento de los núcleos (kernels) y ayudan a identificar cuellos de botella y guiar las optimizaciones.

## Comprendiendo la Naturaleza de la Ejecución de Warps
En esta sección, el libro explica en detalle el concepto de la ejecución de warps. Comienza por introducir la idea de los warps, que son grupos de 32 hilos que se ejecutan juntos en una unidad de ejecución llamada Multiprocesador de Transmisión (SM). Enfatiza que aunque los hilos dentro de un warp se ejecutan lógicamente en paralelo, no todos los hilos pueden ejecutarse físicamente en paralelo al mismo tiempo.

La ejecución de warps es esencial para escribir código eficiente en CUDA, ya que permite a los desarrolladores optimizar la utilización de los recursos de la GPU y minimizar los cuellos de botella. Los desarrolladores deben considerar cuidadosamente la organización de los hilos en warps y cómo se gestionan las dependencias entre ellos para maximizar el rendimiento de sus aplicaciones en GPU.

### Warps y Bloques de Hilos
Warps y bloques de hilos son conceptos fundamentales en el modelo de ejecución de CUDA. Un bloque de hilos es una colección de hilos organizados en una disposición 1D, 2D o 3D. Desde la perspectiva del hardware, un bloque de hilos es una colección 1D de warps. Cada bloque de hilos consta de múltiples warps, y cada warp consta de 32 hilos consecutivos. Todos los hilos dentro de un warp ejecutan la misma instrucción en una moda de Un Instrucción, Múltiples Hilos (SIMT).

Los **bloques de hilos** se pueden configurar como unidimensionales, bidimensionales o tridimensionales. Sin embargo, desde la perspectiva del hardware, todos los hilos están dispuestos unidimensionalmente. Cada hilo tiene un ID único en un bloque, y para un bloque de hilos unidimensional, el ID de hilo único se almacena en la variable incorporada en CUDA threadIdx.x.

**La divergencia de warps** ocurre cuando los hilos dentro de un warp siguen caminos diferentes a través de una aplicación. Esto puede suceder cuando hay ramas condicionales en el código. Si los hilos en el mismo warp divergen, el warp ejecuta secuencialmente cada camino de la rama, deshabilitando los hilos que no toman ese camino. La divergencia de warps puede degradar significativamente el rendimiento, ya que reduce la cantidad de paralelismo dentro de un warp.

Existen **límites de recursos** impuestos a los bloques de hilos, como el número máximo de hilos por bloque, el número máximo de warps concurrentes por multiprocesador y la cantidad máxima de memoria compartida por multiprocesador. Lograr una alta ocupación, que se refiere al número de hilos o warps concurrentes por SM, es importante para la optimización del rendimiento. Sin embargo, la ocupación completa no es el único objetivo, y otros factores deben considerarse para la optimización del rendimiento.
### Divergencia de Warps
**Características de la Divergencia de Warps:**

-   La divergencia de warps ocurre cuando los hilos dentro de un warp toman diferentes caminos de código.
-   Los hilos en un warp deben ejecutar la misma instrucción en cada ciclo.
-   Si los hilos de un warp divergen, el warp ejecuta secuencialmente cada camino de la rama, deshabilitando los hilos que no siguen ese camino.
-   La divergencia de warps puede causar un rendimiento significativamente degradado, ya que se reduce la cantidad de paralelismo en el warp.
-   Diferentes valores condicionales en diferentes warps no causan divergencia de warps.

**La Importancia de Evitar la Divergencia de Warps:**

Evitar la divergencia de warps es crucial para lograr un rendimiento óptimo en la programación de CUDA. Cuando los hilos de un warp ejecutan diferentes caminos de código, la GPU no puede aprovechar plenamente su capacidad de procesamiento en paralelo. En lugar de ejecutar múltiples hilos simultáneamente, el warp debe ejecutar cada rama de forma secuencial, lo que disminuye la eficiencia. Por lo tanto, los programadores deben diseñar sus algoritmos de manera que los hilos dentro de un warp sigan la misma ruta de ejecución tanto como sea posible.

### Partición de Recursos
La partición de recursos es una consideración importante en la programación de CUDA. Implica gestionar los recursos de cálculo disponibles en la GPU para maximizar el rendimiento. El número de warps activos está limitado por los recursos de cálculo, por lo que es crucial ser consciente de las restricciones del hardware y de los recursos utilizados por el kernel. Al maximizar el número de warps activos, también se puede maximizar la utilización de la GPU.

**Partition camping**

"Partition camping" es un fenómeno que puede ocurrir al acceder a la memoria global. Se refiere a la situación en la que las solicitudes de memoria se acumulan en algunas particiones mientras que otras particiones permanecen sin usar. Esto puede llevar a un rendimiento subóptimo.

**Pautas para Mejorar la Utilización del Ancho de Banda:**

Para mejorar la utilización del ancho de banda, se proporcionan dos pautas. En primer lugar, maximizar el número de accesos a memoria concurrentes en vuelo. Esto se puede lograr creando más solicitudes de memoria independientes en cada hilo o ajustando la configuración de ejecución de bloques y cuadrículas. En segundo lugar, maximizar la utilización de bytes que viajan en el bus entre la memoria global y la memoria en el chip. Esto se puede lograr esforzándose por lograr accesos a memoria alineados y cohesionados.

**Comprensión de la Naturaleza de la Ejecución de Warps:**

Cuando se lanza un kernel, los hilos en el kernel se ejecutan en paralelo desde un punto de vista lógico. Sin embargo, no todos los hilos pueden ejecutarse físicamente en paralelo al mismo tiempo. Los warps son la unidad básica de ejecución en un SM, y los hilos dentro de un warp se ejecutan en grupos de 32.

**Modelo de Memoria de CUDA:**
Al comprender el modelo de memoria, los desarrolladores pueden utilizar eficientemente la memoria global en sus kernels.

###  Ocultamiento de Latencia
**Aspectos Clave del Ocultamiento de Latencia:**

-   El ocultamiento de latencia en la programación de CUDA se logra ejecutando instrucciones de diferentes warps residentes.
-   Las GPU están diseñadas para manejar un gran número de hilos concurrentes y livianos para maximizar el rendimiento.
-   La latencia de las instrucciones se puede clasificar en latencia de instrucciones aritméticas y latencia de instrucciones de memoria.
-   La latencia de instrucciones aritméticas es el tiempo entre el inicio de una operación aritmética y la producción de su salida.
-   La latencia de instrucciones de memoria es el tiempo entre la emisión de una operación de carga o almacenamiento y la llegada de los datos a su destino.
-   Las GPU pueden ocultar la latencia de instrucciones aritméticas de manera más efectiva que la latencia de instrucciones de memoria.
-   El número de warps activos por SM juega un papel crucial en el ocultamiento de latencia.
-   La Ley de Little se puede utilizar para estimar el número de warps activos necesarios para ocultar la latencia.
-   Elegir una configuración de ejecución óptima es importante para encontrar un equilibrio entre el ocultamiento de latencia y la utilización de recursos.

### Ocupación
La ocupación se refiere a la proporción de warps activos con respecto al número máximo de warps por Multiprocesador de Transmisión (SM) en una GPU. Es una métrica importante para optimizar el rendimiento en aplicaciones de CUDA. Lograr una alta ocupación permite una mejor utilización de los recursos de cálculo y puede llevar a un rendimiento mejorado.

### Sincronización
La sincronización en CUDA se refiere a la coordinación de hilos en un bloque de hilos durante la ejecución de un kernel. Permite que los hilos esperen a que los demás alcancen un punto específico en su ejecución antes de continuar.

**Sincronización a Nivel de Sistema:**

La sincronización a nivel de sistema implica esperar a que todo el trabajo tanto en el host como en el dispositivo se complete. Esto se puede lograr utilizando la función

`cudaError_t cudaDeviceSynchronize(void);`

que bloquea la aplicación del host hasta que todas las operaciones de CUDA asincrónicas, como copias de memoria y lanzamientos de kernels, hayan terminado.

**Sincronización a Nivel de Bloque:**

La sincronización a nivel de bloque, por otro lado, implica esperar a que todos los hilos en un bloque de hilos alcancen el mismo punto en su ejecución en el dispositivo. Esto se logra utilizando la función

`__device__ void __syncthreads(void);`

que se llama dentro de un kernel. Cuando se llama a `__syncthreads`, cada hilo en el mismo bloque de hilos debe esperar hasta que todos los demás hilos en ese bloque hayan alcanzado el punto de sincronización.

### Escalabilidad
La escalabilidad es fundamental en la programación paralela, ya que permite que las aplicaciones se beneficien de un mayor poder de procesamiento a medida que se agregan más núcleos de cálculo. Esto es especialmente importante en el campo de la informática de alto rendimiento, donde las aplicaciones a menudo se escalan para aprovechar las supercomputadoras y clústeres de GPU con numerosos SM. La escalabilidad transparente, que no requiere modificaciones en el código de la aplicación, facilita la adaptación de las aplicaciones existentes a hardware con diferentes configuraciones de GPU.

## Exponiendo el Paralelismo
Este apartado explica que el paralelismo dinámico permite la creación de nuevo trabajo directamente desde la GPU, lo que permite expresar algoritmos paralelos recursivos o dependientes de datos de una manera más natural y fácil de entender. El libro menciona que se debe prestar atención a la estrategia de lanzamiento de la malla secundaria, la sincronización entre padre e hijo y la profundidad de los niveles anidados al implementar un kernel anidado eficiente.

El paralelismo dinámico es una característica valiosa en la programación de CUDA que permite una mayor flexibilidad y eficiencia en la implementación de algoritmos paralelos. Sin embargo, su uso requiere una cuidadosa planificación y gestión de recursos para garantizar un rendimiento óptimo.

### Comprobación de Warps Activos con nvprof
Este apartado trata sobre el proceso de comprobar los warps activos utilizando nvprof, una herramienta de perfilado en la programación de CUDA. Se explica que los warps activos son los warps a los que se les han asignado recursos de cálculo y están listos para la ejecución. 

El libro proporciona ejemplos de diferentes configuraciones de bloques de hilos y sus valores de ocupación correspondientes, que indican la proporción de warps activos con respecto al número máximo de warps admitidos en un multiprocesador de transmisión (SM). 

Alcanzar una mayor ocupación no siempre garantiza un mejor rendimiento y que otros factores pueden restringir el rendimiento.

### Comprobación de Operaciones de Memoria con nvprof
**Métricas de Eficiencia de Memoria:**

-   "gld_throughput" mide el rendimiento de las operaciones de lectura global de memoria, lo que proporciona información sobre qué tan rápido se pueden leer datos desde la memoria global.
-   "gld_efficiency" mide la eficiencia de las operaciones de lectura global de memoria, lo que indica qué proporción de tiempo se está utilizando eficazmente para lecturas de memoria global.

**Importancia de la Eficiencia de Carga:**

La eficiencia de carga es un factor crítico en el rendimiento de aplicaciones de CUDA, ya que las operaciones de lectura y escritura de memoria son fundamentales en muchos algoritmos paralelos. La ineficiencia en las operaciones de memoria puede ser un cuello de botella importante, por lo que es esencial medir y optimizar la eficiencia de carga.

La comprobación de operaciones de memoria y la eficiencia de carga son pasos esenciales en la optimización del rendimiento en programas de CUDA. Identificar áreas de ineficiencia y abordarlas puede resultar en un rendimiento significativamente mejorado en aplicaciones paralelas.

### Exponiendo más Paralelismo
Este apartado explica que el paralelismo dinámico permite la creación de nuevo trabajo directamente desde la GPU, lo que facilita la expresión de algoritmos paralelos recursivos o dependientes de datos de una manera más natural y comprensible. 

Al utilizar el paralelismo dinámico, la decisión de cuántos bloques y mallas crear en la GPU se puede posponer hasta el tiempo de ejecución, lo que permite una mejor utilización de los planificadores de hardware de la GPU y los balanceadores de carga. Esto puede llevar a un mejor rendimiento y una mayor adaptabilidad en respuesta a decisiones impulsadas por los datos o cargas de trabajo.

El libro también menciona que la capacidad de crear trabajo directamente desde la GPU reduce la necesidad de transferir el control de ejecución y los datos entre el host y el dispositivo.

## Evitar la Divergencia de Ramas
La divergencia de ramas se refiere a la situación en la que los hilos dentro de un warp siguen diferentes caminos de código. Cuando los hilos en un warp divergen, el warp ejecuta secuencialmente cada camino de la rama, deshabilitando los hilos que no toman ese camino. Esto puede resultar en un rendimiento degradado, ya que se reduce la cantidad de paralelismo dentro del warp.

**Consideraciones en la Programación de CUDA:**

-   Evitar estructuras condicionales complejas que generen divergencia de ramas.
-   Considerar la reorganización del código para que los hilos dentro de un warp sigan caminos de código similares.
-   Utilizar estrategias de programación que reduzcan la divergencia de ramas, como la paralelización de tareas independientes en lugar de depender de estructuras condicionales complejas.

### El Problema de Reducción Paralela
El problema de reducción paralela implica calcular la suma de un conjunto de enteros en paralelo. En lugar de sumar secuencialmente cada elemento, el conjunto se puede dividir en fragmentos más pequeños y cada hilo puede calcular la suma parcial de su fragmento. Los resultados parciales de cada fragmento se suman luego para obtener la suma final. Este enfoque aprovecha las propiedades asociativas y conmutativas de la suma para realizar una adición paralela de manera eficiente.

### Divergencia en la Reducción Paralela
La divergencia se refiere a la situación en la que los hilos dentro de un warp siguen diferentes caminos de ejecución. Esto puede ocurrir cuando hay ejecución condicional dentro de un warp, lo que conduce a un mal rendimiento del kernel. 

Para evitar la divergencia, se pueden utilizar técnicas como la reorganización de patrones de acceso a datos. Un enfoque es la implementación de pares vecinos, donde cada hilo suma dos elementos adyacentes para producir una suma parcial. 

Otro enfoque es la implementación de pares entrelazados, donde los elementos emparejados están separados por una determinada longitud de paso. Estas técnicas ayudan a reducir o eliminar la divergencia de warps y mejoran el rendimiento de los kernels de reducción paralela.

### Mejorando la Divergencia en la Reducción Paralela
Para mejorar la divergencia, el índice del conjunto de datos al que accede cada hilo puede ser reorganizado de manera que los hilos vecinos realicen la operación de suma. Esto reduce la divergencia y mejora la eficiencia del algoritmo de reducción paralela. 

La implementación implica establecer el índice de acceso al conjunto de datos para cada hilo y utilizar estructuras condicionales para garantizar que solo ciertos hilos realicen la operación de suma. Al reducir la divergencia, el algoritmo de reducción paralela puede lograr un mejor rendimiento.

### Reducción con Pares Entrelazados
La reducción con pares entrelazados implica agrupar elementos en un cierto paso o longitud de salto. Esta implementación permite que un hilo tome dos elementos adyacentes y produzca una suma parcial en cada paso. 

Para un conjunto de datos con N elementos, este enfoque requiere N - 1 sumas y log2N pasos. Las entradas para un hilo en esta implementación se escalonan a la mitad de la longitud de la entrada en cada paso.

La reducción con pares entrelazados es una técnica eficiente para reducir elementos de datos en programación de CUDA. Aprovecha el paralelismo al tomar dos elementos adyacentes en cada paso y ofrece un rendimiento mejorado en operaciones de reducción de conjuntos de datos.

## Desenrollando Bucles
El desenrollado de bucles es una técnica utilizada para mejorar el rendimiento de los bucles en la programación de CUDA. Implica replicar el cuerpo del bucle varias veces, reduciendo el número de iteraciones y mejorando el rendimiento de las instrucciones. El desenrollado de bucles puede ser efectivo para bucles de procesamiento de matrices secuenciales donde el número de iteraciones se conoce antes de la ejecución.

### Reducción con Desenrollado
**El Desenrollado de Bucles en Programación de CUDA:**

En el contexto de la programación de CUDA, el desenrollado de bucles se utiliza para mejorar el rendimiento al reducir los costos de instrucciones y crear más instrucciones independientes para programar. Conduciendo a una mayor saturación de instrucciones y ancho de banda de memoria, lo que resulta en más operaciones concurrentes y un mejor rendimiento. 

El desenrollado se puede realizar de diferentes maneras, como el desenrollado de dos bloques de datos por un solo bloque de hilos o el desenrollado de warps. La elección de la técnica de desenrollado depende de los requisitos específicos de la aplicación.

### Reducción con Warps Desenrollados
**Desenrollado de Warps:**

La técnica de desenrollado de warps implica desenrollar las últimas iteraciones de un bucle de reducción. Esto significa que en lugar de ejecutar las últimas iteraciones del bucle de manera tradicional, se escriben explícitamente como instrucciones independientes. Al hacerlo, se evita la ejecución de la lógica de control del bucle y la sincronización de hilos para esas iteraciones, lo que puede llevar a una reducción significativa de la latencia y las paradas.

**Beneficios del Desenrollado de Warps:**

El desenrollado de warps puede tener varios beneficios. Al evitar la sincronización y la lógica de control del bucle en las últimas iteraciones, se reduce la latencia y se mejora la eficiencia de la ejecución del núcleo de reducción. Esto puede resultar en un mayor rendimiento y una mayor saturación del ancho de banda de instrucciones y memoria. Además, el código generado puede ser más eficiente y reducir el uso de recursos de hardware.

### Reducción con Desenrollado Completo
**Optimización de Bucles con Desenrollado Completo:**

El desenrollado completo es una técnica que se aplica a bucles donde el número de iteraciones es conocido antes de la ejecución. En lugar de mantener un bucle que verifica la condición de terminación en cada iteración, el bucle se desenrolla completamente, lo que significa que el cuerpo del bucle se replica tantas veces como iteraciones haya. Esto reduce la sobrecarga de instrucciones y permite que las operaciones de memoria se emitan de manera más eficiente.

**Ventajas del Desenrollado Completo:**

El desenrollado completo ofrece varias ventajas en términos de rendimiento. Al reducir la cantidad de veces que se verifica la condición del bucle, se disminuye la sobrecarga de instrucciones, lo que puede resultar en una ejecución más eficiente. Además, dado que las operaciones de memoria dentro de cada iteración se pueden emitir simultáneamente, se aprovecha al máximo el ancho de banda de memoria y se obtiene un rendimiento superior.

###  Reducción con Funciones de Plantilla
Las funciones de plantilla son una característica útil en CUDA para reducir aún más la sobrecarga de ramas en núcleos de reducción paralela. La principal ventaja de las funciones de plantilla es que permiten que el tamaño del bloque se especifique como un parámetro, lo que facilita la adaptación del núcleo a diferentes configuraciones de bloque. Esto es especialmente útil cuando se busca optimizar el rendimiento para diferentes tamaños de bloque sin necesidad de escribir múltiples versiones del núcleo.

**Implementación en CUDA:**

En el contexto de la programación de CUDA, las funciones de plantilla se pueden utilizar para implementar núcleos de reducción paralela con un desenrollado completo del bucle. El tamaño del bloque se especifica como un parámetro de la función de plantilla, lo que permite una adaptación sencilla a diferentes configuraciones de bloque.

## Paralelismo Dinámico
El Paralelismo Dinámico es una característica introducida en CUDA que permite a la GPU lanzar nuevas mallas de manera dinámica. Esto permite que la GPU lance núcleos anidados, eliminando la necesidad de comunicación con la CPU. Con el paralelismo dinámico, cualquier núcleo puede lanzar otro núcleo y gestionar cualquier dependencia entre núcleos necesaria para realizar trabajo adicional.

### Ejecución Anidada
La ejecución anidada se refiere a la capacidad de crear nuevo trabajo directamente desde el dispositivo, lo que permite expresar algoritmos paralelos recursivos o dependientes de datos de una manera más natural y fácil de entender. Involucra el lanzamiento de mallas secundarias desde dentro de un núcleo, lo que puede tener múltiples niveles de anidación. La profundidad de los niveles anidados y la estrategia para lanzar mallas secundarias son consideraciones importantes para implementar núcleos anidados de manera eficiente.

### Ejemplo "Hola Mundo" Anidado en la GPU

En esta sección se crea un núcleo para imprimir "Hola Mundo" utilizando una ejecución anidada y recursiva. La malla principal se invoca desde el host con 8 hilos en un único bloque de hilos. El hilo 0 en la malla principal luego invoca una malla secundaria con la mitad de hilos. Este proceso continúa de manera recursiva hasta que solo queda un hilo en la anidación final. Se muestra la salida del programa de kernel anidado, indicando la profundidad de la recursión y la ejecución de cada hilo y bloque.

El paralelismo dinámico es una característica avanzada en CUDA que permite la creación de estructuras de ejecución anidadas de manera eficiente. Este ejemplo de "Hola Mundo" anidado ilustra cómo se pueden crear tareas recursivas de manera eficaz y proporciona una base para comprender aplicaciones más complejas que aprovechan esta característica.

### **Reducción Anidada**
La reducción anidada es una técnica utilizada en la informática paralela para realizar una operación de reducción en una gran matriz de elementos de datos. Implica dividir el vector de entrada en fragmentos más pequeños y hacer que cada hilo calcule la suma parcial para su fragmento. Luego, se suman los resultados parciales de cada fragmento para obtener la suma final. 

Este enfoque reduce o evita la divergencia de los warps, que puede afectar negativamente el rendimiento del núcleo. Se pueden utilizar diferentes implementaciones de reducción anidada, como los enfoques de pares adyacentes e intercalados, según los requisitos específicos de la operación de reducción.

### Resumen del Capítulo 3

Bueno, en este capítulo hemos visto cómo funciona el modelo de ejecución de CUDA en los dispositivos GPU. Hay dos características clave que debemos tener en cuenta: los hilos se ejecutan en warps de manera SIMT (Single Instruction Multiple Thread), y los recursos de hardware se dividen entre bloques y hilos. Estas características nos permiten controlar cómo nuestra aplicación utiliza el ancho de banda de instrucciones y memoria para aumentar la paralelización y el rendimiento.

Es importante recordar que los diferentes dispositivos GPU tienen límites de hardware distintos, por lo que las heurísticas de grillas y bloques son fundamentales para optimizar el rendimiento de los núcleos. El paralelismo dinámico nos permite crear nuevo trabajo directamente desde el dispositivo, lo que facilita la expresión de algoritmos paralelos recursivos o dependientes de datos.

A la hora de implementar núcleos anidados eficientes, debemos prestar atención al tiempo de ejecución del dispositivo, incluyendo la estrategia de lanzamiento de grillas secundarias, la sincronización entre grillas padre e hijo y la profundidad de los niveles anidados.

He aprendido cómo analizar el rendimiento de los núcleos utilizando la herramienta de perfilado de línea de comandos, nvprof. El perfilado es crucial en la programación de CUDA para identificar cuellos de rendimiento y optimizar el comportamiento de los núcleos.

# CAPÍTULO 4: MEMORIA GLOBAL

## Introducción al modelo de memoria de CUDA
El modelo de memoria de CUDA es un aspecto fundamental de la programación con CUDA. Unifica los sistemas de memoria separados del host y el dispositivo, y expone toda la jerarquía de memoria, lo que permite a los programadores controlar explícitamente la ubicación de los datos para lograr un rendimiento óptimo.

Consta de diferentes tipos de memoria, incluida la memoria global, la memoria compartida y la memoria local. Cada tipo de memoria tiene sus propias características y se utiliza de manera específica en función de los requisitos de la aplicación.


### Beneficios de una Jerarquía de Memoria
En general, las aplicaciones no acceden a datos arbitrarios o ejecutan código arbitrario en cualquier momento. En su lugar, las aplicaciones suelen seguir el principio de localidad, que sugiere que acceden a una porción relativamente pequeña y localizada de su espacio de direcciones en cualquier momento. Hay dos tipos diferentes de localidad:

-   Localidad temporal (localidad en el tiempo)
-   Localidad espacial (localidad en el espacio)

La **localidad temporal** asume que si se referencia una ubicación de datos, es más probable que se vuelva a referenciar dentro de un corto período de tiempo y menos probable que se referencie a medida que pasa más tiempo.

La **localidad espacial** asume que si se referencia una ubicación de memoria, es probable que se referencien ubicaciones cercanas.

Tanto las GPU como las CPU utilizan principios y modelos similares en el diseño de la jerarquía de memoria. La diferencia clave entre los modelos de memoria de GPU y CPU es que el modelo de programación CUDA expone más de la jerarquía de memoria y le brinda un control más explícito sobre su comportamiento.

En resumen, la jerarquía de memoria es esencial para aprovechar la localidad de datos y optimizar el rendimiento. Tanto las GPU como las CPU utilizan jerarquías de memoria para aprovechar el principio de localidad y proporcionar acceso rápido a los datos que se utilizan con más frecuencia, mientras que se almacenan datos menos utilizados en niveles de memoria con mayor latencia y mayor capacidad. La programación CUDA ofrece un mayor control sobre esta jerarquía de memoria, lo que permite una optimización más precisa del rendimiento.

### El modelo de memoria de CUDA
En el mundo de la programación con CUDA, los programadores suelen encontrarse con dos clasificaciones generales de memoria:

1.  **Memoria programable:** En esta categoría, tienes un control explícito sobre qué datos se almacenan en la memoria programable.
    
2.  **Memoria no programable:** En este caso, no tienes control sobre la ubicación de los datos y dependes de técnicas automáticas para lograr un buen rendimiento.

En la jerarquía de memoria de una CPU, ejemplos de memoria no programable son la memoria caché L1 y la memoria caché L2. Por otro lado, el modelo de memoria de CUDA expone muchos tipos de memoria programable, como registros, memoria compartida, memoria local, memoria constante, memoria de textura y memoria global.

## Gestión de memoria
El modelo de memoria de CUDA ofrece una jerarquía de memoria unificada que permite un control explícito sobre la ubicación de los datos para lograr un rendimiento óptimo. La gestión de la memoria desempeña un papel crucial en la informática de alto rendimiento en los aceleradores modernos.

La jerarquía de memoria consta de sistemas de memoria separados para el host y el dispositivo, y el modelo de memoria de CUDA expone esta jerarquía al programador.

### Asignación y Liberación de Memoria

El modelo de programación de CUDA supone un sistema heterogéneo que consta de un host y un dispositivo, cada uno con su propio espacio de memoria separado. 

Las funciones del kernel operan en el espacio de memoria del dispositivo, y el tiempo de ejecución de CUDA proporciona funciones para asignar y liberar memoria del dispositivo.

La asignación y liberación de memoria del dispositivo son operaciones costosas, por lo que la memoria del dispositivo debe ser reutilizada por las aplicaciones siempre que sea posible para minimizar el impacto en el rendimiento general.

### Transferencia de Memoria
-   La función cudaMemcpy se utiliza para copiar datos entre la memoria del host y la memoria del dispositivo.
-   La dirección de la copia se especifica mediante el parámetro "kind", que puede tomar diferentes valores.
-   La transferencia de datos entre el host y el dispositivo debe ser gestionada cuidadosamente para minimizar el impacto en el rendimiento, ya que la velocidad de transferencia entre la CPU y la GPU a través del bus PCIe es mucho más lenta que la velocidad de transferencia dentro de la GPU.
### Memoria anclada
-   La memoria anclada es una forma de memoria del host que puede ser accedida directamente por el dispositivo, lo que la hace más adecuada para transferencias de datos de alto rendimiento.
-   La asignación de memoria anclada es más costosa que la memoria pageable, pero puede proporcionar un rendimiento superior en transferencias de datos grandes.
-   Deberías considerar la memoria anclada al realizar transferencias de datos entre el host y el dispositivo para optimizar el rendimiento de tu aplicación. La mejora en el rendimiento depende de la capacidad de cómputo del dispositivo y el tamaño de los datos transferidos.
### Memoria sin copia
La memoria sin copia es útil para compartir una pequeña cantidad de datos entre el host y el dispositivo, ya que simplifica la programación y ofrece un rendimiento razonable. 

Para conjuntos de datos más grandes en sistemas con GPU discretas conectadas a través del bus PCIe, la memoria sin copia no es una buena elección y puede causar una degradación significativa del rendimiento.

Es importante sincronizar los accesos a la memoria compartida entre el host y el dispositivo para evitar problemas de datos causados por múltiples hilos que acceden a la misma ubicación de memoria sin sincronización.

### Direccionamiento Virtual Unificado
Los dispositivos con capacidad de cómputo 2.0 y posteriores admiten un modo de direccionamiento especial llamado Direccionamiento Virtual Unificado (UVA). UVA, introducido en CUDA 4.0, es compatible con sistemas Linux de 64 bits. Con UVA, la memoria del host y la memoria del dispositivo comparten un espacio de direcciones virtuales único.

Antes de UVA, era necesario administrar qué punteros se referían a la memoria del host y cuáles a la memoria del dispositivo. Con UVA, el espacio de memoria al que se hace referencia mediante un puntero se vuelve transparente para el código de la aplicación.

### Memoria Unificada
Con CUDA 6.0 se introdujo una nueva característica llamada Memoria Unificada para simplificar la gestión de memoria en el modelo de programación CUDA. La Memoria Unificada crea un conjunto de memoria gestionada, donde cada asignación de este conjunto de memoria es accesible tanto en la CPU como en la GPU con la misma dirección de memoria (es decir, puntero). El sistema subyacente migra automáticamente los datos en el espacio de memoria unificado entre el host y el dispositivo. Este movimiento de datos es transparente para la aplicación, lo que simplifica enormemente el código de la aplicación.

La Memoria Unificada ofrece un modelo de "un solo puntero a datos" que es conceptualmente similar a la memoria sin copia. Sin embargo, la memoria sin copia se asigna en la memoria del host y, como resultado, el rendimiento del kernel generalmente sufre debido a los accesos de alta latencia a la memoria sin copia a través del bus PCIe. La Memoria Unificada, por otro lado, desacopla los espacios de memoria y ejecución para que los datos se puedan migrar de manera transparente según sea necesario en el host o el dispositivo para mejorar la localidad y el rendimiento.

## Patrones de Acceso a la Memoria
La optimización de los patrones de acceso a la memoria es crucial para maximizar el rendimiento de la memoria global y mejorar el rendimiento del kernel. Los accesos a la memoria alineados y cohesionados son preferidos, especialmente para las lecturas almacenadas en caché y las escrituras en la memoria global, ya que minimizan el ancho de banda desperdiciado y maximizan la utilización del bus.

### Acceso Alineado y Coalescido
Hay dos características de los accesos a la memoria del dispositivo a las que debes aspirar al optimizar tu aplicación:

-   Accesos a memoria alineados
-   Accesos a memoria coalescidos

Los accesos a memoria alineados ocurren cuando la primera dirección de una transacción de memoria del dispositivo es un múltiplo par de la granularidad de la caché que se utiliza para atender la transacción (ya sea 32 bytes para la caché L2 o 128 bytes para la caché L1). Realizar una carga desalineada provocará un ancho de banda desperdiciado.

Los accesos a memoria coalescidos ocurren cuando los 32 hilos en un warp acceden a un trozo contiguo de memoria.

Los accesos a memoria alineados y coalescidos son ideales: un warp que accede a un trozo contiguo de memoria que comienza en una dirección de memoria alineada. Para maximizar el rendimiento de la memoria global, es importante organizar las operaciones de memoria para que sean tanto alineadas como coalescidas.

### Lecturas de Memoria Global
En un SM (Streaming Multiprocessor), los datos se canalizan a través de uno de los siguientes tres caminos de caché/buffer, dependiendo del tipo de memoria del dispositivo a la que se hace referencia:

-   Caché L1/L2
-   Caché constante
-   Caché de solo lectura
El camino predeterminado es el de la caché L1/L2. Para que los datos pasen a través de los otros dos caminos, se requiere una gestión explícita por parte de la aplicación, pero esto puede mejorar el rendimiento según los patrones de acceso utilizados. Si las operaciones de carga de memoria global pasan por la caché L1 depende de dos factores:

-   Capacidad de cómputo del dispositivo.
-   Opciones del compilador.

### Escrituras en Memoria Global
Las operaciones de almacenamiento en memoria son relativamente simples. La caché L1 no se utiliza para operaciones de escritura en las GPU Fermi o Kepler; las operaciones de escritura solo se almacenan en la caché L2 antes de enviarse a la memoria del dispositivo. Las escrituras se realizan en una granularidad de segmentos de 32 bytes. Las transacciones de memoria pueden ser de uno, dos o cuatro segmentos a la vez. 

Por ejemplo, si dos direcciones caen dentro de la misma región de 128 bytes pero no dentro de una región alineada de 64 bytes, se emitirá una transacción de cuatro segmentos (es decir, emitir una única transacción de cuatro segmentos es más eficiente que emitir dos transacciones de un solo segmento).

### Array of Structures (AoS) frente a Structure of Arrays (SoA)
Almacenar los datos en formato SoA aprovecha al máximo el ancho de banda de memoria de la GPU. Dado que no hay entrelazado de elementos del mismo campo, el diseño SoA en la GPU proporciona accesos de memoria coalescentes y puede lograr una utilización más eficiente de la memoria global.

En resumen, se comparan las estructuras de datos AoS y SoA y se muestra cómo pueden afectar el rendimiento y la eficiencia de la memoria global en programación paralela, especialmente en CUDA. Se muestran ejemplos de kernels implementados en ambos enfoques, y se analiza su rendimiento y eficiencia en el acceso a la memoria global.

### Afinamiento del rendimiento
Existen dos objetivos a los que se debe aspirar al optimizar la utilización del ancho de banda de memoria del dispositivo:

-   Accesos de memoria alineados y cohesionados que reduzcan el ancho de banda desperdiciado.
-   Suficientes operaciones de memoria concurrentes para ocultar la latencia de memoria.

La clave para optimizar el rendimiento en términos de ancho de banda de memoria es asegurarse de que los patrones de acceso a la memoria estén alineados y coherentes, y exponer suficiente paralelismo en el acceso a la memoria mediante el desenrollado de bucles y la configuración de ejecución del kernel.

## ¿Qué ancho de banda puede lograr un kernel?
Esta sección proporciona información sobre los factores que afectan el rendimiento de un kernel, como la latencia de memoria, el ancho de banda de memoria, el tamaño del bloque y diferentes técnicas de transposición. Enfatiza la importancia de optimizar estos factores para lograr el mejor ancho de banda posible para un kernel.

La latencia y el ancho de banda de la memoria son factores críticos en el rendimiento de los kernels, y optimizarlos puede marcar una gran diferencia en la velocidad de procesamiento de las aplicaciones de GPU. Por lo tanto, entender cómo afectan estos factores y cómo abordarlos de manera efectiva es esencial para desarrolladores y programadores que trabajan con GPUs.

### Ancho de banda de memoria
La mayoría de los kernels son muy sensibles al ancho de banda de memoria, es decir, están limitados por el ancho de banda de memoria. Como resultado, a menudo es importante centrarse en las métricas de ancho de banda de memoria al ajustar los kernels. 

El ancho de banda puede verse afectado de manera dramática por la disposición de los datos en la memoria global y la forma en que esos datos son accedidos por un warp. 

Hay dos tipos de ancho de banda:

-   Ancho de banda teórico: es el ancho de banda máximo absoluto alcanzable con el hardware disponible
-   Ancho de banda efectivo: es el ancho de banda medido que un kernel realmente logra y se calcula mediante la siguiente ecuación: ancho de banda efectivo (GB/s) = (bytes leídos + bytes escritos) × 10^9 / tiempo transcurrido


Optimizar el ancho de banda efectivo es esencial para aprovechar al máximo el rendimiento de la GPU.

### Transposición de matrices
La seccion trata sobre la optimización de la transposición de matrices en GPUs mediante diferentes técnicas y enfoques para mejorar el rendimiento y la eficiencia del ancho de banda de la memoria, mostrando codigos al respecto.

### Resumen del capítulo 4

En este capítulo, se explorao el manejo de la memoria global en CUDA y cómo optimizar su uso para obtener un mejor rendimiento. La memoria global es muy importante en programación en paralelo, pero su acceso eficiente es aun mas importanto. Se mostro la manera de maximizar la cantidad de accesos de memoria concurrentes y a optimizar los patrones de acceso a memoria para mejorar el ancho de banda y la eficiencia.

Además, se vio cómo la Memoria Unificada en CUDA 6.0 simplifica la programación al eliminar la necesidad de copiar explícitamente datos entre el host y el dispositivo. Si bien prioriza la coherencia sobre el rendimiento, es una herramienta valiosa para simplificar el desarrollo de aplicaciones en CUDA.

La programación en GPU sigue siendo un campo muy importante y en constante evolución, comprender cómo manejar la memoria de manera eficiente es clave para aprovechar al máximo el rendimiento de las GPU.


### Referencias 

> J. Cheng, M. Grossman, T. McKercher, and B. Chapman, _Professional CUDA C Programming_. 2014. [Online]. Available: http://hgpu.org/?p=12757



