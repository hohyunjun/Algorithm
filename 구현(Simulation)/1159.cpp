#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

    int n;

    cin >> n;

    map<char, int> _map;

    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        _map[tmp[0]] += 1;
    }

    bool notDo = true;

    for(auto each:_map){
        if(each.second >= 5){
            notDo = false;
            break;
        }
    }

    if(notDo){
        cout << "PREDAJA" << '\n';
    }else{
        for(auto each:_map){
            if(each.second >= 5){
                cout << each.first;
            }
        }
    }

    return 0;
}