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

    int plus, minus, mul, divs;

    cin >> plus >> minus >> mul >> divs;

    vector<int> p;

    // 더하기는 0, 빼기는 1, 곱하기는 2, 나누기는 3
    for(int i=0; i<plus; i++){
        p.push_back(0);
    }
    for(int i=0; i<minus; i++){
        p.push_back(1);
    }
    for(int i=0; i<mul; i++){
        p.push_back(2);
    }
    for(int i=0; i<divs; i++){
        p.push_back(3);
    }

    sort(p.begin(), p.end());

    int minAns = 0x7FFFFFFF;
    int maxAns = -0x7FFFFFFF;

    do{
        int tmp = nums[0];
        for(int i=0; i<p.size(); i++){
            if(p[i] == 0){
                tmp += nums[i+1];
            }
            if(p[i] == 1){
                tmp -= nums[i+1];
            }
            if(p[i] == 2){
                tmp *= nums[i+1];
            }
            if(p[i] == 3){
                tmp /= nums[i+1];
            }
        }
        if(tmp < minAns) minAns = tmp;
        if(tmp > maxAns) maxAns = tmp;
    }while(next_permutation(p.begin(), p.end()));

    cout << maxAns << '\n';
    cout << minAns << '\n';

    return 0;
}