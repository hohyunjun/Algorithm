#include <iostream>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 소문자 97~122
    string input;
    int count[26] = {};

    cin >> input;

    for(int i=97; i<=122; i++){
        for(int j=0; j<input.length(); j++){
            if(input[j] == char(i)){
                count[i-97]++;
            }
        }
    }

    for(int i=0; i<26; i++){
        cout << count[i] << " ";
    }

    return 0;
}