#include <cstdio>
using namespace std;

int main(){

    int N;

    scanf("%d", &N);

    for(int k=1; k<=N; k++){
        for(int j=0; j<N-k; j++){
            printf(" ");
        }
        for(int i=1; i<=k; i++){
            printf("*");
        }
        printf("\n");
    }
}