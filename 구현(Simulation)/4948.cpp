#include <iostream>
#include <vector>
using namespace std;

int main(){

    while(true){
        int n;
        cin >> n;

        if(n == 0) break;

        vector<bool> check(2*n+1, true);
        check[0] = false;
        check[1] = false;

        for(int i=2; i*i<=2*n; i++){
            if(check[i] == false) continue;
            for(int j=i*i; j<=2*n; j+=i){
                check[j] = false;
            }
        }
        int ans = 0;
        for(int i=n+1; i<=2*n; i++){
            if(check[i] == true) ans++;
        }
        cout << ans << '\n';
    }



    return 0;
}