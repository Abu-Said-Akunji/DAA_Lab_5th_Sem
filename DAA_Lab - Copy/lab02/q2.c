#include <stdio.h>

// Function to calculate GCD using recursion
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (!inputFile)
    {
        printf("Error opening the input file.\n");
        return 1;
    }

    if (!outputFile)
    {
        printf("Error opening the output file.\n");
        return 1;
    }

    int num1, num2;

    // Read pairs of numbers from the input file and calculate GCD
    while (fscanf(inputFile, "%d-%d", &num1, &num2) != EOF)
    {
        int result = gcd(num1, num2);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}