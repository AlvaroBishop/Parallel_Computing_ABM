# **Examen sobre Complejidad Temporal en Algoritmos, Programación Paralela y CUDA**

1. ¿Qué es la complejidad temporal de un algoritmo?
   - [ ] El número de instrucciones en un algoritmo.
   - [ ] La cantidad de memoria utilizada por un algoritmo.
   - [x] El tiempo que tarda un algoritmo en ejecutarse en función del tamaño de entrada.

2. ¿Cuál de las siguientes notaciones se utiliza comúnmente para describir la complejidad temporal de un algoritmo?
   - [ ] Números romanos. $I,II,III$ 
   - [ ] Notación big $\theta$     $\theta(N)$ 
   - [x] Notación big $O$      $O(n)$.

3. ¿Qué significa $O(log n)$  en la notación big O?
   - [x] El tiempo de ejecución del algoritmo crece de manera logarítmica con el tamaño de entrada.
   - [ ] El tiempo de ejecución del algoritmo es constante.
   - [ ] El tiempo de ejecución del algoritmo crece de manera lineal con el tamaño de entrada.

4. ¿Qué es la programación paralela en informática?
   - [ ] Un tipo de lenguaje de programación.
   - [ ] Un método para ocultar la complejidad de un algoritmo.
   - [x] Una técnica que utiliza múltiples hilos o procesadores para resolver un problema de manera simultánea.

5. ¿Cuál es uno de los beneficios clave de la programación paralela?
   - [ ] Mayor utilización de recursos de almacenamiento.
   - [x] Mayor capacidad de procesamiento y reducción de tiempos de ejecución.
   - [ ] Menor consumo de energía.

6. ¿Qué es CUDA en el contexto de la programación paralela?
   - [ ] Un lenguaje de programación paralela.
   - [x] Una plataforma de computación paralela desarrollada por NVIDIA&trade; 
   - [ ] Una técnica de programación secuencial.

7. ¿Cuál es el objetivo principal de CUDA?
   - [ ] Ejecutar algoritmos de manera secuencial.
   - [x] Aprovechar el poder de procesamiento de las tarjetas gráficas (GPUs) para cálculos paralelos.
   - [ ] Optimizar el uso de la memoria RAM.

8. ¿Cuál de las siguientes declaraciones sobre CUDA es cierta?
   - [ ] CUDA solo funciona en sistemas operativos Windows.
   - [x] CUDA es una plataforma de programación paralela que permite el desarrollo de aplicaciones para GPUs NVIDIA&trade; . 
   - [ ] CUDA se utiliza exclusivamente en aplicaciones de inteligencia artificial.

9. ¿Qué es un "kernel" en el contexto de CUDA?
   - [ ] Un tipo de unidad de procesamiento central (CPU).
   - [ ] Un tipo de tarjeta de video.
   - [x] Un pequeño programa o función que se ejecuta en la GPU de manera paralela.
1. ¿Cuál de las siguientes afirmaciones describe mejor la ventaja de utilizar CUDA en aplicaciones de procesamiento intensivo?
    - [ ] CUDA solo se utiliza para aplicaciones de bajo rendimiento.
    - [ ] CUDA solo es adecuado para aplicaciones de oficina.
    - [x] CUDA permite un aumento significativo en el rendimiento al aprovechar la potencia de cálculo de las GPUs.

## Calculo de complejidad de un algoritmo

Analiza los siguientes algoritmos y calcula su complejidad en _Big O notation_ 

Algoritmo 1:
```cpp
#include <iostream>

int algoritmo1(int n) {
    int resultado = 0;
    
    for (int i = 0; i < n; i++) {
        resultado += i; // Operación simple O(1)
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado += i * j; // Operación simple O(1)
        }
    }
    
    return resultado;
}

int main() {
    int n;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;
    
    int resultado = 1(n);
    std::cout << "Resultado: " << resultado << std::endl;
    
    return 0;
}

```
El primer for tiene una complejidad de O(n), el segundo for, al ser anidado tiene una complejidad de O(n^2). Por lo tanto la complejidad del algoritmo es O(n^2).

Algoritmo 2:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int algoritmo2(std::vector<int>& arr) {
    int n = arr.size();
    int resultado = 0;
    
    // Ordenamos el vector utilizando QuickSort con complejidad O(n log n)
    std::sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                resultado += arr[i] * arr[j] * arr[k];
            }
        }
    }
    
    return resultado;
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de elementos: ";
    std::cin >> n;
    
    std::vector<int> arr(n);
    std::cout << "Ingrese los elementos del vector:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int resultado = algoritmo2(arr);
    std::cout << "Resultado: " << resultado << std::endl;
    
    return 0;
}
-


```

El algoritmo sort tiene una complejidad de O(n log n), el for triple anidado tiene una complejidad de O(n^3), por lo tanto la complejidad del algoritmo es de  O(n^3)