#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int S[20][20];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> S[i][j];
        }
    }

    int ans = 0x7FFFFFFF;

    for(int i=0; i<(1<<n); i++){
        int cnt = 0;
        vector<int> start, link;
        for(int j=0; j<n; j++){
            if( (i & (1<<j)) == 0 ){ // check!! j라는 숫자가 포함되어 있는지
                cnt++;
            }
        }
        if(cnt != n/2) continue;

        for(int j=0; j<n; j++){
            if( (i & (1<<j)) == 0 ){ // check!! j라는 숫자가 포함되어 있는지
                start.push_back(j);
            }else{
                link.push_back(j);
            }
        }
        int t1 = 0;
        int t2 = 0;
        for(int l1=0; l1<n/2; l1++){
            for(int l2=0; l2<n/2; l2++){
                if(l1 == l2) continue;
                t1 += S[start[l1]][start[l2]];
                t2 += S[link[l1]][link[l2]];
            }
        }
        int diff = abs(t1-t2);
        ans = min(diff, ans);
    }

    cout << ans << '\n';

    return 0;
}