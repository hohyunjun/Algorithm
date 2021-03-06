## 그래프 기초
 - 그래프틑 자료구조의 일종이다.
 - 정점(Node, Vertex)과 간선(Edge)으로 이루어진다.
 - G = (V,E)로 나타낸다.
 - 경로 : 정점 A에서 B로 가는 경로
 - 사이클 : 정점 A에서 A로 돌아오는 경로
 - 유향 그래프, 무향 그래프
 - 간선이 여러개일 수도 있다. 
 - 간선의 양 끝점이 같을 수도 있다(Loop)
 - 차수 : 정점과 연결된 간선의 개수

## 그래프의 표현
 - 인접 행렬
  + 정점의 개수를 V라고 했을 때, V*V 크기의 이차원 배열을 이용한다.
  + A[i][j] = 1 (i->j 간선이 있을 경우 1, 없을 경우 0)
  + 가중치가 있을 경우, 1 대신에 가중치를 표현한다.
  + 공간 복잡도는 O(V^2) (V는 정점의 개수)  

 - 인접 리스트
  + 링크드 리스트를 이용해서 구현한다.
  + A[i] = i와 연결된 정점을 링크드 리스트로 표현
  + 주로 vector를 이용해서 구현한다.
  + **vector 이용 시, vector<int> a(10)은 1차원 배열, vector<int> a[10]은 2차원 배열**
  + 공간 복잡도는 O(E)  (E는 간선의 개수)
  + 인접 리스트를 사용해 가중치를 표현할 경우는 아래와 같이 표현한다.
  ```cpp
  #include <cstdio>
  #include <vector>
  using namespace std;
  vector<pair<int, int>> a[10];
  int main(){
      int n, m;
      scanf("%d %d", &n, &m);
      for(int i=0; i<m; i++){
          int u, v, w;
          scanf("%d %d %d", &u, &v, &w);
          a[u].push_back(make_pair(v,w));
          a[v].push_back(make_pair(u,w));
      }
  }
  ```  
 
 - 간선 리스트
  + STL의 사용이 필요없는 방식. 공간복잡도도 O(E)
  + 배열을 이용해서 구현한다.
  + 간선을 모두 저장하고 있다.
  + E라는 배열에 간선을 모두 저장한다.
  + 각 간선의 앞 정점을 기준으로 정렬하여 개수를 센다.
  + cnt 배열을 만들고 각 간선의 앞 정점을 기준으로 개수를 센다.
  + cnt 배열에서 각 개수를 누적시켜 더한다.
  + i번 정점과 연결된 간선은 E 배열에서 cnt[i-1] 부터 cnt[i]-1 까지이다.

 *대부분의 경우 인접 리스트를 사용한다. 특수한 경우만 간선 리스트를 사용한다. 인접 행렬의 경우 공간을 너무 비효율적으로 사용하므로 실제로는 잘 사용하지 않는다. 불필요한 간선을 저장하므로 인접 리스트에 비해 시간 복잡도도 높다.*

## 그래프의 탐색
- 목적 : 모든 정점을 1번씩 방문한다.
- DFS, BFS
- DFS : 깊이 우선 탐색(Depth First Search)
- BFS : 너비 우선 탐색(Breadth First Search)
- DFS는 최대한 깊숙히 많이, BFS는 최대한 넓게 가는 것
- DFS는 스택 사용, BFS는 큐를 사용
- BFS는 그래프 알고리즘에서도 제일 중요한 알고리즘.  
  모든 가중치가 1인 경우 최단거리를 찾는 알고리즘.

## DFS
 - 스택을 이용해서 갈 수 있는 만큼 최대한 많이 가고 갈 수 없으면 이전 정점으로 돌아간다.  
 - 모든 정점을 한 번씩 방문하는 것을 확인하기 위해 check[i] 배열을 사용한다.  
 - check[i] 배열의 값이 0인 경우 아직 방문하지 않음. 1인경우 방문한 배열 
 - 스택이 모두 비어있게 될 경우 탐색을 종료한다.
 - 재귀함수 자체가 스택을 통해 구현되어 있으므로 재귀함수를 통해 쉽게 구현 가능하다.  
 ```cpp
 // 인접행렬을 사용한 DFS
 // dfs(x) : x를 방문했다.
 void dfs(int x){
     check[x] = true;
     printf("%d ", x);
     for(int i=1; i<=n; i++){
         if(a[x][i] == 1 && check[i] == false){ // 간선이 있고, 방문하지 않았을 경우
             dfs(i);
         }
     }
 }
 ```
 - 인접행렬을 사용할 경우, DFS의 시간, 공간 복잡도는 O(V^2)이다.
 ```cpp
 // 인접 리스트를 사용한 DFS
 void dfs(int x){
     check[x] = true;
     printf("%d ", x);
     for(int i=0; i<a[x].size(); i++){
         int y = a[x][i];
         if(check[y]==false){
             dfs(y);
         }
     }
 }
 // a[x]는 x와 연결된 정점. a[x].size()는 x와 연결된 정점의 개수
 ```
 - 인접 리스트를 사용할 경우, 재귀함수는 V번 호출되고, 모든 간선을 한번씩  
   접근하므로 DFS의 시간복잡도는 O(V+E)이다. 공간복잡도도 O(V+E)

## BFS
 - 큐를 이용해서 지금 위치에서 갈 수 있는 것을 모두 큐에 넣는 방식
 - 큐에 넣을 때 방문했다고 체크해야 한다.
 ```cpp
 // 인접행렬을 사용한 BFS
 queue<int> q;
 check[1] = true; q.push(1); // 큐에 넣을 때 체크
 while(!q.empty()){
     int x = q.front(); q.pop();
     printf("%d ", x);
     for(int i=1; i<=n; i++){
         if(a[x][i] == 1 && check[i] == false){
             check[i] = true;
             q.push(i);
         }
     }
 }
 ```
 - 인접 행렬을 사용했을 경우 시간, 공간 복잡도는 O(V^2)
 ```cpp
 // 인접 리스트를 활용한 BFS
 queue<int> q;
 check[1] = true; q.push(1);
 while(!q.empty()){
     int x = q.front(); q.pop();
     printf("%d ", x);
     for(int i=0; i<a[x].size(); i++){
         int y = a[x][i];
         if(check[y] == false){
             check[y] = true;
             q.push(y);
         }
     }
 }
 ```
 - 인접 리스트를 사용했을 경우 시간, 공간 복잡도는 O(V+E)
 *BFS, DFS 모두 인접 행렬보다 리스트를 사용하는 것이 더 빠르다.*

## 연결 요소(Connected Components)
 - BOJ 11724
 - 그래프가 연결되지 않은 경우
 - 나누어진 각각의 그래프를 연결 요소라고한다.
 - 연결 요소에 속한 모든 정점을 연결하는 경로가 있어야 하며, 다른 연결 요소에 속한 정점과 연결하는 경로가 있으면 안 된다.
 - 연결 요소를 구하는 것은 DFS나 BFS 탐색을 이용하여 구할 수 있다.

## 이분 그래프(Bipartite Graph)
 - BOJ 1707
 - 그래프를 A와 B로 크게 나눌 수 있으면 이분 그래프라고 한다.
 - A에 포함된 정점끼리 연결된 간선이 없음
 - B에 포함된 정점끼리 연결된 간선이 없음
 - 모든 간선의 한 끝 점은 A에, 다른 끝 점은 B에
 - DFS 또는 BFS 탐색을 이용하고, Check 배열의 의미를 확장시켜 색칠하는 방식으로 문제를 풀 수 있다.
 **모든 그래프의 정점이 연결되어 있지 않을 수 있음을 생각하자!!**
 **반례: 6 3 4 5 5 6 1 3 OUTPUT : YES**

## 순열 사이클
 - BOJ 10451
 - 그래프에서 일반적인 사이클을 찾는 것이 아니라, 항상 어떤 정점이 다른 정점 하나로만 연결되는 경우의 사이클을 찾는 것
 - 연결 요소문제와 똑같은 방식으로 풀 수 있음.
 - 하지만, 인접 행렬과 인접 리스트를 사용하지 않고도 풀 수 있음. 모든 정점이 간선 하나만 가지기 때문이다.
 - A[i]에 연결된 정점 하나만 넣어서 효율적으로 풀 수 있음.

## 반복수열
 - BOJ 2331
 - 순열 사이클 문제와 유사한 방식으로 풀 수 있는 문제.
 - 배열의 범위를 정해주는 것에서 생길 수 있는 런타임 에러에 주의한다.

## 텀 프로젝트
 - BOJ 9466
 - 진짜 안풀려서 3일을 고생한 문제. 개빡친다.
 - 차근차근 하나씩 따져보면서 풀어보니 풀린 문제. BFS 든 DFS든 모두 사용 가능하다.
 - 계속해서 틀렸던 경우의 반례는 1 3 2 3 2 와 같은 경우.
 - cycle이 자기 자신이 아닌 다른 정점으로 갈때, 무조건 해당 step에 속한 정점을 다 더해줬었는데,
   각 step별로 정점의 방문순서를 기록해서 cycle이 어떤 크기로 형성되는지를 파악해야 했었다.
 - 꼭 다시한번 풀어보면 좋을 문제.

## 플러드 필(Flood Fill)
 - 어떤 위치와 연결된 모든 위치를 찾는 알고리즘
 - 단지번호 붙이기
   + BOJ 2667 : 좌표로 이루어진 정점을 처리하는 방법. dx, dy를 활용하여 상하좌우 벡터를 처리하는 방법에 대해 배웠다.
 - 섬의 개수
   + BOJ 4963
   + 단지번호 붙이기에서 대각선 방향까지 합쳐진 문제. dx, dy 범위를 늘려주면 쉽게 풀 수 있다.
 - 미로 탐색
   + BOJ 2178
   + (1,1)에서 (N,M)으로 가는 가장 빠른 길을 구하는 문제.
   + DFS로는 문제를 풀 수 없다. BFS탐색을 사용해야 한다.
   + BFS의 가장 큰 특징 : 그래프의 모든 가중치가 1일 때, 최단거리 알고리즘을 BFS를 이용해 구할 수 있다.
   + dist[nx][ny] = dist[x][y] + 1 이용.
 - 토마토
   + BOJ 7576
   + 미로 찾기와 똑같은 문제.
 - 다리만들기
   + BOJ 2146
   + 단지번호 붙이기 + 토마토 문제.
   + 섬의 그룹번호를 붙이고 각 그룹별로 다른 섬까지의 최소 거리 구하기
