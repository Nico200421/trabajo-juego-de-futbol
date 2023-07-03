#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "torneo.h"

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

void jugarPartidos(char equipos[Equipos][Nombreequipos], int puntos[], int NE) {
    srand(time(NULL));
    printf("\nResultados de los partidos generados automáticamente:\n");
    for (int i = 0; i < NE; i++) {
        for (int j = i + 1; j < NE; j++) {
            int GEL = rand() % 5;
            int GEV = rand() % 5;
            printf("%s %d - %d %s\n", equipos[i], GEL, GEV, equipos[j]);
            if (GEL > GEV) {
                puntos[i] += 3;
            } else if (GEL < GEV) {
                puntos[j] += 3;
            } else {
                puntos[i] += 1;
                puntos[j] += 1;
            }
        }
    }
}

void mostrarTabla(char equipos[Equipos][Nombreequipos], int puntos[], int NE) {
    ordenarEquipos(equipos, puntos, NE);

    printf("\nTabla de resultados de los partidos:\n");
    for (int i = 0; i < NE; i++) {
        printf("%d. %s: %d puntos\n", i + 1, equipos[i], puntos[i]);
    }
}

void jugarTorneo() {
    char equipos[Equipos][Nombreequipos];
    int NE = 0;
    int puntos[Equipos] = {0};

    FILE *archivo;
    archivo = fopen("equipos.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo equipos.txt.\n");
        return;
    }

    printf("Equipos ingresados:\n");
    while (fgets(equipos[NE], Nombreequipos, archivo) != NULL) {
        equipos[NE][strlen(equipos[NE]) - 1] = '\0';  // Remove the newline character
        printf("%d. %s\n", NE + 1, equipos[NE]);
        NE++;
    }

    fclose(archivo);

    jugarPartidos(equipos, puntos, NE);

    mostrarTabla(equipos, puntos, NE);
}
