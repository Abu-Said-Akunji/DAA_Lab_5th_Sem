#include <stdio.h>
#include <stdlib.h>

void DecToBinary(FILE *lab2_1out, int n_3)
{
    if (n_3 > 0)
    {
        DecToBinary(lab2_1out, n_3 / 2);
        fprintf(lab2_1out, "%d", n_3 % 2);
    }
}
int main(int argc_3, char *argv_3[])
{
    if (argc_3 != 4)
    {
        printf("Usage: %s <input_file> <output_file> <n>\n", argv_3[0]);
        return 1;
    }

    FILE *lab2_1in, *lab2_1out;
    int n_3, num_3;

    lab2_1in = fopen(argv_3[1], "r");
    if (lab2_1in == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    lab2_1out = fopen(argv_3[2], "w");
    if (lab2_1out == NULL)
    {
        perror("Error opening output file");
        fclose(lab2_1in);
        return 1;
    }

    n_3 = atoi(argv_3[3]);

    for (int i_3 = 0; i_3 < n_3; i_3++)
    {
        if (fscanf(lab2_1in, "%d", &num_3) == 1)
        {
            DecToBinary(lab2_1out, num_3);
            fprintf(lab2_1out, "\n");
        }
        else
        {
            break;
        }
    }
    fclose(lab2_1in);
    fclose(lab2_1out);
    char str[100];
    lab2_1out = fopen(argv_3[2], "r");
    while (fgets(str, sizeof(str), lab2_1out) != NULL)
    {
        printf("%s", str);
    }

    fclose(lab2_1out);

    printf("\nConversion successful!\n");
    return 0;
}
