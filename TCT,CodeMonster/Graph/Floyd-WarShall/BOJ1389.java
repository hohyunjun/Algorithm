import java.util.*;

import java.io.*;

/*
    케빈 베이컨의 6단계 법칙
     - 모든 정점에서 모든 정점까지의 최소거리를 구한다.
*/

public class BOJ1389 {

    // 인접 리스트
    public static ArrayList<Integer> A[];

    // 정답 행렬
    public static int d[][];

    public static int INF = Integer.MAX_VALUE;

    public static class Pair{
        int v, w;

        public Pair(int v, int w){
            this.v = v;
            this.w = w;
        }
    }

    // 시작점으로부터 다른 정점까지의 최소거리
    public static void Dijkstra(int start){

        d[start][start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> {
            int comparison = a.w - b.w;

            return comparison;
        });

        pq.offer(new Pair(start, 0));

        while(!pq.isEmpty()){

            int now = pq.poll().v;

            // now와 연결된 모든 정점을 돈다
            for(int i=0; i<A[now].size(); i++){

                int next = A[now].get(i);

                // 아직 방문되지 않은 정점인 경우
                if(d[start][next] == INF){
                    d[start][next] = d[start][now] + 1;
                    pq.offer(new Pair(next, d[start][next]));
                }else if(d[start][next] > d[start][now] + 1){
                    d[start][next] = d[start][now] + 1;
                    pq.offer(new Pair(next, d[start][next]));
                }
            }
        }

    }


    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());

        // N은 정점의 수, M은 간선의 수
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        A = (ArrayList<Integer>[])new ArrayList[N+1];

        for(int i=0; i<N+1; i++){
            A[i] = new ArrayList<Integer>();
        }

        d = new int[N+1][N+1];

        for(int i=0; i<N+1; i++){
            for(int j=0; j<N+1; j++){
                d[i][j] = INF;
            }
        }

        while(M-- > 0){
            int u, v;

            st = new StringTokenizer(br.readLine());

            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            A[u].add(v);
            A[v].add(u);
        }

        for(int i=1; i<=N; i++){
            Dijkstra(i);
        }

        int min = INF;
        int answer = 0;

        for(int i=1; i<=N; i++){
            int sum = 0;
            for(int j=1; j<=N; j++){
                sum+=d[i][j];
            }
            if(sum < min){
                min = sum;
                answer = i;
            }
        }

        System.out.println(answer);

    }
}