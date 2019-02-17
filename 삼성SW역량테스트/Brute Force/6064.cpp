#include <cstdio>
using namespace std;

int main(){

    int t;

    scanf("%d", &t);

    while(t--){
        int m, n;
        int x, y;
        scanf("%d%d%d%d", &m,&n,&x,&y);

        int year = -1;
        if(x<=m && y<=n){
            for(int i=x; i<=m*n; i+=m){
                if( (i-1) % n + 1 == y){
                    year = i;
                    break;
                }
            }
        }
        printf("%d\n", year);


    }


    return 0;
}