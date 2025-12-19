#include <stdio.h>
#include <limits.h>

#define N 3

int bcdParaInt(int v[], int pos) {
    int valor = 0;
    for (int i = 0; i < 4; i++) {
        valor = (valor << 1) | v[pos + i];
    }
    return valor;
}

void intParaBCD(int valor, int v[], int pos) {
    for (int i = 3; i >= 0; i--) {
        v[pos + i] = valor & 1;
        valor >>= 1;
    }
}

void imprimeBinario(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d", v[i]);
    }
    printf("\n");
}

int binParaInt(int v[], int tam) {
    int valor = 0;
    for (int i = 0; i < tam; i++) {
        valor = (valor << 1) | v[i];
    }
    if (v[0] == 1) {
        valor -= (1 << tam);
    }
    return valor;
}

void intParaBin(int valor, int v[], int tam) {
    unsigned int u = (unsigned int)valor;
    for (int i = tam - 1; i >= 0; i--) {
        v[i] = u & 1;
        u >>= 1;
    }
}

void imprimeHex(int v[], int tam) {
    for (int i = 0; i < tam; i += 4) {
        int dig = 0;
        for (int j = 0; j < 4; j++) {
            dig = (dig << 1) | v[i + j];
        }
        if (dig < 10) printf("%d", dig);
        else printf("%c", 'A' + dig - 10);
    }
    printf("\n");
}

int main() {
    int A[4*N] = {
        0,1,0,1,
        1,1,0,0,
        0,0,1,1
    };

    int B[4*N] = {
        1,0,1,0,
        0,0,1,0,
        0,0,0,1
    };

    int C[4*N];

    int a = binParaInt(A, 4*N);
    int b = binParaInt(B, 4*N);

    long soma = (long)a + (long)b;

    int min = -(1 << (4*N - 1));
    int max =  (1 << (4*N - 1)) - 1;

    if (soma < min || soma > max) {
        printf("Erro\n");
        return 1;
    }

    intParaBin((int)soma, C, 4*N);
    imprimeHex(C, 4*N);

    return 0;
}
