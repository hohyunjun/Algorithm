#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    string input;

    while(true){
        getline(cin, input);
        if(input == "END") break;

        for(int i=input.length()-1; i>=0; i--){
            cout << input[i];
        }
        cout << '\n';
    }

    return 0;
}