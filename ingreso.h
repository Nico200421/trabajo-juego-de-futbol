#ifndef INGRESO_H
#define INGRESO_H

#define Equipos 11
#define Nombreequipos 50

void variable(int *l, int *v);
void variablecadena(char l[], char v[]);
void ordenarEquipos(char equipos[Equipos][Nombreequipos], int puntos[], int NE);
void ingresarEquipos();
void ingresarResultados();

#endif  