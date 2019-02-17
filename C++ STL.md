## C++11 에서 새로 도입된 범위기반 for문과 auto 사용하기
    ```
    int a[7] = {7,6,5,4,3,2,1};
    for(auto n: a){
        cout << n << ' ';
    }
    ```
    범위 기반 for문에서는 배열 요소 개수에 맞추어 자동으로 반복한다.   
    조건문이 따라 필요없고 배열 요소의 개수가 변하더라고 for문의 조건문을 바꿀 필요가 없다.  

## map 사용하기
    map은 원소를 key와 value의 쌍으로 저장한다.  
    m[k] = v : m 컨테이너에 원소 (k,v)를 추가하거나 key에 해당하는 원소의 value를 v로 갱신한다.
    ```
    #include <map>
    using namespace std;

    map<int, int> _map;
    int n1 = 0;
    int n2 = 1;
    _map[0] = n1;
    _map[1] = n2;
    int p1 = _map[0]; // 0
    int p2 = _map[1]; // 1
    int p3 = _map[2]; // 0 초기화 되지 않은 값은 0으로 할당되어 있다.
    ```
    - map을 사용하여 시간복잡도를 줄일 수 있다.
    - 알고리즘 특론 수업파일 map활용하기 두숫자 스크린샷 참고

## map 정렬하기
    - sort by key
        일반적으로 map 사용 시 key를 사용하여 정렬하게 되는데, 특별한 내용 없이 생성 단계에서 지정 가능하다.
        오름차순 : map<int, int, less<int>> m; (default)
        내림차순 : map<int, int, greater<int>> m;
    - sort by value
        경우에 따라 value 기준의 sorting이 필요한데, 이 경우는 순수한 map으로 구현하기 까다롭다. 
        pair vector를 활용해 정렬 후 map형태로 다시 만든다.

## pair를 사용한 구조체, 클래스 정렬하기
 - pair
   + 두 자료형을 묶어주는 C++ Container
   + utility Header 에 존재
   + 문제에서 주어진 정렬조건이 pair의 정렬조건과 같은경우
   + **대소 비교 및 sort에의한 정렬에서 : 첫번째 인자 기준, 첫번째가 같으면 두번째인자로 판단**
   ```c++
   // pair 인스턴스 만들기
   pair<int, string> p1 = make_pair(1,"BlockDMask");    
   // pair 형태의 vector 선언
   vector< pair<int, int> > point(n);
   cin >> point[i].first;
   cin >> point[i].second;
   ```
## C++ Tuple
 - pair를 확장한 자료형. pair가 2개의 값을 한 번에 저장할 수 있다면, tuple은 제한이 없다.
 - 3개 이상의 서로 다른 자료형을 하나의 변수로 묶을 때 사용가능하다.
 - 아래 코드 예제와 같이 튜플을 생성할 수 있고, get<n>(tp) 형태로 내부 값을 가져올 수 있다.
 ```c++
    #include <iostream>
    #include <tuple>
    using namespace std;

    int main(){

        tuple<int, int, int> tp = make_tuple(2,3,4);

        cout << get<0>(tp) << '\n';
        cout << get<1>(tp) << '\n';
        cout << get<2>(tp) << '\n';

        //또는,
        int a, b, c;
        tie(a,b,c) = tp;


        return 0;
    }
 ```

## C++ next_permutation
 - <algorithm> 헤더 파일에 포함되어 있다.
 - next_permutation(v.begin(), v.end()) 형태로 사용한다.
 - v 순열에서 인자로 넘어간 범위에 해당하는 다음 순열을 구하고 true를 반환한다. 다음 순열이 없다면, false를 반환한다.
 - 이와 반대되는 함수로 prev_permutation()이 있다.
 - next_permutation을 사용해서 조합, 순열 문제를 풀 수 있다.
  + 조합 : n개중에서 m개를 선택하는 문제 등

## priority_queue
 - <queue> 헤더 파일에 포함되어 있다.
 - priority_queue<데이터 타입> [변수 이름]; 형태로 선언한다.
 - pq의 top()은 정렬된 큐 중 가장 우선순위가 높은 것을 반환한다.
 - 선언 시에 정렬기준을 넣어줘서 우선순위를 바꿔줄 수 있다.
 - 멤버함수로는 pq.empty(), pq.top(), pq.pop(), pq.push() 등이 있다.

## vector의 중복제거 방법
 - unique와 erase활용
 - unique와 erase를 활용하기 위해서는 먼저, 중복을 제거하려는 벡터가 정렬상태이어야 한다.
 - unique(vector.begin(), vector.end()) 함수는 연속된 중복 원소를 vector의 제일 뒷부분으로 쓰레기값으로 보내버린다.
 - unique함수는, 보내버린 쓰레기값의 첫번째 위치를 반환한다. 이를 활용해서 중복값을 지울 수 있다.
 - erase() 함수는 첫번재 인자로 시작위치를 받고, 두번째 인자로 끝위치를 받아서 해당 범위의 배열을 지운다.
 - 즉 중복을 제거하는 예시는 아래와 같다.
 ```c++
 #include<algorithm>
 #include<vector>
 using namespace std;

 int main(){

     vector<int> s;

     s.push_back(1);
     s.push_back(1);
     s.push_back(2);
     s.push_back(2);

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    return 0;
 }
 ```
 - 위의 예시에서 s벡터에는 1,2라는 원소만 남게 된다.
