#include <stdio.h>
#include <stdlib.h>


float* alloca1DF(int colunas)
{
    float* vetor = NULL;
    vetor = ((float*)malloc(colunas * sizeof(float)));
    if(vetor == NULL)
    {
        printf("Erro.\n");
        exit(1);
    }
    return vetor;
}
float** alloca2DF(int linhas, int colunas)
{
    int i;
    float** matriz = NULL;
    matriz = ((float**)malloc(linhas * sizeof(float*)));
    if(matriz == NULL)
    {
        printf("Erro.\n");
        exit(1);
    }
    for(i = 0; i < linhas; i ++)
    {
        matriz[i] = ((float*)malloc(colunas * sizeof(float)));
        if(matriz[i] == NULL)
        {
            printf("Erro.\n");
            exit(1);
        }
    }
    return matriz;
}
float* libera1DF(float* vetor)
{
    free(vetor);
    vetor = NULL;
    return vetor;
}
float** libera2DF(float** matriz,int linhas)
{
    int i;
    for(i = 0; i < linhas; i ++)
    {
        free(matriz[i]);
        matriz[i] = NULL;
    }
    free(matriz);
    matriz = NULL;
    return matriz;
}
int * alloca1DI(int colunas)
{
    int* vetor = NULL;
    vetor = ((int*) malloc(colunas * sizeof(int)));
    if(vetor == NULL)
    {
        printf("Erro.\n");
        exit(1);
    }
    return vetor;
}
int* libera1DI(int* vetor)
{
    free(vetor);
    vetor = NULL;
    return vetor;
}

REDE* allocaREDE()
{

    REDE* rede = ((REDE*)malloc(sizeof(REDE)));
    if(rede == NULL)
    {
        printf("Erro.\n");
        exit(1);
    }
    return rede;
}
PSO* allocaPSO()
{
    PSO* pso = ((PSO*)malloc(sizeof(PSO)));
    if(pso == NULL)
    {
        printf("Erro.\n");
        exit(1);
    }
    return pso;
}
PSOAUX* allocaPSOAUX()
{
    PSOAUX* psoaux = ((PSOAUX*)malloc(sizeof(PSOAUX)));
    if(psoaux == NULL)
    {
        printf("Erro.\n");
        exit(1);
    }
    return psoaux;
}
