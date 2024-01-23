# Scalable Parallel Execution

Introducción
Este documento discute los conceptos de recursos, capacidades y ejecución paralela en el contexto de los sistemas informáticos. Proporciona ejemplos de la vida cotidiana, como servicios de hoteles y escenarios de oficinas de correos, para explicar estos conceptos. El documento también incluye ejercicios relacionados con bloques de subprocesos, dimensiones de cuadrícula y tolerancia de latencia. El propósito del documento es educar a los lectores sobre la importancia de comprender los recursos y capacidades en diversos entornos y cómo se relacionan con la ejecución paralela en sistemas informáticos.

Recursos y capacidades
En el contexto de los sistemas informáticos, los recursos son los elementos que permiten realizar tareas. Los recursos pueden ser físicos, como procesadores, memoria y almacenamiento, o lógicos, como software y datos. Las capacidades son las propiedades de los recursos que determinan cómo se pueden utilizar.

Por ejemplo, un procesador puede tener un número determinado de núcleos, cada uno de los cuales puede ejecutar instrucciones en paralelo. Esto significa que el procesador tiene una capacidad de paralelismo de un cierto número de núcleos.

Ejecución paralela
La ejecución paralela es la ejecución de tareas al mismo tiempo en diferentes recursos. La ejecución paralela puede mejorar el rendimiento de las tareas al reducir el tiempo total de ejecución.

La ejecución paralela se puede lograr de varias maneras, como la programación paralela, el procesamiento en paralelo y la computación en la nube.

## CUDA Thread Organization

CUDA es una API que permite a los desarrolladores programar aplicaciones para dispositivos de procesamiento gráfico (GPU). CUDA utiliza una jerarquía de dos niveles para organizar los subprocesos, con una cuadrícula que consta de uno o más bloques y cada bloque consta de uno o más subprocesos.

Cada subproceso tiene tres coordenadas: threadIdx.x, threadIdx.y y threadIdx.z. Estas coordenadas permiten que los subprocesos se distingan entre sí e identifiquen la porción de datos que necesitan procesar.

## Mapping Threads to Multidimensional Data

El mapeo de subprocesos a datos multidimensionales es el proceso de asignar subprocesos a porciones de datos multidimensionales. El mapeo adecuado de subprocesos a datos puede mejorar el rendimiento de las aplicaciones paralelas.

En el contexto del procesamiento de imágenes, una cuadrícula 2D con bloques 2D suele ser conveniente para procesar píxeles en una imagen. Por ejemplo, una imagen de 76x62 puede ser procesada por una cuadrícula de 5 bloques en la dirección x y 4 bloques en la dirección y. Cada bloque puede contener 16 hilos, lo que da un total de 400 subprocesos.

## Image Blur: Un kernel más complejo

En este capítulo, se analiza la organización de subprocesos dentro de un bloque en la programación CUDA. Cada subproceso tiene tres campos:

threadIdx.x: La coordenada x del subproceso dentro del bloque.
threadIdx.y: La coordenada y del subproceso dentro del bloque.
threadIdx.z: La coordenada z del subproceso dentro del bloque.
Los bloques dentro de una cuadrícula tienen las mismas dimensiones. Por ejemplo, un bloque de 4x2x2 contiene 16 subprocesos. Los dispositivos con una capacidad inferior a 2.0 permiten bloques de hasta 512 subprocesos.

## Sincronización y escalabilidad transparente

Los parámetros de configuración de ejecución del kernel definen las dimensiones de una cuadrícula y sus bloques. Las coordenadas únicas en blockIdx y threadIdx permiten que los subprocesos de una cuadrícula se identifiquen a sí mismos y a sus dominios de datos.

El programador es responsable de utilizar estas variables en las funciones del kernel para garantizar que los subprocesos puedan identificar correctamente la parte de los datos a procesar.

Los subprocesos en diferentes bloques no pueden sincronizarse entre sí. Esto permite una escalabilidad transparente de las aplicaciones CUDA. Para superar esta limitación, el método simple es terminar el kernel e iniciar un nuevo kernel para las actividades después del punto de sincronización.

Los subprocesos se asignan a Streaming Multiprocessors (SM) para su ejecución bloque por bloque. Cada dispositivo CUDA tiene limitaciones en la cantidad de bloques y subprocesos que sus SM pueden acomodar. Las limitaciones de recursos de cada dispositivo pueden convertirse en el factor limitante de un kernel.

## Resource Assignment

Se nos habla sobre lla consulta de propiedades del dispositivo en la programación CUDA. Explica que los dispositivos CUDA tienen recursos de ejecución organizados en Streaming Multiprocessors (SM) y se pueden asignar múltiples bloques de subprocesos a cada SM. El documento menciona que cada dispositivo CUDA establece un límite en la cantidad de bloques que se pueden asignar a cada SM. Si hay escasez de recursos necesarios para la ejecución simultánea de bloques, el tiempo de ejecución de CUDA reduce automáticamente la cantidad de bloques asignados a cada SM. El documento también menciona que la cantidad de bloques que se pueden ejecutar activamente en un dispositivo CUDA es limitada. El sistema de ejecución mantiene una lista de bloques que deben ejecutarse y asigna nuevos bloques a los SM a medida que los bloques previamente asignados completan la ejecución. Además, el documento analiza las limitaciones en la cantidad de subprocesos que los SM pueden rastrear y programar simultáneamente. Explica que se necesitan recursos de hardware para que los SM mantengan los índices de subprocesos y bloques y realicen un seguimiento de su estado de ejecución. El documento proporciona un ejemplo en el que se asignan tres bloques de subprocesos a cada SM. También menciona que la cantidad máxima de subprocesos permitidos en un bloque puede variar según el dispositivo, y la cantidad de SM y la frecuencia de reloj del dispositivo proporcionan una indicación de su capacidad de ejecución de hardware. Finalmente, el documento explica cómo consultar propiedades del dispositivo, como la cantidad máxima de subprocesos permitidos en un bloque, la cantidad de SM en el dispositivo y la frecuencia de reloj del dispositivo.

## Propiedades del dispositivo

En la programación CUDA, los dispositivos se organizan en Streaming Multiprocessors (SM). Cada dispositivo tiene un límite en la cantidad de bloques que se pueden asignar a cada SM.

Es importante consultar las propiedades del dispositivo antes de ejecutar un programa CUDA. Estas propiedades incluyen:

La cantidad máxima de subprocesos permitidos en un bloque
La cantidad de SM en el dispositivo
La frecuencia de reloj del dispositivo
El código host puede encontrar la cantidad máxima de subprocesos permitidos en cada dimensión de un bloque.

Al determinar las dimensiones de bloque más apropiadas para un rendimiento óptimo, se deben considerar las propiedades del dispositivo.

El sistema de tiempo de ejecución CUDA mantiene una lista de bloques que deben ejecutarse. A medida que los bloques previamente asignados completan la ejecución, el sistema de tiempo de ejecución asigna nuevos bloques a los SM.

## Programación de subprocesos y tolerancia a la latencia

La programación de subprocesos es un concepto de implementación que debe entenderse en el contexto de implementaciones de hardware específicas.

En la mayoría de las implementaciones de CUDA, un bloque asignado a un SM se divide en 32 unidades de subprocesos llamadas warps. El tamaño de las deformaciones es específico de la implementación y se puede obtener de la variable de consulta del dispositivo.

Las deformaciones son la unidad de programación de subprocesos en los SM. Los bloques se dividen en urdimbres y cada urdimbre consta de 32 hilos.

La tolerancia a la latencia se refiere a la capacidad de un programa de ocultar la latencia de los accesos a la memoria u otras operaciones superponiéndo las con otros cálculos.

Al ejecutar múltiples warps simultáneamente, el SM puede cambiar entre warps para ocultar la latencia de los accesos a la memoria y mejorar el rendimiento general.

## Conclusión

El texto "Ejecución paralela escalable" proporciona una introducción a los conceptos de recursos, capacidades y ejecución paralela en el contexto de los sistemas informáticos. Comienza definiendo los conceptos de recursos y capacidades, y luego discute cómo se relacionan con la ejecución paralela.

El texto luego proporciona una descripción general de la programación CUDA, una API que permite a los desarrolladores programar aplicaciones para dispositivos de procesamiento gráfico (GPU). CUDA utiliza una jerarquía de dos niveles para organizar los subprocesos, con una cuadrícula que consta de uno o más bloques y cada bloque consta de uno o más subprocesos.

Se analizan varios conceptos relacionados con la ejecución paralela en CUDA, incluidos el mapeo de subprocesos a datos multidimensionales, la sincronización y la escalabilidad transparente. También proporciona información sobre cómo consultar las propiedades del dispositivo en CUDA.

En general, el texto proporciona una descripción completa y exhaustiva de los conceptos de recursos, capacidades y ejecución paralela en el contexto de los sistemas informáticos. Es una valiosa referencia para cualquier persona que esté aprendiendo sobre programación paralela o que esté desarrollando aplicaciones para dispositivos CUDA.

Principales puntos:

- Los recursos son los elementos que permiten realizar tareas. Las capacidades son las propiedades de los recursos que determinan cómo se pueden utilizar.

- La ejecución paralela es la ejecución de tareas al mismo tiempo en diferentes recursos. La ejecución paralela puede mejorar el rendimiento de las tareas al reducir el tiempo total de ejecución.
- CUDA es una API que permite a los desarrolladores programar aplicaciones para dispositivos de procesamiento gráfico (GPU).
- CUDA utiliza una jerarquía de dos niveles para organizar los subprocesos, con una cuadrícula que consta de uno o más bloques y cada bloque consta de uno o más subprocesos.
- El mapeo de subprocesos a datos multidimensionales es el proceso de asignar subprocesos a porciones de datos multidimensionales.
- La sincronización es el proceso de coordinar la ejecución de subprocesos.
- La escalabilidad transparente es la capacidad de una aplicación de ejecutarse de manera eficiente en una variedad de dispositivos con diferentes capacidades.
- Las propiedades del dispositivo son las características de un dispositivo CUDA que afectan el rendimiento de las aplicaciones CUDA.
