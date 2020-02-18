#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, type;

    cin >> n >> type;

    if(type == 1){
        int k;
        cin >> k;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            nums[i] = i+1;
        }

        int cnt = 0;
        do{
            cnt++;
            if(cnt == k) break;

        }while(next_permutation(nums.begin(), nums.end()));

        for(int i=0; i<n; i++){
            cout << nums[i] << " ";
        }
        cout << '\n';
    }else{
        vector<int> find(n);
        for(int i=0; i<n; i++){
            cin >> find[i];
        }
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            nums[i] = i+1;
        }

        int cnt = 0;

        do{
            cnt++;
            if(nums == find) break;

        }while(next_permutation(nums.begin(), nums.end()));

        cout << cnt << '\n';
    }


    return 0;
}