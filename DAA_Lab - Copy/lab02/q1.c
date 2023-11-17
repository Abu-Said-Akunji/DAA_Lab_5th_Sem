// Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using
// recursion.Store the binary value in a separate disc file.

#include <stdio.h>

void decimalToBinary(int num, FILE *destFile)
{
    if (num > 0)
    {
        decimalToBinary(num / 2, destFile);
        fprintf(destFile, "%d", num % 2);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "r");
    FILE *destFile = fopen(destinationFileName, "w");

    if (sourceFile == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    int decimalNumber;
    for (int i = 0; i < n; i++)
    {
        if (fscanf(sourceFile, "%d", &decimalNumber) == 1)
        {
            fprintf(destFile, "The binary equivalent of %d is ", decimalNumber);
            decimalToBinary(decimalNumber, destFile);
            fprintf(destFile, "\n");
        }
        else
        {
            break;
        }
    }

    fclose(sourceFile);
    fclose(destFile);
    return 0;
}
