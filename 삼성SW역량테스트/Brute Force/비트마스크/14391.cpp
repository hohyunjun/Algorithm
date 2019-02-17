#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

int A[4][4];


int main(){

    int n, m;

    scanf("%d%d", &n,&m);
    //cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    int ans = -1;

    // 최대 범위는 m*n이다.
    // 가로면 0, 세로면 1을 direction 배열에 넣는다.
    for(int i=0; i < (1<<(m*n)); i++){
        int direction[4][4];
        int check[4][4];
        memset(check, false, sizeof(check));

        for(int j=0; j<m*n; j++){
            if(i&(1<<j)){ // i에 j 값이 존재한다면
                direction[j/m][j%m] = 1;
            }else{
                direction[j/m][j%m] = 0;
            }
        }

        // printf("checking!!\n");
        // for(int l1=0; l1<n; l1++){
        //     for(int l2=0; l2<m; l2++){
        //         printf("%d ", direction[l1][l2]);
        //     }
        //     printf("\n");
        // }

        int sum = 0;

        // 가로, 세로 방향을 보고 숫자의 합을 구하는 코드
        for(int l1=0; l1<n; l1++){
            for(int l2=0; l2<m; l2++){
                // 이미 숫자가 체크된 곳이면 pass
                if(check[l1][l2]) continue;
                string tmp = "";
        
                // 가로방향일 경우
                if(direction[l1][l2] == 0){
                    int garo = l2;
                    while(direction[l1][garo] == 0 && garo < m){
                        check[l1][garo] = true;
                        tmp += (A[l1][garo] + '0');
                        garo++;
                    }
                }else{
                    int sero = l1;
                    while(direction[sero][l2] == 1 && sero < n){
                        check[sero][l2] = true;
                        tmp += (A[sero][l2] + '0');
                        sero++;
                    }
                }
                sum += stoi(tmp);
            }
        }

        //printf("sum : %d\n", sum);

        ans = max(sum, ans);
    }

    printf("%d\n", ans);


    return 0;
}