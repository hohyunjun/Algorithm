#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int cycle = 0;
        vector<int> A;
        A.push_back(0);
        bool check[1001] = {false};
        int N;
        scanf("%d", &N);
        // 그래프의 간선 초기화
        for (int j = 0; j < N; j++)
        {
            int b;
            scanf("%d", &b);
            A.push_back(b);
        }

        // BFS 수행해서 사이클 구하기
        for (int j = 1; j <= N; j++)
        {
            if (check[j] == false)
            {
                queue<int> q;
                q.push(j);
                check[j] = true;
                while (!q.empty())
                {
                    int w = q.front();
                    if(check[A[w]]==false){
                        q.push(A[w]);
                        check[A[w]] = true;
                    }
                    q.pop();
                }
                cycle += 1;
            }
        }

        printf("%d\n", cycle);
    }

    return 0;
}