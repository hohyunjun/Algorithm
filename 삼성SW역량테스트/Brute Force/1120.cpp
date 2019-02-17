#include <iostream>
using namespace std;

int diff = 0x7FFFFFFF;


int main(){

    string a, b;

    cin >> a >> b;

    int cnt = 0;
    for(int i=0; i<=b.length()-a.length(); i++){
        cnt = 0;
        for(int j=0; j< a.length(); j++){
            if(a[j] != b[i+j]) cnt++;
        }
        diff = min(diff, cnt);
    }

    cout << diff << '\n';

    return 0;
}