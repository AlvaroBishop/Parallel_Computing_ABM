# Proyecto de Operaciones con Matrices

Este proyecto consiste en una aplicación de consola en C que realiza operaciones matriciales básicas, como la suma, resta y multiplicación de matrices de tamaño 10x10. El código proporcionado incluye las funciones necesarias para realizar estas operaciones y un programa principal que permite al usuario ingresar dos matrices y ver los resultados de las operaciones.

## Marco Teórico

### Matrices

Una matriz es una estructura bidimensional que consta de filas y columnas de elementos. En este proyecto, trabajamos con matrices cuadradas de 10x10, lo que significa que tienen 10 filas y 10 columnas. Cada elemento de la matriz se almacena en una ubicación específica identificada por su fila y columna.

### Multiplicación de Matrices

La multiplicación de dos matrices se realiza multiplicando filas de la primera matriz por columnas de la segunda matriz y sumando los productos resultantes. El elemento resultante en la fila i y columna j de la matriz resultante C se calcula como:

C[i][j] = Σ (A[i][k] * B[k][j]) para k de 0 a 9.

## Código

```c
#include <stdio.h>

// Prototipos de funciones
void sumaMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]);
void restaMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]);
void multiplicacionMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]);

int main() {
    int matriz1[10][10], matriz2[10][10], resultado[10][10];

    printf("Primera matriz: \n");
    // Leer la primera matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", j);
            matriz1[i][j] = j;
        }
        printf("\n");
    }

    printf("Segunda matriz: \n");
    // Leer la segunda matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", i);
            matriz2[i][j] = i;
        }
        printf("\n");
    }

    sumaMatrices(matriz1, matriz2, resultado);

    printf("La suma de las matrices es:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    restaMatrices(matriz1, matriz2, resultado);

    printf("La resta de las matrices es:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    multiplicacionMatrices(matriz1, matriz2, resultado);

    printf("La multiplicación de las matrices es:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void sumaMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void restaMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void multiplicacionMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            resultado[i][j] = 0; // Inicializar el elemento de resultado en 0
            for (int k = 0; k < 10; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}
```
## Analisis del Codigo
Para la funcion multiplicacionMatrices:
Realizo una iteracion a traves de las matrices utilizando tres bucles for anidados. Los bucles externos recorren las filas y los bucles internos recorren las columnas.

Antes de calcular el valor de cada elemento en resultado, inicializamos ese elemento en 0. 

Para calcular el valor de un elemento en la matriz resultado, utilizo el tercer bucle for interno que recorre las columnas de matriz1 y las filas de matriz2. Multiplico los elementos correspondientes de matriz1 y matriz2, y el valor acumulado se guarda en resultado. Este proceso se repite para cada elemento en resultado, calculando asi todos los elementos de la matriz resultante.

## Ejecución

Este código se puede compilar y ejecutar en un entorno de desarrollo de C. El programa solicitará que ingreses los elementos de la primera y segunda matriz, pero en el código proporcionado, las matrices ya se han inicializado con valores predefinidos para facilitar la prueba.

## Conclusiones

Este proyecto proporciona una implementación básica de operaciones matriciales en C. Puedes expandirlo agregando funciones adicionales o trabajando con matrices de diferentes tamaños. Además, puedes permitir que el usuario ingrese valores para las matrices en lugar de utilizar valores predefinidos.




