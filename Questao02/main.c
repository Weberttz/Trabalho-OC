#include <stdio.h>
#include <stdlib.h>

int verificaMaior(int n,int *A, int *B){
    int somaA = 0, somaB = 0;
    for(int i = 0; i<n; i++){
        somaA += A[i];
        somaB += B[i];
    }

    if(somaB > somaA)
        return 0;

    return 1;
}

void subtrairBinarios(int n, int *A, int *B, int *C){
    int carry = 0;
    for(int i=n-1; i>=0; i--){
        if(A[i] + carry - B[i] < 0){
            A[i - 1] -= 1;
            carry = 2;
        }
        C[i] = A[i] + carry - B[i];
        carry = 0;
    }
}


int main() {

    int *A, *B, *C, n;
    int sA, sB;

    printf("Digite n: ");
    scanf("%d%*c", &n);
    
    A = (int*) malloc(n*sizeof(int));
    B = (int*) malloc(n*sizeof(int));
    C = (int*) malloc((n)*sizeof(int));
    
    printf("Digite o primeiro numero: ");
    scanf("%d", &sA);
    
    for(int i=n-1; i >= 0; i--){
        A[i] = sA%10;
        sA -= A[i];
        sA/=10;
    }
    
    printf("Digite o segundo numero: ");
    scanf("%d", &sB);
    
    for(int i=n-1; i>=0; i--){
        B[i] = sB%10;
        sB -= B[i];
        sB/=10;
    }

    if(!verificaMaior(n, A, B)){
        printf("Impossivel subtrair");
        return 1;
    }
    subtrairBinarios(n, A, B, C);

    for(int i=0; i<n; i++)
        printf("%d", C[i]);
    
    free(A);
    free(B);
    free(C);

    return 0;
}