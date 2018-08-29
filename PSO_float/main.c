#include <stdio.h>
#include <stdlib.h>


typedef struct rede// estrutura que armazena as variáveis da rede
{
    float** H;
    float* g_t, * Ltx_i, * F;
    float a_star,alfa,Gamp,Pn;
    float Pmax,Pmin,Vmax, Vmin;
    float SNR_target, Rc, Rb, q, sigma_cc2;
    int K,M;
}REDE;

typedef struct pso// estrutura que armazena as variáveis do PSO
{
    float** SNIR,** P, ** G,** Fth, ** v;
    float ** Pibest;
    float *Gii, * F, * jP, *Pgbest;
    float * jPibest,*SNR;
    float Pn,Pmax, Pmin,jPgbest;
    float c1,c2,Wadp,Vmin,Vmax;
    int K, M,iteracoes;
}PSO;


typedef struct psoaux
{
    float** SNIR,** P, ** G,** Fth, ** v, ** Pibest, **Pgbest;
    float *Gii, * F, * jP, * jPibest,*SNR;
    int K,iteracoes,M;

}PSOAUX;
#include "aloca/aloca.c"
#include "InsertionSort/InsertSort.c"
#include "Randomica/randomica.c"
#include "imprimir.c"
#include "CalculaH/CalculaH.c"
#include "CalculaF/CalculaF.c"
#include "rede.c"
#include "pso.c"
#include "CalculaP/CalculaP.c"
#include "CalculaFth/CalculaFth.c"
#include "CalculaPibest/calculaPibest.c"
#include "CalculaPgbest/CalculaPgbest.c"
#include "CalculaG/CalculaG.c"
#include "calculajPibest/calculajPibest.c"
#include "CalculaVelocidade/calculaVelocidade.c"
#include "CalculaSNR/calculaSNR.c"
#include "calculaSNIR_aux/calculaSNIR_aux.c"
#include "calculaPgbest_aux/calculaPgbest_aux.c"
#include "calculaPSOAUX/calculaPSOAUX.c"
#include "gravarTxt/gravarTxt.c"

int main()
{
int i;
    REDE* rede = allocaREDE();
    calculaRede(rede);
    PSO* pso = allocaPSO();
    PSOAUX * psoaux = allocaPSOAUX();
    inserirPSO(pso,rede);
    calculaPSOAUX(psoaux,pso);
    CalculaP(pso);
    calculaPibest(pso);
    calculaPgbest(pso);
    calculaG(pso,rede);
    calculaSNIR(pso);
    calculaFth(pso,rede);
    fitness(pso);
    zerosV(pso);
    for(i = 0; i < pso->iteracoes; i ++)
    {
        calculaSNIR(pso);
        calculaFth(pso,rede);
        fitness(pso);
        calculaMelhorLocal(pso);
        calculaMelhorGlobal(pso);
        calculaVelocidade(pso);
        speedBounds(pso);
        populationUpdate(pso);
        powerBounds(pso);

        calculaSNIR_aux(pso,psoaux,i);
        calculaPgbest_aux(pso,psoaux,i);
        psoaux->jP[i] = pso->jPgbest;
    }
    calculaSNR(pso,rede);
    imprimir1DF(pso->SNR,pso->K);
    gravarTxt(psoaux);
    return 0;
}


