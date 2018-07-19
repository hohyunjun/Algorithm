#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string input;
    string S[1000] = {};
    int index = 0;

    cin >> input;

    for(int i=0; i<input.length(); i++){
        S[index++] = input.substr(i);
    }

    sort(S, S+index);

    for(int i=0; i<index; i++){
        cout << S[i] << endl;
    }




    return 0;
}