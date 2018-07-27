#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N >> K;

    vector<int> yaksu;

    for(int i=1; i<=N; i++){
        if(N%i==0){
            yaksu.push_back(i);
        }
    }    

    sort(yaksu.begin(), yaksu.end());

    if(yaksu.size() < K){
        cout << 0 << endl;
    }else{
        cout << yaksu[K-1] << endl;
    }

    return 0;
}