#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_NOMBRE 50

struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float notaFinal;
};


void agregarEstudiante(struct Estudiante estudiantes[], int *cantidad);


int main() {
    struct Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidad = 0;
    int opcion;

    do {
        printf("Seleccione opcion:\n");
        printf("1. Agregar nuevo estudiante\n");
        printf("2. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, &cantidad);
                break;
            case 2:
            printf("Saliendo del programa.\n");
            break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 2);

    return 0;
}

void agregarEstudiante(struct Estudiante estudiantes[], int *cantidad) {
    if (*cantidad >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar mas estudiantes.\n");
        return 0;
    }

    printf("Nombre: ");
    scanf("%s", estudiantes[*cantidad].nombre);

    printf("Edad: ");
    scanf("%d", &estudiantes[*cantidad].edad);

    printf("Nota final: ");
    scanf("%f", &estudiantes[*cantidad].notaFinal);

    (*cantidad)++;
}
