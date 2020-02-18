#include <iostream>
#include <string>
using namespace std;

int main(){

    int jongmal[10001];
    int N;

    cin >> N;

    jongmal[1] = 666;

    int size = 1;

    int startNum = 1666;

    string tmp = to_string(startNum);


    while(size != N){

        string tmp = to_string(startNum);
        bool found = false;

        for(int i=0; i<=tmp.length()-3; i++){
            if(tmp[i] == '6' && tmp[i+1] == '6' && tmp[i+2] == '6'){
                found = true;
                break;
            }
        }

        if(found){
            size++;
            jongmal[size] = startNum;
        }

        startNum++;
    }

    cout << jongmal[N] << '\n';

    return 0;
}