#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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

    // n명 중에서 n/2명을 뽑으면 된다.
    vector<int> check;
    for(int i=0; i<n/2; i++){
        check.push_back(0);
    }
    for(int i=0; i<n/2; i++){
        check.push_back(1);
    }

    int ans = 0x7FFFFFFF;

    // check 벡터를 순열로 돌려서 n/2명을 뽑을 수 있는 경우를 모두 계산한다.
    do{
        vector<int> start;
        vector<int> link;
        for(int i=0; i<n; i++){
            if(check[i] == 0){
                start.push_back(i);
            }else{
                link.push_back(i);
            }
        }

        int startCapa = 0;
        int linkCapa = 0;
        for(int i=0; i<start.size()-1; i++){
            for(int j=i+1; j<start.size(); j++){
                startCapa += S[start[i]][start[j]];
                startCapa += S[start[j]][start[i]];
            }
        }
        for(int i=0; i<link.size() -1; i++){
            for(int j=i+1; j<link.size(); j++){
                linkCapa += S[link[i]][link[j]];
                linkCapa += S[link[j]][link[i]];
            }   
        }

        ans = min(abs(linkCapa-startCapa), ans);
    }while(next_permutation(check.begin(), check.end()));

    cout << ans << '\n';

    return 0;
}