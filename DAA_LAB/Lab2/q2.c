#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (!output_file) {
        perror("Error creating/opening output file");
        fclose(input_file);
        return 2;
    }

    int num1, num2;
    while (fscanf(input_file, "%d %d", &num1, &num2) != EOF) {
        int result = gcd(num1, num2);
        fprintf(output_file, "The GCD of %d %d:%d\n",num1,num2, result);
    }

    fclose(input_file);
    fclose(output_file);

    printf("GCDs of the pairs have been calculated and stored in 'output.txt'.\n");

    return 0;
}

