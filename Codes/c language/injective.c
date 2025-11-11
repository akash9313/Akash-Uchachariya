#include<stdio.h>

void injectivity(int f[])
{
    int injectivity;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if(f[i] == f[j])
            {
                injectivity = 0;
            }else
            {
                injectivity = 1;
            }
        }   
    }
    printf("f : {1,2,3,4,5} --> N\n");
    if(injectivity == 1)
    {
        printf("This function is injective\n");
    }
    else
    {
        printf("The function is not injective");
    }
}

int main()
{
    int f[5] = {1,2,3,4,5};
    
    injectivity(f);

    return 0;
}