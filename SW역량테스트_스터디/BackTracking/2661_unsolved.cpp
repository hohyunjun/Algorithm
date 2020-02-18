#include <iostream>
#include <string>
#include <vector>
using namespace std;

// tmp 배열이 좋은 수열인지 아닌지 : 맨 마지막 숫자가 추가되고 바로 검사하는 것이므로, 맨 마지막 숫자 기준으로 체크해주면 된다.
bool check(string tmp){
    int len = tmp.length();
    int start = len - 1;

    for(int i=1; i<=len/2; i++){
        string s1 = tmp.substr(start-i, i);
        string s2 = tmp.substr(start, i);
        if(s1 == s2) return false;
        start--;
    }
    return true;
}

void solve(int n, int index, string tmp){
    if(!check(tmp)) return;
    if(index == n){
        cout << tmp;
        cout << '\n';
        exit(0);
    }else{
        for(int i=1; i<=3; i++){
            solve(n, index+1, tmp + to_string(i));
        }
    }
}


int main(){

    int n;

    cin >> n;

    string tmp;

    solve(n,0,tmp);

    return 0;
}