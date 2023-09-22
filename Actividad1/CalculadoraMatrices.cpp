#include <stdio.h>

// Prototipos de funciones
void sumaMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]);
void restaMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]);
void multiplicacionMatrices(int matriz1[10][10], int matriz2[10][10], int resultado[10][10]);

int main() {
    int matriz1[10][10], matriz2[10][10], resultado[10][10];


    //printf("Ingrese los elementos de la primera matriz:\n");
    printf("primera matriz: \n");
    // Leer la primera matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
             // si se quiere que el usuario ingrese los valores:
             // printf("Ingrese el elemento en la fila %d y columna %d: ", i + 1, j + 1);
             // scanf_s("%d", &matriz2[i][j]);
            printf("%d ", j);
            matriz1[i][j] = j;
        }
        printf("\n");
    }

    //printf("Ingrese los elementos de la segunda matriz:\n");
    printf("segunda matriz: \n");
    // Leer la segunda matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // si se quiere que el usuario ingrese los valores:
            // printf("Ingrese el elemento en la fila %d y columna %d: ", i + 1, j + 1);
            // scanf_s("%d", &matriz2[i][j]);
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

