#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w[10][10];

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> w[i][j];
        }
    }

    int ans = 0x7FFFFFFF;

    vector<int> p;
    for(int i=0; i<n; i++){
        p.push_back(i);
    }

    do{
        int tmp=0;
        for(int i=0; i<n-1; i++){
            if(w[p[i]][p[i+1]] == 0){
                tmp = 0x7FFFFFFF;
                break;
            }
            tmp += w[p[i]][p[i+1]];
        }
        if(tmp != 0x7FFFFFFF){
            if(w[p[n-1]][p[0]] == 0){
                tmp = 0x7FFFFFFF;
            }else{
                tmp += w[p[n-1]][p[0]];
            }
        }
        if(ans > tmp) ans = tmp;
    }while(next_permutation(p.begin() + 1,p.end()));

    cout << ans << endl;

    return 0;
}