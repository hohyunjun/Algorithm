import java.util.*;

public class BOJ1504 {

    public static class Pair{
        int v, w;

        public Pair(int v, int w){
            this.v = v;
            this.w = w;
        }
    }

    static ArrayList<Pair> A[];
    static int d[][];
    static int INF = Integer.MAX_VALUE;

    public static void Dijkstra(int start){

        d[start][start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> {
            int comparison = a.w - b.w;

            return comparison;
        });

        pq.offer(new Pair(start, 0));

        while(!pq.isEmpty()){

            int now = pq.peek().v;

            pq.poll();

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

        int n, e;

        n = sc.nextInt();
        e = sc.nextInt();

        // d 배열 초기화
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
        for(int i=0; i<e; i++){
            int u, v, w;
            u = sc.nextInt();
            v = sc.nextInt();
            w = sc.nextInt();

            A[u].add(new Pair(v, w));
            A[v].add(new Pair(u, w));
        }

        int mid1, mid2;

        mid1 = sc.nextInt();
        mid2 = sc.nextInt();

        Dijkstra(1);
        Dijkstra(mid1);
        Dijkstra(mid2);

        int min = Integer.MAX_VALUE;

        // 1부터 N까지 거쳐가야 하는 정점을 모두 지나서 갔을 때의 최소거리

        // 1 -> (mid1 or mid2) -> (mid1 or mid2) -> n
        // 가능한 경로 A) 1 -> mid1 -> mid2 -> i
        int possible1 = d[1][mid1];
        if(possible1 == INF){
            possible1 = INF;
        }else{
            if(d[mid1][mid2] == INF){
                possible1 = INF;
            }else{
                possible1 += d[mid1][mid2];
            }

            if(possible1 == INF){
                possible1 = INF;
            }else{
                if(d[mid2][n] == INF){
                    possible1 = INF;
                }else{
                    possible1 += d[mid2][n];
                }
            }
        }
        // B) 1 -> mid2 -> mid1 -> i
        // 가능한 경로 A) 1 -> mid1 -> mid2 -> i
        int possible2 = d[1][mid2];
        if(possible2 == INF){
            possible2 = INF;
        }else{
            if(d[mid2][mid1] == INF){
                possible2 = INF;
            }else{
                possible2 += d[mid2][mid1];
            }

            if(possible2 == INF){
                possible2 = INF;
            }else{
                if(d[mid1][n] == INF){
                    possible2 = INF;
                }else{
                    possible2 += d[mid1][n];
                }
            }
        }

        min = Math.min(possible1, possible2);
        
        if(min == INF) min = -1;


        System.out.println(min);

        sc.close();
    }
}