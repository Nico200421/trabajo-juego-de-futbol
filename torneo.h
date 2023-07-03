#ifndef TORNEO_H
#define TORNEO_H

#define Equipos 11
#define Nombreequipos 50

void variable(int *l, int *v);
void variablecadena(char l[], char v[]);
void ordenarEquipos(char equipos[Equipos][Nombreequipos], int puntos[], int NE);
void jugarPartidos(char equipos[Equipos][Nombreequipos], int puntos[], int NE);
void mostrarTabla(char equipos[Equipos][Nombreequipos], int puntos[], int NE);
void jugarTorneo();

#endif  