#include <iostream>
using namespace std;

int main(){

    int s=0, t=0;

    for(int i=0; i<4; i++){
        int tmp;
        cin >> tmp;
        s += tmp;
    }

    for (int i = 0; i < 4; i++){
        int tmp;
        cin >> tmp;
        t += tmp;
    }

    int ans = max(s,t);

    cout << ans << '\n';

    return 0;
}