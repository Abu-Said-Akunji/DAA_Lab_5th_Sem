#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(FILE *src_file, FILE *dest_file, int n) {
    if (n <= 0) {
        return;
    }

    int decimal;
    fscanf(src_file, "%d", &decimal);


    int binary[32];
    int index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    fprintf(dest_file,"The Binary conversion of %d:",decimal);
    for (int i = index - 1; i >= 0; i--) {
        fprintf(dest_file, "%d", binary[i]);
    }
    fprintf(dest_file, "\n");

    decimalToBinary(src_file, dest_file, n - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
    }

    int n = atoi(argv[1]);
    char *source_file_name = argv[2];
    char *destination_file_name = argv[3];

    FILE *src_file = fopen("src.txt", "r");
    if (!src_file) {
        perror("Error opening source file");

    }

    FILE *dest_file = fopen("desti.txt", "w");
    if (!dest_file) {
        perror("Error creating/opening destination file");
        fclose(src_file);

    }

    decimalToBinary(src_file, dest_file, n);

    fclose(src_file);
    fclose(dest_file);

    dest_file = fopen(destination_file_name, "r");
    if (!dest_file) {
        perror("Error opening destination file for reading");

    }

    printf("Decimal Numbers and their Equivalent Binary Numbers:\n");
    int decimal_val, line_count = 0;
    while (fscanf(dest_file, "%d", &decimal_val) != EOF) {
        printf("%d: %d\n", line_count + 1, decimal_val);
        line_count++;
    }

    fclose(dest_file);

    return 0;
}

