#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    int minnum = n-m;
    int num2 = 0;
    int num5 = 0;

    for(long long int i=5; i<=n; i*=5){
        num5 += n/i;
    }

    for(long long int i=2; i<=n; i*=2){
        num2 += n/i;
    }

    for(long long int i=5; i<=m; i*=5){
        num5 -= m/i;
    }

    for(long long int i=2; i<=m; i*=2){
        num2 -= m/i;
    }

    for(long long int i=5; i<=minnum; i*=5){
        num5 -= minnum/i;
    }

    for(long long int i=2; i<=minnum; i*=2){
        num2 -= minnum/i;
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