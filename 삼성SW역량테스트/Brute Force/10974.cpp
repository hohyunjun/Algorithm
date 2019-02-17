#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int N;

    cin >> N;

    vector<int> v;

    for(int i=1; i<=N; i++){
        v.push_back(i);
    }

    for(auto each:v){
        cout << each << " ";
    }

    cout << '\n';

    while(next_permutation(v.begin(),v.end())){
        for(auto each:v){
            cout << each << " ";
        }
        cout << '\n';
    }


    return 0;
}