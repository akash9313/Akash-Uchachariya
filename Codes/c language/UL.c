#include<stdio.h>
int main()
{
    char ch,ch1,ch2,ch3;
    printf("Enter an Alphabet : \n");
    scanf(" %c",&ch);
    
    ch1 = (ch>='A' && ch<='Z')?'U':'L';
    printf("%c\n",ch1);
    printf("U stands for upper case and L stand for lower case\n");

    ch2=(ch=='@' || ch=='#' || ch=='$' || ch=='*' || ch=='&')?'S':'s';
    printf("%c\n",ch2);
    printf("S is stands for spatial chracter and s stands for not spatial character\n");

    int years;
    printf("Enter year : \n");
    scanf("%d",&years);
    
    ch3 = (years%4==0 && (years%100!=0 || years%400==0))?'Y':'N';
    printf("%c\n",ch3);
    printf("Y is for leap year and N for not leap year\n");


return 0;
}