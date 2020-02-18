#include <iostream>
using namespace std;

int main(){

    int ans = 0;
    int tmp;

    for(int i=0; i<5; i++){
        cin >> tmp;
        ans += tmp;
    }

    cout << ans << '\n';

    return 0;
}