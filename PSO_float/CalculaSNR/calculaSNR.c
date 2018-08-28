#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void  calculaSNR(PSO* pso, REDE* rede)
{
    int i;
    for(i = 0; i < pso->K; i ++)
    {
        pso->SNR[i] = 10.00 * (log(pso->SNIR[i][pso->M-1] * ((rede->q*rede->q) / rede->sigma_cc2)) / log(10.00));
    }

}
