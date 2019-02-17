#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int N;

    cin >> N;

    vector<int> v(N);

    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    if(next_permutation(v.begin(), v.end())){ // 다음 순열이 존재할 경우
        for(auto each:v){
            cout << each << " ";
        }
    }else{
        cout << -1 << endl;
    }


    return 0;
}