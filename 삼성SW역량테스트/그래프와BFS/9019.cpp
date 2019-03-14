#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[10000]; // 최소연산횟수 저장
pair<char, int> from[10000]; // 어떤 연산으로 인해 이동되었는지, 어떤 수로부터 이동 되었는지 저장

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        memset(dist, 0, sizeof(dist));
        memset(from, ' ', sizeof(from));

        queue<int> q;
        q.push(a);
        dist[a] = 1;
        while(!q.empty()){
            int x = q.front();
            int d = (2*x)%10000;
            int s = x-1;
            if(s==-1){s = 9999;}

            int tmp = x;
            int a,b,c,e;
            a = tmp / 1000;
            tmp -= a*1000;
            b = tmp/100;
            tmp -= b*100;
            c = tmp/10;
            tmp -= c*10;
            e = tmp;

            int l = b*1000 + c*100 + e*10 + a;
            int r = e*1000 + a*100 + b*10 + c;

            if(dist[d] == 0){ // 아직 방문되지 않은 레지스터
                q.push(d);
                dist[d] = dist[x] + 1;
                from[d].first = 'D';
                from[d].second = x;
            }else if(dist[d] != 0 && dist[d] > dist[x] + 1){ // 최소가 아닐 경우
                q.push(d);
                dist[d] = dist[x] + 1;
                from[d].first = 'D';
                from[d].second = x;
            }

            if(dist[s] == 0){
                q.push(s);
                dist[s] = dist[x] + 1;
                from[s].first = 'S';
                from[s].second = x;
            }else if(dist[s] != 0 && dist[s] > dist[x] + 1){
                q.push(s);
                dist[s] = dist[x] + 1;
                from[s].first = 'S';
                from[s].second = x;
            }

            if(dist[l] == 0){
                q.push(l);
                dist[l] = dist[x] + 1;
                from[l].first = 'L';
                from[l].second = x;
            }else if(dist[l] != 0 && dist[l] > dist[x] + 1){
                q.push(l);
                dist[l] = dist[x] + 1;
                from[l].first = 'L';
                from[l].second = x;
            }

            if(dist[r] == 0){
                q.push(r);
                dist[r] = dist[x] + 1;
                from[r].first = 'R';
                from[r].second = x;
            }else if(dist[r] !=0 && dist[r] > dist[x] + 1){
                q.push(r);
                dist[r] = dist[x] + 1;
                from[r].first = 'R';
                from[r].second = x;
            }
            q.pop();
        }
        vector<char> ans;
        int tmp = b;
        while(tmp != a){
            ans.push_back(from[tmp].first);
            tmp = from[tmp].second;
        }
        reverse(ans.begin(), ans.end());
        for(auto each: ans){
            cout << each;
        }
        cout << '\n';
    }    



    return 0;
}