#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    for(int i=1000; i<=9999; i++){
        vector<int> twelve;
        vector<int> sixteen;
        int sum10 = 0, sum12 = 0, sum16 = 0;
        string tmp = to_string(i);
        for(int i=0; i<tmp.length(); i++){
            sum10 += tmp[i] - '0';
        }

        int tmpNum = i;
        while(tmpNum){
            sixteen.push_back(tmpNum % 16);
            tmpNum /= 16;
        }

        for(auto each:sixteen){
            sum16 += each;
        }

        tmpNum = i;
        while(tmpNum){
            twelve.push_back(tmpNum % 12);
            tmpNum /= 12;
        }

        for(auto each:twelve){
            sum12 += each;
        }
        
        if(sum10 == sum12 && sum12 == sum16){
            cout << i << '\n';
        }
        
    }

    

    return 0;
}