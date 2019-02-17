#include <iostream>
#include <queue>
using namespace std;

int check[100001];

int main(){

    // check 배열 -1로 초기화
    fill_n(check, 100001, -1);

    int n, k;

    cin >> n >> k;

    queue<int> q;
    queue<int> next_q;
    q.push(n);
    check[n] = 0;

    while(!q.empty()){
        int now = q.front();

        // 2*now
        if(now*2 <= 100000){
            if(check[now*2] == -1){
                q.push(now*2);
                check[now*2] = check[now];
            }
        }

        // now+1
        if(now+1 <= 100000){
            if(check[now+1] == -1){
                next_q.push(now+1);
                check[now+1] = check[now] + 1;
            }
        }

        // now-1
        if(now-1 >= 0){
            if(check[now-1] == -1){
                next_q.push(now-1);
                check[now-1] = check[now] + 1;
            }
        }

        q.pop();

        // 0 큐에 있는 것들을 다 돌렸을 때, 0큐를 next_q로 바꿔주고, next_q는 다시 비워준다.
        if(q.empty()){
            q = next_q;
            queue<int> tmp;
            next_q = tmp;
        }
    }

    cout << check[k] << '\n';

    return 0;
}