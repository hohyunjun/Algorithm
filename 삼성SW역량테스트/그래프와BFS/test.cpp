#include <string>
#include <iostream>
using namespace std;

int main(){

    int now[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> now[i][j];
        }
    }

    int next[3][3];

    next = now;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << next[i][j];
        }
    }



    return 0;
}