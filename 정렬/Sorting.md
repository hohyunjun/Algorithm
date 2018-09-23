## 정렬 기초
 - 많은 정렬 알고리즘이 있다.
 - 선택, 버블, 삽입, 퀵, 힙, 병합정렬..
 - 크게 O(pow(n,2)), O(nlogn) 두 개로 나눌 수 있다.
 - 선택, 버블, 삽입정렬 : O(pow(n,2));
 - 퀵, 힙, 병합정렬 : O(nlogn);
 - 일반적으로 문제를 풀 때는 nlogn 의 정렬방식을 사용한다.
 - 직접 구현하기보다는 STL의 sort를 사용하는 것이 좋다.
 - sort(begin, end) : [begin, end) 를 정렬하는 함수.
 - a[10]의 경우, sort(a, a+10);
 - vector<int> a의 경우, sort(a.begin(), a.end());

## 구조체, 클래스 정렬하기
 - pair 사용
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
 - 비교함수 만들기
   ```
   struct Point{
       int x, y;
   };
   bool cmp(const Point &u, const Point &v){
       if(u.x < v.x){
           return true;
       } else if(u.x==v.x){
           return u.y<v.y;
       }else{
           return true;
       }
   }
   //u가 v 앞에 오는 것이 맞으면 true
   //순서가 올바르지 않으면 false
   ```
   비교 함수를 만드는 경우에는 3번째 인자로 함수 이름을 넘겨줘야 한다.
   sort(a.begin(), a.end(), cmp);
 - 연산자 Overloading
   ```
   struct Point{
       int x, y;
       bool operator < (const Point &v) const{
           if(x < v.x){
               return true;
           }else if(x == v.x){
               return y < v.y;
           }else{
               return false;
           }
       }
   }
   ```

## Stable Sorting
 - 안정 정렬
  + 같은 것이 있는 경우에 정렬하기 전의 순서가 유지되는 정렬 알고리즘.
  + 정렬하기 전의 순서가 유지되지 않는 것은 Stable sorting 알고리즘이 아니다.
  + 시간 복잡도가 NlogN인 정렬 알고리즘 중에는 병합 정렬이 있다.
  + 관련 문제 : 나이순 정렬(10814번)
  + stable_sort(a.begin(), a.end(), cmp); 형태로 사용할 수 있다.

## K번째 수
 - nth_element
  + nth_element 알고리즘은 N번째 위치에 시퀀스가 정렬되었을 경우 놓이게 되는 원소가  
    놓여지도록 하며, 또한 N번째 원소의 왼쪽에 있는 모든 원소가 오른쪽에 위치한  
    원소들보다 모두 작거나 동등하도록 시퀀스를 파티션한다.
  ```
  nth_element(v.begin(), v.begin()+N, v.end());
  // N번째로 작은 원소를 V의 N번째 위치인, v.begin()+N에 놓는다.
  ```