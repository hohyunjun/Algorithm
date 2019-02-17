#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    string data = "1,2,3,4,5,null,5,3,";
    stringstream ss(data);
    string token;

    while(getline(ss, token, ',')){
        cout << token << '\n';
    }



    return 0;
}