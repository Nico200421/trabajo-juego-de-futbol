#include <stdio.h>
#include "resultados.h"

void mostrarResultados() {
    FILE *archivoResultados;
    archivoResultados = fopen("resultados.txt", "r");
    if (archivoResultados == NULL) {
        printf("No se pudo abrir el archivo resultados.txt.\n");
        return;
    }

    char resultado[100];
    printf("\nTabla de resultados de los partidos:\n");
    while (fgets(resultado, sizeof(resultado), archivoResultados) != NULL) {
        printf("%s", resultado);
    }

    fclose(archivoResultados);
}
