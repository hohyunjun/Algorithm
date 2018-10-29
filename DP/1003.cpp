#include <iostream>
using namespace std;

int dpz[41], dpo[41];

int fz(int n){

    dpz[0] = 1;
    dpz[1] = 0;

    if(n<=1){
        return dpz[n];
    }
    for(int i=2; i<=n; i++){
        dpz[i] = dpz[i-1] + dpz[i-2];
    }
    return dpz[n];
}

int fo(int n){

    dpo[0] = 0;
    dpo[1] = 1;

    if (n <= 1)
    {
        return dpo[n];
    }
    for (int i = 2; i <= n; i++)
    {
        dpo[i] = dpo[i - 1] + dpo[i - 2];
    }
    return dpo[n];
}

int main(){

    int T, N;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        cout << fz(N) << " " << fo(N) << endl;
    }


    return 0;
}