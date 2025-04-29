#include <stdio.h>


int dias;
int regiones;

int main()
{

    printf("Ingrese la cantidad de dias para cargar recursos: \n");
    scanf("%d", &dias);

    printf("Ingrese la cantidad de regiones: \n");
    scanf("%d", &regiones);

    int recursosDia[3][dias];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < dias; j++) {
            recursosDia[i][j] = 0;
        }
    }

    

    for (int i = 0; i < dias; i++) {
        for (int j  = 0; j < regiones; j++)
        {
            int cant;
            
            printf("Ingrese la cantidad de agua para la region %d en el dia %d: \n", j + 1, i + 1);
            scanf("%d", &cant);
            recursosDia[i][0]+=cant;

            printf("Ingrese la cantidad de alimentos para la region %d en el dia %d: \n", j + 1, i + 1);
            scanf("%d", &cant);
            recursosDia[i][1]+=cant;

            printf("Ingrese la cantidad de medicina para la region %d en el dia %d: \n", j + 1, i + 1);
            scanf("%d", &cant);
            recursosDia[i][2]+=cant;

        }

    }


    int totalRecursos=0;
    int totalAgua=0;
    int totalAlimentos=0;
    int totalMedicinas=0;

    for (int i = 0; i < dias; i++) {
        for (int j  = 0; j < 3; j++)
        {
            totalRecursos+=recursosDia[i][j];
        }
        totalAgua+=recursosDia[i][0];
        totalAlimentos+=recursosDia[i][1];
        totalMedicinas+=recursosDia[i][2];
    }

    int promedioAgua=totalAgua/dias;
    int promedioAlimentos=totalAlimentos/dias;
    int promedioMedicinas=totalMedicinas/dias;

    printf("Cant recursos distribuidos: %d \n", totalRecursos);

    if (totalAgua>totalMedicinas && totalMedicinas>totalAlimentos)
    {
        printf("El recuros que recibio mayotr disribucion fue el agua con %d \n ", totalAgua);

    }else if (totalMedicinas>totalAgua && totalAgua>totalAlimentos)
    {
        printf("El recuros que recibio mayor disribucion fue la medicina con %d \n ", totalMedicinas);

    }else{
        printf("El recuros que recibio mayor disribucion fue el alimento con %d \n ", totalAlimentos);
    }

    printf("Promedio agua: %d \n", promedioAgua);
    printf("Promedio alimentos: %d \n", promedioAlimentos);
    printf("Promedio medicina: %d \n", promedioMedicinas);

    

    return 0;
}
