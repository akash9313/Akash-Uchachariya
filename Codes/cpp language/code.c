#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    long int arr[19]={2};
    for(int i=1;i<19;i++){
        arr[i]=arr[i-1]*2;
    }
    while (t--)
    {
        int x, count = 0,pure2;
        scanf("%d", &x);
        long int arr[19]={2};
        for(int i=1;i<19;i++){
        arr[i]=arr[i-1]*2;
        if(arr[i]>x){
            pure2=arr[i-1];
            break;
        }
        }

        count = (x - pure2) / 2;

        printf("%d\n", 4 * count );
    }
}
