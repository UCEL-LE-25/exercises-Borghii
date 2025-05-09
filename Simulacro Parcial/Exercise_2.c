#include <stdio.h>

const int dañoHechizoMago =40; 

int main()
{

    int manaEnemigo=0;
    int dañoInfligido=0;

    do
    {
        printf("Ingrese el mana del enemigo debe estar entre 120-300:\n");
        scanf("%d", &manaEnemigo);
        if (manaEnemigo < 120 || manaEnemigo > 300)
        {
            printf("El mana ingresado no es valido, por favor intente de nuevo.\n");
        }

    } while (manaEnemigo < 120 || manaEnemigo > 300);

    

    dañoInfligido = dañoHechizoMago + (int)(0.15 * manaEnemigo);


    if (dañoInfligido>80)
    {
        printf("Critical hit\n");
        printf("Daño infligido: %d\n", dañoInfligido);
    }
    else
    {
        printf("Normal hit\n");
        printf("Daño infligido: %d\n", dañoInfligido);

    }
    
    




    return 0;
}

