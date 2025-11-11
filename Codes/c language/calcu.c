#include<stdio.h>
#include<math.h>

void calculation(int arr[], int *sum, float *avg, float *std)
{
    *sum = 0;
    for (int i = 0; i < 5; i++)
    {
        *sum = *sum + arr[i];
    }

    *avg = *sum/5.0;

    float x = 0.0;
    for (int i = 0; i < 5; i++)
    {
        x = x + pow((arr[i] - *avg),2);
    }

    *std = sqrt(x/5);   
}

int main()
{
    int arr[5];
    printf("Enter the five numbers : ");
    for (int i = 0; i < 5; i++)
    {
    scanf("%d", &arr[i]);
    }

    int sum;
    float avg,std;
    calculation(arr,&sum,&avg,&std);
    printf("Sum : %d\n",sum);
    printf("Average : %0.2f\n",avg);
    printf("Standard deviation : %0.2f\n",std);

    return 0;
}