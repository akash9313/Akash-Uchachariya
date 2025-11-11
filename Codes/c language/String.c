#include<stdio.h>
#include<string.h>

struct address
{
    int house;
    int block;
    char city[50];
    char state[40];
};

void printadd(struct address add);

int main()
{
    struct address add[5];

    printf("Enter info for person 1 : ");
    scanf("%d", &add[0].house);
    scanf("%d", &add[0].block);
    scanf("%s", add[0].city);
    scanf("%s", add[0].state);

    printf("Enter info for person 2 : ");
    scanf("%d", &add[1].house);
    scanf("%d", &add[1].block);
    scanf("%s", add[1].city);
    scanf("%s", add[1].state);

    printf("Enter info for person 3 : ");
    scanf("%d", &add[2].house);
    scanf("%d", &add[2].block);
    scanf("%s", add[2].city);
    scanf("%s", add[2].state);

    printf("Enter info for person 4 : ");
    scanf("%d", &add[3].house);
    scanf("%d", &add[3].block);
    scanf("%s", add[3].city);
    scanf("%s", add[3].state);

    printf("Enter info for person 5 : ");
    scanf("%d", &add[4].house);
    scanf("%d", &add[4].block);
    scanf("%s", add[4].city);
    scanf("%s", add[4].state);

    printadd(add[0]);
    printadd(add[1]);
    printadd(add[2]);
    printadd(add[3]);
    printadd(add[4]);


    return 0;
}

void printadd(struct address add)
{
    printf("address is : %d, %d, %s, %s \n", add.house, add.block, add.city, add.state);
}

