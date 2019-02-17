#include <iostream>
#include <algorithm>
using namespace std;

int nums[10];
int ans[10];

void go(int ansIdx, int n, int m){
    if(ansIdx == m){
        for(int i=0; i<m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++){
        ans[ansIdx] = nums[i];
        go(ansIdx+1, n, m);
    }
}

int main(){

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    sort(nums, nums+n);

    go(0,n,m);

    return 0;
}