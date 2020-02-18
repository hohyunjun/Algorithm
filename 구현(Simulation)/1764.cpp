#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main(){

    int n, m;

    cin >> n >> m;

    map<string, int> _map;

    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        _map[tmp]+=1;
    }

    for(int i=0; i<m; i++){
        string tmp;
        cin >> tmp;
        _map[tmp]+=1;
    }

    int cnt = 0;
    vector<string> ans;

    for(auto each:_map){
        if(each.second == 2){
            cnt++;
            ans.push_back(each.first);
        }
    }

    cout << cnt << '\n';

    sort(ans.begin(), ans.end());

    for(auto each: ans){
        cout << each << '\n';
    }

    return 0;
}