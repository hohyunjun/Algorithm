#include <iostream>
using namespace std;

/*
    1번

    1. 입력으로 주어진 n에 대해서 조건을 만족하는지 확인한다.
    2. n을 1씩 계속 증가시키면서 조건을 만족할 경우의 n을 출력한다.
*/


// 수의 길이를 반환하는 함수
int len(int n){
    int cnt = 0;
    while(n){
        n /= 10;
        cnt++;
    }
    return cnt;
}

// 조건을 만족하는지 확인
bool isRight(int n){

    // 홀수일 경우
    if(len(n) % 2) return false;

    // 앞자리수 곱, 뒷자리수 곱을 계산해준다.
    int front = 1, back = 1;

    // 뒷자리수 n/2개 개수를 세는 변수 cnt
    int cnt = len(n)/2;

    while(cnt--){
        back *= n%10;
        n/=10;
    }

    // 남은 앞자리수의 곱
    while(n){
        front *= n%10;
        n/=10;
    }

    if(front == back) return true;
    return false;   
}

int main(){

    int n;

    cin >> n;

    while(!isRight(n)){
        n++;
    }

    cout << n << '\n';

    return 0;
}