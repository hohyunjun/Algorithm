#include <iostream>
#include <vector>
#include <string>
using namespace std;

int S[10][10];
int n;
vector<int> ans(10);

bool ok(int len){
    for(int i=0; i<=len; i++){
        int sum = 0;
        for(int j=i; j<=len; j++){
            sum += ans[j];
            if(S[i][j] == '0' && sum != 0) return false;
            if(S[i][j] == '+' && sum <= 0) return false;
            if(S[i][j] == '-' && sum >= 0) return false;
        }
    }
    return true;
}

bool check(int index){
    int sum = 0;
    for(int i=index; i>=0; i--){
        sum += ans[i];
        if(S[i][index] == 0){
            if(sum != 0) return false;
        }else if(S[i][index] == -1){
            if(sum >= 0) return false;
        }else if(S[i][index] == 1){
            if(sum <= 0) return false;
        }
    }
    return true;
}

// ans[index] 
bool go(int index){
    // 종료조건
    if(index == n){
        return true;
    }
    // 불필요조건
    // 진행조건
    if(S[index][index] == 0){
        ans[index] = 0;
        return check(index) && go(index+1);
    }
    for(int i=1; i<=10; i++){
        // 부호가 음수일 경우
        ans[index] = i*S[index][index];
        if(check(index) && go(index+1)) return true;
    
    }
    return false;
}


int main(){

    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(s[cnt] == '0'){
                S[i][j] = 0;
            }else if(s[cnt] == '+'){
                S[i][j] = 1;
            }else{
                S[i][j] = -1;
            }
            cnt+=1;
        }
    }

    go(0);

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}