#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificarSoma(int tam, int *A,int *B){
    int somaA = 0, somaB = 0;
    for(int i = tam-1; i>=0; i--){
        if(A[i] == 1)
            somaA += pow(2, tam - 1 - i);
        if(B[i] == 1)
            somaB += pow(2, tam - 1 - i);
    }    
    if(somaA + somaB >= pow(2, tam))
        return 0;
    
    return 1;
}

void somarBinarios(int tam, int *A, int *B, int *C){
    int carry = 0;
    for(int i=tam-1; i>=0; i--){
        switch(A[i] + B[i] + carry){
            case 0:
                 carry = 0;
                 C[i] = 0;
                 break;
            case 1:
                 carry = 0;
                 C[i] = 1;
                 break;
            case 2:
                 carry = 1;
                 C[i] = 0;
                 break;
            case 3:
                 carry = 1;
                 C[i] = 1;
                 break;
            default:
                 break;
        }
    }
}

void calcularCompUm(int tam, int *n, int *m){
    for(int i = 0; i<tam; i++){
        m[i] = 1;
        n[i] = m[i] - n[i];
    }
}

void calcularCompDois(int tam, int *n){
    int *m = malloc(tam * sizeof(int));
    calcularCompUm(tam, n, m);
    for(int i = 0; i<tam-1; i++){
        m[i] = 0;
    }
    somarBinarios(tam, n, m, n);
}

int main() {
    int *A, *B, *C, n;
    int sA, sB;
    
    printf("Digite n: ");
    scanf("%d", &n);
    A = malloc(n*sizeof(int));
    B = malloc(n*sizeof(int));
    C = malloc(n*sizeof(int));
    
    printf("Digite o primeiro numero binario de %d algarismos: ", n);
    scanf("%d", &sA);
    
    for(int i=n-1; i >= 0; i--){
        A[i] = sA%10;
        sA -= A[i];
        sA/=10;
    }
    
    printf("Digite o segundo numero binario de %d algarismos: ", n);
    scanf("%d", &sB);
    
    for(int i=n-1; i >= 0; i--){
        B[i] = sB%10;
        sB -= B[i];
        sB/=10;
    }
    
    if(!verificarSoma(n, A, B)){
        printf("Impossivel somar esses numeros e armazenar em n bits");
        return 1;
    }
    somarBinarios(n, A, B, C);
    
    for(int i = 0; i<n; i++){
        printf("%d", C[i]);
    }
    
    
    free(A);
    free(B);
    free(C);
    
    return 0;
}