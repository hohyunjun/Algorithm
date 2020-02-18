#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    int n;

    int maxAns = -0x7FFFFFFF;
    int minAns = 0x7FFFFFFF;

    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int plus, minus, mul, divi;

    cin >> plus >> minus >> mul >> divi;

    // 더하기는 0, 빼기 1, 곱하기 2, 나누기 3
    vector<int> op;

    for(int i=0; i<plus; i++){
        op.push_back(0);
    }

    for(int i=0; i<minus; i++){
        op.push_back(1);
    }

    for(int i=0; i<mul; i++){
        op.push_back(2);
    }

    for(int i=0; i<divi; i++){
        op.push_back(3);
    }

    sort(op.begin(), op.end());

    do{
        int tmp = nums[0];
        for(int i=0; i<n-1; i++){
            if(op[i] == 0){
                tmp += nums[i+1];
            }else if(op[i] == 1){
                tmp -= nums[i+1];
            }else if(op[i] == 2){
                tmp *= nums[i+1];
            }else{
                tmp /= nums[i+1];
            }
        }
        maxAns = max(maxAns, tmp);
        minAns = min(minAns, tmp);
    }while(next_permutation(op.begin(), op.end()));

    cout << maxAns << '\n';
    cout << minAns << '\n';


    return 0;
}