#include <cstdio>
using namespace std;

int main(){

    int N;

    scanf("%d", &N);

    for(int k=1; k<N; k++){
        for(int i=1; i<=N-k; i++){
            printf(" ");
        }
        
        printf("*");
        
        for(int j=1; j<=2*(k-1)-1; j++){
            printf(" ");
        }
        if(k!=1){printf("*");}
        printf("\n");
    }
    for(int k=1; k<=(2*N-1); k++){
        printf("*");
    }

    return 0;
}