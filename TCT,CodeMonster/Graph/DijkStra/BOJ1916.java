import java.util.*;

/*
    Dijkstra 활용문제
*/

public class BOJ1916 {

    public static class Pair{
        int v, w;

        public Pair(int v, int w){
            this.v = v;
            this.w = w;
        }
    }

    static ArrayList<Pair> A[];
    static int d[];
    static int INF = Integer.MAX_VALUE;

    public static void Dijkstra(int start){

        // 시작점 표시
        d[start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> {
            int comparison = a.w - b.w;

            return comparison == 0 ? a.v - b.v : comparison;
        });

        pq.offer(new Pair(start, 0));

        while(!pq.isEmpty()){

            // 현재 정점
            int now = pq.peek().v;

            pq.poll();

            // 현재 정점과 연결된 모든 정점을 돈다
            for(int i=0; i<A[now].size(); i++){
                int next = A[now].get(i).v;
                int nextDistance = A[now].get(i).w;
                if(d[next] > d[now] + nextDistance){
                    d[next] = d[now] + nextDistance;
                    pq.offer(new Pair(next, d[next]));
                }
            }

        }

        return;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int n, m;

        n = sc.nextInt();
        m = sc.nextInt();

        // d 배열 초기화
        d = new int[n+1];

        for(int i=0; i<n+1; i++){
            d[i] = INF;
        }

        // A 배열 초기화
        A = (ArrayList<Pair>[])new ArrayList[n+1];

        for(int i=0; i<n+1; i++){
            A[i] = new ArrayList<Pair>();
        }

        // 연결 정보 insert
        for(int i=0; i<m; i++){
            int u, v, w;
            u = sc.nextInt();
            v = sc.nextInt();
            w = sc.nextInt();

            A[u].add(new Pair(v,w));
        }

        int start, end;

        start = sc.nextInt();
        end = sc.nextInt();

        Dijkstra(start);

        System.out.println(d[end]);

        sc.close();

    }

}