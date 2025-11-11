#include <stdio.h>

// Function to run at startup
void startup_fun() {
    printf("This is startup function\n");
}

// Function to run at the end
void end_fun() {
    printf("This is end function\n");
}

// Pragma directives to call functions before and after main
#pragma startup startup_fun
#pragma exit end_fun

int main() {
    printf("This is main function\n");
    return 0;
}
