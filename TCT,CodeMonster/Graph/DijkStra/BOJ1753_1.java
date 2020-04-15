import java.util.*;

public class BOJ1753_1 {

    public static class Pair{
        int vertex, cost;

        public Pair(int v, int c){
            this.vertex = v;
            this.cost = c;
        }
    }

    static int V, E, K;

    static ArrayList<Pair> A[];

    static int d[];

    static int INF = Integer.MAX_VALUE;

    public static void DijkStra(int start){

        boolean visited[] = new boolean[V+1];

        // 시작 정점 -> 시작 정점의 거리는 0
        d[start] = 0;

        // 가중치 기준 최소 힙 선언
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> {

            int comparison = a.cost - b.cost;

            return comparison == 0 ? a.vertex - b.vertex : comparison;

        });

        pq.offer(new Pair(start, d[start]));

        // pq가 빌 때까지 -> pq는 현재 이동가능한 최소거리의 정점들 중 가장 가까운 정점부터 차례로 방문한다.
        while(!pq.isEmpty()){

            int now = pq.peek().vertex;
            int distance = pq.peek().cost;

            pq.poll();

            if(visited[now]) continue;
            visited[now] = true; 

            // 현재 정점에 연결되어 있는 모든 정점을 돈다
            for(int i=0; i<A[now].size(); i++){
                int next = A[now].get(i).vertex; // 연결되어 있는 정점
                int nextCost = distance + A[now].get(i).cost; // 연결되어 있는 정점까지 가는데 필요한 비용
                if(d[next] > nextCost){ // start -> next 보다 start -> now -> next 가 비용이 더 낮은 경우
                    d[next] = nextCost;
                    pq.offer(new Pair(next, d[next]));
                }
            }

        }

        return;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        V = sc.nextInt();
        E = sc.nextInt();
        K = sc.nextInt();

        // 인접 리스트 초기화
        A = (ArrayList<Pair>[])new ArrayList[V+1];

        for(int i=0; i<V+1; i++){
            A[i] = new ArrayList<Pair>();
        }

        // 정답 배열 초기화
        d = new int[V+1];

        for(int i=0; i<V+1; i++){
            d[i] = INF;
        }

        // 인접 리스트 그래프 표현
        for(int i=0; i<E; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            A[u].add(new Pair(v, w));
        }

        DijkStra(K);

        for(int i=1; i<=V; i++){
            if(d[i] == Integer.MAX_VALUE){
                System.out.println("INF");
            }else{
                System.out.println(d[i]);
            }
        }


        sc.close();

    }
}