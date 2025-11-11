#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter a and b : ");
    scanf("%d %d", &a, &b);

    char ch;
    printf("Enter mathematical operator : ");
    scanf(" %c", &ch);

    if(ch == '+'){
    printf("Sum is : %d\n",a+b);
    }
    
    else if(ch == '-'){
    printf("Substraction is : %d\n",a-b);
    }

    else if(ch == '*'){
    printf("Multiplication is : %d\n",a*b);
    }

    else if(ch == '/'){
    printf("Division is : %0.2f\n",(float)a / (float)b);
    }

    else if(ch == '%'){
    printf("Modulus is : %d\n",a%b);
    }

    else{
    printf("No valid mathematical operator entered\n");
    }

    return 0;
}