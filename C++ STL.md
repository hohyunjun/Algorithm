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

## pair를 사용한 구조체, 클래스 정렬하기
 - pair
   + 두 자료형을 묶어주는 C++ Container
   + utility Header 에 존재
   + 문제에서 주어진 정렬조건이 pair의 정렬조건과 같은경우
   + **대소 비교 및 sort에의한 정렬에서 : 첫번째 인자 기준, 첫번째가 같으면 두번째인자로 판단**
   ```
   // pair 인스턴스 만들기
   pair<int, string> p1 = make_pair(1,"BlockDMask");    
   // pair 형태의 vector 선언
   vector< pair<int, int> > point(n);
   cin >> point[i].first;
   cin >> point[i].second;
   ```