import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1753_2 {
    
    static int stoi(String S){ return Integer.parseInt(S);}
    static final int INF = 1000000000;
    static int N, M, K;
    static ArrayList<Pair> adList[];
    static int dist[];
    static boolean visited[];
    static PriorityQueue<Pair> pq;



    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());
        K = stoi(br.readLine());

        // adList = (ArrayList<Pair>[])new ArrayList[N+1];

        // for(int i=0; i<=N; i++){
        //     adList[i] = new ArrayList<>();
        // }

        adList = new ArrayList<>();

        adList.add(new<Pair> ArrayList());
        for(int i=1; i<=N; i++){
            adList.add(new<Pair> ArrayList());
        }

        // dist[] INF 로 초기화
        dist = new int[N+1];
        Arrays.fill(dist, INF);

        while( M-- > 0){
            st = new StringTokenizer(br.readLine());
            int u = stoi(st.nextToken());
            int v = stoi(st.nextToken());
            int cost = stoi(st.nextToken());

            // adList[u].add(new Pair(v,w));
            adList.get(u).add(new Pair(v,cost));
        }

        dijkstra(K);

        printAnswer();

    }
    
    private static void dijkstra(int start){
        // pq = new PriorityQueue<>((a,b) -> {
        //     int comparison = a.w - b.w;

        //     return comparison;
        // });
        pq = new PriorityQueue<>();
        visited = new boolean[N+1];

        dist[start] = 0;

        pq.add(new Pair(start, 0));

        while(!pq.isEmpty()){
            Pair current = pq.poll();
            
            // 재방문 여부 확인
            if(visited[current.v]) continue;
            visited[current.v] = true;

            // 연결된 정점들 확인
            for(Pair next : adList.get(current.v)){
                // 최소 거리 비용이 갱신되는 경우만 queue에 넣는다.
                if(dist[next.v] > dist[current.v] + next.w){
                    //최소 거리 비용 갱신
                    dist[next.v] = dist[current.v] + next.w;
                    pq.add(new Pair(next.v, dist[next.v]));
                }
            }
        }
    }

    public static void printAnswer() {
        StringBuilder sb = new StringBuilder();
        for (int i=1; i <= N; i++) {
        	sb.append((dist[i] >= INF ? "INF" : dist[i]));
        	sb.append("\n");
        }
        System.out.println(sb.toString());
    }
}

class Pair implements Comparable<Pair>{
    int v, w;
    public Pair(int v, int w){
        this.v = v;
        this.w = w;
    }

    @Override
    public int compareTo(Pair target){
        return this.w - target.w;
    }
}