#include <cstdio>
using namespace std;

int main(){

    int N;

    scanf("%d", &N);

    for(int k=1; k<=N; k++){
        for(int i=0; i<=N-k; i++){
            printf("*");
        }
        printf("\n");
    }
}