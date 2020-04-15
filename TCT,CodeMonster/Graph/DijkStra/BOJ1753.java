import java.util.*;

public class BOJ1753{

    // (정점, 가중치)
    public static class Pair{
        int v, w;

        public Pair(int v, int w){
            this.v = v;
            this.w = w;
        }
    }

    public static ArrayList<Pair> A[];

    // public static boolean visited[];
    public static int d[];
    public static int INF = 999;

    /* Dijkstra
      1. 출발 노드를 설정한다.
      2. 출발 노드를 기준으로 각 노드의 최소비용을 저장한다.
      3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택한다.
      4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신한다.
      5. 위 과정에서 3~4를 반복한다. 
    */

    public static void Dijkstra(int start){

        // 출발 노드 기준으로 각 노드의 최소비용 저장
        d[start] = 0;
        // visited[start] = true;

        // for(int i=0; i<A[start].size(); i++){
        //     Pair p = A[start].get(i);
        //     d[p.v] = p.w;
        // }

        // 가중치 기준 오름차순(가중치가 낮은게 앞으로), 가중치가 같을 경우 정점 번호 순으로 오름차순
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> {
            int comparison = -1;
            comparison = (a.w - b.w);
            return comparison == 0 ? a.v - b.v : comparison;
        });

        pq.offer(new Pair(start, 0));

        // Priority Queue TEST

        // pq.offer(new Pair(2, 4));
        // pq.offer(new Pair(3, 5));
        // pq.offer(new Pair(4, 1));
        // pq.offer(new Pair(4, 2));

        // while(!pq.isEmpty()){
        //     System.out.println(pq.peek().v + ", " + pq.peek().w);
        //     pq.poll();
        // }

        while(!pq.isEmpty()){
            int current = pq.peek().v;
            int distance = pq.peek().w;
            pq.poll();

            // 최단 거리가 아닌 경우 스킵
            if(d[current] < distance) continue;
            for(int i=0; i<A[current].size(); i++){
                // 선택된 노드의 인접 노드
                int next = A[current].get(i).v;
                // 선택된 노드를 인접 노드로 거쳐서 가는 비용
                int nextDistance = distance + A[current].get(i).w;
                // 기존 최소비용보다 더 저렴하다면 교체
                if(nextDistance < d[next]){
                    d[next] = nextDistance;
                    pq.offer(new Pair(next, nextDistance));
                }
            }


        }

        return;

    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();
        int E = sc.nextInt();
        int start = sc.nextInt();

        // visited = new boolean[V+1];
        d = new int[V+1];

        // 초기화
        for(int i=1; i<V+1; i++){
            d[i] = INF;
        }

        // 정점 개수만큼 인접리스트 생성
        A = (ArrayList<Pair>[])new ArrayList[V + 1];

        // 인접 리스트 초기화
        for(int i=0; i<V + 1; i++){
            A[i] = new ArrayList<Pair>();
        }

        // 인접 리스트 표현
        for(int i=0; i<E; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            A[u].add(new Pair(v,w));
            //A[v].add(new Pair(u,w));
        }

        // for(int i=1; i<V+1; i++){
        //     System.out.print(i + "와 연결된 정점 : ");
        //     for(Pair p : A[i]){
        //         System.out.print( "(" + p.v + ", " + p.w + ") , ");
        //     }
        //     System.out.println();
        // }

        Dijkstra(start);        

        for(int i=1; i<=V; i++){
            if(d[i] >= 999){
                System.out.println("INF");
            }else{
                System.out.println(d[i]);
            }
        }


        sc.close();
    }


}