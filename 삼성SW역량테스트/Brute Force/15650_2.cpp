#include <iostream>
#include <vector>
using namespace std;

// 오름차순만 고르는 것이기 때문에 각각의 자연수를 선택하는 경우와 선택하지 않는경우 모두를 시도해 볼 수 있다.

int a[10];
int nums[10] = {1,2,3,4,5,6,7,8,9,10};

// 수열 a
void solve(int index, int length, int n, int m){
    // 종료조건
    if(length == m){
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }

    // 불가능한 경우
    if(index >= n){
        return;
    }

    // index를 선택할 경우
    a[length] = nums[index];
    solve(index+1, length+1, n, m);
    // index를 선택하지 않을 경우
    a[length] = 0;
    solve(index+1, length, n, m);
}

int main(){

    int n, m;

    cin >> n >> m;

    solve(0, 0, n, m);

    return 0;
}