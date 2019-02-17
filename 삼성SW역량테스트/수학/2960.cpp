#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    vector<bool> isPrime(n+1, true);
    vector<int> deleted;

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            isPrime[i] = false;
            deleted.push_back(i);
            for(int j=i*i; j<=n; j+=i){
                if(isPrime[j]){
                    isPrime[j] = false;
                    deleted.push_back(j);
                }
            }
        }
    }

    cout << deleted[k-1] << '\n';

    return 0;
}