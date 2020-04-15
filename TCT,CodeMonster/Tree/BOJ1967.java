import java.util.*;

public class BOJ1967{

    // 트리를 표현할 ArrayList
    public static ArrayList<Pair> A[];

    // 정점간의 거리를 나타낼 배열
    public static int dist[];

    // 정점과 가중치 정보를 나타낼 클래스
    public static class Pair{
        int connected, weight;

        public Pair(int c, int w){
            this.connected = c;
            this.weight = w;
        }
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // ArrayList 초기화
        A = (ArrayList<Pair>[])new ArrayList[n+1];

        for(int i=0; i<=n; i++){
            A[i] = new ArrayList<Pair>();
        }

        // dist 초기화
        dist = new int[n+1];

        // Tree 초기화
        for(int i=1; i<n; i++){
            int v, c, w;
            v = sc.nextInt();
            c = sc.nextInt();
            w = sc.nextInt();

            A[v].add(new Pair(c,w));
            A[c].add(new Pair(v,w));
        }

        // root 에서 가장 먼 정점을 찾아야 한다.
        BFS(1);

        int answer = 0;

        for(int i=0; i<=n; i++){
            answer = Math.max(answer, dist[i]);
        }

        // root 에서 가장 먼 정점으로부터 가장 먼 정점까지의 거리 = 트리의 지름
        int mostFarV = 0;
        for(int i=0; i<=n; i++){
            if(dist[i] == answer) mostFarV = i;
            dist[i] = 0;
        }

        // System.out.println(mostFarV);

        BFS(mostFarV);

        for(int i=0; i<=n; i++){
            answer = Math.max(answer, dist[i]);
        }

        System.out.println(answer);

    }

    public static void BFS(int start){

        ArrayDeque<Pair> dq = new ArrayDeque<>();

        dq.offerLast(new Pair(start, 0));

        while(!dq.isEmpty()){
            Pair now = dq.pollFirst();
            // System.out.println("now : " + now.connected + ", " + now.weight);
            for(int i=0; i<A[now.connected].size(); i++){
                Pair next = A[now.connected].get(i);
                if(dist[next.connected] == 0 && next.connected != start){
                    dist[next.connected] = dist[now.connected] + next.weight;
                    // System.out.println("dist[" + next.connected + "] : " + dist[next.connected]);
                    dq.offerLast(next);
                }
            }
        }

    }



}