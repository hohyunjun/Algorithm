#include <iostream>
#include <map>
using namespace std;

int main(){

    map<string, int, greater<string>> m;

    m["One"] = 1;
    m["Two"] = 2;
    m["Three"] = 3;
    m["Four"] = 4;
    m["Five"] = 5;
    m["Six"] = 6;
    m["Seven"] = 7;

    for(auto each:m){
        cout << each.first << " " << each.second << '\n';
    }




    return 0;
}