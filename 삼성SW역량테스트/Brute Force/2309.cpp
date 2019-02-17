#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int h[9];
    int check[9] = {false};
    int sum = 0;

    for(int i=0; i<9; i++){
        cin >> h[i];
        sum += h[i];
    }

    bool found = false;

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            int tmp = sum;
            tmp-=h[i];
            tmp-=h[j];
            if(tmp==100){
                check[i] = true;
                check[j] = true;
                found = true;
                break;
            }
        }
        if(found) break;
    }

    vector<int> answers;

    for(int i=0; i<9; i++){
        if(check[i]==false){
            answers.push_back(h[i]);
        }
    }

    sort(answers.begin(), answers.end());

    for(auto each:answers){
        cout << each << endl;
    }

    return 0;
}