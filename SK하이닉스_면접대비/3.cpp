#include <iostream>
#include <vector>
#include <string>
#define MAX 20
using namespace std;

/*
    BOJ 13368

    1. 계산기 만들기
     - 계산결과를 저장하는 벡터에 괄호에 포함된 숫자들부터 계산해서 저장한다.
     - 괄호가 계산된 벡터에서 *를 먼저 계산한다.
     - 나머지 +, - 를 계산한다.
    
    2. DFS로 괄호 넣기
*/


/*
    3번 문제 알고리즘

    1. 계산기 만들기
     - 괄호 먼저 계산
     - *계산
     - +, - 계산하기

    2. 괄호 가정하기
     - 이 때, 괄호 내부에 연산자가 2개 이상 올 수 있고, 대신 괄호는 하나만 존재하므로, 괄호가 생길 수 있는 모든 경우의 수에 대해 먼저 계산을 해 준다.
     - 즉, 괄호는 숫자부터 시작해서 숫자로 끝나야 하며, 숫자의 좌표는 항상 짝수이다. ex) 1+2+3*4-5 에서, 첫번째 원소의 인덱스가 0일때, 숫자의 인덱스는 항상 짝수이다.
     - 0~2 까지 괄호를 가정할 경우, 0~4, 0~6 ... 2~4, 2~6 ... 4~6 등으로 해당 범위 내의 연산식만 먼저 계산하여 벡터에 저장한다. --> 괄호 내부를 계산할 때도 연산자 우선순위가 적용되어야 한다.


*/

// 식을 받을 변수
int n;
vector<char> input(MAX);

// 괄호를 체크할 변수
bool check[MAX];

// 최대값 저장할 변수
int ans = -0x7FFFFFFF;

int cal(int num1, int num2, string op){
    if(op == "+"){
        return num1 + num2;
    }else if(op == "-"){
        return num1 - num2;
    }else{
        return num1 * num2;
    }
}

int calculate(){
    // 괄호계산 후 저장할 벡터
    vector<string> v;
    for(int i=0; i<n;){
        if(check[i] == false){ //괄호가 아닐 경우
            string s = "";
            s += input[i];
            v.push_back(s);
            i++;
        }else{ // 괄호가 있을 경우
            string num1 = "";
            num1 += input[i];
            string op = "";
            op += input[i+1];
            string num2 = "";
            num2 += input[i+2];
            v.push_back(to_string(cal(stoi(num1), stoi(num2), op)));
            i+=3;
        }
    }

    // *계산 후 저장할 벡터
    vector<string> nv;
    for(int i=0; i<v.size();){
        if(v[i] == "*"){ // 곱하기 연산자가 나올 경우
            string num1 = nv.back();
            nv.pop_back();
            string num2 = v[i+1];
            nv.push_back(to_string(cal(stoi(num1), stoi(num2), "*")));
            i+=2; 
        }else{
            nv.push_back(v[i]);
            i++;
        }
    }

    int retValue = stoi(nv[0]);
    for(int i=1; i<nv.size();){
        if(nv[i] == "+"){
            retValue = cal(retValue, stoi(nv[i+1]), "+");
            i+=2;
        }else{
            retValue = cal(retValue, stoi(nv[i+1]), "-");
            i+=2;
        }
    }

    return retValue;
}

// 괄호를 넣어보는 dfs
void dfs(int idx){
    // 괄호를 더 이상 넣을 수 없을 경우
    if(idx >= n){
        ans = max(ans, calculate());
        return;
    }
    for(int i=idx; i<n; i+=2){
        if(i+2 < n){
            if(check[i] == false && check[i+2] == false){
                check[i] = true;
                check[i+2] = true;
                dfs(idx+2);
                check[i] = false;
                check[i+2] = false;
            }
        }else{
            dfs(i+1);
        }
    }
}

int main(){

    cin >> n;

    for(int i=0; i<n ; i++){
        cin >> input[i];
    }

    dfs(0);

    cout << ans << '\n';

    return 0;
}