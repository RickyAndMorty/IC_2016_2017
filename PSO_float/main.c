#include <stdio.h>
#include <stdlib.h>


typedef struct rede// structure that store the network variables
{
    float** H;
    float* g_t, * Ltx_i, * F;
    float a_star,alfa,Gamp,Pn;
    float Pmax,Pmin,Vmax, Vmin;
    float SNR_target, Rc, Rb, q, sigma_cc2;
    int K,M;
}REDE;

typedef struct pso// structure that store the pso variables
{
    float** SNIR,** P, ** G,** Fth, ** v;
    float ** Pibest;
    float *Gii, * F, * jP, *Pgbest;
    float * jPibest,*SNR;
    float Pn,Pmax, Pmin,jPgbest;
    float c1,c2,Wadp,Vmin,Vmax;
    int K, M,iteracoes;
}PSO;


typedef struct psoaux// Structure that store the algorithm evolution on each round, an then store the results in a .txt file. 
{
    float** SNIR,** P, ** G,** Fth, ** v, ** Pibest, **Pgbest;
    float *Gii, * F, * jP, * jPibest,*SNR;
    int K,iteracoes,M;

}PSOAUX;
#include "aloca/aloca.c"// This file contains the functions responsible for dynamically allocating memory
#include "InsertionSort/InsertSort.c"// This file contains the Insertion Sort function, which is responsible for sorting numbers, in one step of the pso algorithm.
#include "Randomica/randomica.c"// This file contains the function responsible for generating numbers randomically. 
#include "imprimir.c"// This file contains the functions responsible for shown the results in the prompt window.
#include "CalculaH/CalculaH.c"// This file contains the function responsible for generate the normalized matrix H of interference. 
#include "CalculaF/CalculaF.c"// This file contains the function responsible for calculate the quocient of the bit rate by the chip rate. 
#include "rede.c"// This file contains all the attributes related to the passive optical network, all the datas are generated mathematically, and with datasheets.
#include "pso.c"// This file contains the functions related to the pso algorithm. 
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


