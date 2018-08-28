#include <stdio.h>
#include <stdlib.h>


void insertionSort(float* jP, float * MaxJ, int* idx, int M)
{
    int i,j;
    float chave;
    float * original = NULL;
    original = alloca1DF(M);
    for(i = 0; i < M; i ++)
    {
        MaxJ [i] = original[i] = jP[i];
    }
    for(j = 1; j < M; j ++)
    {
        chave = MaxJ[j];
        i  = j - 1;
        while((i > -1) && (MaxJ[i] > chave))
        {
            MaxJ[i + 1] = MaxJ[i];
            i = i - 1;
        }
        MaxJ[i + 1] = chave;
    }
    for(i = 0; i < M; i ++)
    {
        j = 0;
        while(MaxJ[i] != original[j])
        {
            j ++;
        }
        original[j] = -1;
        idx[i] = j;
    }
}
