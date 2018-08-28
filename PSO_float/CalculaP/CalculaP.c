#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void CalculaP(PSO* pso)
{
    int i,j;
    //float a;


    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            pso->P[i][j] = (((float)(rand())) / RAND_MAX) / 100.00F;

        }
    }

}
