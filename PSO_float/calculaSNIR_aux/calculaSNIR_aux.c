#include <stdio.h>
#include <stdlib.h>



void calculaSNIR_aux(PSO* pso, PSOAUX* psoaux, int z)
{
    int i,j;
    float* aux1 = NULL;
    float** aux2 = NULL;
    aux1 = alloca1DF(pso->K);
    aux2 = alloca2DF(pso->K,pso->K);

    for(i= 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->K; j ++)
        {
            aux2[i][j] = pso->Pgbest[j];
        }
    }
    for(i = 0; i < pso->K; i ++)
    {
        aux1[i] = 0.00;
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
        psoaux->SNIR[z][i] = (pso->F[i] * (pso->Pgbest[i] / (aux1[i] - pso->Pgbest[i] + (pso->Pn / pso->Gii[i]))));
    }
    aux1 = libera1DF(aux1);
    aux2 = libera2DF(aux2,pso->K);
}
