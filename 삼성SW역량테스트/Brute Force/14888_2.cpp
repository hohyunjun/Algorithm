#include <iostream>
using namespace std;

int minAns = 0x7FFFFFFF;
int maxAns = -0x7FFFFFFF;
int n;
int nums[11];
int p,m,mul,d;

void solve(int plus, int minus, int mul, int divs, int result, int nextIdx){
    // 불가능한 경우
    if(plus < 0 || minus < 0 || mul < 0 || divs < 0) return;
    // 정답을 찾은 경우
    if(plus == 0 && minus == 0 && mul == 0 && divs == 0){
        if(result < minAns){
            minAns = result;
        }
        if(result > maxAns){
            maxAns = result;
        }
        return;
    }
    solve(plus-1, minus, mul, divs, result+nums[nextIdx], nextIdx+1);
    solve(plus, minus-1, mul, divs, result-nums[nextIdx], nextIdx+1);
    solve(plus, minus, mul-1, divs, result*nums[nextIdx], nextIdx+1);
    solve(plus, minus, mul, divs-1, result/nums[nextIdx], nextIdx+1);
}

int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cin >> p >> m >> mul >> d;

    solve(p,m,mul,d,nums[0],1);

    cout << maxAns << '\n';
    cout << minAns << '\n';

    return 0;
}