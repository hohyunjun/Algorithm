import java.util.*;
import java.io.*;

public class BOJ10282 {

    public static class Pair{
        int num, sec;

        public Pair(int num, int sec){
            this.num = num;
            this.sec = sec;
        }
    }

    // 컴퓨터 간의 의존 관계를 표현할 인접 리스트
    public static ArrayList<Pair> A[];

    // 해킹된 컴퓨터(시작점)로부터의 최단거리를 나타낼 배열
    public static int dist[];
    public static int INF = Integer.MAX_VALUE;

    public static void Dijkstra(int start){

        dist[start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> (a.sec - b.sec));

        pq.offer(new Pair(start, dist[start]));

        while(!pq.isEmpty()){

            int now = pq.poll().num;

            // 현재 컴퓨터를 의존하는 컴퓨터들 탐색
            for(int i=0; i<A[now].size(); i++){
                int next = A[now].get(i).num; // 현재 컴퓨터를 의존하는 컴퓨터
                int nextSec = A[now].get(i).sec; // 다음 컴퓨터로 전이되는 데 소요되는 시간
                if(dist[next] > dist[now] + nextSec){
                    dist[next] = dist[now] + nextSec;
                    pq.offer(new Pair(next, dist[next]));
                }
            }


        }

        return;

    }

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int tc;

        st = new StringTokenizer(br.readLine());

        tc = Integer.parseInt(st.nextToken());

        while(tc-- != 0){

            int n, d, c; // 컴퓨터, 의존성, 해킹당한 컴퓨터 수

            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            // 인접 리스트 초기화
            A = (ArrayList<Pair>[])new ArrayList[n+1];

            for(int i=0; i<n+1; i++){
                A[i] = new ArrayList<Pair>();
            }

            // dist 배열 초기화
            dist = new int[n+1];

            for(int i=0; i<n+1; i++){
                dist[i] = INF;
            }

            // 의존성 만큼 초기화
            for(int i=0; i<d; i++){
                int a, b, s;
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                s = Integer.parseInt(st.nextToken());

                // 컴퓨터 a가 b를 의존한다.(b 가 감염되면 a가 감염된다)
                A[b].add(new Pair(a, s)); // --> b가 감염되면 s초 후에 a도 감염된다.
            }

            Dijkstra(c); // 해킹된 컴퓨터 c로부터 감염되는데 걸리는 최단시간

            // 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되기까지 걸리는 시간 출력
            int cnt = 0 ;
            int maxSec = -1;

            for(int i=1; i<n+1; i++){
                if(dist[i] != INF){
                    cnt++;
                    maxSec = maxSec < dist[i] ? dist[i] : maxSec;
                }
            }

            System.out.println(cnt + " " + maxSec);


        }

    }

}