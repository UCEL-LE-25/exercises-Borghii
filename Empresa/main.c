#include <stdio.h>

int plantaUnidadesProducidas[3][4] = {0};
int plantaCostoFabricacion[3][4] = {0};
int plantaPrecioVenta[3][4] = {0};


void cargaDeDatos(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4]);
void plantaMayorRentabilidad(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4]);
void plantaMenorRentabilidad(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4]);
void promedioGananciaEmpresa(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4]);

int main()
{

    cargaDeDatos(plantaUnidadesProducidas,plantaCostoFabricacion,plantaPrecioVenta);
    plantaMayorRentabilidad(plantaUnidadesProducidas,plantaCostoFabricacion,plantaPrecioVenta);
    plantaMenorRentabilidad(plantaUnidadesProducidas,plantaCostoFabricacion,plantaPrecioVenta);
    promedioGananciaEmpresa(plantaUnidadesProducidas,plantaCostoFabricacion,plantaPrecioVenta);

    return 0;
}


void cargaDeDatos(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4] ){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese los datos del siguiente producto \n");
            printf("de la planta %d y del producto %d: \n",i+1,j+1 );
            printf("Ingrese la cantidad de unidades producidas: \n");
            scanf("%d",&plantaUnid[i][j]);
            printf("Ingrese el costo de fabricacion: \n");
            scanf("%d",&plantaCost[i][j]);
            printf("Ingrese el precio de venta: \n");
            scanf("%d",&plantaPrecio[i][j]);
        }
    }

}

void plantaMayorRentabilidad(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4]){

    int plantaMaxGanancias=0;
    int sumGanancias=0;
    int idPlantaMaxGanancias;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sumGanancias+= plantaUnid[i][j]*(plantaPrecio[i][j]-plantaCost[i][j]);

        }

        if (sumGanancias>plantaMaxGanancias)
        {
            idPlantaMaxGanancias=i+1;
            plantaMaxGanancias=sumGanancias;
        }

        sumGanancias=0;
    }
    printf("La planta con mayor ganancias es %d \n", idPlantaMaxGanancias);
}

void plantaMenorRentabilidad(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4]){

    int productoMenorGanancias=0;
    int sumGananciasProducto=0;
    int idPlanta;
    int idProducto;


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sumGananciasProducto+= plantaUnid[i][j]*(plantaPrecio[i][j]-plantaCost[i][j]);

            if (sumGananciasProducto<productoMenorGanancias)
            {
                productoMenorGanancias=sumGananciasProducto;
                idPlanta= i+1;
                idProducto=j+1;
            }

            sumGananciasProducto=0;
        }

    }
    printf("El producto con menor margen economico pertenece a la planta %d con un id %d \n", idPlanta,idProducto);
}

void promedioGananciaEmpresa(int plantaUnid[3][4],int plantaCost[3][4],int plantaPrecio[3][4]){

    int sumGanancias=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sumGanancias+= plantaUnid[i][j]*(plantaPrecio[i][j]-plantaCost[i][j]);
        }
    }

    printf("El promedio de ganania de la empresa es %.2f: \n", (float)sumGanancias/3);
}