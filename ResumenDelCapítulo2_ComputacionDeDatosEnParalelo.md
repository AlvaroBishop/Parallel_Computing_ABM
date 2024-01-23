
# Resumen del Capítulo 2: Computación de datos en paralelo

## Introducción 

**Paralelismo de datos:** El paralelismo de datos es un concepto en la computación paralela que consiste en organizar y expresar la computación masivamente paralela en función de los datos que se procesan. Es particularmente útil cuando se trata de grandes cantidades de datos, como la manipulación de imágenes o vídeos con millones o billones de píxeles, el modelado de la dinámica de fluidos utilizando miles de millones de celdas de cuadrícula o la simulación de interacciones entre miles o millones de átomos. La idea detrás del paralelismo de datos es dividir la computación en tareas más pequeñas e independientes que pueden ejecutarse en paralelo, lo que resulta en un procesamiento general más rápido. Este enfoque permite la utilización eficiente de procesadores masivamente paralelos y puede mejorar significativamente el rendimiento de las aplicaciones.

**Estructura del programa CUDA C:** En la programación CUDA C, la estructura de un programa refleja la coexistencia de un host (CPU) y uno o más dispositivos (GPUs) en el ordenador. Por defecto, cualquier programa C tradicional es un programa CUDA que sólo contiene código del host. Sin embargo, se pueden añadir funciones y declaraciones de datos del dispositivo a cualquier archivo fuente.

La estructura del programa CUDA C permite la inclusión de código del host y del dispositivo en el mismo archivo fuente. Las funciones y declaraciones de datos del dispositivo se marcan con palabras clave especiales de CUDA C, lo que indica que presentan una gran cantidad de paralelismo de datos.

Esta estructura permite al programador aprovechar las capacidades de procesamiento paralelo de las GPUs descargando cálculos específicos en el dispositivo. El código del host se ejecuta en la CPU, mientras que el código del dispositivo se ejecuta en la GPU. El compilador de CUDA, NVCC, procesa el programa CUDA C, reconociendo y comprendiendo las declaraciones adicionales, y compila el código en consecuencia.

En general, la estructura del programa CUDA C facilita la utilización del paralelismo de datos para una ejecución más rápida aprovechando la potencia de las GPUs junto con el procesamiento tradicional de la CPU.

## Resumen

### Paralelismo de datos:

En la programación paralela, existen dos tipos principales de paralelismo: el paralelismo de tareas y el paralelismo de datos. El paralelismo de tareas implica descomponer una aplicación en tareas independientes que pueden ejecutarse de forma concurrente. Por ejemplo, una aplicación sencilla podría tener tareas como la suma de vectores o la multiplicación de matrices por vectores. El paralelismo de datos, por otro lado, implica dividir un conjunto de datos grande en fragmentos más pequeños y procesarlos en paralelo. Es la principal fuente de escalabilidad para los programas paralelos, ya que permite la utilización de procesadores masivamente paralelos. Aunque el paralelismo de datos es más común, el paralelismo de tareas también puede ser importante para alcanzar los objetivos de rendimiento, especialmente en aplicaciones grandes con un mayor número de tareas.

**Representación RGB y conversión a escala de grises:**

En una representación RGB, cada píxel de una imagen se almacena como una tupla de valores (r, g, b). Los valores de r, g y b representan la intensidad de las fuentes de luz roja, verde y azul cuando se renderiza el píxel. Los valores de intensidad van de 0 (oscuro) a 1 (intensidad total). El formato de una fila de una imagen es (r g b) (r g b) (r g b), y cada tupla especifica una mezcla de rojo, verde y azul. Las combinaciones reales de estos colores pueden variar en función del espacio de color utilizado. En el espacio de color AdobeRGB, las combinaciones válidas se muestran como el interior de un triángulo, con los coeficientes de mezcla (x, y, 1 - y - x) que indican la fracción de intensidad del píxel asignada a cada color.

Para convertir una imagen en color a escala de grises, se calcula el valor de luminancia (L) de cada píxel mediante una fórmula de suma ponderada. La fórmula es L = 0,21 * r + 0,72 * g + 0,07 * b, donde r, g y b representan los valores rojo, verde y azul del píxel, respectivamente.

**Estructura de la computación:**

La imagen de entrada se organiza como una matriz (I) de valores RGB, y la salida es una matriz correspondiente (O) de valores de luminancia. La estructura de la computación es simple: cada píxel de salida (O[i]) se genera calculando la suma ponderada de los valores RGB del píxel de entrada correspondiente (I[i]). Estas computaciones se realizan de forma independiente para cada píxel, sin que haya dependencias entre ellos.

**Paralelismo de datos:**

El proceso de conversión de color a escala de grises presenta una gran cantidad de paralelismo de datos. La computación de cada píxel puede realizarse de forma independiente a la de los demás, lo que permite una ejecución paralela. Este paralelismo puede acelerar significativamente el proceso de conversión global. Sin embargo, es importante tener en cuenta que el paralelismo de datos en aplicaciones completas puede ser más complejo, y este libro se centra en enseñar el "pensamiento paralelo" necesario para identificar y explotar el paralelismo de datos de forma efectiva.

### Estructura del programa CUDA C:

**Compilación y ejecución:**

-   Una vez que se añaden funciones y declaraciones de datos de dispositivos a un archivo fuente, no puede ser compilado por un compilador C tradicional. En su lugar, debe ser compilado por un compilador CUDA C llamado NVCC, que reconoce y entiende estas declaraciones adicionales.
-   El compilador NVCC procesa un programa CUDA C utilizando palabras clave CUDA para separar el código del host (código ANSI C) y el código del dispositivo.
-   El código del host se compila con los compiladores C/C++ estándar del host y se ejecuta como un proceso tradicional de la CPU.
-   El código del dispositivo, marcado con palabras clave CUDA, es compilado por el componente de tiempo de ejecución de NVCC y ejecutado en un dispositivo GPU.
-   En algunos casos, si no hay un dispositivo de hardware disponible o un kernel puede ser ejecutado apropiadamente en una CPU, el kernel también puede ser ejecutado en una CPU utilizando herramientas como MCUDA.
-   La ejecución de un programa CUDA comienza con el código del host y cuando se llama a una función de kernel, esta es ejecutada por múltiples hilos en un dispositivo.
-   Estos hilos se denominan colectivamente cuadrícula y son el principal vehículo de ejecución paralela en una plataforma CUDA.
-   Después de la ejecución del kernel, la cuadrícula termina y la ejecución continúa en el host hasta que se lanza otro kernel.
-   Es importante tener en cuenta que la figura dada (Fig. 2.4) muestra un modelo simplificado en el que la ejecución de la CPU y la GPU no se solapan, pero en realidad, muchas aplicaciones de computación heterogénea gestionan la ejecución solapada de la CPU y la GPU para aprovechar ambas.

**Lanzamiento de kernels y paralelismo de datos:**

-   El lanzamiento de un kernel suele generar un gran número de hilos para explotar el paralelismo de datos. Esto significa que cuando se lanza un kernel en CUDA, crea múltiples hilos que pueden procesar diferentes partes de los datos en paralelo.
-   En el ejemplo de la conversión de color a escala de grises, cada hilo podría utilizarse para calcular un píxel de la matriz de salida O.
-   El número de hilos que generará el kernel es igual al número de píxeles de la imagen.
-   Para imágenes grandes, se generará un gran número de hilos.
-   En la práctica, cada hilo puede procesar múltiples píxeles para mayor eficiencia.
-   Los programadores de CUDA pueden asumir que estos hilos tardan muy pocos ciclos de reloj en generarse y programarse debido al eficiente soporte del hardware. Esto contrasta con los hilos tradicionales de la CPU, que suelen tardar miles de ciclos de reloj en generarse y programarse.

### Un núcleo de adición de vectores:

**Concepto de adición de vectores:**

-   La adición de vectores se considera la forma más simple de computación en paralelo de datos, similar al programa "Hola Mundo" en la programación secuencial.

**Estructura de la función vecAdd en la programación secuencial:**

-   El código del host, que es el programa C tradicional, consiste en una función principal y una función de adición de vectores llamada  `vecAdd`.
-   En los ejemplos proporcionados, las variables procesadas por el host tienen el prefijo "h_" para distinguirlas de las variables procesadas por el dispositivo.
-   La función  `vecAdd`  utiliza un bucle  `for`  para iterar a través de los elementos del vector.
-   Cada iteración calcula la suma de los elementos correspondientes de dos vectores de entrada y almacena el resultado en el vector de salida.
-   La longitud de los vectores está controlada por el parámetro  `vector_length`, y la función utiliza la pasada por referencia para leer los elementos de entrada y escribir el resultado.

**Modificación de la función vecAdd para la ejecución en paralelo:**

-   Para ejecutar la adición de vectores en paralelo, la función  `vecAdd`  se modifica y sus cálculos se trasladan a un dispositivo (GPU).
-   La función  `vecAdd`  modificada, que se muestra en la Figura 2.6, incluye tres partes:
    1.  **Asignación de memoria y transferencia de datos:**
        -   Se asigna espacio en la memoria del dispositivo para almacenar copias de los vectores A, B y C.
        -   Se copian los vectores desde la memoria del host a la memoria del dispositivo.
    2.  **Lanzamiento del kernel:**
        -   Se lanza la ejecución paralela del kernel de adición de vectores en el dispositivo.
    3.  **Recuperación de resultados y liberación de memoria:**
        -   Se copia el vector suma C desde la memoria del dispositivo a la memoria del host.
        -   Se liberan los vectores en la memoria del dispositivo.

**Resumen:**

-   La función  `vecAdd`  modificada permite la ejecución paralela de la adición de vectores mediante la asignación de memoria del dispositivo, la transferencia de datos entre la memoria del host y del dispositivo, y la realización del cálculo de la adición de vectores en el dispositivo.

**Consideraciones de eficiencia:**

-   La función  `vecAdd`  revisada actúa como un agente de externalización que se encarga de la transferencia de datos, el cálculo y la recopilación de resultados en un dispositivo.
-   Permite que el programa principal no sea consciente de que la adición de vectores se está realizando en un dispositivo.
-   Sin embargo, este modelo de externalización transparente puede ser ineficiente debido a la frecuente copia de datos entre el host y el dispositivo.
-   En la práctica, suele ser más eficiente mantener las estructuras de datos masivas importantes en el dispositivo e invocar las funciones del dispositivo desde el código del host.


### Memoria global del dispositivo y transferencia de datos:

**Memoria global del dispositivo:**

-   La memoria global del dispositivo se refiere a la memoria RAM dinámica (DRAM) presente en las tarjetas de hardware utilizadas en los sistemas CUDA, como la NVIDIA GTX1080.
-   Esta memoria global también se conoce como memoria del dispositivo.
-   Se utiliza para almacenar los datos que se necesitan para ejecutar los kernels en el dispositivo.

**Asignación y transferencia de datos:**

-   Para ejecutar un kernel en un dispositivo, el programador debe:
    1.  Asignar memoria global en el dispositivo.
    2.  Transferir los datos relevantes desde la memoria del host a la memoria del dispositivo asignada.
-   Esto se hace utilizando las funciones de la API de CUDA.
-   Después de la ejecución del dispositivo, el programador debe:
    1.  Transferir los datos de resultado desde la memoria del dispositivo a la memoria del host.
    2.  Liberar la memoria del dispositivo que ya no se necesita.

**Funciones de la API de CUDA:**

-   El sistema de tiempo de ejecución de CUDA proporciona funciones API como  `cudaMalloc`  y  `cudaFree`  para la asignación y liberación de memoria global del dispositivo.
-   `cudaMalloc`: Se utiliza para asignar memoria en el dispositivo.
-   `cudaFree`: Se utiliza para liberar la memoria asignada.

**Transferencia de datos:**

-   La transferencia de datos entre la memoria del host y la memoria del dispositivo se realiza utilizando la función  `cudaMemcpy`.
-   Esta función se utiliza para copiar datos desde la memoria del host a la memoria del dispositivo (`cudaMemcpyHostToDevice`) y desde la memoria del dispositivo a la memoria del host (`cudaMemcpyDeviceToHost`).
-   La función toma parámetros como el puntero de origen, el puntero de destino, el número de bytes a copiar y el tipo/dirección de la transferencia.

**Limitaciones:**

-   Es importante tener en cuenta que la función  `cudaMemcpy`  actualmente no puede utilizarse para copiar datos entre diferentes GPUs en sistemas multi-GPU.

**Resumen:**

-   La memoria global del dispositivo es la memoria del dispositivo utilizada para almacenar los datos necesarios para ejecutar los kernels.
-   La transferencia de datos entre la memoria del host y la memoria del dispositivo se realiza mediante la función  `cudaMemcpy`.
-   La asignación y liberación de memoria en el dispositivo se realiza mediante las funciones  `cudaMalloc`  y  `cudaFree`.


### Funciones de kernel y threading:

**Funciones de kernel:**

-   En CUDA, una función de kernel especifica el código que debe ser ejecutado por todos los hilos durante una fase paralela.
-   Todos los hilos ejecutan el mismo código en una función de kernel.
-   Las funciones de kernel se declaran con la palabra clave  `global`  y se ejecutan en el dispositivo.
-   Solo pueden ser llamadas desde el código del host, excepto en los sistemas CUDA que admiten el paralelismo dinámico.
-   Las funciones de kernel se utilizan para iniciar la ejecución paralela lanzándolas.
-   Explotan el paralelismo de datos creando muchos hilos para procesar diferentes partes de los datos en paralelo.

**Threading:**

-   Cuando se lanza un kernel, el sistema de tiempo de ejecución de CUDA genera una cuadrícula de hilos organizada en una jerarquía de dos niveles.
-   Cada cuadrícula se organiza como una matriz de bloques de hilos, también conocidos como bloques.
-   Todos los bloques de una cuadrícula tienen el mismo tamaño y pueden contener hasta 1024 hilos.
-   El número de hilos en un bloque se especifica en el código del host y puede variar para diferentes partes del código del host.
-   Los hilos se organizan en una matriz unidimensional, bidimensional o tridimensional en función de la dimensionalidad de los datos que se procesan.
-   La variable integrada  `blockDim`  ayuda a organizar los hilos en una matriz unidimensional, bidimensional o tridimensional.
-   La elección de la dimensionalidad para organizar los hilos suele reflejar la dimensionalidad de los datos que se procesan.

**Resumen:**

-   Las funciones de kernel en CUDA especifican el código que debe ser ejecutado por todos los hilos durante la ejecución paralela.
-   Los hilos se organizan en bloques, que forman parte de una cuadrícula.
-   El número de hilos en un bloque y la organización de los hilos reflejan la dimensionalidad de los datos que se procesan.
-   Las funciones de kernel se ejecutan en el dispositivo y solo pueden ser llamadas desde el código del host.
-   Explotan el paralelismo de datos creando muchos hilos para procesar diferentes partes de los datos en paralelo.

### Lanzamiento de kernels:

**Resumen del proceso de lanzamiento del kernel:**

1.  **Inicialización del lanzamiento del kernel:**  Cuando un programa CUDA inicia la ejecución paralela, lo hace mediante el lanzamiento de funciones de kernel.
2.  **Generación de la cuadrícula de hilos:**  El sistema de tiempo de ejecución de CUDA genera una cuadrícula de hilos que se organizan en una jerarquía de dos niveles.
3.  **Organización de bloques y hilos:**
    -   Cada cuadrícula se organiza como una matriz de bloques de hilos (bloques).
    -   Todos los bloques de una cuadrícula tienen el mismo tamaño y pueden contener hasta 1024 hilos.
    -   El número de hilos en cada bloque se especifica en el código del host cuando se lanza un kernel.
4.  **Dimensionalidad de los hilos:**  La elección de la dimensionalidad para organizar los hilos suele reflejar la dimensionalidad de los datos que se procesan.
5.  **Ejecución de hilos:**
    -   Los hilos dentro de un bloque pueden ejecutarse en cualquier orden arbitrario.
    -   La ejecución de cada hilo dentro de un bloque es secuencial.
6.  **Escalabilidad:**  La escalabilidad de los kernels CUDA en términos de velocidad de ejecución depende del hardware.

**Puntos clave:**

-   El lanzamiento del kernel permite la generación de una cuadrícula de hilos que procesan diferentes partes de los datos en paralelo.
-   La organización de los hilos refleja la organización de los datos.
-   Los programadores no deben hacer suposiciones sobre el orden de ejecución de los hilos dentro de un bloque.
-   El número de bloques de hilos utilizados depende de la longitud de los vectores que se procesan.
-   El mismo kernel puede lanzarse con diferentes números de hilos en diferentes partes del código del host.
-   La escalabilidad de los kernels CUDA depende del hardware disponible.

## Reflexión:

**Puntos clave aprendidos:**

-   **Paralelismo de datos:**  Es una estrategia fundamental para acelerar aplicaciones que manejan grandes cantidades de datos, dividiendo el trabajo en tareas independientes que se ejecutan en paralelo.
-   **Estructura del programa CUDA C:**  Combina código de host (CPU) y de dispositivo (GPU) para aprovechar la potencia de procesamiento paralela de las GPUs.
-   **Kernels de CUDA:**  Son funciones ejecutadas por múltiples hilos en paralelo, cada uno realizando un cálculo independiente.
-   **Memoria global del dispositivo:**  Es un espacio de memoria compartido entre el host y el dispositivo, utilizado para almacenar datos que deben ser accesibles por ambos.
-   **Lanzamiento de kernels:**  Es el proceso de iniciar la ejecución de un kernel en la GPU, especificando la cantidad de bloques de hilos y hilos por bloque.

**Reflexiones sobre la importancia del paralelismo de datos:**

-   El paralelismo de datos es esencial para acelerar tareas computacionales intensivas, especialmente en el ámbito de la ciencia, ingeniería, inteligencia artificial y gráficos.
-   Permite aprovechar la arquitectura paralela de las GPUs para obtener resultados más rápidos y eficientes.
-   Es fundamental comprender los conceptos de CUDA C para escribir programas paralelos efectivos y aprovechar al máximo las capacidades de las GPUs.

**Reflexiones sobre la estructura del programa CUDA C:**

-   La separación del código de host y dispositivo permite una clara organización del programa y facilita la gestión de la ejecución paralela.
-   Es importante comprender la interacción entre el host y el dispositivo para optimizar el rendimiento y evitar errores comunes.

**Reflexiones sobre los kernels y el lanzamiento de kernels:**

-   Los kernels son el núcleo de la ejecución paralela en CUDA, y su diseño adecuado es crucial para obtener un buen rendimiento.
-   El lanzamiento de kernels involucra decisiones importantes sobre la cantidad de bloques y hilos a utilizar, lo cual afecta directamente la eficiencia del programa.

**Interés en profundizar en CUDA C:**

-   El aprendizaje de CUDA C abre puertas a la creación de aplicaciones de alto rendimiento en diversos campos.
-   Es fundamental continuar explorando los conceptos avanzados de CUDA C para dominar la programación paralela en GPUs.

**Interés en los ejercicios:**

-   Los ejercicios son una excelente oportunidad para poner en práctica los conceptos aprendidos y consolidar el conocimiento.
-   La resolución de problemas prácticos ayuda a comprender mejor la programación paralela y las capacidades de CUDA C.