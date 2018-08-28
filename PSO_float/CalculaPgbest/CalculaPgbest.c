#include <stdio.h>
#include <stdlib.h>

void calculaPgbest(PSO * pso)
{
    int i;
    for(i = 0; i < pso->K; i ++)
    {
        pso->Pgbest[i] = pso->Pmax;
    }
}
void calculaPgbest2(float** Pgbest, float** P, int K,int M)
{
    int i,j;
    for(i = 0; i < K; i ++)
    {
        for(j = 0; j < M; j ++)
        {
            Pgbest[i][j] = P[i][j];
        }
    }
}
