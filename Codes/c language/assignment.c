#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char Data[100];
    int num;

    // 1. fopen: Open a file in write mode
    file = fopen("example.txt","w");
    if(file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    // 2. fprintf: Write formatted data to a file
    fprintf(file, "Hello World.\n");
    fprintf(file, "Number: %d\n", 42);

    // 3. fputs: Write a string to a file
    fputs("Hello , World.\n",file);

    // 4. fputc: Write a single character to a file
    fputc('A', file);
    fputc('\n', file);

    // Close and reopen in read mode
    fclose(file);
    file = fopen("example.txt", "r");
    if(file == NULL) 
    {
        printf("Unable to open file.\n");
        return 1;
    }

    // 5. fscanf: Read formatted data from a file
    fscanf(file, "Number: %d\n", &num);
    printf("Number = %d\n", num);

    // 6. fgets: Read a string from a file
    fgets(Data, sizeof(Data), file);
    printf("Read using fgets: %s", Data);

    // 7. fgetc: Read a single character from a file
    char ch = fgetc(file);
    printf("Read using fgetc: %c\n", ch);

    // 8. ftell: Get the current position in the file
    long position = ftell(file);
    printf("Current file position: %ld\n", position);

    // 9. fseek: Move the file pointer to a specific position
    fseek(file, 0, SEEK_SET); // Move to the beginning of the file

    // 10. rewind: Reset the file pointer to the beginning of the file
    rewind(file);

    // 11. fread: Read binary data from a file
    FILE *binFile = fopen("binary.dat", "wb+");
    int data[3] = {10, 20, 30};
    fwrite(data, sizeof(int), 3, binFile); // Write binary data

    rewind(binFile); // Reset the pointer to the beginning
    int readData[3];
    fread(readData, sizeof(int), 3, binFile); // Read binary data
    printf("Read using fread: %d, %d, %d\n", readData[0], readData[1], readData[2]);
    fclose(binFile);

    // 12. fputc: Write an integer to a file (character-based)
    FILE *intFile = fopen("integer.txt", "w+");
    fputc(100, intFile); // Write an integer to the file

    // 13. fgetc: Read an integer from a file
    rewind(intFile);
    int intValue = fgetc(intFile);
    printf("Read using fgetc: %d\n", intValue);
    fclose(intFile);

    // 14. fclose: Close the file
    fclose(file);

    printf("File operations completed successfully.\n");
    return 0;
}
