#include <cstdio>
using namespace std;

int main(){

    int m, n;

    scanf("%d%d", &m, &n);

    //vector<bool> check(n+1, false); // 지워졌는지 아닌지를 체크할 배열
    bool check[n+1] = {false};
    check[0] = true;
    check[1] = true;

    for(int i=2; i*i<=n; i++){
        if(check[i] == false){
            for(int j=i*2; j<=n; j+=i){
                check[j] = true;
            }
        }
    }

    for(int i=m; i<=n; i++){
        if(check[i] == false){
            printf("%d\n", i);
        }
    }

    return 0;
}