#include <stdio.h>
#include <stdlib.h>



void gravarSNR(PSOAUX* psoaux)
{
    FILE *pArq;
    int i;
    if((pArq = fopen("C:/Users/Ricardo Santos/Documents/PSO_float/resultados/SNR.bin", "wb")) == 0x0)
    {
        printf("erro.");
        exit(1);
    }

    for(i = 0; i < psoaux->K ; i ++)
    {
        fprintf(pArq, "%f\n",psoaux->SNR[i]);
    }

    if(fclose(pArq))
    {
        printf("erro.");
        exit(1);
    }
}
void gravarPAUX(PSOAUX* psoaux)
{
    FILE *pArq;
    int i,j;
    if((pArq = fopen("C:/Users/Ricardo Santos/Documents/PSO_float/resultados/P.bin", "wb")) == 0x0)
    {
        printf("erro.");
        exit(1);
    }

    for(i = 0; i < psoaux->K ; i ++)
    {
        for(j = 0; j < psoaux->M; j ++)
        {
            fprintf(pArq, "%e\t",psoaux->P[i][j]);
        }
        fprintf(pArq, "\n");
    }

    if(fclose(pArq))
    {
        printf("erro.");
        exit(1);
    }
}

void gravarP(PSO* pso)
{
    FILE *pArq;
    int i,j;
    if((pArq = fopen("C:/Users/Ricardo Santos/Documents/PSO_float/resultados/P.bin", "wb")) == 0x0)
    {
        printf("erro.");
        exit(1);
    }

    for(i = 0; i < pso->K ; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            fprintf(pArq, "%e\t",pso->P[i][j]);
        }
        fprintf(pArq, "\n");
    }

    if(fclose(pArq))
    {
        printf("erro.");
        exit(1);
    }
}
void gravarjP(PSOAUX* psoaux)
{
    FILE *pArq;
    int i;
    if((pArq = fopen("C:/Users/Ricardo Santos/Documents/PSO_float/resultados/jPgbest.bin", "wb")) == 0x0)
    {
        printf("erro.");
        exit(1);
    }

    for(i = 0; i < psoaux->iteracoes; i ++)
    {

        fprintf(pArq, "%e\n",psoaux->jP[i]);
    }

    if(fclose(pArq))
    {
        printf("erro.");
        exit(1);
    }
}
void gravarSNIR(PSOAUX* psoaux)
{
    FILE *pArq;
    int i,j;
    if((pArq = fopen("C:/Users/Ricardo Santos/Documents/PSO_float/resultados/SNIR.bin", "wb")) == 0x0)
    {
        printf("erro.");
        exit(1);
    }

    for(i = 0; i < psoaux->iteracoes ; i ++)
    {
            for(j = 0; j < psoaux->K; j ++)
            {
                fprintf(pArq, "%e\t",psoaux->SNIR[i][j]);
            }
            fprintf(pArq, "\n");
    }

    if(fclose(pArq))
    {
        printf("erro.");
        exit(1);
    }
}
void gravarPgbest(PSOAUX* psoaux)
{
    FILE *pArq;
    int i,j;
    if((pArq = fopen("C:/Users/Ricardo Santos/Documents/PSO_float/resultados/Pgbest.bin", "wb")) == 0x0)
    {
        printf("erro.");
        exit(1);
    }

    for(i = 0; i < psoaux->iteracoes; i ++)
    {
            for(j = 0; j < psoaux->K ; j ++)
            {
                fprintf(pArq, "%e\t",psoaux->Pgbest[i][j]);
            }
            fprintf(pArq, "\n");
    }

    if(fclose(pArq))
    {
        printf("erro.");
        exit(1);
    }
}
void LerRAND(PSO* pso, float** rand1)
{
    FILE *pArq;
    int i,j;
    if((pArq = fopen("C:/Users/Ricardo Santos/Documents/PSO_float/resultados/P1.txt", "r")) == 0x0)
    {
        printf("erro.");
        exit(1);
    }
    for(i = 0; i < pso->K; i ++)
    {
        for(j = 0; j < pso->M; j ++)
        {
            fscanf(pArq,"%f",&rand1[i][j]);
        }
    }
    if(fclose(pArq))
    {
        printf("erro.");
        exit(1);
    }
}
void gravarTxt(PSOAUX* psoaux)
{
    gravarjP(psoaux);
    gravarSNIR(psoaux);
    gravarPgbest(psoaux);
    gravarSNR(psoaux);
}
