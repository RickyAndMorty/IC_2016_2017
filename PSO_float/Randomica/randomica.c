#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float** randomica(int linhas, int colunas)
{
    float** matriz = NULL;
    matriz = alloca2DF(linhas,colunas);
    int i,j;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < linhas; i ++)
    {
        for(j = 0; j < colunas; j ++)
        {
            matriz[i][j] = ((float)(rand())) /RAND_MAX;
        }
    }
    return matriz;
}
