#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char A[9];

int main(){

    int k;

    cin >> k;

    for(int i=0; i<k; i++){
        cin >> A[i];
    }

    long long int maxAns = -0x7FFFFFFF;
    long long int minAns = 9999999999;

    // 최소경우(작은 숫자 순서대로 k+1개로만 이루어져 있다)
    // 뽑은 숫자들로 순열 돌린 후 부등호 비교한다.
    vector<int> nums;
    for(int i=0; i<k+1; i++){
        nums.push_back(i);
    }
    do{
        string tmp = "";
        bool valid = true;
        for(int i=0; i<k; i++){
            if(A[i] == '<' && nums[i] > nums[i+1]){
                valid = false;
                break;
            }
            if(A[i] == '>' && nums[i] < nums[i+1]){
                valid = false;
                break;
            }
        }
        if(valid){
            for(int i=0; i<k+1; i++){
                tmp += nums[i] + '0';
            }
            minAns = min(minAns, stoll(tmp));
        }
    }while(next_permutation(nums.begin(), nums.end()));
    
    // 최대경우(큰 숫자 순서대로 k+1개로만 이루어져 있다)
    // 뽑은 숫자들로 순열 돌린 후 부등호 비교한다.
    vector<int> nums2;
    for(int i=0; i<k+1; i++){
        nums2.push_back(9 - i);
    }
    do{
        string tmp = "";
        bool valid = true;
        for(int i=0; i<k; i++){
            if(A[i] == '<' && nums2[i] > nums2[i+1]){
                valid = false;
                break;
            }
            if(A[i] == '>' && nums2[i] < nums2[i+1]){
                valid = false;
                break;
            }
        }
        if(valid){
            for(int i=0; i<k+1; i++){
                tmp += nums2[i] + '0';
            }
            maxAns = max(maxAns, stoll(tmp));
        }
    }while(prev_permutation(nums2.begin(), nums2.end()));


    if(to_string(maxAns).length() < k+1){
        string tmp = "";
        for(int i=0; i< (k+1) - to_string(maxAns).length(); i++){
            tmp += '0';
        }
        tmp += to_string(maxAns);
        cout << tmp << '\n';
    }else{
        cout << to_string(maxAns) << '\n';
    }
    
    if(to_string(minAns).length() < k+1){
        string tmp = "";
        for(int i=0; i< (k+1) - to_string(minAns).length(); i++){
            tmp += '0';
        }
        tmp += to_string(minAns);
        cout << tmp << '\n';
    }else{
        cout << to_string(minAns) << '\n';
    }


    return 0;
}