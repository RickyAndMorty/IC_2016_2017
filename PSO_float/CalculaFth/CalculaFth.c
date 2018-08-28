#include <stdio.h>
#include <stdlib.h>

void calculaFth(PSO* pso, REDE* rede)
{
    int i,j;
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            if(pso->SNIR[i][j] > rede->SNR_target)
            {
                pso->Fth[i][j] = 1.00F;
            }
            else
            {
                pso->Fth[i][j] = 0.00F;
            }
        }
    }
}
