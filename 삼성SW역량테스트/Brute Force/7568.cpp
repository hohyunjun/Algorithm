#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<pair<int,int>> input;
    vector<int> ans;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        input.push_back(make_pair(a,b));
    }

    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(input[j].first > input[i].first && input[j].second > input[i].second){
                cnt++;
            }
        }
        ans.push_back(cnt+1);
    }

    for(auto each:ans){
        cout << each << " ";
    }

    cout << '\n';

    return 0;
}