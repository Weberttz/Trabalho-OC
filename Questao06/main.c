#include <stdio.h>

#define N 8

unsigned int binParaInt(int v[], int n) {
    unsigned int valor = 0;
    for (int i = 0; i < n; i++) {
        valor = (valor << 1) | v[i];
    }
    return valor;
}

void intParaBin(unsigned int valor, int v[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        v[i] = valor & 1;
        valor >>= 1;
    }
}

void imprimeBin(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
    }
    printf("\n");
}

int main() {
    int A[N] = {0,0,1,1,0,1,0,0};
    int B[N] = {0,0,0,0,1,1,0,1};

    int C[N] = {0};
    int R[N] = {0};

    unsigned int a = binParaInt(A, N);
    unsigned int b = binParaInt(B, N);

    if (b == 0) {
        printf("Erro\n");
        return 1;
    }

    unsigned int q = a / b;
    unsigned int r = a % b;

    intParaBin(q, C, N);
    intParaBin(r, R, N);

    imprimeBin(C, N);
    imprimeBin(R, N);

    return 0;
}
