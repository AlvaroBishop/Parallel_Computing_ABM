# Ejercicio Memoria compartida
Este código en C utiliza la biblioteca CUDA para realizar operaciones en paralelo en una GPU. El objetivo principal es aplicar un relleno (padding) a una matriz bidimensional y luego calcular la suma de las columnas de la matriz resultante. A continuación, se presenta una descripción detallada del código.

## Kernels CUDA
### Kernel applyPaddingKernel
Este kernel se encarga de aplicar el relleno a la matriz original. Cada hilo de CUDA corresponde a un elemento de la matriz, y si el índice del hilo está dentro de los límites de la matriz original, se realiza la operación de relleno.

```c
__global__ void applyPaddingKernel(int *inputMatrix, int *paddedMatrix, int width, int height, int paddingX) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        paddedMatrix[row * (width + paddingX) + col + paddingX] = inputMatrix[row * width + col];
    }
}
```
Kernel sumColumnsKernel
Este kernel calcula la suma de las columnas de la matriz resultante después de aplicar el relleno. Cada hilo se encarga de sumar los elementos de una columna específica.

``` c

__global__ void sumColumnsKernel(int *matrix, int *result, int width, int height) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (col < width) {
        int sum = 0;
        for (int row = 0; row < height; ++row) {
            sum += matrix[row * width + col];
        }
        result[col] = sum;
    }
}
```
Funciones Auxiliares
Función printMatrix
Esta función imprime una matriz en la consola. Se utiliza para mostrar la matriz original, la matriz con relleno y la suma de columnas.

``` c

void printMatrix(int *matrix, int rows, int cols, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i * cols + j]);
        }
        printf("\n");
    }
}
```
Función Principal main
La función principal realiza lo siguiente:

- Inicializa la matriz original con valores aleatorios.
- Imprime la matriz original.
- Reserva memoria en la GPU para las matrices originales y los resultados intermedios.
- Transfiere la matriz original a la GPU.
- Llama al kernel applyPaddingKernel para aplicar el relleno.
- Transfiere los resultados de vuelta a la CPU e imprime la matriz con relleno.
- Llama al kernel sumColumnsKernel para calcular la suma de las columnas.
- Transfiere los resultados finales a la CPU e imprime la suma de las columnas.
- Libera la memoria de la GPU.
- Este código utiliza la GPU para realizar operaciones en paralelo, mejorando así el rendimiento en comparación con enfoques puramente secuenciales en la CPU.

``` c
#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#define MATRIX_SIZE_X 5
#define MATRIX_SIZE_Y 5
#define PADDING_SIZE_X 1
#define BLOCK_SIZE_X 16
#define BLOCK_SIZE_Y 16

// Kernel para aplicar el relleno (padding)
__global__ void applyPaddingKernel(int *inputMatrix, int *paddedMatrix, int width, int height, int paddingX) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        paddedMatrix[row * (width + paddingX) + col + paddingX] = inputMatrix[row * width + col];
    }
}

// Kernel para sumar las columnas
__global__ void sumColumnsKernel(int *matrix, int *result, int width, int height) {
    unsigned int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (col < width) {
        int sum = 0;
        for (int row = 0; row < height; ++row) {
            sum += matrix[row * width + col];
        }
        result[col] = sum;
    }
}

// Función para imprimir una matriz
void printMatrix(int *matrix, int rows, int cols, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int originalMatrix[MATRIX_SIZE_X][MATRIX_SIZE_Y];
    int paddedMatrix[(MATRIX_SIZE_X + PADDING_SIZE_X) * MATRIX_SIZE_Y];
    int columnSumResult[MATRIX_SIZE_Y];

    // Inicialización de la matriz original
    for (int i = 0; i < MATRIX_SIZE_X; ++i) {
        for (int j = 0; j < MATRIX_SIZE_Y; ++j) {
            originalMatrix[i][j] = (rand() % 9) + 1;
        }
    }

    // Imprime la matriz original
    printMatrix((int *)originalMatrix, MATRIX_SIZE_X, MATRIX_SIZE_Y, "Original");

    // Variables para GPU
    int *d_originalMatrix, *d_paddedMatrix, *d_columnSumResult;

    // Asignación de memoria en GPU
    cudaMalloc((void **)&d_originalMatrix, MATRIX_SIZE_X * MATRIX_SIZE_Y * sizeof(int));
    cudaMalloc((void **)&d_paddedMatrix, (MATRIX_SIZE_X + PADDING_SIZE_X) * MATRIX_SIZE_Y * sizeof(int));
    cudaMalloc((void **)&d_columnSumResult, MATRIX_SIZE_Y * sizeof(int));

    // Copia la matriz original a la GPU
    cudaMemcpy(d_originalMatrix, originalMatrix, MATRIX_SIZE_X * MATRIX_SIZE_Y * sizeof(int), cudaMemcpyHostToDevice);

    // Definición de las dimensiones de bloque y cuadrícula
    dim3 gridDim((MATRIX_SIZE_Y + BLOCK_SIZE_X - 1) / BLOCK_SIZE_X, (MATRIX_SIZE_X + BLOCK_SIZE_Y - 1) / BLOCK_SIZE_Y, 1);
    dim3 blockDim(BLOCK_SIZE_X, BLOCK_SIZE_Y, 1);

    // Llama al kernel para aplicar el relleno
    applyPaddingKernel<<<gridDim, blockDim>>>(d_originalMatrix, d_paddedMatrix, MATRIX_SIZE_Y, MATRIX_SIZE_X, PADDING_SIZE_X);

    // Copia los resultados de GPU a CPU
    cudaMemcpy(paddedMatrix, d_paddedMatrix, (MATRIX_SIZE_X + PADDING_SIZE_X) * MATRIX_SIZE_Y * sizeof(int), cudaMemcpyDeviceToHost);

    // Imprime la matriz con relleno
    printMatrix(paddedMatrix, MATRIX_SIZE_X + PADDING_SIZE_X, MATRIX_SIZE_Y, "Con Relleno");

    // Llama al kernel para sumar las columnas
    sumColumnsKernel<<<gridDim, blockDim>>>(d_paddedMatrix, d_columnSumResult, MATRIX_SIZE_Y, MATRIX_SIZE_X + PADDING_SIZE_X);

    // Copia los resultados de la suma de columnas de GPU a CPU
    cudaMemcpy(columnSumResult, d_columnSumResult, MATRIX_SIZE_Y * sizeof(int), cudaMemcpyDeviceToHost);

    // Imprime las sumas de las columnas
    printMatrix(columnSumResult, 1, MATRIX_SIZE_Y, "Suma de Columnas");

    // Libera la memoria de GPU
    cudaFree(d_originalMatrix);
    cudaFree(d_paddedMatrix);
    cudaFree(d_columnSumResult);

    return 0;
}
