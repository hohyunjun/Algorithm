#include <cstdio>
using namespace std;

int main(){

    int N;

    scanf("%d", &N);

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N-k; i++){
            printf(" ");
        }
        
        printf("*");
        
        for(int j=1; j<=k-1; j++){
            printf(" *");
        }
        printf("\n");
    }
}