#include <iostream>
#include <vector>
#include <string>
using namespace std;

char A[9]; // 부등호
string minAns = "9999999999";
string maxAns = "-1";
int k;
bool check[10];

// go 함수는 nums string을 만든다.
void go(string nums){
    // 종료조건
    if(nums.length() == k+1){
        // 부등호 방향이 안맞는 놈들 걸러주고
        for(int i=0; i<nums.length()-1; i++){
            if(A[i] == '>' && nums[i]-'0' < nums[i+1] - '0') return;
            if(A[i] == '<' && nums[i]-'0' > nums[i+1] - '0') return;
        }
        minAns = to_string(min(stoll(minAns), stoll(nums)));
        maxAns = to_string(max(stoll(maxAns), stoll(nums)));
        return;
    }
    // 불필요조건
    if(nums.length() >= 2){
        for(int i=0; i<nums.length()-1; i++){
            if(A[i] == '>' && nums[i]-'0' < nums[i+1] - '0') return;
            if(A[i] == '<' && nums[i]-'0' > nums[i+1] - '0') return;
        }
    }
    // 진행조건
    for(int i=0; i<=9; i++){
        if(check[i]) continue;
        check[i] = true;
        go(nums+to_string(i));
        check[i] = false;
    }
}

int main(){

    cin >> k;

    for(int i=0; i<k; i++){
        cin >> A[i];
    }
    
    string nums = "";

    go(nums);

    if(maxAns.length() != k+1){
        string tmp = "0";
        maxAns = tmp + maxAns;
    }

    if(minAns.length() != k+1){
        string tmp = "0";
        minAns = tmp + minAns;
    }

    cout << maxAns << '\n';
    cout << minAns << '\n';


    return 0;
}