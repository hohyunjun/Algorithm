#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a(10);
vector<int> ans(10);
bool check[10];
vector<vector<int>> answers;

void solve(int index, int n, int m){
    if(index == m){
        answers.push_back(ans);
        return;
    }
    for(int i=0; i<n; i++){
        if(check[i]) continue;
        check[i] = true;
        ans[index] = a[i];
        solve(index+1, n, m);
        check[i] = false;
    }
}


int main(){

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

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