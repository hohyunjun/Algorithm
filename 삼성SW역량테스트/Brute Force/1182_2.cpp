#include <iostream>
#include <vector>
using namespace std;

int solve(int s, vector<int> nums, int sum, int idx){
    // 찾은경우
    if(sum == s && idx == nums.size()){
        return 1;
    }
    // 불가능한 경우
    if(idx >= nums.size()) return 0;

    int result = 0;

    result += solve(s, nums, sum+nums[idx], idx+1);
    result += solve(s, nums, sum, idx+1);

    return result;
}

int main(){

    int n, s;

    cin >> n >> s;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    if(s == 0){
        cout << solve(s, nums, 0 , 0) -1 << '\n';
    }else{
        cout << solve(s, nums, 0, 0) << '\n';
    }

    return 0;
}