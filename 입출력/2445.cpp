#include <cstdio>
using namespace std;

int main(){

    int N;

    scanf("%d", &N);

    for(int k=1; k<=N; k++){
        for(int i=0; i<k; i++){
            printf("*");
        }
        for(int j=1; j<=2*(N-k); j++){
            printf(" ");
        }
        for(int i=0; i<k; i++){
            printf("*");
        }

        printf("\n");
    }

    for(int k=1; k<=N-1; k++){
        for(int i=0; i<N-k; i++){
            printf("*");
        }
        for(int j=0; j<2*k; j++){
            printf(" ");
        }
        for(int i=0; i<N-k; i++){
            printf("*");
        }

        printf("\n");
    }
}