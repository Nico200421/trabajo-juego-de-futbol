#include <stdio.h>
#include <string.h>
#include "ingreso.h"

void variable(int *l, int *v) {
    int temp = *l;
    *l = *v;
    *v = temp;
}

void variablecadena(char l[], char v[]) {
    char temp[Nombreequipos];
    strcpy(temp, l);
    strcpy(l, v);
    strcpy(v, temp);
}

void ordenarEquipos(char equipos[Equipos][Nombreequipos], int puntos[], int NE) {
    for (int i = 0; i < NE - 1; i++) {
        for (int j = 0; j < NE - i - 1; j++) {
            if (puntos[j] < puntos[j + 1]) {
                variable(&puntos[j], &puntos[j + 1]);
                variablecadena(equipos[j], equipos[j + 1]);
            }
        }
    }
}

void ingresarEquipos() {
    char equipos[Equipos][Nombreequipos];
    int NE = 0;
    FILE *archivo;

    archivo = fopen("equipos.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Ingrese el nombre de los equipos (ingrese 'terminar' para finalizar):\n");
    while (1) {
        char nombreEquipo[Nombreequipos];
        printf("Equipo %d: ", NE + 1);
        scanf("%s", nombreEquipo);
        if (strcmp(nombreEquipo, "terminar") == 0) {
            break;
        }
        strcpy(equipos[NE], nombreEquipo);
        NE++;
        fprintf(archivo, "%s\n", nombreEquipo);
    }

    fclose(archivo);

    printf("\nEquipos ingresados:\n");
    for (int i = 0; i < NE; i++) {
        printf("%d. %s\n", i + 1, equipos[i]);
    }
}

void ingresarResultados() {
    char equipos[Equipos][Nombreequipos];
    int NE = 0;
    int puntos[Equipos] = {0};
    FILE *archivoResultados;

    archivoResultados = fopen("resultados.txt", "w");
    if (archivoResultados == NULL) {
        printf("No se pudo abrir el archivo resultados.txt.\n");
        return;
    }

    printf("\nIngrese los resultados de los partidos:\n");
    for (int i = 0; i < NE; i++) {
        for (int j = i + 1; j < NE; j++) {
            int GEL, GEV;
            printf("%s vs %s: ", equipos[i], equipos[j]);
            scanf("%d %d", &GEL, &GEV);
            if (GEL > GEV) {
                puntos[i] += 3;
            } else if (GEL < GEV) {
                puntos[j] += 3;
            } else {
                puntos[i] += 1;
                puntos[j] += 1;
            }
            fprintf(archivoResultados, "%s %d - %d %s\n", equipos[i], GEL, GEV, equipos[j]);
        }
    }

    fclose(archivoResultados);

    ordenarEquipos(equipos, puntos, NE);

    printf("\nTabla de resultados de los partidos:\n");
    archivoResultados = fopen("resultados.txt", "r");
    if (archivoResultados == NULL) {
        printf("No se pudo abrir el archivo resultados.txt.\n");
        return;
    }

    char resultado[100];
    while (fgets(resultado, sizeof(resultado), archivoResultados) != NULL) {
        printf("%s", resultado);
    }

    fclose(archivoResultados);

    printf("\nTabla de puntos:\n");
    for (int i = 0; i < NE; i++) {
        printf("%s: %d puntos\n", equipos[i], puntos[i]);
    }
}
