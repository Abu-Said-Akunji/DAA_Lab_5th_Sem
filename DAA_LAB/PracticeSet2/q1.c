#include <stdio.h>

double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    } else if (n % 2 == 0) {
        double half = power(x, n / 2);
        return half * half;
    } else {
        double half = power(x, (n - 1) / 2);
        return x * half * half;
    }
}

int main() {
    double x;
    int n;

    printf("Enter the base (x): ");
    scanf("%lf", &x);

    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    double result = power(x, n);
    printf("%lf ^ %d = %lf\n", x, n, result);

    return 0;
}
