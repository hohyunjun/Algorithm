#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000001];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    vector<int> vt;
    vt.push_back(-1);
    for(int i=0; i<n; i++){
        if(vt.back() < A[i]){
            vt.push_back(A[i]);
        }else{
            auto it = lower_bound(vt.begin(), vt.end(), A[i]);
            *it = A[i];
        }
    }

    // for(auto each:vt){
    //     cout << each << " ";
    // }

    cout << vt.size() - 1 << '\n';

    return 0;
}