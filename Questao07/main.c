#include <stdio.h>
#include <stdlib.h>

void soma_binaria(int *A, int *B, int *C, int n) {
    int total_bits = 4 * n;
    int carry = 0;

    for (int i = 0; i < total_bits + 4; i++) {
        C[i] = 0;
    }

    for (int i = 0; i < total_bits; i++) {
        int idx = total_bits - 1 - i;
        int bit_a = A[idx];
        int bit_b = B[idx];
        int soma = bit_a + bit_b + carry;
        C[total_bits + 4 - 1 - i] = soma % 2;
        carry = soma / 2;
    }

    for (int i = 0; i < 4; i++) {
        int idx_c = 4 - 1 - i;
        int soma = carry;
        C[idx_c] = soma % 2;
        carry = soma / 2;
    }
}

void imprime_binario(int *C, int n) {
    int total_bits = 4 * n + 4;
    int encontrou_um = 0;

    for (int i = 0; i < total_bits; i++) {
        if (C[i] == 1) {
            encontrou_um = 1;
        }
        if (encontrou_um) {
            printf("%d", C[i]);
        }
    }

    if (!encontrou_um) {
        printf("0");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite o valor de n (numero de digitos BCD): ");
    scanf("%d", &n);

    int total_bits = 4 * n;
    int *A = (int *)malloc(total_bits * sizeof(int));
    int *B = (int *)malloc(total_bits * sizeof(int));
    int *C = (int *)malloc((total_bits + 4) * sizeof(int));

    printf("Digite os %d bits de A (um por linha, comecando do MSB):\n", total_bits);
    for (int i = 0; i < total_bits; i++) {
        scanf("%d", &A[i]);
    }

    printf("Digite os %d bits de B (um por linha, comecando do MSB):\n", total_bits);
    for (int i = 0; i < total_bits; i++) {
        scanf("%d", &B[i]);
    }

    soma_binaria(A, B, C, n);

    printf("Resultado em binario: ");
    imprime_binario(C, n);

    free(A);
    free(B);
    free(C);

    return 0;
}