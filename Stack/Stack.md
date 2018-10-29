## Stack 기초
  한쪽 끝에서만 자료를 넣고 뺄 수 있는 자료구조  
  마지막으로 넣은 것이 가장 먼저 나오기 때문에 Last In First Out(LIFO) 라고도 한다.  
  push : 스택에 자료를 넣는 연산  
  pop : 스택에서 자료를 빼는 연산  
  top : 스택의 가장 위에 있는 자료를 보는 연산  
  empty : 스택이 비어있는지 아닌지를 보는 연산  
  size : 스택에 저장되어있는 자료의 개수를 알아보는 연산  
  **Stack은 가장 가까운 것을 O(1)만에 찾아낼 수 있다는 특징을 가진다**

## 활용하기
  C++ 의 경우에는 STL의 stack 사용
  ```
  #include <stack>
  using namespace std;

  int main(){

    stack<int> s;

    s.push(1);
    s.pop();
    s.top();
    s.empty();
    s.size();

    return 0;
  }
  ```