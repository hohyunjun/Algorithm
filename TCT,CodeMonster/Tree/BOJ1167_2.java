/*

트리에서 지름이란, 가장 먼 두 정점 사이의 거리 혹은 가장 먼 두 정점을 연결하는 경로를 의미한다. 선형 시간안에 트리에서 지름을 구하는 방법은 다음과 같다:

1. 트리에서 임의의 정점 x를 잡는다.

2. 정점 x에서 가장 먼 정점 y를 찾는다.

3. 정점 y에서 가장 먼 정점 z를 찾는다.

트리의 지름은 정점 y와 정점 z를 연결하는 경로다

출처: https://blog.myungwoo.kr/112 [PS 이야기]

*/


import java.util.*;



public class BOJ1167_2{

    // 그래프 표현할 인접 리스트 : Pair 형태로 저장(연결된 정점, 길이)
    public static ArrayList<Pair> A[];

    // 방문 및 dist 표현 배열 : dist[i] = 정점 1에서 정점i 까지의 거리
    public static int dist[];

    // (연결된 정점, 길이)
    public static class Pair{
        int connected, len;

        public Pair(int c, int l){
            this.connected = c;
            this.len = l;
        }
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        // 정점의 개수
        int v = sc.nextInt();

        // 정점의 개수에 맞게 초기화
        A = (ArrayList<Pair>[])new ArrayList[v+1]; // check
        dist = new int[v+1];

        // 각각의 ArrayList 초기화
        for(int i=0; i<=v; i++){
            A[i] = new ArrayList<Pair>();
        }

        // 정점에 연결된 값들 받아서 초기화
        for(int i=0; i<v; i++){
            int vval = sc.nextInt();
            while(true){
                int a = sc.nextInt();
                if(a == -1) break;
                int b = sc.nextInt();
                A[vval].add(new Pair(a,b));
            }
        }

        BFS(1);

        int answer = 0;

        for(int i=1; i<=v; i++){
            answer = Math.max(answer, dist[i]);
        }

        //System.out.println(answer);


        // 1에서 출발했을 때 가장 먼 정점은?
        int mostFarFrom1 = 0;
        for(int i=1; i<=v; i++){
            if(dist[i] == answer){
                mostFarFrom1 = i;
            }
        }

        //dist 초기화
        for(int i=0; i<=v; i++){
            dist[i] = 0;
        }

        // System.out.println(mostFarFrom1);    
        BFS(mostFarFrom1);

        
        for(int i=1; i<=v; i++){
            answer = Math.max(answer, dist[i]);
        }

        System.out.println(answer);
    }

    public static void BFS(int start){

        ArrayDeque<Pair> dq = new ArrayDeque<>();

        // Start
        dq.offerFirst(new Pair(start, 0));

        while(!dq.isEmpty()){
            Pair now = dq.pollFirst();

            for(int i=0; i<A[now.connected].size(); i++){
                Pair next = A[now.connected].get(i); // 다음 연결된 정점과 가중치
                if(dist[next.connected] == 0 && next.connected != start){
                    dist[next.connected] = dist[now.connected] + next.len;
                    //System.out.println("dist[" + next.connected + "] : " + dist[next.connected]);
                    dq.offerLast(next);
                }
            }
        }
    }



}