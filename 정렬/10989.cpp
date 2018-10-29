#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num[10001] = {};

    int N;

    cin >> N;

    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        num[tmp]++;
    }

    for(int i=0; i<10001; i++){
        if(num[i]==0) continue;
        int repeat = num[i];
        for(int j=0; j<repeat; j++){
            cout << i << '\n';
        }
    }

    return 0;
}