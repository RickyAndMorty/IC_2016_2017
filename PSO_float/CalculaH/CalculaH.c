#include <stdio.h>
#include <stdlib.h>

void calculaH(REDE* rede)
{
    int i,j;
    float** H1 = NULL;
    float** H2 = NULL;
    H1 = alloca2DF(rede->K,rede->K);
    H2 = alloca2DF(rede->K,rede->K);
    for(i = 0; i < rede->K; i ++)
    {
        for(j = 0; j < rede->K; j ++)
        {
            H1[i][j] = rede->g_t[j];
        }
    }
    for(i = 0; i < rede->K; i ++)
    {
        for(j = 0; j < rede->K; j ++)
        {
            H2[j][i] = rede->g_t[j];
        }
    }
    for(i = 0; i < rede->K; i ++)
    {
        for(j = 0; j < rede->K; j ++)
        {
            if(i == j)
            {
                rede->H[i][j] = H1[i][j] / H2[i][j] - 1.00F;
            }
            else
            {
                rede->H[i][j] = H1[i][j] / H2[i][j];
            }

        }
    }
    H1 = libera2DF(H1,rede->K);
    H2 = libera2DF(H2,rede->K);
}
