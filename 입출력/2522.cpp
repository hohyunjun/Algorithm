#include <cstdio>
using namespace std;

int main(){

    int N;

    scanf("%d", &N);

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N-k; i++){
            printf(" ");
        }
        for(int j=1; j<=k; j++){
            printf("*");
        }

        printf("\n");
    }

    for(int k=1; k<=N-1; k++){
        for(int i=1; i<=k; i++){
            printf(" ");
        }
        for(int j=0; j<N-k; j++){
            printf("*");
        }

        printf("\n");
    }
}