import java.util.*;

/*
    BOJ1753
    다익스트라 구현

*/

public class BOJ1753_3 {

    public static class Pair{
        int v, w;

        public Pair(int v, int w){
            this.v = v;
            this.w = w;
        }
    }

    // 인접 리스트 형태로 표현할 ArrayList
    static ArrayList<Pair> A[];
    static int d[];
    static int INF = Integer.MAX_VALUE;
    static boolean visited[];

    public static void Dijkstra(int start){

        // 시작점 0으로 초기화
        d[start] = 0;

        // 현재 정점에서 가장 가까운 정점을 뽑아내기 위해 Heap 이용
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            int comparison = a.w - b.w;
            return comparison == 0 ? a.v - b.v : comparison;
        });

        // 현재 정점으로부터 시작
        pq.offer(new Pair(start, 0));

        while(!pq.isEmpty()){

            int now = pq.peek().v;

            pq.poll();

            if(visited[now]) continue;

            visited[now] = true;

            // 현재 정점과 연결된 모든 정점을 돌면서, 연결된 정점을 거쳐서 다른 정점으로 이동하는 경우의 비용이 더 적은 경우를 탐색
            for(int i=0; i<A[now].size(); i++){
                int next = A[now].get(i).v;
                int nextDistance = A[now].get(i).w; // 연결된 정점까지 이동하는 데 드는 비용
                if(d[next] > d[now] + nextDistance){ // 현재 저장된 next정점까지의 비용보다, 현재 정점에서 다음 정점까지 이동하는 비용이 더 작을 경우
                    d[next] = d[now] + nextDistance;
                    pq.offer(new Pair(next, d[next]));
                }
            }
        }

        return;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int v, e, k;

        v = sc.nextInt();
        e = sc.nextInt();
        k = sc.nextInt();

        // 방문 배열 초기화
        visited = new boolean[v+1];

        // 정답 배열 초기화(start 로부터 각 정점까지의 최소거리 저장 배열 d)
        d = new int[v+1];

        for(int i=0; i<v+1; i++){
            d[i] = INF;
        }

        // 인접 리스트 A 초기화

        A = (ArrayList<Pair>[])new ArrayList[v+1];

        for(int i=0; i<v+1; i++){
            A[i] = new ArrayList<Pair>();
        }

        // 연결 정보 insert

        for(int i=0; i<e; i++){
            int u, c, w;
            u = sc.nextInt();
            c = sc.nextInt();
            w = sc.nextInt();

            A[u].add(new Pair(c, w));
        }

        Dijkstra(k);

        for(int i=1; i<v+1; i++){
            if(d[i] == INF){
                System.out.println("INF");
            }else{
                System.out.println(d[i]);
            }
        }

        sc.close();
    }
}