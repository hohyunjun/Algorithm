#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;
    // true 이면 지우고, false 이면 지우지 않고
    bool check[N+1] = {0};

    for(int i=1; i*i<=N; i++){
        if(i==1){
            check[i] = true;
            continue;
        }
        if(check[i]==false){
            for(int j=i*2; j<=N; j+=i){
                    check[j] = true;
            }
        }
    }

    for(int i=M; i<=N; i++){
        if(check[i]==false){
            cout << i << '\n';
        }
    }
    
    return 0;
}