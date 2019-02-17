#include <iostream>
using namespace std;

int main(){

    int e, f, c;

    cin >> e >> f >> c;

    int binBottle = e + f;

    int ans = 0;
    while(binBottle >= c){
        binBottle -= c;
        ans++;
        binBottle += 1;
    }

    cout << ans << '\n';

    return 0;
}