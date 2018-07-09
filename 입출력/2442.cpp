#include <cstdio>
using namespace std;

int main(){

    int N;

    scanf("%d", &N);

    for(int k=1; k<=N; k++){
        for(int j=1; j<=N-k; j++){
            printf(" ");
        }
        for(int i=0; i<=2*(k-1); i++){
            printf("*");
        }

        printf("\n");
    }
}