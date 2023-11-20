#include <stdio.h>

int gcd(int a_3, int b_3)
{
    if (b_3 == 0)
    {
        return a_3;
    }
    return gcd(b_3, a_3 % b_3);
}

int main(int argc_3, char *argv_3[])
{
    if (argc_3 != 3)
    {
        printf("Usage: %s <input_file> <output_file>\n", argv_3[0]);
        return 1;
    }

    FILE *lab2_2in, *lab2_2out;
    int num1_3, num2_3;

    lab2_2in = fopen(argv_3[1], "r");
    if (lab2_2in == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    lab2_2out = fopen(argv_3[2], "w");
    if (lab2_2out == NULL)
    {
        perror("Error opening output file");
        fclose(lab2_2in);
        return 1;
    }

    while (fscanf(lab2_2in, "%d %d", &num1_3, &num2_3) == 2)
    {
        int result_3 = gcd(num1_3, num2_3);
        fprintf(lab2_2out, "GCD of %d and %d is %d\n", num1_3, num2_3, result_3);
    }
    fclose(lab2_2in);
    fclose(lab2_2out);
    char str_3[100];
    lab2_2out = fopen(argv_3[2], "r");
    while (fgets(str_3, sizeof(str_3), lab2_2out) != NULL)
    {
        printf("%s", str_3);
    }

    fclose(lab2_2out);

    printf("GCD calculations completed!\n");
    return 0;
}
