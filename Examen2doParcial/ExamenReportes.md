### SimpleMathAoS 
~~~
==1011== NVPROF is profiling process 1011, command: ./simpleMathAoS
==1011== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==1011== Profiling application: ./simpleMathAoS
==1011== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   80.19%  23.304ms         2  11.652ms  8.6804ms  14.623ms  [CUDA memcpy DtoH]
                   18.05%  5.2457ms         1  5.2457ms  5.2457ms  5.2457ms  [CUDA memcpy HtoD]
                    0.88%  256.10us         1  256.10us  256.10us  256.10us  warmup(innerStruct*, innerStruct*, int)
                    0.88%  255.85us         1  255.85us  255.85us  255.85us  testInnerStruct(innerStruct*, innerStruct*, int)
      API calls:   88.83%  566.38ms         2  283.19ms  376.90us  566.01ms  cudaMalloc
                    5.61%  35.742ms         1  35.742ms  35.742ms  35.742ms  cudaDeviceReset
                    4.90%  31.267ms         3  10.422ms  6.6946ms  15.576ms  cudaMemcpy
                    0.34%  2.1562ms         1  2.1562ms  2.1562ms  2.1562ms  cuDeviceGetPCIBusId
                    0.19%  1.2200ms         2  610.00us  446.90us  773.10us  cudaFree
                    0.11%  669.90us         2  334.95us  334.90us  335.00us  cudaDeviceSynchronize
                    0.03%  161.60us         2  80.800us  63.500us  98.100us  cudaLaunchKernel
                    0.00%  14.600us       101     144ns     100ns  1.3000us  cuDeviceGetAttribute
                    0.00%  6.1000us         1  6.1000us  6.1000us  6.1000us  cudaSetDevice
                    0.00%  5.8000us         2  2.9000us  2.6000us  3.2000us  cudaGetLastError
                    0.00%  4.7000us         1  4.7000us  4.7000us  4.7000us  cudaGetDeviceProperties
                    0.00%  1.4000us         3     466ns     200ns  1.0000us  cuDeviceGetCount
                    0.00%     800ns         2     400ns     100ns     700ns  cuDeviceGet
                    0.00%     600ns         1     600ns     600ns     600ns  cuDeviceGetName
                    0.00%     400ns         1     400ns     400ns     400ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~
**GPU activities:**
    
[CUDA memcpy DtoH] Estas llamadas representan transferencias de memoria desde el dispositivo (GPU) a la memoria principal (Host). Esta actividad ocupa el 80.19% del tiempo de ejecución y se llama dos veces. 
  
[CUDA memcpy HtoD]:  Esta llamada representa una transferencia de memoria desde la memoria principal al dispositivo. Esta actividad ocupa el 18.05% del tiempo de ejecución y se llama una vez. 
        
 __warmup(innerStruct_, innerStruct_, int): Esta actividad ocupa el 0.88% del tiempo de ejecución y se llama una vez. El tiempo promedio es de 256.10 us. 
        
 __testInnerStruct(innerStruct_, innerStruct_, int): Esta actividad también ocupa el 0.88% del tiempo de ejecución y se llama una vez. El tiempo promedio es de 255.85 us. 
            
cudaMalloc:  Se utiliza para asignar memoria en el dispositivo.
        
cudaDeviceReset: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo.
        
cudaMemcpy: Esta llamada ocupa el 4.90% del tiempo de ejecución y se llama tres veces. Se utiliza para copiar datos entre el dispositivo y la memoria principal.
        
cuDeviceGetPCIBusId: Esta llamada ocupa el 0.34% del tiempo de ejecución y se llama una vez. Se utiliza para obtener el identificador del bus PCI del dispositivo.
        
cudaFree: Esta llamada ocupa el 0.19% del tiempo de ejecución y se llama dos veces.  Se utiliza para liberar la memoria asignada previamente en el dispositivo.
        
cudaDeviceSynchronize: Esta llamada ocupa el 0.11% del tiempo de ejecución y se llama dos veces. El tiempo promedio es de 334.95 us. Se utiliza para sincronizar el dispositivo.
        
cudaLaunchKernel: Esta llamada ocupa el 0.03% del tiempo de ejecución y se llama dos veces. El tiempo promedio es de 80.800 us. Se utiliza para lanzar un kernel en el dispositivo.

---
### SimpleMathSoA
~~~
==1027== NVPROF is profiling process 1027, command: ./simpleMathSoA
==1027== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==1027== Profiling application: ./simpleMathSoA
==1027== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   73.35%  12.215ms         2  6.1076ms  3.7599ms  8.4554ms  [CUDA memcpy DtoH]
                   23.58%  3.9265ms         1  3.9265ms  3.9265ms  3.9265ms  [CUDA memcpy HtoD]
                    1.54%  256.42us         1  256.42us  256.42us  256.42us  warmup2(InnerArray*, InnerArray*, int)
                    1.54%  256.03us         1  256.03us  256.03us  256.03us  testInnerArray(InnerArray*, InnerArray*, int)
      API calls:   90.98%  584.89ms         2  292.45ms  380.00us  584.51ms  cudaMalloc
                    5.47%  35.165ms         1  35.165ms  35.165ms  35.165ms  cudaDeviceReset
                    2.89%  18.564ms         3  6.1881ms  3.9129ms  9.2690ms  cudaMemcpy
                    0.39%  2.4897ms         1  2.4897ms  2.4897ms  2.4897ms  cuDeviceGetPCIBusId
                    0.15%  981.80us         2  490.90us  359.80us  622.00us  cudaFree
                    0.11%  682.20us         2  341.10us  302.90us  379.30us  cudaDeviceSynchronize
                    0.01%  94.200us         2  47.100us  43.700us  50.500us  cudaLaunchKernel
                    0.00%  16.500us       101     163ns     100ns  1.4000us  cuDeviceGetAttribute
                    0.00%  5.9000us         1  5.9000us  5.9000us  5.9000us  cudaSetDevice
                    0.00%  5.1000us         1  5.1000us  5.1000us  5.1000us  cudaGetDeviceProperties
                    0.00%  4.7000us         2  2.3500us  2.3000us  2.4000us  cudaGetLastError
                    0.00%  1.4000us         3     466ns     200ns  1.0000us  cuDeviceGetCount
                    0.00%  1.2000us         1  1.2000us  1.2000us  1.2000us  cuDeviceGetName
                    0.00%  1.1000us         2     550ns     100ns  1.0000us  cuDeviceGet
                    0.00%     300ns         1     300ns     300ns     300ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~

[CUDA memcpy DtoH]: Estas llamadas representan transferencias de memoria desde el dispositivo (GPU) a la memoria principal (Host). Esta actividad ocupa el 73.35% del tiempo de ejecución y se llama dos veces. El tiempo promedio es de 6.1076 ms, con un mínimo de 3.7599 ms y un máximo de 8.4554 ms. Estas transferencias de memoria son críticas para copiar resultados o datos desde la GPU a la CPU.

[CUDA memcpy HtoD]: Esta llamada representa una transferencia de memoria desde la memoria principal al dispositivo. Esta actividad ocupa el 23.58% del tiempo de ejecución y se llama una vez. El tiempo promedio es de 3.9265 ms. Esta transferencia es crucial para cargar datos desde la CPU a la GPU antes de la ejecución del kernel en el dispositivo.

warmup2(InnerArray*, InnerArray*, int): Esta actividad ocupa el 1.54% del tiempo de ejecución y se llama una vez. El tiempo promedio es de 256.42 us. Esta función parece ser un kernel que realiza cálculos en la GPU y se ejecuta durante la fase de "calentamiento" (warm-up) del programa.

testInnerArray(InnerArray*, InnerArray*, int): Esta actividad también ocupa el 1.54% del tiempo de ejecución y se llama una vez. El tiempo promedio es de 256.03 us. Similar a la función anterior, esta es otro kernel que realiza cálculos en la GPU.

cudaMalloc: Se utiliza para asignar memoria en el dispositivo. Esta llamada ocupa el 90.98% del tiempo de ejecución y se llama dos veces. El tiempo promedio es de 292.45 ms. La asignación de memoria en el dispositivo es una parte fundamental de la preparación de datos para su procesamiento en la GPU.

cudaDeviceReset: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo. Esta llamada ocupa el 5.47% del tiempo de ejecución y se llama una vez. Su principal función es restablecer el estado del dispositivo de GPU.

cudaMemcpy: Esta llamada ocupa el 2.89% del tiempo de ejecución y se llama tres veces. Se utiliza para copiar datos entre el dispositivo y la memoria principal. El tiempo promedio para estas llamadas es de 6.1881 ms. La copia de datos entre la GPU y la CPU es una operación común en las aplicaciones de CUDA.

cuDeviceGetPCIBusId: Esta llamada ocupa el 0.39% del tiempo de ejecución y se llama una vez. Se utiliza para obtener el identificador del bus PCI del dispositivo. Esto puede ser útil para identificar la GPU en un sistema multi-GPU.

cudaFree: Esta llamada ocupa el 0.15% del tiempo de ejecución y se llama dos veces. Se utiliza para liberar la memoria asignada previamente en el dispositivo, lo que es importante para la gestión de recursos en CUDA.

cudaDeviceSynchronize: Esta llamada ocupa el 0.11% del tiempo de ejecución y se llama dos veces. El tiempo promedio es de 341.10 us. Se utiliza para sincronizar el dispositivo, asegurando que todas las tareas en la GPU se completen antes de continuar con la ejecución en la CPU.

cudaLaunchKernel: Esta llamada ocupa el 0.01% del tiempo de ejecución y se llama dos veces. El tiempo promedio es de 47.100 us. Se utiliza para lanzar un kernel en el dispositivo, lo que inicia la ejecución paralela en la GPU.

---
### sumArrayZerocpy
~~~
==1049== NVPROF is profiling process 1049, command: ./sumArrayZerocpy
==1049== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==1049== Profiling application: ./sumArrayZerocpy
==1049== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   33.33%  3.5200us         1  3.5200us  3.5200us  3.5200us  sumArraysZeroCopy(float*, float*, float*, int)
                   22.73%  2.4000us         2  1.2000us  1.1840us  1.2160us  [CUDA memcpy DtoH]
                   22.12%  2.3360us         1  2.3360us  2.3360us  2.3360us  sumArrays(float*, float*, float*, int)
                   21.82%  2.3040us         2  1.1520us     864ns  1.4400us  [CUDA memcpy HtoD]
      API calls:   94.24%  583.14ms         3  194.38ms  1.8000us  583.14ms  cudaMalloc
                    5.09%  31.475ms         1  31.475ms  31.475ms  31.475ms  cudaDeviceReset
                    0.35%  2.1756ms         1  2.1756ms  2.1756ms  2.1756ms  cuDeviceGetPCIBusId
                    0.16%  988.60us         2  494.30us  3.8000us  984.80us  cudaHostAlloc
                    0.06%  368.90us         2  184.45us  4.5000us  364.40us  cudaFreeHost
                    0.06%  358.00us         4  89.500us  33.100us  129.40us  cudaMemcpy
                    0.04%  218.20us         3  72.733us  2.5000us  208.10us  cudaFree
                    0.01%  60.300us         2  30.150us  28.600us  31.700us  cudaLaunchKernel
                    0.00%  14.900us       101     147ns     100ns  1.0000us  cuDeviceGetAttribute
                    0.00%  6.2000us         1  6.2000us  6.2000us  6.2000us  cudaSetDevice
                    0.00%  2.3000us         1  2.3000us  2.3000us  2.3000us  cudaGetDeviceProperties
                    0.00%  2.1000us         2  1.0500us     600ns  1.5000us  cudaHostGetDevicePointer
                    0.00%  1.6000us         3     533ns     200ns  1.0000us  cuDeviceGetCount
                    0.00%  1.1000us         2     550ns     200ns     900ns  cuDeviceGet
                    0.00%     700ns         1     700ns     700ns     700ns  cuDeviceGetName
                    0.00%     300ns         1     300ns     300ns     300ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~



`sumArraysZeroCopy(float*, float*, float*, int)`: Esta actividad ocupa el 33.33% del tiempo de ejecución y se llama una vez. El tiempo promedio es de 3.5200 us. Esta función representa una operación en la GPU llamada "sumArraysZeroCopy", que trabaja con tres arreglos de tipo float y un entero como argumentos.
    
`[CUDA memcpy DtoH]`: Estas llamadas representan transferencias de memoria desde el dispositivo (GPU) a la memoria principal (Host). Esta actividad ocupa el 22.73% del tiempo de ejecución y se llama dos veces. Se utiliza para copiar datos desde la GPU a la memoria principal.
    
`sumArrays(float*, float*, float*, int)`: Esta actividad ocupa el 22.12% del tiempo de ejecución y se llama una vez. El tiempo promedio es de 2.3360 us. Esta función representa otra operación en la GPU llamada "sumArrays", que trabaja con tres arreglos de tipo float y un entero como argumentos.
    
`[CUDA memcpy HtoD]`: Esta llamada representa una transferencia de memoria desde la memoria principal al dispositivo. Esta actividad ocupa el 21.82% del tiempo de ejecución y se llama dos veces. Se utiliza para copiar datos desde la memoria principal a la GPU.
    



`cudaMalloc`: Esta llamada ocupa el 94.24% del tiempo de ejecución y se llama tres veces. Se utiliza para asignar memoria en el dispositivo (GPU). El tiempo promedio de ejecución es de 194.38 ms. Es una operación costosa en términos de tiempo.
    
`cudaDeviceReset`: La función `cudaDeviceReset` ocupa el 5.09% del tiempo de ejecución y se llama una vez. Se utiliza para reiniciar el dispositivo (GPU).
    
`cuDeviceGetPCIBusId`: Esta llamada ocupa el 0.35% del tiempo de ejecución y se llama una vez. Se utiliza para obtener el identificador del bus PCI del dispositivo (GPU).
    
`cudaHostAlloc`: Esta llamada ocupa el 0.16% del tiempo de ejecución y se llama dos veces. Se utiliza para asignar memoria en el host.
    
`cudaFreeHost`: Esta llamada ocupa el 0.06% del tiempo de ejecución y se llama dos veces. Se utiliza para liberar la memoria asignada previamente en el host.
    
`cudaMemcpy`: Esta llamada ocupa el 0.06% del tiempo de ejecución y se llama cuatro veces. Se utiliza para copiar datos entre el dispositivo y la memoria principal.
    
`cudaFree`: Esta llamada ocupa el 0.04% del tiempo de ejecución y se llama tres veces. Se utiliza para liberar la memoria asignada previamente en el dispositivo.
    
`cudaLaunchKernel`: Esta llamada ocupa el 0.01% del tiempo de ejecución y se llama dos veces. Se utiliza para lanzar un kernel en el dispositivo. El tiempo promedio de ejecución es de 30.150 us.
    
`cuDeviceGetAttribute`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. Se utiliza para obtener atributos del dispositivo.
    
`cudaSetDevice`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama una vez. Se utiliza para seleccionar un dispositivo.
    
`cudaGetDeviceProperties`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama una vez. Se utiliza para obtener las propiedades del dispositivo.
    
`cudaHostGetDevicePointer`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama dos veces. Se utiliza para obtener un puntero de dispositivo a partir de un puntero de host.
    
`cuDeviceGetCount`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama tres veces. Se utiliza para obtener el número de dispositivos.
    
`cuDeviceGet`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama dos veces. Se utiliza para obtener información sobre el dispositivo.
    
`cuDeviceGetName`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama una vez. Se utiliza para obtener el nombre del dispositivo.
    
`cuDeviceTotalMem`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama una vez. Se utiliza para obtener la cantidad total de memoria en el dispositivo.
    
`cuDeviceGetUuid`: Esta llamada ocupa el 0.00% del tiempo de ejecución y se llama una vez. Se utiliza para obtener un identificador único del dispositivo.

---
###   sumMatrixGPUManaged
~~~
==1071== NVPROF is profiling process 1071, command: ./sumMatrixGPUManaged
==1071== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==1071== Profiling application: ./sumMatrixGPUManaged
==1071== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:  100.00%  12.948ms         2  6.4741ms  288.67us  12.660ms  sumMatrixGPU(float*, float*, float*, int, int)
      API calls:   91.39%  815.38ms         4  203.85ms  27.532ms  731.17ms  cudaMallocManaged
                    3.45%  30.801ms         1  30.801ms  30.801ms  30.801ms  cudaDeviceReset
                    3.31%  29.569ms         4  7.3922ms  7.2484ms  7.4490ms  cudaFree
                    1.52%  13.583ms         1  13.583ms  13.583ms  13.583ms  cudaDeviceSynchronize
                    0.24%  2.1681ms         1  2.1681ms  2.1681ms  2.1681ms  cuDeviceGetPCIBusId
                    0.07%  644.20us         2  322.10us  11.200us  633.00us  cudaLaunchKernel
                    0.00%  14.100us       101     139ns     100ns     900ns  cuDeviceGetAttribute
                    0.00%  5.8000us         1  5.8000us  5.8000us  5.8000us  cudaSetDevice
                    0.00%  4.0000us         1  4.0000us  4.0000us  4.0000us  cudaGetDeviceProperties
                    0.00%  1.2000us         3     400ns     100ns     900ns  cuDeviceGetCount
                    0.00%  1.1000us         2     550ns     100ns  1.0000us  cuDeviceGet
                    0.00%     900ns         1     900ns     900ns     900ns  cudaGetLastError
                    0.00%     700ns         1     700ns     700ns     700ns  cuDeviceGetName
                    0.00%     300ns         1     300ns     300ns     300ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~



`sumMatrixGPU(float*, float*, float*, int, int)`: Esta actividad representa la ejecución de un kernel llamado "sumMatrixGPU", que opera en matrices en el dispositivo GPU. Ocupa el 100.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 6.4741 ms, con un mínimo de 288.67 us y un máximo de 12.660 ms. Este kernel es la parte central del código y se encarga de realizar la suma de matrices en la GPU.



`cudaMallocManaged`: Esta llamada se utiliza para asignar memoria unificada en el dispositivo y la memoria principal. Ocupa el 91.39% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 203.85 ms, con un mínimo de 27.532 ms y un máximo de 731.17 ms. Esta función se utiliza para asignar memoria gestionada en el dispositivo.
    
`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo. Ocupa el 3.45% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 30.801 ms.
    
`cudaFree`: Esta llamada se utiliza para liberar la memoria previamente asignada en el dispositivo. Ocupa el 3.31% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 7.3922 ms, con un mínimo de 7.2484 ms y un máximo de 7.4490 ms.
    
`cudaDeviceSynchronize`: Esta llamada se utiliza para sincronizar el dispositivo. Ocupa el 1.52% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 13.583 ms.
    
`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo. Ocupa el 0.24% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.1681 ms.
    
`cudaLaunchKernel`: Esta llamada se utiliza para lanzar un kernel en el dispositivo. Ocupa el 0.07% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 322.10 us, con un mínimo de 11.200 us y un máximo de 633.00 us.
    
`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. El tiempo promedio de ejecución de cada llamada es de 139 ns, con un mínimo de 100 ns y un máximo de 900 ns.
    
-   `cudaSetDevice`: Se utiliza para seleccionar el dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 5.8000 us.
    
`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 4.0000 us.
    
`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos. Ocupa el 0.00% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 400 ns, con un mínimo de 100 ns y un máximo de 900 ns.
    
`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 550 ns, con un mínimo de 100 ns y un máximo de 1.0000 us.
    
`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 900 ns.
    
`cuDeviceGetName`: Esta llamada se utiliza para obtener el nombre del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 700 ns.
    
`cuDeviceTotalMem`: Esta llamada se utiliza para obtener la memoria total del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 300 ns.
    
`cuDeviceGetUuid`: Esta llamada se utiliza para obtener el identificador único del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 200 ns.

---
###   sumMatrixGPUManual
~~~
==1089== NVPROF is profiling process 1089, command: ./sumMatrixGPUManual
==1089== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==1089== Profiling application: ./sumMatrixGPUManual
==1089== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   65.52%  27.101ms         2  13.550ms  8.3698ms  18.731ms  [CUDA memcpy HtoD]
                   30.63%  12.669ms         1  12.669ms  12.669ms  12.669ms  [CUDA memcpy DtoH]
                    2.69%  1.1118ms         2  555.89us  288.73us  823.04us  sumMatrixGPU(float*, float*, float*, int, int)
                    1.16%  479.42us         2  239.71us  238.91us  240.51us  [CUDA memset]
      API calls:   87.57%  607.17ms         3  202.39ms  713.10us  605.72ms  cudaMalloc
                    6.50%  45.038ms         3  15.013ms  8.6183ms  23.545ms  cudaMemcpy
                    5.26%  36.474ms         1  36.474ms  36.474ms  36.474ms  cudaDeviceReset
                    0.33%  2.2576ms         1  2.2576ms  2.2576ms  2.2576ms  cuDeviceGetPCIBusId
                    0.19%  1.3256ms         3  441.87us  223.90us  799.30us  cudaFree
                    0.13%  929.30us         1  929.30us  929.30us  929.30us  cudaDeviceSynchronize
                    0.01%  62.700us         2  31.350us  24.300us  38.400us  cudaMemset
                    0.01%  62.500us         2  31.250us  28.200us  34.300us  cudaLaunchKernel
                    0.00%  15.600us       101     154ns     100ns  1.0000us  cuDeviceGetAttribute
                    0.00%  7.3000us         1  7.3000us  7.3000us  7.3000us  cudaSetDevice
                    0.00%  7.1000us         1  7.1000us  7.1000us  7.1000us  cudaGetDeviceProperties
                    0.00%  1.3000us         3     433ns     200ns     900ns  cuDeviceGetCount
                    0.00%  1.1000us         1  1.1000us  1.1000us  1.1000us  cuDeviceGetName
                    0.00%  1.0000us         2     500ns     200ns     800ns  cuDeviceGet
                    0.00%     700ns         1     700ns     700ns     700ns  cudaGetLastError
                    0.00%     300ns         1     300ns     300ns     300ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~




`CUDA memcpy HtoD` y `CUDA memcpy DtoH`: Estas actividades representan transferencias de memoria desde la CPU al GPU (HtoD) y desde el GPU a la CPU (DtoH). En este caso, se observa que estas operaciones ocupan el 65.52% y el 30.63% del tiempo de ejecución, respectivamente. Se realizan 2 llamadas a la transferencia HtoD y 1 llamada a la transferencia DtoH. El tiempo promedio de ejecución de las transferencias HtoD es de 13.550 ms, con un mínimo de 8.3698 ms y un máximo de 18.731 ms. Para la transferencia DtoH, el tiempo promedio de ejecución es de 12.669 ms, con un mínimo y máximo de 12.669 ms. Estas transferencias son esenciales para mover datos entre la CPU y el GPU y son un componente significativo del tiempo de ejecución.
    
`sumMatrixGPU(float*, float*, float*, int, int)`: Esta actividad representa la ejecución de un kernel llamado "sumMatrixGPU" que opera en matrices en el dispositivo GPU. Ocupa el 2.69% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 555.89 us, con un mínimo de 288.73 us y un máximo de 823.04 us. Este kernel es la parte central del código y se encarga de realizar la suma de matrices en la GPU.
    
`CUDA memset`: Esta actividad representa llamadas a la función `cudaMemset` que se utiliza para llenar una región de memoria con un valor específico. Ocupa el 1.16% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 239.71 us, con un mínimo de 238.91 us y un máximo de 240.51 us.
   

`cudaMalloc`: Esta llamada se utiliza para asignar memoria en el dispositivo GPU. Ocupa el 87.57% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 202.39 ms, con un mínimo de 713.10 us y un máximo de 605.72 ms. Esta función se utiliza para asignar memoria en el dispositivo.
    
`cudaMemcpy`: Esta llamada se utiliza para copiar datos entre la CPU y el GPU. Ocupa el 6.50% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 15.013 ms, con un mínimo de 8.6183 ms y un máximo de 23.545 ms.
    
`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo GPU. Ocupa el 5.26% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 36.474 ms.
    
`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo. Ocupa el 0.33% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.2576 ms.
    
`cudaFree`: Esta llamada se utiliza para liberar la memoria previamente asignada en el dispositivo. Ocupa el 0.19% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 441.87 us, con un mínimo de 223.90 us y un máximo de 799.30 us.
    
`cudaDeviceSynchronize`: Esta llamada se utiliza para sincronizar el dispositivo GPU. Ocupa el 0.13% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 929.30 us.
    
`cudaMemset`: Esta llamada se utiliza para llenar una región de memoria con un valor específico. Ocupa el 0.01% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 31.350 us, con un mínimo de 24.300 us y un máximo de 38.400 us.
    
`cudaLaunchKernel`: Esta llamada se utiliza para lanzar un kernel en el dispositivo GPU. Ocupa el 0.01% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 31.250 us, con un mínimo de 28.200 us y un máximo de 34.300 us.
    
`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. El tiempo promedio de ejecución de cada llamada es de 154 ns, con un mínimo de 100 ns y un máximo de 1.0000 us.
    
`cudaSetDevice`: Se utiliza para seleccionar el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 7.3000 us.
    
`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 7.1000 us.
    
`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos GPU. Ocupa el 0.00% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 433 ns, con un mínimo de 200 ns y un máximo de 900 ns.
    
`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 500 ns, con un mínimo de 200 ns y un máximo de 800 ns.
    
`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 700 ns.
    
`cuDeviceGetName`: Esta llamada se utiliza para obtener el nombre del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 1.1000 us.
    
`cuDeviceTotalMem`: Esta llamada se utiliza para obtener la memoria total del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 300 ns.
    
`cuDeviceGetUuid`: Esta llamada se utiliza para obtener el identificador único del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 200 ns.

---
###   transpose
~~~
==1111== NVPROF is profiling process 1111, command: ./transpose
==1111== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==1111== Profiling application: ./transpose
==1111== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   86.82%  1.9853ms         1  1.9853ms  1.9853ms  1.9853ms  [CUDA memcpy HtoD]
                    6.62%  151.49us         1  151.49us  151.49us  151.49us  copyRow(float*, float*, int, int)
                    6.56%  150.02us         1  150.02us  150.02us  150.02us  warmup(float*, float*, int, int)
      API calls:   86.44%  634.10ms         2  317.05ms  434.00us  633.66ms  cudaMalloc
                   12.79%  93.791ms         1  93.791ms  93.791ms  93.791ms  cudaDeviceReset
                    0.32%  2.3634ms         1  2.3634ms  2.3634ms  2.3634ms  cudaMemcpy
                    0.31%  2.2569ms         1  2.2569ms  2.2569ms  2.2569ms  cuDeviceGetPCIBusId
                    0.07%  549.80us         2  274.90us  222.60us  327.20us  cudaFree
                    0.06%  404.50us         2  202.25us  166.80us  237.70us  cudaDeviceSynchronize
                    0.01%  57.000us         2  28.500us  15.400us  41.600us  cudaLaunchKernel
                    0.00%  16.500us       101     163ns     100ns  1.2000us  cuDeviceGetAttribute
                    0.00%  5.4000us         1  5.4000us  5.4000us  5.4000us  cudaSetDevice
                    0.00%  5.0000us         1  5.0000us  5.0000us  5.0000us  cudaGetDeviceProperties
                    0.00%  1.4000us         3     466ns     100ns  1.1000us  cuDeviceGetCount
                    0.00%  1.3000us         2     650ns     600ns     700ns  cudaGetLastError
                    0.00%  1.0000us         2     500ns     200ns     800ns  cuDeviceGet
                    0.00%     600ns         1     600ns     600ns     600ns  cuDeviceGetName
                    0.00%     400ns         1     400ns     400ns     400ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~
`[CUDA memcpy HtoD]`: Esta actividad representa la copia de memoria desde la CPU hacia el GPU (Host to Device). Ocupa el 86.82% del tiempo de ejecución. Se llama una vez y toma 1.9853 ms en promedio. El tiempo mínimo y máximo de ejecución son iguales a 1.9853 ms.
    
`copyRow(float*, float*, int, int)`: Esta actividad representa la ejecución de un kernel llamado `copyRow`, que opera en el dispositivo GPU. Ocupa el 6.62% del tiempo de ejecución, se llama una vez y toma en promedio 151.49 us por llamada. El tiempo mínimo y máximo de ejecución son iguales a 151.49 us.
    
`warmup(float*, float*, int, int)`: Esta actividad representa la ejecución de un kernel llamado `warmup`, que opera en el dispositivo GPU. Ocupa el 6.56% del tiempo de ejecución, se llama una vez y toma en promedio 150.02 us por llamada. El tiempo mínimo y máximo de ejecución son iguales a 150.02 us.
    

`cudaMalloc`: Esta llamada se utiliza para asignar memoria en el dispositivo. Ocupa el 86.44% del tiempo de ejecución, se llama dos veces, y toma en promedio 317.05 ms por llamada. El tiempo mínimo y máximo de ejecución son 434.00 us y 633.66 ms, respectivamente.
    
`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo. Ocupa el 12.79% del tiempo de ejecución, se llama una vez y toma 93.791 ms.
    
`cudaMemcpy`: Esta llamada se utiliza para copiar datos entre la CPU y el GPU. Ocupa el 0.32% del tiempo de ejecución, se llama una vez y toma 2.3634 ms.
    
`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo. Ocupa el 0.31% del tiempo de ejecución, se llama una vez y toma 2.2569 ms.
    
`cudaFree`: Esta llamada se utiliza para liberar la memoria previamente asignada en el dispositivo. Ocupa el 0.07% del tiempo de ejecución, se llama dos veces, y toma en promedio 202.25 us por llamada. El tiempo mínimo y máximo de ejecución son 166.80 us y 237.70 us, respectivamente.
    
`cudaDeviceSynchronize`: Esta llamada se utiliza para sincronizar el dispositivo. Ocupa el 0.06% del tiempo de ejecución, se llama dos veces, y toma en promedio 166.80 us por llamada. El tiempo mínimo y máximo de ejecución son 222.60 us y 327.20 us, respectivamente.
    
`cudaLaunchKernel`: Esta llamada se utiliza para lanzar un kernel en el dispositivo. Ocupa el 0.01% del tiempo de ejecución, se llama 101 veces, y toma en promedio 28.500 us por llamada. El tiempo mínimo y máximo de ejecución son 15.400 us y 41.600 us, respectivamente.
    
`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama 101 veces, y toma en promedio 163 ns por llamada. El tiempo mínimo y máximo de ejecución son 100 ns y 1.2000 us, respectivamente.
    
`cudaSetDevice`: Se utiliza para seleccionar el dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama una vez y toma 5.4000 us.
    
`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama una vez y toma 5.0000 us.
    
`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos. Ocupa el 0.00% del tiempo de ejecución, se llama tres veces, y toma en promedio 466 ns por llamada. El tiempo mínimo y máximo de ejecución son 100 ns y 1.1000 us, respectivamente.
    
`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama dos veces, y toma en promedio 500 ns por llamada. El tiempo mínimo y máximo de ejecución son 200 ns y 800 ns, respectivamente.
    
`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama una vez y toma 900 ns.
    
`cuDeviceGetName`: Esta llamada se utiliza para obtener el nombre del dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama una vez y toma 700 ns.
    
`cuDeviceTotalMem`: Esta llamada se utiliza para obtener la memoria total del dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama una vez y toma 300 ns.
    
`cuDeviceGetUuid`: Esta llamada se utiliza para obtener el identificador único del dispositivo. Ocupa el 0.00% del tiempo de ejecución, se llama una vez y toma 200 ns.

---

###   writeSegment
~~~
==1127== NVPROF is profiling process 1127, command: ./writeSegment
==1127== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==1127== Profiling application: ./writeSegment
==1127== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   65.98%  2.1129ms         3  704.29us  518.98us  921.45us  [CUDA memcpy DtoH]
                   29.36%  940.23us         2  470.12us  465.19us  475.04us  [CUDA memcpy HtoD]
                    1.55%  49.504us         1  49.504us  49.504us  49.504us  writeOffset(float*, float*, float*, int, int)
                    1.49%  47.712us         1  47.712us  47.712us  47.712us  warmup(float*, float*, float*, int, int)
                    0.91%  29.120us         1  29.120us  29.120us  29.120us  writeOffsetUnroll2(float*, float*, float*, int, int)
                    0.72%  23.072us         1  23.072us  23.072us  23.072us  writeOffsetUnroll4(float*, float*, float*, int, int)
      API calls:   92.61%  579.23ms         3  193.08ms  301.40us  578.59ms  cudaMalloc
                    6.01%  37.576ms         1  37.576ms  37.576ms  37.576ms  cudaDeviceReset
                    0.83%  5.1802ms         5  1.0360ms  537.40us  2.0100ms  cudaMemcpy
                    0.34%  2.1550ms         1  2.1550ms  2.1550ms  2.1550ms  cuDeviceGetPCIBusId
                    0.11%  687.50us         3  229.17us  186.80us  276.10us  cudaFree
                    0.06%  399.00us         4  99.750us  72.600us  145.30us  cudaDeviceSynchronize
                    0.04%  225.60us         4  56.400us  20.100us  89.100us  cudaLaunchKernel
                    0.00%  14.400us       101     142ns     100ns  1.0000us  cuDeviceGetAttribute
                    0.00%  4.9000us         1  4.9000us  4.9000us  4.9000us  cudaGetDeviceProperties
                    0.00%  4.1000us         1  4.1000us  4.1000us  4.1000us  cudaSetDevice
                    0.00%  3.3000us         4     825ns     400ns  1.1000us  cudaGetLastError
                    0.00%  1.2000us         3     400ns     200ns     800ns  cuDeviceGetCount
                    0.00%  1.1000us         2     550ns     200ns     900ns  cuDeviceGet
                    0.00%     700ns         1     700ns     700ns     700ns  cuDeviceGetName
                    0.00%     300ns         1     300ns     300ns     300ns  cuDeviceTotalMem
                    0.00%     100ns         1     100ns     100ns     100ns  cuDeviceGetUuid
~~~

`CUDA memcpy DtoH`: Esta actividad representa la transferencia de datos desde el dispositivo GPU a la memoria principal (host). Ocupa el 65.98% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 704.29 us, con un mínimo de 518.98 us y un máximo de 921.45 us. Estas operaciones son esenciales para obtener resultados del dispositivo a la CPU.
    
`CUDA memcpy HtoD`: Esta actividad representa la transferencia de datos desde la memoria principal (host) al dispositivo GPU. Ocupa el 29.36% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 470.12 us, con un mínimo de 465.19 us y un máximo de 475.04 us. Estas transferencias son cruciales para enviar datos al dispositivo para su procesamiento.
    
`writeOffset(float*, float*, float*, int, int)`: Esta función es parte de la aplicación y se ejecuta en el dispositivo GPU. Ocupa el 1.55% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta función es de 49.504 us. Esta función realiza alguna operación de escritura en la GPU con datos de entrada y salida.
    
`warmup(float*, float*, float*, int, int)`: Similar a la función anterior, esta también se ejecuta en el dispositivo GPU. Ocupa el 1.49% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta función es de 47.712 us. Realiza una operación de "calentamiento" en la GPU.
    
`writeOffsetUnroll2(float*, float*, float*, int, int)`: Otra función que se ejecuta en la GPU. Ocupa el 0.91% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta función es de 29.120 us. Realiza alguna operación de escritura en la GPU con datos de entrada y salida.
    
`writeOffsetUnroll4(float*, float*, float*, int, int)`: Similar a la función anterior, esta también se ejecuta en la GPU. Ocupa el 0.72% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta función es de 23.072 us. Realiza alguna operación de escritura en la GPU con datos de entrada y salida.

`cudaMalloc`: Esta llamada se utiliza para asignar memoria en el dispositivo GPU. Ocupa el 92.61% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 193.08 ms, con un mínimo de 301.40 us y un máximo de 578.59 ms. Esta función se utiliza para asignar memoria en el dispositivo.
    
`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo. Ocupa el 6.01% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 37.576 ms.
    
`cudaMemcpy`: Esta llamada se utiliza para transferir datos entre la CPU y el GPU. Ocupa el 0.83% del tiempo de ejecución y se llama cinco veces. El tiempo promedio de ejecución de cada llamada es de 1.0360 ms, con un mínimo de 537.40 us y un máximo de 2.0100 ms.
    
`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo. Ocupa el 0.34% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.1550 ms.
    
`cudaFree`: Esta llamada se utiliza para liberar la memoria previamente asignada en el dispositivo. Ocupa el 0.11% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 229.17 us, con un mínimo de 186.80 us y un máximo de 276.10 us.
    
`cudaDeviceSynchronize`: Esta llamada se utiliza para sincronizar el dispositivo. Ocupa el 0.06% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 99.750 us, con un mínimo de 72.600 us y un máximo de 145.30 us.
    
`cudaLaunchKernel`: Esta llamada se utiliza para lanzar un kernel en el dispositivo. Ocupa el 0.04% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 56.400 us, con un mínimo de 20.100 us y un máximo de 89.100 us.
    
`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. El tiempo promedio de ejecución de cada llamada es de 142 ns, con un mínimo de 100 ns y un máximo de 1.0000 us.
    
`cudaSetDevice`: Se utiliza para seleccionar el dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 4.9000 us.
    
`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 4.1000 us.
    
`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos. Ocupa el 0.00% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 400 ns, con un mínimo de 100 ns y un máximo de 900 ns.
    
`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 550 ns, con un mínimo de 100 ns y un máximo de 1.0000 us.
    
`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo. Ocupa el 0.00% del

---

###   memTransfer
~~~
==935== NVPROF is profiling process 935, command: ./memTransfer
==935== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==935== Profiling application: ./memTransfer
==935== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   52.15%  2.1117ms         1  2.1117ms  2.1117ms  2.1117ms  [CUDA memcpy HtoD]
                   47.85%  1.9374ms         1  1.9374ms  1.9374ms  1.9374ms  [CUDA memcpy DtoH]
      API calls:   93.74%  577.35ms         1  577.35ms  577.35ms  577.35ms  cudaMalloc
                    5.15%  31.729ms         1  31.729ms  31.729ms  31.729ms  cudaDeviceReset
                    0.71%  4.3856ms         2  2.1928ms  2.1784ms  2.2072ms  cudaMemcpy
                    0.34%  2.0994ms         1  2.0994ms  2.0994ms  2.0994ms  cuDeviceGetPCIBusId
                    0.05%  306.30us         1  306.30us  306.30us  306.30us  cudaFree
                    0.00%  14.700us       101     145ns     100ns  1.0000us  cuDeviceGetAttribute
                    0.00%  8.0000us         1  8.0000us  8.0000us  8.0000us  cudaSetDevice
                    0.00%  2.8000us         1  2.8000us  2.8000us  2.8000us  cudaGetDeviceProperties
                    0.00%  1.4000us         3     466ns     200ns  1.0000us  cuDeviceGetCount
                    0.00%     900ns         2     450ns     100ns     800ns  cuDeviceGet
                    0.00%     900ns         1     900ns     900ns     900ns  cuDeviceGetName
                    0.00%     400ns         1     400ns     400ns     400ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~


`[CUDA memcpy HtoD]`: Representa una copia de memoria desde el host al dispositivo (GPU). Esta actividad ocupa el 52.15% del tiempo de ejecución y se llama una vez. El tiempo promedio de ejecución de esta copia es de 2.1117 ms, con un mínimo de 2.1117 ms y un máximo de 2.1117 ms.
    
`[CUDA memcpy DtoH]`: Representa una copia de memoria desde el dispositivo al host. Esta actividad ocupa el 47.85% del tiempo de ejecución y se llama una vez. El tiempo promedio de ejecución de esta copia es de 1.9374 ms, con un mínimo de 1.9374 ms y un máximo de 1.9374 ms.
    

`cudaMalloc`: Esta llamada se utiliza para asignar memoria en el dispositivo. Ocupa el 93.74% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 577.35 ms.
    
`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo. Ocupa el 5.15% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 31.729 ms.
    
`cudaMemcpy`: Esta llamada se utiliza para copiar memoria entre el host y el dispositivo. Ocupa el 0.71% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 2.1928 ms.
    
`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo. Ocupa el 0.34% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.0994 ms.
    
`cudaFree`: Esta llamada se utiliza para liberar la memoria previamente asignada en el dispositivo. Ocupa el 0.05% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 306.30 us.
    
`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. El tiempo promedio de ejecución de cada llamada es de 145 ns.
    
`cudaSetDevice`: Se utiliza para seleccionar el dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 8.0000 us.
    
`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.8000 us.
    
`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos. Ocupa el 0.00% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 466 ns.
    
`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 450 ns.
    
`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 900 ns.
    
`cuDeviceGetName`: Esta llamada se utiliza para obtener el nombre del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 900 ns.
    
`cuDeviceTotalMem`: Esta llamada se utiliza para obtener la memoria total del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 400 ns.
    
`cuDeviceGetUuid`: Esta llamada se utiliza para obtener el identificador único del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 200 ns.

---

###   pinMemTransfer
~~~
==947== NVPROF is profiling process 947, command: ./pinMemTransfer
==947== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==947== Profiling application: ./pinMemTransfer
==947== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   50.57%  1.3036ms         1  1.3036ms  1.3036ms  1.3036ms  [CUDA memcpy HtoD]
                   49.43%  1.2743ms         1  1.2743ms  1.2743ms  1.2743ms  [CUDA memcpy DtoH]
      API calls:   93.65%  564.84ms         1  564.84ms  564.84ms  564.84ms  cudaHostAlloc
                    5.15%  31.051ms         1  31.051ms  31.051ms  31.051ms  cudaDeviceReset
                    0.45%  2.7319ms         2  1.3660ms  1.3368ms  1.3951ms  cudaMemcpy
                    0.34%  2.0604ms         1  2.0604ms  2.0604ms  2.0604ms  cuDeviceGetPCIBusId
                    0.30%  1.8091ms         1  1.8091ms  1.8091ms  1.8091ms  cudaFreeHost
                    0.06%  342.90us         1  342.90us  342.90us  342.90us  cudaMalloc
                    0.04%  261.00us         1  261.00us  261.00us  261.00us  cudaFree
                    0.00%  15.400us       101     152ns     100ns     900ns  cuDeviceGetAttribute
                    0.00%  7.2000us         1  7.2000us  7.2000us  7.2000us  cudaSetDevice
                    0.00%  2.4000us         1  2.4000us  2.4000us  2.4000us  cudaGetDeviceProperties
                    0.00%  1.0000us         3     333ns     100ns     700ns  cuDeviceGetCount
                    0.00%  1.0000us         2     500ns     100ns     900ns  cuDeviceGet
                    0.00%     600ns         1     600ns     600ns     600ns  cuDeviceGetName
                    0.00%     400ns         1     400ns     400ns     400ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~



`[CUDA memcpy HtoD]`: Esta actividad representa una copia de memoria desde la CPU (Host) al dispositivo GPU (Device). Ocupa el 50.57% del tiempo de ejecución y se llama una vez. El tiempo promedio de ejecución de cada llamada es de 1.3036 ms, con un mínimo de 1.3036 ms y un máximo de 1.3036 ms. Esta actividad se utiliza para transferir datos desde la CPU al GPU.
    
`[CUDA memcpy DtoH]`: Esta actividad representa una copia de memoria desde el dispositivo GPU al CPU. Ocupa el 49.43% del tiempo de ejecución y se llama una vez. El tiempo promedio de ejecución de cada llamada es de 1.2743 ms, con un mínimo de 1.2743 ms y un máximo de 1.2743 ms. Esta actividad se utiliza para transferir datos desde el GPU al CPU.
    
`cudaHostAlloc`: Esta llamada se utiliza para asignar memoria en el host. Ocupa el 93.65% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 564.84 ms. Se utiliza para asignar memoria gestionada en el host.
    
`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo. Ocupa el 5.15% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 31.051 ms.
    
`cudaMemcpy`: Esta llamada se utiliza para copiar datos entre la CPU y el GPU. Ocupa el 0.45% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 1.3660 ms, con un mínimo de 1.3368 ms y un máximo de 1.3951 ms.
    
`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo. Ocupa el 0.34% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.0604 ms.
    
`cudaFreeHost`: Esta llamada se utiliza para liberar memoria en el host. Ocupa el 0.30% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 1.8091 ms.
    
`cudaMalloc`: Esta llamada se utiliza para asignar memoria en el dispositivo GPU. Ocupa el 0.06% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 342.90 us.
    
`cudaFree`: Esta llamada se utiliza para liberar memoria previamente asignada en el dispositivo. Ocupa el 0.04% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 261.00 us.
    
`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. El tiempo promedio de ejecución de cada llamada es de 152 ns, con un mínimo de 100 ns y un máximo de 900 ns.
    
`cudaSetDevice`: Se utiliza para seleccionar el dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 7.2000 us.
    
`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.4000 us.
    
`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos. Ocupa el 0.00% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 1.0000 us, con un mínimo de 100 ns y un máximo de 900 ns.
    
`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 600 ns, con un mínimo de 100 ns y un máximo de 1.0000 us.
    
`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 900 ns.
    
`cuDeviceGetName`: Esta llamada se utiliza para obtener el nombre del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 700 ns.
    
`cuDeviceTotalMem`: Esta llamada se utiliza para obtener la memoria total del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 300 ns.
    
`cuDeviceGetUuid`: Esta llamada se utiliza para obtener el identificador único del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 200 ns.

---

###   readSegment
~~~
==963== NVPROF is profiling process 963, command: ./readSegment
==963== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==963== Profiling application: ./readSegment
==963== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   49.71%  992.10us         1  992.10us  992.10us  992.10us  [CUDA memcpy DtoH]
                   45.41%  906.47us         2  453.23us  447.23us  459.23us  [CUDA memcpy HtoD]
                    2.48%  49.408us         1  49.408us  49.408us  49.408us  readOffset(float*, float*, float*, int, int)
                    2.40%  48.001us         1  48.001us  48.001us  48.001us  warmup(float*, float*, float*, int, int)
      API calls:   93.88%  603.77ms         3  201.26ms  313.00us  603.14ms  cudaMalloc
                    5.02%  32.299ms         1  32.299ms  32.299ms  32.299ms  cudaDeviceReset
                    0.52%  3.3638ms         3  1.1213ms  585.30us  2.1168ms  cudaMemcpy
                    0.40%  2.5464ms         1  2.5464ms  2.5464ms  2.5464ms  cuDeviceGetPCIBusId
                    0.13%  833.20us         3  277.73us  167.00us  455.50us  cudaFree
                    0.03%  206.30us         2  103.15us  68.900us  137.40us  cudaDeviceSynchronize
                    0.01%  65.800us         2  32.900us  16.900us  48.900us  cudaLaunchKernel
                    0.00%  15.800us       101     156ns     100ns  1.4000us  cuDeviceGetAttribute
                    0.00%  5.5000us         1  5.5000us  5.5000us  5.5000us  cudaSetDevice
                    0.00%  4.9000us         1  4.9000us  4.9000us  4.9000us  cudaGetDeviceProperties
                    0.00%  1.2000us         2     600ns     600ns     600ns  cudaGetLastError
                    0.00%     900ns         3     300ns     100ns     600ns  cuDeviceGetCount
                    0.00%     800ns         2     400ns     100ns     700ns  cuDeviceGet
                    0.00%     800ns         1     800ns     800ns     800ns  cuDeviceGetName
                    0.00%     500ns         1     500ns     500ns     500ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~


`[CUDA memcpy DtoH]`: Esta actividad representa la ejecución de una operación de copia de datos desde el dispositivo GPU a la memoria del host. Ocupa el 49.71% del tiempo de ejecución y se llama una vez. El tiempo de ejecución promedio de esta llamada es de 992.10 us, con un mínimo de 992.10 us y un máximo de 992.10 us. Esta operación se utiliza para transferir datos desde la GPU a la CPU.

`[CUDA memcpy HtoD]`: Esta actividad representa la ejecución de una operación de copia de datos desde la memoria del host al dispositivo GPU. Ocupa el 45.41% del tiempo de ejecución y se llama dos veces. El tiempo de ejecución promedio de cada llamada es de 453.23 us, con un mínimo de 447.23 us y un máximo de 459.23 us. Esta operación se utiliza para transferir datos desde la CPU a la GPU.

`readOffset(float*, float*, float*, int, int)`: Esta actividad representa la ejecución de una función llamada "readOffset". Ocupa el 2.48% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 49.408 us. Esta función realiza alguna operación relacionada con lectura de datos.

`warmup(float*, float*, float*, int, int)`: Esta actividad representa la ejecución de una función llamada "warmup". Ocupa el 2.40% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 48.001 us. Esta función parece ser una fase de calentamiento del código.

`cudaMalloc`: Esta llamada se utiliza para asignar memoria en el dispositivo GPU. Ocupa el 93.88% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 201.26 ms, con un mínimo de 313.00 us y un máximo de 603.14 ms. Esta función se utiliza para reservar espacio en la memoria del dispositivo.

`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo GPU. Ocupa el 5.02% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 32.299 ms. La función se utiliza para restablecer el dispositivo GPU a su estado inicial.

`cudaMemcpy`: Esta llamada se utiliza para copiar datos entre el host y el dispositivo GPU. Ocupa el 0.52% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 1.1213 ms, con un mínimo de 585.30 us y un máximo de 2.1168 ms. Esta función se utiliza para transferir datos entre la CPU y la GPU.

`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo GPU. Ocupa el 0.40% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.5464 ms. La función proporciona información sobre la conexión del dispositivo al bus PCI.

`cudaFree`: Esta llamada se utiliza para liberar la memoria previamente asignada en el dispositivo GPU. Ocupa el 0.13% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 277.73 us, con un mínimo de 167.00 us y un máximo de 455.50 us. Esta función se utiliza para liberar la memoria en el dispositivo GPU.

`cudaDeviceSynchronize`: Esta llamada se utiliza para sincronizar el dispositivo GPU. Ocupa el 0.03% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 103.15 us, con un mínimo de 68.900 us y un máximo de 137.40 us. La sincronización asegura que todas las operaciones en el dispositivo se completen antes de continuar.

`cudaLaunchKernel`: Esta llamada se utiliza para lanzar un kernel en el dispositivo GPU. Ocupa el 0.01% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 32.900 us, con un mínimo de 16.900 us y un máximo de 48.900 us. Esta función inicia la ejecución de kernels en el GPU.

`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. El tiempo promedio de ejecución de cada llamada es de 156 ns, con un mínimo de 100 ns y un máximo de 1.4000 us. La función proporciona información sobre diversas características del dispositivo.

`cudaSetDevice`: Se utiliza para seleccionar el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 5.5000 us. La función permite elegir el dispositivo en el que se realizarán las operaciones subsiguientes.

`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 4.9000 us. La función proporciona información detallada sobre las capacidades del dispositivo.

`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos GPU. Ocupa el 0.00% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 200 ns, con un mínimo de 100 ns y un máximo de 600 ns. La función determina cuántos dispositivos GPU están disponibles.

`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 600 ns, con un mínimo de 100 ns y un máximo de 1.0000 us. La función proporciona detalles sobre el dispositivo seleccionado.

`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 900 ns. La función se utiliza para verificar si se ha producido algún error en las operaciones anteriores.

`cuDeviceGetName`: Esta llamada se utiliza para obtener el nombre del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 800 ns. La función devuelve el nombre del dispositivo seleccionado.

`cuDeviceTotalMem`: Esta llamada se utiliza para obtener la cantidad total de memoria disponible en el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 500 ns. La función proporciona información sobre la capacidad de memoria del dispositivo.

`cuDeviceGetUuid`: Esta llamada se utiliza para obtener el identificador único del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 200 ns. La función proporciona un identificador único que puede utilizarse para identificar de manera única el dispositivo.

---
###   readSegmentUnroll
~~~
==985== NVPROF is profiling process 985, command: ./readSegmentUnroll
==985== Warning: Unified Memory Profiling is not supported on the current configuration because a pair of devices without peer-to-peer support is detected on this multi-GPU setup. When peer mappings are not available, system falls back to using zero-copy memory. It can cause kernels, which access unified memory, to run slower. More details can be found at: http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-managed-memory
==985== Profiling application: ./readSegmentUnroll
==985== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:   64.13%  2.0672ms         3  689.07us  470.56us  864.49us  [CUDA memcpy DtoH]
                   27.79%  895.65us         2  447.83us  446.53us  449.12us  [CUDA memcpy HtoD]
                    1.94%  62.593us         4  15.648us  15.360us  16.320us  [CUDA memset]
                    1.56%  50.368us         1  50.368us  50.368us  50.368us  readOffsetUnroll4(float*, float*, float*, int, int)
                    1.55%  49.984us         1  49.984us  49.984us  49.984us  readOffset(float*, float*, float*, int, int)
                    1.54%  49.632us         1  49.632us  49.632us  49.632us  readOffsetUnroll2(float*, float*, float*, int, int)
                    1.49%  47.904us         1  47.904us  47.904us  47.904us  warmup(float*, float*, float*, int, int)
      API calls:   93.30%  592.46ms         3  197.49ms  309.10us  591.77ms  cudaMalloc
                    5.46%  34.676ms         1  34.676ms  34.676ms  34.676ms  cudaDeviceReset
                    0.69%  4.4052ms         5  881.04us  498.20us  1.8633ms  cudaMemcpy
                    0.32%  2.0617ms         1  2.0617ms  2.0617ms  2.0617ms  cuDeviceGetPCIBusId
                    0.12%  749.60us         3  249.87us  170.00us  390.60us  cudaFree
                    0.06%  357.30us         4  89.325us  71.700us  130.70us  cudaDeviceSynchronize
                    0.02%  144.90us         4  36.225us  22.500us  52.700us  cudaMemset
                    0.01%  91.300us         4  22.825us  9.4000us  47.700us  cudaLaunchKernel
                    0.00%  14.600us       101     144ns     100ns  1.3000us  cuDeviceGetAttribute
                    0.00%  6.9000us         1  6.9000us  6.9000us  6.9000us  cudaGetDeviceProperties
                    0.00%  5.7000us         1  5.7000us  5.7000us  5.7000us  cudaSetDevice
                    0.00%  2.4000us         4     600ns     500ns     700ns  cudaGetLastError
                    0.00%  1.5000us         2     750ns     300ns  1.2000us  cuDeviceGet
                    0.00%  1.2000us         3     400ns     100ns     900ns  cuDeviceGetCount
                    0.00%     800ns         1     800ns     800ns     800ns  cuDeviceGetName
                    0.00%     400ns         1     400ns     400ns     400ns  cuDeviceTotalMem
                    0.00%     200ns         1     200ns     200ns     200ns  cuDeviceGetUuid
~~~
`[CUDA memcpy DtoH]`: Representa la ejecución de operaciones de copia de datos desde el dispositivo GPU a la memoria del host. Ocupa el 64.13% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 689.07 us, con un mínimo de 470.56 us y un máximo de 864.49 us. Estas operaciones transfieren datos desde la GPU a la CPU.

`[CUDA memcpy HtoD]`: Representa la ejecución de operaciones de copia de datos desde la memoria del host al dispositivo GPU. Ocupa el 27.79% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 447.83 us, con un mínimo de 446.53 us y un máximo de 449.12 us. Estas operaciones transfieren datos desde la CPU a la GPU.

`[CUDA memset]`: Representa la ejecución de operaciones de llenado de memoria en el dispositivo GPU. Ocupa el 1.94% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 15.648 us, con un mínimo de 15.360 us y un máximo de 16.320 us. Estas operaciones realizan un llenado de memoria en la GPU.
    
`readOffsetUnroll4(float*, float*, float*, int, int)`: Representa la ejecución de una función llamada "readOffsetUnroll4". Ocupa el 1.56% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 50.368 us. Esta función realiza alguna operación relacionada con la lectura de datos.

`readOffset(float*, float*, float*, int, int)`: Representa la ejecución de una función llamada "readOffset". Ocupa el 1.55% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 49.984 us. Esta función parece estar relacionada con la lectura de datos.

`readOffsetUnroll2(float*, float*, float*, int, int)`: Representa la ejecución de una función llamada "readOffsetUnroll2". Ocupa el 1.54% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 49.632 us. Esta función está relacionada con la lectura de datos.

`warmup(float*, float*, float*, int, int)`: Representa la ejecución de una función llamada "warmup". Ocupa el 1.49% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 47.904 us. Esta función parece ser una fase de calentamiento del código.
  
`cudaMalloc`: Se utiliza para asignar memoria en el dispositivo GPU. Ocupa el 93.30% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 197.49 ms, con un mínimo de 309.10 us y un máximo de 591.77 ms. Esta función se utiliza para reservar espacio en la memoria del dispositivo.

`cudaDeviceReset`: La función `cudaDeviceReset` se utiliza para reiniciar el dispositivo GPU. Ocupa el 5.46% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 34.676 ms. La función se utiliza para restablecer el dispositivo GPU a su estado inicial.

`cudaMemcpy`: Esta llamada se utiliza para copiar datos entre el host y el dispositivo GPU. Ocupa el 0.69% del tiempo de ejecución y se llama cinco veces. El tiempo promedio de ejecución de cada llamada es de 881.04 us, con un mínimo de 498.20 us y un máximo de 1.8633 ms. Esta función se utiliza para transferir datos entre la CPU y la GPU.

`cuDeviceGetPCIBusId`: Esta llamada se utiliza para obtener el identificador del bus PCI del dispositivo GPU. Ocupa el 0.32% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 2.0617 ms. La función proporciona información sobre la conexión del dispositivo al bus PCI.

`cudaFree`: Esta llamada se utiliza para liberar la memoria previamente asignada en el dispositivo GPU. Ocupa el 0.12% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 249.87 us, con un mínimo de 170.00 us y un máximo de 390.60 us. Esta función se utiliza para liberar la memoria en el dispositivo GPU.

`cudaDeviceSynchronize`: Esta llamada se utiliza para sincronizar el dispositivo GPU. Ocupa el 0.06% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 89.325 us, con un mínimo de 71.700 us y un máximo de 130.70 us. La sincronización asegura que todas las operaciones en el dispositivo se completen antes de continuar.

`cudaMemset`: Representa la ejecución de operaciones de llenado de memoria en el dispositivo GPU utilizando la función `cudaMemset`. Ocupa el 0.02% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 36.225 us, con un mínimo de 22.500 us y un máximo de 52.700 us. Estas operaciones llenan la memoria con un valor específico.

`cudaLaunchKernel`: Esta llamada se utiliza para lanzar un kernel en el dispositivo GPU. Ocupa el 0.01% del tiempo de ejecución y se llama cuatro veces. El tiempo promedio de ejecución de cada llamada es de 22.825 us, con un mínimo de 9.4000 us y un máximo de 47.700 us. Los kernels son funciones que se ejecutan en la GPU.

`cuDeviceGetAttribute`: Esta llamada se utiliza para obtener atributos del dispositivo. Ocupa el 0.00% del tiempo de ejecución y se llama 101 veces. El tiempo promedio de ejecución de cada llamada es de 144 ns, con un mínimo de 100 ns y un máximo de 1.3000 us. Esta función proporciona información sobre el dispositivo GPU.

`cudaSetDevice`: Se utiliza para seleccionar el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 6.9000 us. Esta función se utiliza para elegir el dispositivo GPU que se utilizará.

`cudaGetDeviceProperties`: Esta llamada se utiliza para obtener las propiedades del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 5.7000 us. La función proporciona información detallada sobre las características del dispositivo GPU.

`cuDeviceGetCount`: Esta llamada se utiliza para obtener el número de dispositivos GPU disponibles. Ocupa el 0.00% del tiempo de ejecución y se llama tres veces. El tiempo promedio de ejecución de cada llamada es de 400 ns, con un mínimo de 100 ns y un máximo de 900 ns. Esta función informa sobre la cantidad de dispositivos GPU en el sistema.

`cuDeviceGet`: Esta llamada se utiliza para obtener información del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama dos veces. El tiempo promedio de ejecución de cada llamada es de 550 ns, con un mínimo de 100 ns y un máximo de 1.0000 us. Esta función proporciona detalles sobre el dispositivo GPU.

`cudaGetLastError`: Esta llamada se utiliza para obtener el último error ocurrido en el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 900 ns. Esta función se emplea para verificar si se produjeron errores en las operaciones previas.

`cuDeviceGetName`: Esta llamada se utiliza para obtener el nombre del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 700 ns. La función proporciona el nombre del dispositivo GPU.
 
`cuDeviceTotalMem`: Esta llamada se utiliza para obtener la cantidad total de memoria disponible en el dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 400 ns. La función proporciona información sobre la capacidad de memoria del dispositivo.

`cuDeviceGetUuid`: Esta llamada se utiliza para obtener el identificador único del dispositivo GPU. Ocupa el 0.00% del tiempo de ejecución y se llama una vez. El tiempo de ejecución de esta llamada es de 200 ns. La función proporciona un identificador único que puede utilizarse para identificar de manera única el dispositivo.



        