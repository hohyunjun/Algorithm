#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[10];
vector<int> ans(10);
int check[10];
vector<vector<int>> answers;

void go(int ansIdx, int start, int n, int m){
    if(ansIdx == m){
        answers.push_back(ans);
        return;
    }

    for(int i=start; i<n; i++){
        if(check[i]) continue;
        check[i] = true;
        ans[ansIdx] = nums[i];
        go(ansIdx+1, i, n, m);
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

    sort(answers.begin(), answers.end());

    answers.erase(unique(answers.begin(), answers.end()), answers.end());

    for(int i=0; i<answers.size(); i++){
        for(int j=0; j<m; j++){
            cout << answers[i][j];
            if(j != m-1){
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}