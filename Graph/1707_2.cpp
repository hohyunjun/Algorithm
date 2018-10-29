#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int k;
    scanf("%d", &k);

    for(int i=0; i<k; i++){
        vector<int> A[20001];
        int check[20001] = {0};
        int v, e;
        scanf("%d%d", &v, &e);
        for(int j=0; j<e; j++){
            int a,b;
            scanf("%d%d", &a, &b);
            A[a].push_back(b);
            A[b].push_back(a);
        }
        // 여기까지 Graph 초기화
        for(int j=1; j<=v; j++){
            if(check[j]==0){ // 아직 방문되지 않은 정점일 경우
                queue<int> q;
                q.push(j);
                check[j] = 1;
                while(!q.empty()){
                    int w = q.front();
                    for(int l=0; l<A[w].size(); l++){
                        int r = A[w][l];
                        if(check[r] == 0){
                            if(check[w] == 1){
                                check[r] = 2;
                            }else{
                                check[r] = 1;
                            }
                            q.push(r);
                        }
                    }
                    q.pop();
                }
            }
        }

        bool isBipartite = true;
        for(int j=1; j<=v; j++){
            for(int l=0; l<A[j].size(); l++){
                if(check[j] == check[A[j][l]]){
                    isBipartite = false;
                    break;
                }
            }
            if(!isBipartite) break;
        }

        if(isBipartite){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        
    }



    return 0;
}