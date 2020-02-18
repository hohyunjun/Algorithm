#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    int cnt = 1;

    while(t--){
        int a, b;

        cin >> a >> b;

        cout << "Case " << cnt << ": " << a+b <<'\n';

        cnt += 1;
    }


    return 0;
}