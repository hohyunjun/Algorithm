
## 트리의 표현
 - 트리는 그래프이기 때문에, 그래프의 표현과 같은 방식으로 저장할 수 있다.
   + 정점이 V일때 간선은 항상 V-1개이므로 인접 행렬은 비효율적이고, 인접 리스트를 사용하는 것이 효율적
 - 트리의 모든 노드는 부모를 하나 또는 0개만 가지기 때문에 부모만 저장하는 방식으로 저장 가능하다.  
   + 장점 : 어떤 노드의 부모를 찾기가 쉽다. O(1)
   + 단점 : 어떤 노드의 자식을 찾기가 어렵다. O(V)
 - 이진트리의 경우에는 배열로 표현가능하다.
   + 부모의 노드가 x인 경우에 자식의 노드는 2x, 2x+1로 나타낼 수 있다.(root Node를 1부터 저장할 경우)
   + **root Node를 0부터 바로 저장할 경우, 자식의 노드는 2x+1, 2x+2로 나타낼 수 있다. 이 경우, 자식 노드의 부모 노드는 (me-1)/2 로 구할 수 있다.**
   + 하지만, 한쪽 방향으로 치우친 트리의 경우에 공간복잡도가 매우 비효율적이다.
   + 양쪽 방향으로 고루 분포된 이진트리를 표현하는 경우에 좋다.

## 트리의 탐색
 - *트리의 가장 큰 특징 : 사이클이 없다.*
 - *따라서, 임의의 두 정점 사이에 경로는 1개이다.*
 - 그러므로, DFS / BFS 알고리즘이 곧 최단거리 알고리즘과 같다.
 - 일반적으로 문제본문에 트리라는 말이 명시적으로 주어지지 않는다. 어떻게 파악할 수 있을까?
 - 도시가 N개이고, 도로가 N-1개이다 -> 아직까지 트리는 아니다.
 - 도시가 N개이고, 도로가 N-1개이고, 임의의 두 도시 사이에 경로가 항상 존재한다(연결 그래프이다), 방향이 없다 -> 트리이다.
 - BOJ 11725 트리의 부모찾기 문제
  + 트리에서 부모일 때의 속성을 찾고, 해당 속성을 적용해 BFS를 돌리면 된다.
  + parent[next] = now;


## 인접 리스트를 활용한 트리의 표현(자주 까먹는 것)
 ```java
    import java.util.*;

    public class BOJ11725{

        // 트리 구조를 표현할 ArrayList
        public static ArrayList<Integer> A[];

        // 트리의 부모 노드 및 Visited 를 표현
        // public static int parent[];

        // public static void main(String[] args){

        //     Scanner sc = new Scanner(System.in);

        //     int n = sc.nextInt();

            // 자꾸 까먹는 부분 - ArrayList 초기화 !!
            parent = new int[n+1];
            A = (ArrayList<Integer>[])new ArrayList[n+1];

            // Tree 표현하기
            for(int i=0; i<=n; i++){
                A[i] = new ArrayList<Integer>();
            }

            // for(int i=0; i<n-1; i++){
            //     int u = sc.nextInt();
            //     int w = sc.nextInt();
            //     A[u].add(w);
            //     A[w].add(u);
            // }

            // BFS(1);

            // for(int i=2; i<=n; i++){
            //     System.out.println(parent[i]);
            // }

        }

        public static void BFS(int start){

            ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
            
            // root Node
            parent[start] = -1;
            dq.offerLast(start);

            while(!dq.isEmpty()){
                int front = dq.pollFirst();
                // 연결된 모든 자식노드 순회
                for(int i=0; i<A[front].size(); i++){
                    // 아직 방문되지 않았다면
                    if(parent[A[front].get(i)] == 0){
                        parent[A[front].get(i)] = front;
                        dq.offerLast(A[front].get(i));
                    }
                }
            }


        }


    }   
 ```

## 트리의 지름

 - 트리에서 지름이란, 가장 먼 두 정점 사이의 거리 혹은 가장 먼 두 정점을 연결하는 경로를 의미한다. 선형 시간안에 트리에서 지름을 구하는 방법은 다음과 같다:

   1. 트리에서 임의의 정점 x를 잡는다.

   2. 정점 x에서 가장 먼 정점 y를 찾는다.

   3. 정점 y에서 가장 먼 정점 z를 찾는다.

   트리의 지름은 정점 y와 정점 z를 연결하는 경로다

   출처: https://blog.myungwoo.kr/112 [PS 이야기]