#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int score = 0;
        string s;
        int successive = 0;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            if(s[j] == 'O'){
                successive+=1;
            }else{
                successive=0;
            }
            score += successive;
        }
        cout << score << endl;
    }

    return 0;
}