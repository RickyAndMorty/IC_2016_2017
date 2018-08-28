#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void calculaRede(REDE* rede)
{
    int i;

    rede->Gamp = 100.00F;
    rede->alfa = 0.0461F;
    rede->a_star = 0.0016F;
    rede->K = 16;
    rede->Pmax = 0.0100F;
    rede->Pmin = 1.0F * pow(10,-10);
    rede->Vmax = 0.0020F;
    rede->Vmin = - 0.0020F;
    rede->SNR_target = 1.5259F * pow(10,-5);
    rede->sigma_cc2 = 0.01F;
    rede->q = 256.00F;

    rede->Rc = 1.00F;
    rede->Rb = 1.00F;
    rede->Pn = 2.0F * (rede->Gamp - 1.0F) * 193.0F * pow(10,12) * 100.0F* pow(10,9) * 6.63F * pow(10,-34);
    rede->g_t = alloca1DF(rede->K);
    rede->Ltx_i = alloca1DF(rede->K);
    rede->F = alloca1DF(rede->K);
    rede->H = alloca2DF(rede->K,rede->K);

    rede->Ltx_i[0] = 48.8779F;
    rede->Ltx_i[1] = 26.9518F;
    rede->Ltx_i[2] = 40.0057F;
    rede->Ltx_i[3] = 46.3947F;
    rede->Ltx_i[4] = 18.7903F;
    rede->Ltx_i[5] = 22.8634F;
    rede->Ltx_i[6] = 37.3182F;
    rede->Ltx_i[7] = 5.2198F;
    rede->Ltx_i[8] = 32.6824F;
    rede->Ltx_i[9] = 48.5307F;
    rede->Ltx_i[10] = 10.2101F;
    rede->Ltx_i[11] = 40.0123F;
    rede->Ltx_i[12] = 14.8661F;
    rede->Ltx_i[13] = 26.3720F;
    rede->Ltx_i[14] = 46.7481F;
    rede->Ltx_i[15] = 29.7142F;
    for(i = 0; i < rede->K; i ++)
    {
        rede->g_t[i] = rede->a_star * pow(2.7183F,-rede->alfa * rede->Ltx_i[i]) * rede->Gamp * 0.0025F;
    }

    calculaH(rede);;
    calculaF(rede);
}
