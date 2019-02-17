#include <iostream>
#include <queue>
using namespace std;

int position[100001];
int checkTime[100001];

int main(){

    int n, k;

    cin >> n >> k;
    
    queue<int> q;

    q.push(n);
    checkTime[n] = 1;

    while(!q.empty()){
        int x = q.front();
        int y = x - 1;
        int z = x + 1;
        int w = x * 2;
        if(y >= 0){
            if(checkTime[y] == 0){
                q.push(y);
                checkTime[y] = checkTime[x] + 1;
            }else if(checkTime[y] != 0 && checkTime[y] > checkTime[x] + 1){
                q.push(y);
                checkTime[y] = checkTime[x] + 1;
            }
        }
        if(z <= 100000){
            if(checkTime[z] == 0){
                q.push(z);
                checkTime[z] = checkTime[x] + 1;
            }else if(checkTime[z] != 0 && checkTime[z] > checkTime[x] + 1){
                q.push(z);
                checkTime[z] = checkTime[x] + 1;
            }
        }
        if(w <= 100000){
            if(checkTime[w] == 0){
                q.push(w);
                checkTime[w] = checkTime[x] + 1;
            }else if(checkTime[w] != 0 && checkTime[w] > checkTime[x] + 1){
                q.push(w);
                checkTime[w] = checkTime[x] + 1;
            }
        }
        q.pop();
    }

    cout << checkTime[k] - 1 << '\n';

    return 0;
}