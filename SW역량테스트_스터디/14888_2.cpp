#include <iostream>
using namespace std;

int maxAns = -0x7FFFFFFF;
int minAns = 0x7FFFFFFF;
int nums[11];
int n;

void solve(int index, int tmp, int p, int m, int g, int d){
    if(index >= n){
        maxAns = max(maxAns, tmp);
        minAns = min(minAns, tmp); 
        return;
    }
    if(p>0){solve(index+1, tmp+nums[index], p-1, m, g, d);}
    if(m>0){solve(index+1, tmp-nums[index], p, m-1, g, d);}
    if(g>0){solve(index+1, tmp*nums[index], p, m, g-1, d);}
    if(d>0){solve(index+1, tmp/nums[index], p, m, g, d-1);}
}


int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int p,m,g,d;

    cin >> p >> m >> g >> d;

    solve(1, nums[0], p, m , g, d);

    cout << maxAns << '\n';
    cout << minAns << '\n';

    return 0;
}