#include <iostream>
#include <vector>
#define MAX 20
using namespace std;

/*
    유사한 문제인 BOJ 16638 문제를 대신 풀어본다.

    1. 사칙연산을 계산하는 계산기를 스택을 이용하여 만든다. --> 스택을 직접 구현해야 한다.
        1) 스택 구현
        2) infix notation -> postfix notation 변환
        3) 후위표기법 수식 계산
    
    2. 입력으로 주어진 식에 괄호를 직접 넣어본다. (Brute Force) -> 계산하여 최댓값을 update한다.
*/

class Stack{
private:
    int stack[MAX];
    int top;
public:
    void push(int t);
    int pop();
    int get_top();
    bool isEmpty();
    Stack(){
        top = -1;
    }
};

// 정답 저장
int ans = -0x7FFFFFFF;
int n;

// 식 저장
vector<char> input;
// 괄호 체크
bool check[MAX];

// infix to postfix
bool is_operator(char k);
int precedence(char op);

// calculate postfix
int calculate(vector<char> input);

void dfs(int idx){
    if(idx >= n){
        ans = max(ans, calculate(input));
        return;
    }
    for(int i=idx; i<n; i+=2){
        if(i + 2 < n){
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

    for(int i=0; i<n; i++){
        char tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    vector<char> front, inside, back;
    
    for(int i=0; i<2; i++){
        front.push_back(input[i]);
    }

    inside.push_back()

    for(int i=2; i<n; i++){
        back.push_back(input[i]);
    }

    for(auto each : front){
        cout << each << " ";
    }
    cout <<'\n';
    for(auto each: back){
        cout << each << " ";
    }

    //dfs(0);

    //cout << ans << '\n';

    return 0;
}

void Stack::push(int t){
    // 스택 크기가 MAX보다 커질 경우
    if(top >= MAX - 1){
        cout << "Stack Overflow!!\n";
        return; 
    }

    stack[++top] = t;
    return;
}

int Stack::pop(){
    if(top < 0){
        cout << "Stack is empty\n";
        return -1;
    }
    return stack[top--];
}

int Stack::get_top(){
    if(top<0){
        return -1;
    }
    return stack[top];
}

bool Stack::isEmpty(){
    if(top<0){
        return true;
    }
    return false;
}

// 연산자인지 아닌지 판별
bool is_operator(char k){
    return (k == '+' || k == '-' || k == '*' || k == '/');
}

// 연산자 우선순위 체크
int precedence(char op){
    if(op == '(') return 0;
    if(op == '+' || op == '-') return 1;
    if(op == '*') return 2;
    return 3;
}

int calculate(vector<char> input){

    //infix to postfix
    Stack tmp;
    vector<char> pfInput;

    for(auto each:input){
        if(each == '('){
            tmp.push(each);
        }else if(each == ')'){
            while(tmp.get_top() != '('){
                pfInput.push_back(tmp.get_top());
                tmp.pop();
            }
            tmp.pop();
        }else if(is_operator(each)){
            if(tmp.isEmpty()){
                tmp.push(each);
            }else{
                while(!tmp.isEmpty() && precedence(tmp.get_top()) >= precedence(each)){
                    pfInput.push_back(tmp.pop());
                }
                tmp.push(each);
            }
        }else{
            pfInput.push_back(each);
        }
    }

    while(!tmp.isEmpty()){
        pfInput.push_back(tmp.pop());
    }

    Stack num;
    for(auto each:pfInput){
        if(is_operator(each)){
            if(each == '+'){
                int first = num.pop();
                int second = num.pop();
                num.push(first+second);
            }else if(each == '-'){
                int first = num.pop();
                int second = num.pop();
                num.push(second-first);
            }else if(each == '/'){
                int first = num.pop();
                int second = num.pop();
                num.push(second/first);
            }else{
                int first = num.pop();
                int second = num.pop();
                num.push(first*second);
            }
        }else{
            num.push(each - '0');
        }
    }

    return num.get_top();
}