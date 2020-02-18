#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    int check[100001];

    memset(check, -1, sizeof(check));

    deque<int> q;
    q.push_front(n);
    check[n] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop_front();
        if(2*x <= 100000){
            if(check[2*x] == -1){
                check[2*x] = check[x];
                q.push_front(2*x);
            }else{
                if(check[2*x] > check[x]){
                    check[2*x] = check[x];
                    q.push_front(2*x);
                }
            }
            
        }
        if(x+1 <= 100000){
            if(check[x+1] == -1){
                check[x+1] = check[x] + 1;
                q.push_back(x+1);
            }else{
                if(check[x+1] > check[x] + 1){
                    check[x+1] = check[x] + 1;
                    q.push_back(x+1);
                }
            }
        }
        if(x-1 >= 0){
            if(check[x-1] == -1){
                check[x-1] = check[x] + 1;
                q.push_back(x-1);
            }else{
                if(check[x-1] > check[x] + 1){
                    check[x-1] = check[x] + 1;
                    q.push_back(x-1);
                }
            }
        }
    }

    cout << check[k] << '\n';

    return 0;
}