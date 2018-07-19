#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    string str;

    str = to_string(N);

    int Ns[10];

    fill_n(Ns, 10, -1);

    for(int i=0; i<str.length(); i++){
        Ns[i] = str[i] - '0';
    }

    sort(Ns, Ns+10);

    for(int i=9; i>=0; i--){
        if(Ns[i] != -1 ){
            cout << Ns[i];
        }
    }

    return 0;
}