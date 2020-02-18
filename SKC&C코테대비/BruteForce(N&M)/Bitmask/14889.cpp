#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int S[20][20];

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> S[i][j];
        }
    }

    int ans = 0x7FFFFFFF;

    for(int i=0; i<(1<<n); i++){
        int cnt=0;
        vector<int> A, B;
        for(int j=0; j<n; j++){
            if( i&(1<<j) ){
                cnt++;
            }
        }

        if(cnt != n/2) continue;

        // 같은 수로 나뉘어졌을 경우
        for(int j=0; j<n; j++){
            if( i&(1<<j) ){
                A.push_back(j);
            }else{
                B.push_back(j);
            }
        }

        int ta = 0, tb = 0;

        for(int l1=0; l1<n/2; l1++){
            for(int l2=0; l2<n/2; l2++){
                if(l1==l2) continue;
                ta += S[A[l1]][A[l2]];
                tb += S[B[l1]][B[l2]];
            }
        }

        ans = min(ans, abs(ta-tb));
    }

    cout << ans << '\n';


    return 0;
}