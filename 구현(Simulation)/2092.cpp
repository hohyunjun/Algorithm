#include <iostream>
#include <string>
using namespace std;

int main(){

    string input;

    cin >> input;

    string output = "";

    for(int i=0; i<input.length(); i++){
        if(input[i] - 'A' >= 0 && input[i] - 'a' < 0){
            output += input[i];
        }
    }

    cout << output;

    return 0;
}