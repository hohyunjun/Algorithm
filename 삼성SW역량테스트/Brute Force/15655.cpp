#include <iostream>
#include <algorithm>
using namespace std;

int nums[10];
int ans[10];
int check[10];

void go(int ansIdx, int start, int n, int m){
    if(ansIdx == m){
        // 출력
        for(int i=0; i<m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=start; i<n; i++){
        if(check[i]) continue;
        check[i] = true;
        ans[ansIdx] = nums[i];
        go(ansIdx+1, i+1, n, m);
        check[i] = false;
    }
}


int main(){

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    sort(nums, nums+n);

    go(0,0,n,m);


    return 0;
}