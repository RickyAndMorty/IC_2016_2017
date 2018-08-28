#include <stdio.h>
#include <stdlib.h>


void calculaVelocidade(PSO* pso)
{
    int i,j;
    float** aux1 = NULL;
    float** rand1 = NULL;
    float** rand2 = NULL;
    aux1 = alloca2DF(pso->K,pso->M);
    rand1 = randomica(pso->K,pso->M);
    rand2 = randomica(pso->K,pso->M);
    for(i = 0; i < pso->M; i ++)
    {
        for(j = 0; j < pso->K; j ++)
        {
            aux1[j][i] = pso->Pgbest[j];
        }
    }
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            pso->v[i][j] = pso->Wadp * pso->v[i][j] + pso->c1 * rand1[i][j]*(pso->Pibest[i][j] - pso->P[i][j]) +  pso->c2*rand2[i][j]*(aux1[i][j] - pso->P[i][j]);
        }
    }
    aux1 = libera2DF(aux1,pso->K);
    rand1 = libera2DF(rand1,pso->K);
    rand2 = libera2DF(rand2,pso->K);
}
void calculaMelhorLocal(PSO* pso)
{
    int i,j;
    for(i = 0; i < pso->M; i ++)
    {
        if(pso->jP[i] > pso->jPibest[i])
        {
            for(j = 0; j < pso->K; j ++)
            {
                pso->Pibest[j][i] = pso->P[j][i];
            }
            pso->jPibest[i] = pso->jP[i];
        }
    }
}

void calculaMelhorGlobal(PSO* pso)
{
    int i;
    float* MaxJ = NULL;
    int * idx = NULL;
    MaxJ = alloca1DF(pso->M);
    idx = alloca1DI(pso->M);
    insertionSort(pso->jP,MaxJ,idx,pso->M);
    if(MaxJ[pso->M - 1] > pso->jPgbest)
    {
        pso->jPgbest = MaxJ[pso->M - 1];
        for(i = 0; i < pso->K; i ++)
        {
            pso->Pgbest[i] = pso->P[i][idx[pso->M - 1]];
        }
    }
    MaxJ = libera1DF(MaxJ);
    idx = libera1DI(idx);
}
void fitness(PSO* pso)
{
    int i,j;
    float** aux1 = NULL;
    float* aux2 = NULL;
    aux1 = alloca2DF(pso->K,pso->M);
    aux2 = alloca1DF(pso->M);
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            aux1[i][j] = (pso->Fth[i][j] * (1.00F - (pso->P[i][j] / pso->Pmax)));
        }
    }
    for(i = 0; i < pso->M; i ++)
    {
        aux2[i] = 0.00F;
    }
    for(i = 0; i < pso->M; i ++)
    {
        for(j = 0; j < pso->K; j ++)
        {
            aux2[i] = aux2[i] + aux1[j][i];
        }
    }
    for(i = 0; i < pso->M; i ++)
    {
        pso->jP[i] = (1.00F / pso->K) * aux2[i];
    }
    aux1 = libera2DF(aux1,pso->K);
    aux2 = libera1DF(aux2);
}
void calculaSNIR(PSO* pso)
{
    int i,j,z;
    float* aux1 = NULL;
    float** aux2 = NULL;
    aux1 = alloca1DF(pso->K);
    aux2 = alloca2DF(pso->K,pso->K);
    for(z = 0; z < pso->M; z ++)
    {
        for(i= 0; i < pso->K; i ++)
        {
            for(j = 0; j < pso->K; j ++)
            {
                aux2[i][j] = pso->P[j][z];
            }
        }
        for(i = 0; i < pso->K; i ++)
        {
            aux1[i] = 0.00F;
        }
        for(i = 0; i < pso->K; i ++)
        {
            for(j = 0; j < pso->K; j ++)
            {
                aux1[i] = aux1[i] + (aux2[i][j] * pso->G[i][j]);
            }
        }
        for(i = 0; i < pso->K; i ++)
        {
            pso->SNIR[i][z] = (pso->F[i] * (pso->P[i][z] / (aux1[i] - pso->P[i][z] + (pso->Pn / pso->Gii[i]))));
        }
    }
    aux1 = libera1DF(aux1);
    aux2 = libera2DF(aux2,pso->K);
}
void speedBounds(PSO* pso)
{
    int i,j;
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            if(pso->v[i][j] > pso->Vmax)
            {
                pso->v[i][j] = pso->Vmax;
            }
            else if(pso->v[i][j] < pso->Vmin)
            {
                pso->v[i][j] = pso->Vmin;
            }
        }
    }
}
void populationUpdate(PSO* pso)
{
    int i,j;
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            pso->P[i][j] = pso->P[i][j] + pso->v[i][j];
        }
    }
}
void powerBounds(PSO* pso)
{
    int i,j;
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            if(pso->P[i][j] < pso->Pmin)
            {
                pso->P[i][j] = pso->Pmin;
            }
            if(pso->P[i][j] > pso->Pmax)
            {
                pso->P[i][j] = pso->Pmax;
            }
        }
    }
}
void inserirPSO(PSO* pso, REDE* rede)
{
    pso->c1 = 1.600000F;
    pso->c2 = 1.600000F;
    pso->Wadp = 0.922222F;
    pso->K = 16;
    pso->M = 34;
    pso->iteracoes = 1800;
    pso->jPgbest = 0.00;

    pso->SNIR = alloca2DF(pso->K,pso->M);
    pso->P = alloca2DF(pso->K,pso->M);
    pso->G = alloca2DF(pso->K,pso->K);
    pso->Fth = alloca2DF(pso->K,pso->M);
    pso->v = alloca2DF(pso->K,pso->M);
    pso->Pibest = alloca2DF(pso->K,pso->M);
    pso->Gii = alloca1DF(pso->K);
    pso->F = alloca1DF(pso->K);
    pso->SNR = alloca1DF(pso->K);
    pso->Pgbest = alloca1DF(pso->K);
    pso->jP = alloca1DF(pso->M);
    pso->jPibest = alloca1DF(pso->M);

    /*Passando os dados da rede para o PSO*/
    pso->Pmax = rede->Pmax;
    pso->Pn = rede->Pn;
    pso->Pmax = rede->Pmax;
    pso->Pmin = rede->Pmin;
    pso->Vmax = rede->Vmax;
    pso->Vmin = rede->Vmin;
    pso->Gii = rede->g_t;
    pso->F = rede->F;
}
