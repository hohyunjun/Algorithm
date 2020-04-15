import java.util.*;

public class BOJ1238 {

    public static class Pair{
        int v, w;

        public Pair(int v, int w){
            this.v = v;
            this.w = w;
        }
    }

    public static ArrayList<Pair> A[];
    public static int d[][];
    public static int INF = Integer.MAX_VALUE;

    public static void Dijkstra(int start){

        d[start][start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> {
            int comparison = a.w - b.w;

            return comparison;
        });

        pq.offer(new Pair(start, 0));

        while(!pq.isEmpty()){
            int now = pq.poll().v;

            for(int i=0; i<A[now].size(); i++){
                int next = A[now].get(i).v;
                int nextDistance = A[now].get(i).w;
                if(d[start][next] > d[start][now] + nextDistance){
                    d[start][next] = d[start][now] + nextDistance;
                    pq.offer(new Pair(next, d[start][next]));
                }
            }
        }

        return;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int n, m, x;

        n = sc.nextInt();
        m = sc.nextInt();
        x = sc.nextInt();

        // 정답 리스트 초기화
        d = new int[n+1][n+1];

        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                d[i][j] = INF;
            }
        }

        // 인접 리스트 초기화
        A = (ArrayList<Pair>[])new ArrayList[n+1];

        for(int i=0; i<n+1; i++){
            A[i] = new ArrayList<Pair>();
        }

        // 그래프 정보 insert
        for(int i=0; i<m; i++){
            int u, v, w;
            u = sc.nextInt();
            v = sc.nextInt();
            w = sc.nextInt();

            A[u].add(new Pair(v, w));
        }

        // 모든 정점에서 시작하여 다른 정점으로 가는 최소거리를 Dijkstra로 구함
        for(int i=1; i<n+1; i++){
            Dijkstra(i);
        }

        int answer = 0;

        for(int i=1; i<=n; i++){
            answer = answer < d[i][x] + d[x][i] ? d[i][x] + d[x][i] : answer;
        }

        System.out.println(answer);

        sc.close();
    }
}