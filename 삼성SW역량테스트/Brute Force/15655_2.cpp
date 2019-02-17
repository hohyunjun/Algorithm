#include <iostream>
#include <algorithm>
using namespace std;

int nums[10];
int ans[10];

// 오름차순이므로, ans[ansIdx]에 nums[numsIdx]를 사용할 경우와 사용하지 않을 경우 둘로 나누어 풀어본다.
void go(int ansIdx, int numsIdx, int n, int m){
    if(ansIdx == m){
        // 출력
        for(int i=0; i<m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    // 불가능한 경우
    if(numsIdx >= n){
        return;
    }

    // nums[numsIdx] 사용할 경우
    ans[ansIdx] = nums[numsIdx];
    go(ansIdx+1, numsIdx+1, n, m);
    ans[ansIdx] = 0;
    go(ansIdx, numsIdx+1, n, m);
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