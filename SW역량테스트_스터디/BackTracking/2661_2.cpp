#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;

// tmp 배열이 좋은 수열인지 아닌지
bool check(string tmp){
    int len = tmp.length();
    int start = len - 1;

    for(int i=1; i<= len/2; i++){
        string first = tmp.substr(start-i, i);
        string second = tmp.substr(start, i);
        if(first.compare(second) == 0) return false;
        --start;
    }
    return true;
}

void solve(int index, string tmp){
    if(!check(tmp)) return;
    if(index == n){
        cout << tmp;
        exit(0);
    }

    solve(index+1, tmp+"1");
    solve(index+1, tmp+"2");
    solve(index+1, tmp+"3");
}


int main(){

    cin >> n;

    solve(0,"");

    return 0;
}