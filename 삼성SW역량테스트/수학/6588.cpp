#include <cstdio>

int main(){

    // 10000000 까지의 소수를 모두 구한다.
    bool check[1000001] = {false};

    for(int i=1; i*i<=1000000; i++){
        if(i == 1){
            check[i] = true;
            continue;
        }
        if(check[i] == false){ // 소수일 경우
            for(int j=i*i; j<=1000000; j+=i){
                check[j] = true;
            }
        }
    }

    int n;

    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        for(int i=3; i<=1000000; i++){
            if(n<i){
                printf("Goldbach's conjecture is wrong.\n");
            }
            if(check[i] == false && check[n-i] == false){
                printf("%d = %d + %d\n", n,i,n-i);
                break;
            }
        }
    }



    return 0;
}