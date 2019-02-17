#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int check[20001];

int main(){

    int tc;

    cin >> tc;

    while(tc--){
        vector<int> A[20001];
        fill_n(check, 20001, 0);

        int v, e;
        cin >> v >> e;

        for(int i=0; i<e; i++){
            int a, b;
            cin >> a >> b;
            A[a].push_back(b);
            A[b].push_back(a);
        }

        // 모든 정점에 대해 BFS를 수행한다. 
        for(int i=1; i<=v; i++){
            if(check[i] == 0){
                queue<int> q;
                q.push(i);
                check[i] = 1;
                while(!q.empty()){
                    int w = q.front();
                    for(int j=0; j<A[w].size(); j++){
                        int y = A[w][j];
                        if(check[y] == 0){
                            q.push(y);
                            if(check[w] == 1){
                                check[y] = 2;
                            }else{
                                check[y] = 1;
                            }
                        }
                    }
                    q.pop();
                }
            }
        }

        bool isBipartite = true;

        // 모든 정점에 대해 이분 그래프인지 확인한다.
        for(int i=1; i<=v; i++){
            for(int j=0; j<A[i].size(); j++){
                if(check[i] == check[A[i][j]]){
                    isBipartite = false;
                    break;
                }
            }
            if(!isBipartite) break;
        }
        

        if(isBipartite){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }


    return 0;
}