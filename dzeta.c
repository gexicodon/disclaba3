#include <stdio.h>
#include <math.h>


int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


double dzeta_Riemann(double s, double eps) {
    double result = 0, tmp = 0;
    int n = 1;
    do {
        tmp = 1/(pow((double)n, s));
        result += tmp;
        n++;
    } while (fabs(tmp) >= eps);

    return result;
}



double dzeta_Riemann_by_Euler_mul(double s, double eps) {
    double result = 1, tmp = 0;
    int n = 2;
    do {
        if (is_prime(n)) {
            tmp = 1 / (1 - (1 / pow((double)n, s)));
            result *= tmp;
        }
        n++;
    } while (fabs(tmp - 1) >= eps);

    return result;
}



int main() {
    double const eps = 1e-13;
    double s;

    printf("--- Calculation of Riemann dzeta-function ---\n");
    printf("Input an argument of dzeta-function: \n");

    scanf("%lf", &s);

    double opr = dzeta_Riemann(s, eps);
    double eul = dzeta_Riemann_by_Euler_mul(s, eps);


    printf("By definition: %f\n", opr);
    printf("By Euler multiplication: %f\n", eul);
    return 0;
}

