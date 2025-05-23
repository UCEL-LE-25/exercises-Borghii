#include <stdio.h>


int main()
{
    
    return 0;
}

// 1. mal redactado
void printMaxMin(int arr[]){

    int length= sizeof(arr)/sizeof(arr[0]);
    
}


//2.

int contarPares(int *arr, int n){


    int pares = 0;

    for(int i; i<n; i++){
        if (arr[i]%2 ==0)
        {
            pares++;
        }
        
    }

    return pares;
}

//3. 

int* filtrarMayores(int *arr, int n, int umbral, int *out){
    int indexOut=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>umbral)
        {
            out[indexOut]=arr[i];
            indexOut++;
        }
    }
    return arr;
}

//4.

typedef struct {
    int sumValoresNoNegativos;
    int cantValoresNegativos;
} Estadistica;

Estadistica procesaMatriz(int N, int mat[N][N]){

    Estadistica estadistica;

    if (N<2 || N>5 )
    {
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int currentValue = mat[i][j];
            if(currentValue<0){
                estadistica.cantValoresNegativos++;
            }else{
                estadistica.sumValoresNoNegativos+=currentValue;
            }
        }
    }


    return estadistica;
} 

//5.

typedef struct{

    int nroSemana;
    int ventasDiarias[7];
    int totalSemanal;

} Venta;


void registraVentas(int M, Venta semanas[]){

}