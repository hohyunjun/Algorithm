#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    vector<int> ans;
    int M, N;
    cin >> N;
    cin >> M;

    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(!q.empty()){
        int count = 1;
        while(count != M){ // M번째에 도달하기 전까지 push
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            count++;
        }
        int tmp = q.front();
        ans.push_back(tmp);
        q.pop();
    }

    cout << "<";
    for(int i=0; i<ans.size(); i++){
        if(i==ans.size()-1){
            cout << ans[i];
        }else{
            cout << ans[i] << ", ";
        }
    }
    cout << ">";


    return 0;
}