#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[10];
vector<int> ans(10);
vector<vector<int>> answers;

void solve(int index, int n, int m){
    if(index == m){
        answers.push_back(ans);
        return;
    }
    for(int i=0; i<n; i++){
        ans[index] = a[i];
        solve(index+1, n, m);
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    solve(0,n,m);

    sort(answers.begin(), answers.end());

    answers.erase(unique(answers.begin(), answers.end()), answers.end());

    for(auto each:answers){
        for(int i=0; i<m; i++){
            cout << each[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}