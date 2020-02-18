#include <iostream>
using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){
        int s;

        cin >> s;

        int n;

        cin >> n;

        for(int i=0; i<n; i++){
            int q, p;
            cin >> q >> p;

            s += q*p;
        }

        cout << s << '\n';
    }

    return 0;
}