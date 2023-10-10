![](https://uniat.com/wp-content/uploads/2018/12/logo_uniat.png)

Alvaro Bishop Macias                     Investigación CUDA Cores, Threads, Blocks and Grids

**CUDA Cores**

Los NVIDIA CUDA Cores son procesadores paralelos que se encuentran dentro de la GPU y se encargan de procesar todos los datos que entran y salen de la GPU, realizando cálculos gráficos cuyo resultado los ve el usuario final.

Cada núcleo CUDA es un procesador de flujo que ejecuta operaciones aritméticas y lógicas de forma independiente, diseñados específicamente para la aceleración de cálculos matemáticos, como operaciones de punto flotante y vectores, que son comunes en aplicaciones de aprendizaje automático, análisis de datos y procesamiento de imágenes.

Son excepcionales en el manejo de tareas que requieren mucho paralelismo, como animaciones de humo, animación de escombros, fuego, fluidos, entre otros.

La tecnología CUDA de NVIDIA proporciona una plataforma de desarrollo para la creación de aplicaciones de alto rendimiento que se ejecutan en la GPU, permitiendo a los desarrolladores crear aplicaciones altamente optimizadas para la aceleración de cálculos en paralelo.

«Specs Dictionary - CUDA Cores | GamersNexus - Gaming PC Builds & Hardware Benchmarks». https://www.gamersnexus.net/dictionary/2-cuda-cores

N. Foster, «NVIDIA CUDA cores explained: How are they different?», *Ace Cloud*, 24 de julio de 2023. https://www.acecloudhosting.com/blog/nvidia-cuda-cores-explained/

**Threads**

En términos generales, un thread es una secuencia de instrucciones que se ejecutan de forma independiente de otras secuencias de instrucciones en un programa.

Los threads son una forma de programación concurrente que permite que los programas realicen múltiples tareas al mismo tiempo, lo que puede mejorar significativamente el rendimiento y la eficiencia de los programas

S. J. Bigelow, «Thread», *WhatIs.com*, ago. 2023, [En línea]. Disponible en: https://www.techtarget.com/whatis/definition/thread

**Blocks and Grids**

En la programación CUDA, un grupo de subprocesos se denomina block, y los bloques se agrupan en una malla. Un núcleo se ejecuta como una malla de bloques de subprocesos. El número de hilos en un bloque es limitado, pero las rejillas pueden utilizarse para cálculos que requieren un gran número de bloques de hilos para operar en paralelo y utilizar todos los multiprocesadores disponibles.

«How to choose grid and block dimensions for CUDA kernels? | Saturn Cloud Blog», 4 de octubre de 2023. https://saturncloud.io/blog/how-to-choose-grid-and-block-dimensions-for-cuda-kernel s/

**Conclusión**

En conclusión, los NVIDIA CUDA Cores representan una parte esencial de las tarjetas gráficas modernas, encargándose de procesar datos de manera altamente paralela y eficiente. La combinación de los CUDA Cores, threads, bloques y mallas en la programación CUDA brinda a los desarrolladores la capacidad de aprovechar al máximo el potencial de las GPUs para realizar cálculos intensivos y tareas paralelas, lo que es esencial en multitud de aplicaciones..
