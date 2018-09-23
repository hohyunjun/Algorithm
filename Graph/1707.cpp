#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int K;
    scanf("%d", &K);

    for(int i=0; i<K; i++){
        vector<int> A[20001];
        int check[20001] = {0};

        int V, E;
        scanf("%d%d", &V, &E);
        for(int j=0; j<E; j++){
            int a, b;
            scanf("%d%d", &a, &b);
            A[a].push_back(b);
            A[b].push_back(a);
        }
        //BFS 수행 후 1, 2 체크(모든 정점에 대해서 수행해야함.)
        for(int l=1; l<=V; l++){
            if(check[l]==0){
                queue<int> q;
                q.push(l);
                check[l] = 1;
                while (!q.empty())
                {
                    int w = q.front();
                    for (int j = 0; j < A[w].size(); j++)
                    {
                        int y = A[w][j];
                        if (check[y] == 0)
                        {
                            if (check[w] == 1)
                            {
                                check[y] = 2;
                            }
                            else
                            {
                                check[y] = 1;
                            }
                            q.push(y);
                        }
                    }
                    q.pop();
                }
            }
        }

        bool isBiPartite = true;

        for(int j=1; j<=V; j++){
            for(int k=0; k<A[j].size(); k++){
                if(check[j] == check[A[j][k]]){
                    isBiPartite = false;
                    break;
                }
            }
            if(!isBiPartite) break;
        }

        if(isBiPartite){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}