# Resumen de la memoria compartida
Resumen del libro de programación CUDA C profesional de las páginas 216-232

## Visión general
En el documento, la sección "Comprobación del diseño de datos de la memoria compartida" analiza la disposición y la optimización de la memoria compartida en la programación CUDA. Cubre temas como el diseño de la memoria compartida, el acceso eficiente a la memoria compartida, la evitación de conflictos de bancos y la reducción de los accesos a la memoria global. El documento proporciona ejemplos y fragmentos de código para ilustrar estos conceptos.

El documento aborda la eficiencia en el diseño de kernels, focalizándose en la prevención de conflictos de bancos y la optimización del aprovechamiento de la memoria compartida. Se destaca el empleo de la memoria compartida cuadrada para almacenar datos globales en caché y el cálculo de desplazamientos de memoria 1D a partir de índices de subprocesos 2D. 

La asignación cuidadosa de subprocesos a los bancos de memoria compartida se presenta como crucial para maximizar el rendimiento. Además, se introduce el concepto de memoria compartida dinámica y su implementación en la programación CUDA. El documento proporciona ejemplos concretos de kernels que escriben en la memoria compartida en orden principal de filas y leen en orden principal de columnas, detallando el proceso de transposición de matrices utilizando la memoria compartida. 

Se realiza un análisis exhaustivo de las transacciones de memoria asociadas con estos kernels, incluyendo métricas como las transacciones de carga y almacenamiento compartidas por solicitud. En resumen, el documento ofrece una guía completa sobre la optimización de kernels, desde la organización de la memoria compartida hasta el manejo eficiente de transacciones de memoria en el contexto de programación CUDA.

## Comprobación del diseño de datos de la memoria compartida

En esta sección, el documento analiza el diseño de la memoria compartida y cómo se puede utilizar de manera eficiente. Explica que la memoria compartida se puede utilizar para almacenar datos globales con dimensiones cuadradas, lo que facilita el cálculo de desplazamientos de memoria 1D a partir de índices de subprocesos 2D. El documento proporciona una ilustración de un mosaico de memoria compartida con 32 elementos en cada dimensión, almacenados en orden principal de filas. También menciona la importancia de considerar cómo se asignan los subprocesos a los bancos de memoria compartida

### Memoria compartida cuadrada: : 
La memoria compartida cuadrada es una técnica de almacenamiento en caché que se utiliza para mejorar el rendimiento al reducir los accesos a la memoria global. Implica almacenar datos en una matriz compartida bidimensional con dimensiones cuadradas. Los datos son accedidos por subprocesos vecinos en la dimensión x o y. 

Al utilizar la memoria compartida, se puede reducir el número de transacciones de memoria global, lo que resulta en una mejor utilización del ancho de banda y una menor latencia de memoria general. El relleno de la matriz de memoria compartida puede eliminar aún más los conflictos de bancos, lo que optimiza el rendimiento.

### Memoria compartida rectangular:
La memoria compartida rectangular es un caso más general de memoria compartida 2D, donde el número de filas y columnas en una matriz no son iguales. Permite una mayor flexibilidad en el almacenamiento y acceso a datos en memoria compartida. 

En el documento dado, hay ejemplos de kernels que utilizan matrices de memoria compartida rectangulares con diferentes dimensiones. Las dimensiones de la matriz de memoria compartida rectangular se definen mediante macros y el mosaico de memoria compartida se asigna en consecuencia. 

El documento también menciona la necesidad de recalcular los índices de acceso en función de las dimensiones de la matriz cuando se utiliza memoria compartida rectangular.

# Explicación adicional de la comprobación del diseño de datos de la memoria compartida
## Memoria compartida cuadrada:
La memoria compartida cuadrada se refiere a una técnica utilizada en la programación de GPU para almacenar en caché datos globales con dimensiones cuadradas en la memoria compartida. Implica almacenar datos en una matriz bidimensional en memoria compartida, donde cada elemento de la matriz corresponde a un subproceso en un bloque de subprocesos. La dimensionalidad cuadrada de la matriz facilita el cálculo de desplazamientos de memoria unidimensional a partir de índices de subprocesos bidimensionales.

Al utilizar memoria compartida cuadrada, los subprocesos vecinos dentro de un bloque de subprocesos pueden acceder a elementos vecinos en la dimensión x o y de la matriz de memoria compartida. Esto permite un acceso a datos eficiente y puede mejorar el rendimiento de los kernels de GPU al reducir el acceso a la memoria global y aumentar la utilización del ancho de banda de memoria.

### Acceso en Orden de Fila frente a Orden de Columna:
Al acceder a una matriz de memoria compartida cuadrada en orden de fila principal, la longitud de la dimensión más interna de la matriz de memoria compartida se establece en la misma dimensión que la dimensión más interna del bloque de hilos 2D. Esto significa que los hilos vecinos en el mismo warp accederán a celdas de matriz vecinas a lo largo de la dimensión más interna de la matriz, lo que resulta en un mejor rendimiento y menos conflictos de bancos. 

Por otro lado, al acceder a una matriz de memoria compartida cuadrada en orden de columna principal, la longitud de la dimensión más interna de la matriz de memoria compartida se establece en la misma dimensión que la dimensión más externa del bloque de hilos 2D. Esto significa que los hilos vecinos en el mismo warp accederán a celdas de matriz vecinas a lo largo de la dimensión más externa de la matriz, lo que puede provocar más conflictos de bancos y, potencialmente, un rendimiento inferior. 

En resumen, acceder a una matriz de memoria compartida cuadrada en orden de fila principal generalmente proporciona un mejor rendimiento y menos conflictos de bancos en comparación con acceder en orden de columna principal.

### Escritura en Orden de Fila y Lectura en Orden de Columna: 
En el caso de la memoria compartida cuadrada, escribir en orden de fila principal significa que cada hilo en un warp escribe su índice de hilo global en ubicaciones consecutivas en la matriz de memoria compartida a lo largo de la dimensión más interna. Esto permite accesos consecutivos a la memoria y evita conflictos de bancos. Por otro lado, leer en orden de columna principal significa que cada hilo en un warp lee valores de ubicaciones consecutivas en la matriz de memoria compartida a lo largo de la dimensión más externa. Esto puede provocar conflictos de bancos, ya que los hilos vecinos acceden a celdas de matriz vecinas a lo largo de la dimensión más externa.

### Memoria Compartida Dinámica: 
La memoria compartida dinámica se refiere a la memoria compartida que se declara dinámicamente en tiempo de ejecución. En el contexto de la memoria compartida cuadrada, puedes crear un nuevo kernel que declare memoria compartida dinámicamente y realice operaciones como escribir en columnas y leer desde filas. Esto permite más flexibilidad en la asignación de memoria y puede ser útil en ciertos escenarios.

### Relleno de Memoria Compartida Estáticamente Declarada: 
En la memoria compartida cuadrada, el relleno se utiliza para evitar conflictos de bancos. Para rellenar la memoria compartida estáticamente declarada en memoria compartida cuadrada, simplemente agregamos una columna a la asignación de memoria compartida 2D. Al hacer esto, los elementos de la columna se distribuyen entre diferentes bancos, lo que resulta en operaciones de lectura y escritura sin conflictos.

### Relleno de Memoria Compartida Declarada Dinámicamente: 
En el caso de rellenar la memoria compartida declarada dinámicamente de memoria compartida cuadrada, se omite un espacio de memoria rellenado por cada fila al convertir los índices de hilo 2D a índices de memoria 1D. Esto ayuda a resolver conflictos de bancos y mejora el rendimiento al reducir las transacciones de memoria compartida.

### Comparación del Rendimiento de los Kernels de Memoria Compartida Cuadrada:
Al comparar el rendimiento de los kernels de memoria compartida cuadrada, se observa que los kernels que utilizan relleno ganan rendimiento debido a la reducción de conflictos de bancos. 

Por otro lado, los kernels con memoria compartida declarada dinámicamente añaden una pequeña cantidad de sobrecarga. Al analizar los tiempos transcurridos y las transacciones de memoria, es posible determinar el impacto de diferentes técnicas de optimización en el rendimiento de los kernels de memoria compartida cuadrada.

## Memoria Compartida Rectangular:
La memoria compartida rectangular es un tipo de memoria en chip en las GPUs que permite a los hilos dentro del mismo bloque de hilos cooperar y reducir el ancho de banda de memoria global necesario para los kernels. Es una caché gestionada por el programa que se puede utilizar para la comunicación de hilos dentro del bloque, almacenar en caché datos de memoria global y mejorar los patrones de acceso a la memoria global. Las matrices de memoria compartida rectangular pueden declararse estática o dinámicamente y pueden accederse en orden de fila o columna.

### Acceso en Orden de Fila frente a Orden de Columna:
En el caso de la memoria compartida rectangular, donde el número de filas y columnas en una matriz no es igual, acceder a la matriz de memoria compartida en orden de fila o columna requiere consideraciones diferentes.

Al acceder a una matriz de memoria compartida rectangular en orden de fila, la longitud de la dimensión más interna de la matriz de memoria compartida se establece en la misma dimensión que la dimensión más interna del bloque de hilos 2D. Esto permite a los hilos vecinos en el mismo warp acceder a celdas de matriz vecinas a lo largo de la dimensión más interna de la matriz, similar al caso de la memoria compartida cuadrada.

Por otro lado, al acceder a una matriz de memoria compartida rectangular en orden de columna, la longitud de la dimensión más interna de la matriz de memoria compartida se establece en la misma dimensión que la dimensión más externa del bloque de hilos 2D. Esto significa que los hilos vecinos en el mismo warp accederán a celdas de matriz vecinas a lo largo de la dimensión más externa de la matriz, lo que puede provocar más conflictos de bancos y, potencialmente, un rendimiento inferior. 

En resumen, de manera similar al caso de la memoria compartida cuadrada, acceder a una matriz de memoria compartida rectangular en orden de fila generalmente proporciona un mejor rendimiento y menos conflictos de bancos en comparación con acceder en orden de columna.

### Escritura en Orden Row-Major y Lectura en Orden Column-Major:
En el caso de la memoria compartida rectangular, las dimensiones del arreglo de memoria compartida no son iguales. Escribir en orden row-major aún significa que cada hilo en un warp escribe su índice global de hilo en ubicaciones consecutivas en el arreglo de memoria compartida a lo largo de la dimensión más interna. Esto ayuda a evitar conflictos de bancos. 

De manera similar, leer en orden column-major significa que cada hilo en un warp lee valores de ubicaciones consecutivas en el arreglo de memoria compartida a lo largo de la dimensión más externa. Sin embargo, debido a las dimensiones desiguales, aún puede haber conflictos de bancos, especialmente si los hilos vecinos acceden a celdas de arreglo vecinas a lo largo de la dimensión más externa.

### Memoria Compartida Declarada Dinámicamente:
En la memoria compartida rectangular, las dimensiones del arreglo de memoria compartida no son iguales, lo que significa que el cálculo de desplazamientos de memoria 1D desde índices de hilo 2D es más complejo. 

Al usar memoria compartida rectangular, es necesario volver a implementar los kernels y recalcular los índices de acceso basados en las dimensiones de la matriz. Esto se debe a que simplemente cambiar las coordenadas de hilo utilizadas para referenciar una matriz rectangular, como se hace en la memoria compartida cuadrada, resultaría en violaciones de acceso a memoria.

### Relleno de Memoria Compartida Declarada Estáticamente:
En la memoria compartida rectangular, el relleno también se utiliza para evitar conflictos de bancos. Para rellenar la memoria compartida declarada estáticamente en la memoria compartida rectangular, agregamos una columna a la asignación de memoria compartida 2D. Al hacer esto, los elementos de la columna se distribuyen entre diferentes bancos, lo que resulta en operaciones de lectura y escritura sin conflictos.

### Relleno de Memoria Compartida Declarada Dinámicamente:
El relleno de la memoria compartida declarada dinámicamente de la memoria compartida rectangular es más complejo. Similar a la memoria compartida cuadrada, se omite un espacio de memoria rellenado por cada fila al realizar la conversión de índices desde índices de hilo 2D a índices de memoria 1D. Sin embargo, el número de elementos de relleno necesarios para cada fila depende del tamaño de la memoria compartida 2D. Esto requiere pruebas adicionales para determinar el número adecuado de elementos de relleno.

### Comparación del Rendimiento de los Kernels de Memoria Compartida Rectangular:
El documento discute el rendimiento de diferentes kernels que utilizan memoria compartida rectangular. Los kernels están diseñados para realizar operaciones como escribir en columnas y leer desde filas. Se compara el rendimiento de estos kernels en función de factores como el tiempo transcurrido y el ancho de banda efectivo. Se observa que los kernels que utilizan relleno y bloques desenrollados muestran un rendimiento mejorado debido a la reducción de conflictos de bancos y el aumento de la paralelización.

## Conslusion

La principal diferencia entre la memoria compartida cuadrada y la memoria compartida rectangular radica en las dimensiones y la forma en que se accede a los elementos de datos. La memoria compartida cuadrada tiene dimensiones iguales y almacena datos en orden row-major, mientras que la memoria compartida rectangular puede tener dimensiones diferentes y permite el acceso tanto en orden row-major como column-major.


Si hablamos de la **Memoria compartida** su principal diferencia radica en el cálculo de desplazamientos de memoria y la necesidad de una re-implementación en el caso de la memoria compartida rectangular.

Para **rellenar la memoria compartida declarada estáticamente** su proceso es el mismo tanto para la memoria compartida cuadrada como para la memoria compartida rectangular. Involucra agregar una columna a la asignación de memoria compartida 2D para distribuir los elementos entre diferentes bancos y evitar conflictos de bancos.

La principal diferencia entre **escribir en orden row-major y leer en orden column-major** tanto en la memoria compartida cuadrada como en la memoria compartida rectangular es el orden en que los hilos acceden al arreglo de memoria compartida y el potencial de conflictos de bancos. Escribir en orden row-major permite accesos de memoria consecutivos y un mejor rendimiento, mientras que leer en orden column-major puede resultar en conflictos de bancos y un rendimiento disminuido.

## Referencias 
> J. Cheng, M. Grossman, T. McKercher, and B. Chapman, _Professional CUDA C Programming_. 2014. [Online]. Available: http://hgpu.org/?p=12757
