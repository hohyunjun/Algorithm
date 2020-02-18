#include <iostream>
#include <string>
using namespace std;

int main(){

    string name = "Test123";

    cout << sizeof(string) << '\n';
    cout << sizeof(name) << '\n';
    cout << name.size() << '\n';
    cout << name.length() << '\n';


    return 0;
}