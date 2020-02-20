import java.util.*;

public class BOJ1167{

    // (연결된 정점, 가중치) 저장할 클래스
    public static class Pair{
        public int vertex;
        public int weight;

        public Pair(int vertex, int weight){
            this.vertex = vertex;
            this.weight = weight;
        }

    }

    // 트리를 저장할 ArrayList와 각 정점까지의 거리를 저장할 dist 배열
    public static ArrayList<Pair> A[];
    public static int dist[][];
    public static boolean visited[][];

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int v = sc.nextInt();

        // 초기화
        A = (ArrayList<Pair>[])new ArrayList<Pair>[v+1];
        dist = new int[v+1][v+1];
        visited = new boolean[v+1][v+1];

        for(int i=0; i<=v; i++){
            A[i] = new ArrayList<Pair>();
        }

        for(int i=0; i<v; i++){
            int n = sc.nextInt();
            int m, w;
            while(true){
                m = sc.nextInt();
                if(m == -1) break;
                w = sc.nextInt();
                A[i].add(new Pair(m,w));
            }
        }

        for(int i=1; i<=v; i++){
            BFS(i);
        }

    }

    public static void BFS(int start){

        ArrayDeque<Pair> dq = new ArrayDeque<Pair>();

        // Start!
        visited[start][start] = true;
        dq.offerLast(new Pair(start, 0));
        int d = dist[start][start];

        while(!dq.isEmpty()){
            Pair now = dq.pollFirst();

            // 현재 정점과 연결된 정점들로 이동
            for(int i=0; i<A[now.left].size(); i++){
                Pair next = A[now.left].get(i);
                // 아직 현재 정점에서 방문하지 않은 정점이라면
                if(!visited[now.left][next.left]){
                    dist[now.left][next.left] += d + next.right;
                    d += dist[start][next.left];
                    visited[now.left][next.left] = true;
                    visited[next.left][now.left] = true;

                }
            }
        }



    }


}