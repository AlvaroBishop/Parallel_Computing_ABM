#include <stdio.h>

int main() {
    int matriz1[10][10], matriz2[10][10], suma[10][10];

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

    // Sumar las dos matrices
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            suma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Mostrar la matriz resultante
    printf("La suma de las matrices es:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", suma[i][j]);
        }
        printf("\n");
    }

    return 0;
}
