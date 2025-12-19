#include <stdio.h>
#include <stdlib.h>

void somarBinarios(int n, int *A, int *B, int *C){
    int carry = 0;
    for(int i=n-1; i>=0; i--){
        switch(A[i] + B[i] + carry){
            case 0:
                 carry = 0;
                 C[i+1] = 0;
                 break;
            case 1:
                 carry = 0;
                 C[i+1] = 1;
                 break;
            case 2:
                 carry = 1;
                 C[i+1] = 0;
                 break;
            case 3:
                 carry = 1;
                 C[i+1] = 1;
                 break;
            default:
                 break;
        }
    }
    C[0] = carry;
}


int main() {
    int *A, *B, *C, n;
    int sA, sB;
    
    printf("Digite n: ");
    scanf("%d%*c", &n);
    
    A = (int*) malloc(n*sizeof(int));
    B = (int*) malloc(n*sizeof(int));
    C = (int*) malloc((n+1)*sizeof(int));
    
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

    somarBinarios(n, A, B, C);
    
    for(int i=0; i<n+1; i++)
        printf("%d", C[i]);
    
    free(A);
    free(B);
    free(C);
    
    return 0;
}