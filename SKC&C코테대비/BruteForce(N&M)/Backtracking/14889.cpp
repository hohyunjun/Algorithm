#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;

int S[20][20];
int selected[10];
int check[20];
int ans = 0x7FFFFFFF;

void solve(int index, int start, int n, int m){
    if(index==m){
        //selected에 저장된 숫자는 A에 저장, 아닌 건 B에 저장
        for(int i=0; i<m; i++){
            check[selected[i]] = 1;
        }

        vector<int> A;
        vector<int> B;

        for(int i=0; i<n; i++){
            if(check[i]){
                A.push_back(i);
            }else{
                B.push_back(i);
            }
        }

        int ta = 0, tb = 0;

        for(int l1=0; l1<m; l1++){
            for(int l2=0; l2<m; l2++){
                if(l1==l2) continue;
                ta += S[A[l1]][A[l2]];
                tb += S[B[l1]][B[l2]];
            }
        }

        ans = min(ans, abs(ta-tb));

        memset(check, 0, sizeof(check));

        return;
    }
    for(int i=start; i<n; i++){
        selected[index] = i;
        solve(index+1, i+1, n, m);
    }
}

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> S[i][j];
        }
    }

    // n명 중에서 n/2명을 뽑아야 함 -> 조합
    solve(0,0,n,n/2);    

    cout << ans << '\n';

    return 0;
}