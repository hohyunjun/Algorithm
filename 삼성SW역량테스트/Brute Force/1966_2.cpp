#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;

        priority_queue<pair<int,int>> pq;
        queue<pair<int,int>> q;
        map<int,int> removedm;

        for(int i=0; i<n; i++){
            int p;
            cin >> p;
            pq.push(make_pair(p,i));
            q.push(make_pair(p,i));
        }

        int cnt = 1;
        while(!q.empty()){
            //cout << pq.top().first << " " << pq.top().second << '\n';
            if(pq.top().first != q.front().first){
                q.push(make_pair(q.front().first, q.front().second));
                q.pop();
            }else{
                removedm[q.front().second] = cnt;
                pq.pop();
                q.pop();
                cnt+=1;
            }
        }
        cout << removedm[m] << '\n';
    }


    return 0;
}