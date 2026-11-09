#include <stdio.h>
#include <stdlib.h>

void sieve(int N, int mu[], int phi[], int tau[]) {
    int *is_prime = calloc(N + 1, sizeof(int));

    if (is_prime == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i <= N; i++) {
        is_prime[i] = 1;
    }

    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i] == 1) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        mu[i] = 1;
        phi[i] = i;
        tau[i] = 0;
    }

    for (int p = 2; p <= N; p++) {
        if (is_prime[p]) {
            for (int j = p; j <= N; j += p) {
                phi[j] = phi[j] / p * (p - 1);
                mu[j] = -mu[j];

                if ((j / p) % p == 0) {
                    mu[j] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            tau[j]++;
        }
    }

    free(is_prime);
}

int main(void) {
    int N;

    printf("Enter the value of N:\n");

    if (scanf("%d", &N) != 1 || N < 1) {
        printf("N must be positive\n");
        return 1;
    }

    int *mu = calloc(N + 1, sizeof(int));
    int *phi = calloc(N + 1, sizeof(int));
    int *tau = calloc(N + 1, sizeof(int));

    if (mu == NULL || phi == NULL || tau == NULL) {
        printf("Memory allocation failed\n");
        free(mu);
        free(phi);
        free(tau);

        return 1;
    }

    sieve(N, mu, phi, tau);
    printf("\nn\tmu(n)\tphi(n)\ttau(n)\n");

    for (int i = 1; i <= N; i++) {
        printf("%d\t%d\t%d\t%d\n", i, mu[i], phi[i], tau[i]);
    }
    free(mu);
    free(phi);
    free(tau);

    return 0;
}
