#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector< pair<int, int> > A;
    int n, number, ans=0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> number;
        pair<int, int> tmp = make_pair(number, i);
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());

    for(int i=0; i<A.size(); i++){
        if(i < A[i].second && ans<A[i].second - i){
            ans = A[i].second - i;
        }
    }

    cout << ans+1 << '\n';

    return 0;
}