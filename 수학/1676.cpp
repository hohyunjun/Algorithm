#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;

    cin >> N;
    int insu[N+1] = {};

    for(int i=1; i<=N; i++){
        int tmp = i;
        for(int j=2; j*j<=i; j++){
            while(tmp%j==0){
                insu[j]++;
                tmp/=j;
            }
        }
        if(tmp!=1){
            insu[tmp]++;
        }
    }

    int answer;

    if(N<5){
        answer = 0;
    }else if(insu[2] > 0 && insu[5] > 0){
        answer = min(insu[2], insu[5]);
    }else{
        answer = 0;
    }

    cout << answer;




    return 0;
}