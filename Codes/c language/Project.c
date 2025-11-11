#include <stdio.h>
#include <string.h>
#include <math.h>

#define premimum_prize 450
#define gold_prize 300
#define silver_prize 200
#define popcorn_prize 250
#define colddrink_prize 150
#define samosa_prize 100
#define or ||
#define and &&
#define film "PUSHPA 2"

void fun1()
{
    printf("WELCOME TO THE CINEMA WORLD\n\n");
}

void fun2()
{
    printf("THANK YOU\n");
}

static int arr1[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
static int arr2[40] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
static int arr3[40] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};

typedef struct ticket
{
    char name[20];
    int age;
    char gender;
} ticket;

//Function for clearing all data
void clear_history()
{
    FILE *file = fopen("history.txt", "w");
    fclose(file);
}

//Function for checking available seats
void available_seat()
{
    printf("\n\n");
    for (int i = 0; i < 20; i++)
    {
        if (i % 10 == 0 and i != 0)
            printf("\n");
        if (arr1[i] == 0)
            printf(" X   ");
        else
            printf("P%02d  ", arr1[i]);
    }
    printf("\n\n");

    for (int i = 0; i < 40; i++)
    {
        if (i % 10 == 0 and i != 0)
            printf("\n");
        if (arr2[i] == 0)
            printf(" X   ");
        else
            printf("G%02d  ", arr3[i]);
    }
    printf("\n\n");

    for (int i = 0; i < 40; i++)
    {
        if (i % 10 == 0 and i != 0)
            printf("\n");
        if (arr3[i] == 0)
            printf(" X   ");
        else
            printf("S%02d  ", arr3[i]);
    }
    printf("\n\n");
}

//Function for cancelling booked movie ticket
void cancel()
{
    puts("enter the seat type:");
    printf("1.PREMIUM\n2.GOLD\n3.SILVER\n");
    int n;
    scanf("%d", &n);
    int seat;
    FILE *file = fopen("history.txt", "a");
    char temp[] = "CANCELLED";
    switch (n)
    {
    case 1:
        puts("ENTER SEAT:");
        scanf("%d", &seat);
        if (arr1[seat - 1] != 0)
            printf("SEAT IS NOT BOOKED YET!!\n");
        else
        {
            arr1[seat - 1] = seat;
            printf("Seat cancelled succesfully\n");
            printf("Refunded amount: %d\n\n", premimum_prize);
            fprintf(file, "SEAT NO:P%d    STATUS:%s    MOVIE:%s\n", seat, temp, film);
            fclose(file);
        }
        break;
    case 2:
        puts("ENTER SEAT:");
        scanf("%d", &seat);
        if (arr2[seat - 1] != 0)
            printf("SEAT IS NOT BOOKED YET!!\n");
        else
        {
            arr2[seat - 1] = seat;
            printf("Seat cancelled succesfully\n");
            printf("Amount to be refunded: %d\n\n", gold_prize);
            fprintf(file, "SEAT NO:G%d    STATUS:%s     MOVIE%s\n", seat, temp, film);
            fclose(file);

        }
        break;
    case 3:
        puts("ENTER SEAT:");
        scanf("%d", &seat);
        if (arr3[seat - 1] != 0)
            printf("SEAT IS NOT BOOKED YET!!\n");
        else
        {
            arr3[seat - 1] = seat;
            printf("Seat cancelled succesfully\n");
            printf("Amount to be refunded: %d\n\n", silver_prize);
            fprintf(file, "SEAT NO:S%d     STATUS:%s    MOVIE:%s\n", seat, temp, film);
            fclose(file);
        }
        
        break;
    }
}

//Function for checking menu
void menu()
{
    printf("POPCORN         %d\nCOLD DRINK      %d\nSAMOSA          %d",popcorn_prize,colddrink_prize,samosa_prize);
    printf("\n\n");
}

//Function for ordering food
int booking_food()
{   
    int n;
    puts("press 1 to open menu:");
    scanf("%d",&n);
    if(n == 1)menu();
    printf("Enter the number of popcorns : ");
    int popcorn;
    scanf("%d", &popcorn);
    printf("Enter the number of cold drinks : ");
    int colddrink;
    scanf("%d", &colddrink);
    printf("Enter the number of samosas : ");
    int samosa;
    scanf("%d", &samosa);
    return popcorn_prize * popcorn + colddrink * colddrink_prize + samosa * samosa_prize;
}

//Function for booking movie ticket of premium seats
int booking_premium()
{
    printf("\n\n");
    for (int i = 0; i < 20; i++)
    {
        if (i % 10 == 0 and i != 0)
            printf("\n");
        if (arr1[i] == 0)
            printf(" X   ");
        else
            printf("P%02d  ", arr1[i]);
    }
    printf("\n\n");
    int choice;
    puts("Select your seat as your choise  : ");
    scanf("%d", &choice);
    FILE *file = fopen("history.txt", "a");
    if (arr1[choice - 1] != 0)
    {
        char temp[20];
        puts("Enter name : ");
        scanf("%s", temp);
        fprintf(file, "NAME:%s  ", temp);
        puts("Enter age : ");
        int age;
        scanf("%d", &age);
        fprintf(file, "AGE:%d  ", age);
        getchar();
        char gender;
        puts("Enter gender : ");
        scanf("%c", &gender);
        fprintf(file, "GENDER:%c  ", gender);
        char temp1[] = "premium";
        fprintf(file, "SEAT TYPE:%s  SEAT NUMBER:%d   MOVIE:%s\n", temp1, choice, film);
        printf("**********************************\n");
        printf("              TICKET              \n");
        printf("-->  Name : %s\n", temp);
        printf("-->  Age : %d\n", age);
        printf("-->  Gender : %c\n", gender);
        printf("-->  Seat no. : P%d\n", choice);
        printf("**********************************\n");
        arr1[choice - 1] = 0;
        printf("\n\n");
        fclose(file);
        return 1;
    }
    else
    {
        puts("SEAT IS ALREADY BOOKED\n\n");
        puts("DO YOU WANT TO BOOK TICKET AGAIN? (1/0)");
        int r;
        scanf("%d",&r);
        if(r==1)booking_premium();
        return 0;
    }
}

//Function for booking movie ticket of gold seats
int gold_booking()
{
    for (int i = 0; i < 40; i++)
    {
        if (i % 10 == 0 and i != 0)
        {
            printf("\n");
        }

        if (arr2[i] == 0)
            printf(" X   ");

        else
            printf("G%02d  ", arr2[i]);
    }
    printf("\n\n");
    FILE *file = fopen("history.txt", "a");
    int choice;
    puts("Select your seat as your choise  : ");
    scanf("%d", &choice);

    if (arr2[choice - 1] != 0)
    {
        char temp[20];
        puts("Enter name : ");
        scanf("%s", temp);
        puts("Enter age : ");
        int age;
        scanf("%d", &age);
        getchar();
        char gender;
        puts("Enter gender : ");
        scanf("%c", &gender);
        printf("**********************************\n");
        printf("              TICKET              \n");
        printf("-->  Name : %s\n", temp);
        printf("-->  Age : %d\n", age);
        printf("-->  gender : %c\n", gender);
        printf("-->  Seat no. : G%d\n", choice);
        printf("**********************************\n");
        arr2[choice - 1] = 0;
        printf("\n\n");

        fprintf(file, "NAME:%s  ", temp);
        fprintf(file, "AGE:%d  ", age);
        fprintf(file, "GENDER%c  ", gender);
        char temp1[] = "Gold";
        fprintf(file, "SEAT TYPE:%s  SEAT NUMBER:%d  MOVIE:%s\n", temp1, choice, film);
        fclose(file);
        return 1;
    }
    else
    {
        puts("SEAT IS ALREADY BOOKED\n\n");
        puts("DO YOU WANT TO BOOK TICKET AGAIN? (1/0)");
        int r;
        scanf("%d",&r);
        if(r==1)gold_booking();
        return 0;
    }
}

//Function for booking movie ticket of silver seats
int booking_silver()
{
    for (int i = 0; i < 40; i++)
    {
        if (i % 10 == 0 and i != 0)
        {
            printf("\n");
        }

        if (arr3[i] == 0)
            printf(" X   ");

        else
            printf("S%02d  ", arr3[i]);
    }
    printf("\n\n");
    FILE *file = fopen("history.txt", "a");
    int choice;
    puts("Select your seat as your choice  : ");
    scanf("%d", &choice);

    if (arr3[choice - 1] != 0)
    {
        char temp[20];
        puts("Enter name : ");
        scanf("%s", temp);
        fprintf(file, "NAME:%s  ", temp);
        puts("Enter age : ");
        int age;
        scanf("%d", &age);
        fprintf(file, "AGE:%d  ", age);
        getchar();
        puts("Enter gender : ");
        char gender;

        scanf("%c", &gender);
        fprintf(file, "GENDER:%c  ", gender);
        printf("**********************************\n");
        printf("              TICKET              \n");
        printf("-->  Name : %s\n", temp);
        printf("-->  Age : %d\n", age);
        printf("-->  Gender : %c\n", gender);
        printf("-->  Seat no. : S%d\n", choice);
        printf("**********************************\n");
        arr3[choice - 1] = 0;
        printf("\n\n");
        char temp1[] = "Silver";
        fprintf(file, "SEAT TYPE:%s  SEAT NUMBER:%d  MOVIE:%s\n", temp1, choice, film);
        fclose(file);
        return 1;
    }
    else
    {
        puts("SEAT IS ALL READY BOOKED\n\n");
        puts("DO YOU WANT TO BOOK TICKET AGAIN? (1/0)");
        int r;
        scanf("%d",&r);
        if(r==1)booking_silver();
        return 0;
    }
}

//Function for selecting the type of seats
void booking_ticket()
{
    static int premimum_seat = 20, gold_seat = 40, silver_seat = 40;

    int number;
    puts("Enter the number of person : ");
    scanf("%d", &number);
    int amount = 0;
    while (number--)
    {
        printf("\n\n");
        printf("Which type of seats do you want?\n");
        puts("1.Premimum");
        puts("2.Gold");
        puts("3.Silver");
        printf("\n\n");
        int n;
        printf("Enter the type of seats as number given above : ");
        scanf("%d", &n);
        if (n == 1)
        {
            if (premimum_seat >= 0)
            {
                if (booking_premium() == 1)
                {
                    amount = amount + premimum_prize;
                    premimum_seat--;
                }
            }

            else
            {
                puts("SORRY FOR INCONVVINIENT!!");
            }
            printf("\n\n");
        }
        else if (n == 2)
        {
            if (gold_seat >= 0)
            {
                if (gold_booking() == 1)
                {
                    amount = amount + gold_prize;
                    gold_seat--;
                }
                else
                {
                    puts("SORRY FOR INCONVVINIENT!!");
                }
                printf("\n\n");
            }
        }
        else if (n == 3)
        {
            if (silver_seat >= 0)
            {
                if (booking_silver() == 1)
                {
                    amount = amount + silver_prize;
                    silver_seat--;
                }
            }
            else
            {
                puts("SORRY FOR INCONVVINIENT!!");
            }
            printf("\n\n");
        }
    }
    puts("Do you want food Servings : (Y/N) : ");
    getchar();
    char choice;
    scanf("%c", &choice);
    int price = 0;
    if (choice == 'Y' or choice == 'y')
    {
        price = booking_food();
    }
    printf("\n\n");
    puts("Total amount to be paid : ");
    printf("FOOD COST:%d\n", price );
    printf("TICKET COST:%d\n",amount);
    printf("\n\n");
}

int main()
{   
    fun1();
    while (1)
    {
        printf("Enter the number from the option : \n");
        puts("1.Booking ticket");
        puts("2.Booking food");
        puts("3.Cancel");
        puts("4.Clear history");
        puts("5.Seat available");
        puts("6.Food Menu");
        puts("0.Exit");

        int n;
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            booking_ticket();
            break;
        case 2:
            printf("Bill to be paid : %d\n\n", booking_food());
            break;
        case 3:
            cancel();
            break;
        case 4:
            printf("WARNING:  !!IT WILL DELETE YOUR ALL THE DATA!!\n");
            puts("PRESS 1 TO DELETE ALL THE HISTORY");
            int n1;
            scanf("%d", &n1);
            if (n1 == 1)
                clear_history();
            break;
        case 5:
            available_seat();
            break;
        case 6:
            menu();
            break;
        case 0:
            printf("THANK YOU FOR BOOKING WITH US!!!");

            return 0;
        }
    }
    return 0;
}
