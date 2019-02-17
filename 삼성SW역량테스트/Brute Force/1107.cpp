#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// button 0~9
// 부서진 버튼이면 true
bool button[10];
int ans;

int main(){

    int n, m;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int broken;
        cin >> broken;
        button[broken] = true;
    }

    // 바로 +, - 를 이용해서 이동할 경우
    ans = abs(n-100);

    for(int i=0; i<=1000000; i++){
        int c = i;
        string tmp = to_string(c);
        bool hasBroken = false;
        for(int j=0; j<tmp.length(); j++){
            if(button[tmp[j] - '0']){
                hasBroken = true;
                break;
            }
        }
        if(hasBroken) continue;
        int gap = abs(c - n);
        gap += tmp.length();
        ans = min(gap, ans);
    }

    cout << ans << '\n';

    return 0;
}