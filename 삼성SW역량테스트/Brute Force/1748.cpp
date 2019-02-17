#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){

    int n;

    cin >> n;

    int ans = 0;

    int length[9] = {9,90,900,9000,90000,900000,9000000,90000000,900000000};

    string tmp = to_string(n);

    for(int i=0; i<tmp.length()-1; i++){
        ans += (i+1)*length[i];
    }

    ans += (n - pow(10,tmp.length()-1) + 1) * tmp.length();

    cout << ans << '\n';

    return 0;
}