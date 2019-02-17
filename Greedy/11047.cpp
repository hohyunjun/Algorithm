#include <iostream>
using namespace std;

int main(){

    int coins[10];
    int n, k;
    int answer = 0;

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    // for(auto each:coins){
    //     cout << each << " ";
    // }

    while(k){
        for(int i=n-1; i>=0; i--){
            if(k==0) break;
            if(coins[i] <= k){
                answer += k/coins[i];
                k %= coins[i];
            }
        }
    }

    cout << answer << endl;

    return 0;
}