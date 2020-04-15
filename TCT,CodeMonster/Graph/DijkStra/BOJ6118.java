import java.util.*;
import java.io.*;


public class BOJ6118{

    // 그래프 표현 인접리스트
    public static ArrayList<Integer> A[];

    // 정점 1로부터의 최단거리
    public static int d[];
    public static int INF = Integer.MAX_VALUE;

    public static class Pair{
        int v, cost;

        public Pair(int v, int cost){
            this.v = v;
            this.cost = cost;
        }
    }

    // start 배열부터 모든 정점까지의 최단거리 확인
    public static void Dijkstra(int start){

        d[start] = 0;

        // cost 기준 내림차순 정렬 힙
        // PriorityQueue<Pair> pq = new PriorityQueue<>( (a,b) -> (a.cost - b.cost) * -1);

        // pq.offer(new Pair(start, d[start]));

        // while(!pq.isEmpty()){

        //     Pair front = pq.poll();

        //     // 연결된 모든 정점을 돌면서
        //     for(int i=0; i<A[front.v].size(); i++){
        //         int next = A[front.v].get(i); // 연결된 다음 정점
        //         if(d[next] > d[front.v] + 1){ // 현재 저장된 거리보다, 하나의 정점을 거쳐서 가는 거리가 더 최단거리일 경우
        //             d[next] = d[front.v] + 1;
        //             pq.offer(new Pair(next, d[next]));
        //         }
        //     }
        // }

        ArrayDeque<Integer> dq = new ArrayDeque<>();

        dq.offerLast(start);

        while(!dq.isEmpty()){
            int front = dq.pollFirst();

            for(int i=0; i<A[front].size(); i++){
                int next = A[front].get(i);
                if(d[next] > d[front] + 1){
                    d[next] = d[front] + 1;
                    dq.offerLast(next);
                }
            }
        }

        return;

    }


    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int N, M; // 정점의 개수, 간선의 개수

        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 인접 리스트 초기화
        A = (ArrayList<Integer>[])new ArrayList[N+1];

        for(int i=0; i<N+1; i++){
            A[i] = new ArrayList<Integer>();
        }

        // 최단거리 배열 초기화
        d = new int[N+1];
        for(int i=0; i<N+1; i++){
            d[i] = INF;
        }

        // 인접 리스트 초기화
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            A[a].add(b);
            A[b].add(a);
        }

        // 1로부터 모든 정점까지의 최단거리 체크
        Dijkstra(1);

        int maxDist = 0;

        for(int i=1; i<N+1; i++){
            maxDist = maxDist < d[i] ? d[i] : maxDist;
        }

        int answer = 0;

        for(int i=1; i<N+1; i++){
            if(d[i] == maxDist){
                answer = i;
                break;
            }
        }

        int cnt = 0;

        for(int i=1; i<N+1; i++){
            if(d[i] == maxDist){
                cnt++;
            }
        }

        System.out.println(answer + " " + maxDist + " " + cnt);

    }
}