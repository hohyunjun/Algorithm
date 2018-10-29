#include <cstdio>

bool checkHansu(int n){

    if(n<10){
        return true;
    }else if(n<100){
        return true;
    }else if(n==1000){
        return false;
    }else{
        int a,b,c,x;
        a = n/100; // 100자리수
        b = n%100/10; // 10자리수
        c = n%10; // 1의 자리수
        x = b-a;
        if(c == b+x){
            return true;
        }else{
            return false;
        }
    }
}

int main(){

    int N;
    int hansu = 0;

    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        if(checkHansu(i)){
            hansu++;
        }
    }

    printf("%d", hansu);

    return 0;
}