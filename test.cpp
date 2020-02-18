#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(){

    string long_input;

    getline(cin, long_input);

    stringstream ss(long_input);

    string first;
    string second;
    string third;

    getline(ss, first, '/');
    getline(ss, second, '/');
    getline(ss, third);

    cout << first << '\n';
    cout << second << '\n';
    cout << third << '\n';



    return 0;
}