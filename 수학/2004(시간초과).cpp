#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    int maxnum = max(m, n-m);
    int minnum = min(m, n-m);
    int num2 = 0;
    int num5 = 0;

    for(int i=maxnum+1; i<=n; i++){
        int tmp = i;
        while(tmp%2==0){
            num2++;
            tmp/=2;
        }
        while(tmp%5==0){
            num5++;
            tmp/=5;
        }
    }

    for(int i=2; i<=minnum; i++){
        int tmp = i;
        while(tmp%2==0){
            num2--;
            tmp/=2;
        }
        while(tmp%5==0){
            num5--;
            tmp/=5;
        }
    }

    int answer = 0;
    if(n<5){
        answer = 0;
    }else if(num2>0 && num5>0){
        answer = min(num2, num5);
    }else{
        answer = 0;
    }

    cout << answer;

    return 0;
}