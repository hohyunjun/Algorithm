#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int countAlpha[52] = {};
    int countSum[26] = {};

    for(int i=0; i<str.length(); i++){
        if(int(str[i])>=65 && int(str[i])<=90){ // 대문자라면
            countAlpha[int(str[i]) - 65]++;
        }else{
            countAlpha[int(str[i]) - 97]++;
        }
    }

    for(int i=0; i<26; i++){
        countSum[i] = countAlpha[i] + countAlpha[i+26];
    }

    int bigCheck = 0;
    int indexCheck = 0;
    int repeatCheck = 0;

    for(int i=0; i<26; i++){
        if(countSum[i] > bigCheck){
            bigCheck = countSum[i];
            indexCheck = i;
        }
    }

    for(int i=0; i<26; i++){
        if(bigCheck == countSum[i]){
            repeatCheck++;
        }
    }

    if(repeatCheck==1){
        cout << char(indexCheck + 65) << endl;
    }else{
        cout << "?" << endl;
    }


    return 0;
}