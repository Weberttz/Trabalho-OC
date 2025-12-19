#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binToInt(int *bin, int n) {
    int value = 0;

    if (bin[0] == 1) {
       
        int *temp = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            temp[i] = !bin[i];

        for (int i = n - 1; i >= 0; i--) {
            if (temp[i] == 0) {
                temp[i] = 1;
                break;
            } else temp[i] = 0;
        }

        for (int i = 0; i < n; i++)
            value = value * 2 + temp[i];

        free(temp);
        return -value;
    }

    for (int i = 0; i < n; i++)
        value = value * 2 + bin[i];

    return value;
}

void intToBinComplement(int num, int *bin, int size) {
    unsigned int unum;

    if (num < 0)
        unum = (1U << size) + num;
    else
        unum = num;

    for (int i = size - 1; i >= 0; i--) {
        bin[i] = unum & 1;
        unum >>= 1;
    }
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int A[n], B[n];
    printf("Digite o primeiro numero binario (%d bits): ", n);
    for (int i = 0; i < n; i++)
        scanf("%1d", &A[i]);

    printf("Digite o segundo numero binario (%d bits): ", n);
    for (int i = 0; i < n; i++)
        scanf("%1d", &B[i]);

    int x = binToInt(A, n);
    int y = binToInt(B, n);

    int produto = x * y;

    int C[2*n];
    intToBinComplement(produto, C, 2*n);

    printf("Numero 1 = %d\n", x);
    printf("Numero 2 = %d\n", y);
    printf("Produto  = %d\n", produto);

    printf("Resultado em binario (%d bits): ", 2*n);
    for (int i = 0; i < 2*n; i++)
        printf("%d", C[i]);
    printf("\n");

    return 0;
}
