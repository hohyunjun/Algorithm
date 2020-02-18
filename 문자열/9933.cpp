#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<string> strset(n);

    for(int i=0; i<n; i++){
        cin >> strset[i];
    }

    string ans;

    for(int i=0; i<n; i++){
        stack<char> st;
        for(int j=0; j<strset[i].length(); j++){
            st.push(strset[i][j]);
        }

        string tmp = "";
        while(!st.empty()){
            tmp += st.top();
            st.pop();
        }

        bool found = false;

        for(int j=0; j<n; j++){
            if(tmp.length() != strset[j].length()) continue;
            if(tmp == strset[j]){
                ans = tmp;
                found = true;
                break;
            }
        }
        if(found) break;
    }

    cout << ans.length() << " " << ans[ans.length()/2] << '\n';


    return 0;
}