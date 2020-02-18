#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> nums;

    int k;

    cin >> k;

    while(k--){
        int num;

        cin >> num;

        if(!num){
            nums.pop_back();
        }else{
            nums.push_back(num);
        }

    }

    int sum = 0;

    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
    }

    cout << sum << '\n';



    return 0;
}