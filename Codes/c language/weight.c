#include<stdio.h>

void Weight(float *weight, float *inGram, float *inTons, float *inPounds)
{
    *inGram = *weight * 1000.0;

    *inTons = *weight /1000.0;

    *inPounds = *weight * 2.2;
}

int main()
{
    float weight;
    printf("Enter the weight in kg : ");
    scanf("%f",&weight);

    float inGram,inTons,inPounds;

    Weight(&weight, &inGram, &inTons, &inPounds);

    printf("Weight in gram : %0.2f\n",inGram);
    printf("Weight in tons : %f\n",inTons);
    printf("Weight in pounds : %0.2f\n",inPounds);

    return 0;
}