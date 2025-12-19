#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hex_char_para_valor(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

char valor_para_hex_char(int v) {
    if (v >= 0 && v <= 9) return '0' + v;
    if (v >= 10 && v <= 15) return 'A' + (v - 10);
    return '?';
}

void hex_para_binario(char *hex, int *bin, int n) {
    int hex_len = n / 4;
    for (int i = 0; i < hex_len; i++) {
        int valor = hex_char_para_valor(hex[i]);
        for (int j = 0; j < 4; j++) {
            bin[i * 4 + j] = (valor >> (3 - j)) & 1;
        }
    }
}

void complemento_de_2(int *bin, int bits) {
    int carry = 1;
    for (int i = 0; i < bits; i++) {
        bin[i] = !bin[i];
    }
    for (int i = bits - 1; i >= 0; i--) {
        int soma = bin[i] + carry;
        bin[i] = soma % 2;
        carry = soma / 2;
        if (carry == 0) break;
    }
}

int subtrai_binarios(int *A, int *B, int *C, int n) {
    int bits = 4 * n;
    int carry = 0;
    
    for (int i = bits - 1; i >= 0; i--) {
        int diff = A[i] - B[i] - carry;
        if (diff < 0) {
            C[i] = diff + 2;
            carry = 1;
        } else {
            C[i] = diff;
            carry = 0;
        }
    }
    
    if (carry != 0) {
        int *temp = (int *)malloc(bits * sizeof(int));
        for (int i = 0; i < bits; i++) temp[i] = 0;
        temp[bits - 1] = 1;
        
        int new_carry = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int soma = C[i] + temp[i] + new_carry;
            C[i] = soma % 2;
            new_carry = soma / 2;
        }
        free(temp);
    }
    
    int overflow = 0;
    if (A[0] == B[0] && A[0] != C[0]) {
        overflow = 1;
    }
    
    return overflow;
}

void binario_para_hex(int *bin, char *hex, int n) {
    int bits = 4 * n;
    for (int i = 0; i < n; i++) {
        int valor = 0;
        for (int j = 0; j < 4; j++) {
            valor = (valor << 1) | bin[i * 4 + j];
        }
        hex[i] = valor_para_hex_char(valor);
    }
    hex[n] = '\0';
}

int main() {
    int n;
    printf("Digite o numero de dígitos hexadecimais (n): ");
    scanf("%d", &n);
    
    char *hexA = (char *)malloc((n + 1) * sizeof(char));
    char *hexB = (char *)malloc((n + 1) * sizeof(char));
    
    printf("Digite o primeiro numero hexadecimal (%d digitos): ", n);
    scanf("%s", hexA);
    
    printf("Digite o segundo numero hexadecimal (%d digitos): ", n);
    scanf("%s", hexB);
    
    if (strlen(hexA) != n || strlen(hexB) != n) {
        printf("ERRO: Os números devem ter exatamente %d digitos hexadecimais.\n", n);
        free(hexA);
        free(hexB);
        return 1;
    }
    
    int bits = 4 * n;
    int *binA = (int *)malloc(bits * sizeof(int));
    int *binB = (int *)malloc(bits * sizeof(int));
    int *binC = (int *)malloc(bits * sizeof(int));
    
    hex_para_binario(hexA, binA, bits);
    hex_para_binario(hexB, binB, bits);
    
    if (binA[0] == 1) {
        complemento_de_2(binA, bits);
    }
    
    if (binB[0] == 1) {
        complemento_de_2(binB, bits);
    }
    
    complemento_de_2(binB, bits);
    
    int overflow = subtrai_binarios(binA, binB, binC, n);
    
    if (overflow) {
        printf("ERRO: Overflow na subtracao.\n");
    } else {
        if (binC[0] == 1) {
            complemento_de_2(binC, bits);
        }
        
        char *hexC = (char *)malloc((n + 1) * sizeof(char));
        binario_para_hex(binC, hexC, n);
        
        printf("Resultado: %s\n", hexC);
        free(hexC);
    }
    
    free(hexA);
    free(hexB);
    free(binA);
    free(binB);
    free(binC);
    
    return 0;
}