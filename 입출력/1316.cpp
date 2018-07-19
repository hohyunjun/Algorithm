#include <iostream>
#include <math.h>
using namespace std;

bool isGroup(string word){

    int sameIndex = -2;

    for(int i=0; i<word.length(); i++){
        for(int j=i+1; j<word.length(); j++){
            if(word[i] == word[j]){
                sameIndex = j;
                break;
            }
        }
        if (abs(sameIndex - i) > 1 && sameIndex != -2){
            return false;
        }
        sameIndex = -2;
    }

    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    int groupWord = 0;
    string word;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> word;
        if(isGroup(word)){
            groupWord++;
        }
    }

    cout << groupWord << endl;


    return 0;
}