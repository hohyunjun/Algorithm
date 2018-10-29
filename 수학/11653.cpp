#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for(int i=2; i*i<=N; i++){
        while(N%i==0){
            cout << i << '\n';
            N/=i;
        }
    }

    if(N!=1){
        cout << N << '\n';
    }


    return 0;
}