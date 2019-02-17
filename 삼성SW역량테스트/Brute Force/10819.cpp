#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = -0x7FFFFFFF;

    do{
        int tmp = 0;
        for(int i=1; i<n; i++){
            tmp += abs(nums[i]-nums[i-1]);
        }
        if(tmp>ans) ans = tmp;

    }while(next_permutation(nums.begin(), nums.end()));

    cout << ans << endl;

    return 0;
}