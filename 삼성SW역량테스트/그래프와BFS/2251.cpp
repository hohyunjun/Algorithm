#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
using namespace std;

map<tuple<int,int,int>, int> dist; // 정점의 방문여부를 체크

int main(){

    int a, b, c; // 넣을 수 있는 물의 최대치

    cin >> a >> b >> c;

    vector<int> ans; // 정답을 저장할 배열

    tuple<int,int,int> start = make_tuple(0,0,c);

    queue<tuple<int,int,int>> q;
    q.push(start);
    dist[start] = 1;
    while(!q.empty()){
        auto now = q.front();
        int x,y,z; // 현재 들어있는 물의 양(a,b,c)
        tie(x,y,z) = now;
        if(x==0){
            ans.push_back(z);
        }
        // 각각의 물의 양이 0이 아닐 경우, 가능한 경우의 수를 모두 큐에 넣는다.
        if(x){
            int tmpa = x, tmpb = y, tmpc = z;
            // a -> b로 물을 넣을 때
            int possible = b  - tmpb;
            if(possible > tmpa){
                tmpb += tmpa;
                tmpa = 0;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next]==0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }else if(possible <= tmpa){
                tmpb = b;
                tmpa = tmpa - possible;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next] == 0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }

            tmpa = x, tmpb = y, tmpc = z;
            // a -> c로 물을 넣을 때
            possible = c  - tmpc;
            if(possible > tmpa){
                tmpc += tmpa;
                tmpa = 0;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next]==0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }else if(possible <= tmpa){
                tmpc = c;
                tmpa = tmpa - possible;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next] == 0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }
        if(y){
            int tmpa = x, tmpb = y, tmpc = z;
            // b -> a로 물을 넣을 때
            int possible = a - tmpa;
            if(possible > tmpb){
                tmpa += tmpb;
                tmpb = 0;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next]==0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }else if(possible <= tmpb){
                tmpa = a;
                tmpb = tmpb - possible;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next] == 0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }

            tmpa = x, tmpb = y, tmpc = z;
            // b -> c로 물을 넣을 때
            possible = c - tmpc;
            if(possible > tmpb){
                tmpc += tmpb;
                tmpb = 0;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next]==0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }else if(possible <= tmpb){
                tmpc = c;
                tmpb = tmpb - possible;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next] == 0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }

        }
        if(z){
            int tmpa = x, tmpb = y, tmpc = z;
            // c -> a로 물을 넣을 때
            int possible = a  - tmpa;
            if(possible > tmpc){
                tmpa += tmpc;
                tmpc = 0;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next]==0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }else if(possible <= tmpc){
                tmpa = a;
                tmpc = tmpc - possible;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next] == 0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }

            tmpa = x, tmpb = y, tmpc = z;
            // c -> b로 물을 넣을 때
            possible = b - tmpb;
            if(possible > tmpc){
                tmpb += tmpc;
                tmpc = 0;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next]==0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }else if(possible <= tmpc){
                tmpb = b;
                tmpc = tmpc - possible;
                auto next = make_tuple(tmpa, tmpb, tmpc);
                if(dist[next] == 0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }   
        q.pop();
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(),ans.end()), ans.end());

    for(auto each : ans){
        cout << each << " ";
    }

    return 0;
}