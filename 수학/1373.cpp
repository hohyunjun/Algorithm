#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;

int main(){

    string binary;
    vector<char> oct;
    stack<char> threeBin;

    cin >> binary;

    for(int i=binary.length()-1; i>=0; i--){
        threeBin.push(binary[i]);
        if(threeBin.size()==3 || i==0){
            int tmp = 0;
            while(!threeBin.empty()){
                tmp += (threeBin.top() - '0') * pow(2, threeBin.size()-1);
                threeBin.pop();
            }
            oct.push_back(tmp+'0');
        }
    }

    for(int i=oct.size()-1; i>=0; i--){
        cout << oct[i];
    }
    
    
    return 0;
}