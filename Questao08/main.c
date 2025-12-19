#include <stdio.h>

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

int main() {
    int A[4*N] = {
        0,0,1,0,
        0,1,0,1,
        1,0,0,1
    };

    int B[4*N] = {
        0,1,0,0,
        1,0,0,0,
        0,0,1,1
    };

    int C[4*N + 4] = {0};

    int carry = 0;

    for (int i = N - 1; i >= 0; i--) {
        int pos = i * 4;

        int digA = bcdParaInt(A, pos);
        int digB = bcdParaInt(B, pos);

        int soma = digA + digB + carry;

        if (soma >= 10) {
            soma -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        intParaBCD(soma, C, pos + 4);
    }

    if (carry) {
        intParaBCD(1, C, 0);
    }

    imprimeBinario(C, 4*N + 4);

    return 0;
}
