#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int resultadoFlechas[10]={0};


int main()
{
    int length = sizeof(resultadoFlechas)/sizeof(resultadoFlechas[0]);
    int randomNumber = 0;
    int flechasAcertadas=0;
    int flechasFalladas=0;

    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        randomNumber = rand() % 100 + 1; 

        if(randomNumber <= 60)
        {
            resultadoFlechas[i]=1;
            flechasAcertadas++;
        }
        else
        {
            resultadoFlechas[i]=0;
            flechasFalladas++;
        }
    }


    
    printf("Flechas acertadas: %d\n", flechasAcertadas);
    printf("Flechas falladas: %d\n", flechasFalladas);
    printf("Porcentaje de aciertos: %.2f%%\n", (float)flechasAcertadas / length * 100);

    for (int i = 0; i < length; i++)
    {
        printf("%d",resultadoFlechas[i]);

        if (i < 9)
        {
            printf(", ");
        }
        
    }

    return 0;
}
