import java.util.Scanner;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.ArrayDeque;

public class BOJ1260{
    
    // 그래프를 표현할 ArrayList
    // A[i] = i와 연결된 정점들의 리스트
    public static ArrayList<Integer> A[];
    public static boolean visited[];
    public static boolean visited2[];

    @SuppressWarnings("unchecked")
    public static void main(String[] args){

        int n, m, v;

        Scanner sc = new Scanner(System.in);

        // 정점의 개수
        n = sc.nextInt();

        // 간선의 개수
        m = sc.nextInt();

        // 시작점
        v = sc.nextInt();

        // 그래프 표현 : 정점의 개수만큼 ArrayList 생성 및 visited 생성
        A = (ArrayList<Integer>[]) new ArrayList[n+1];
        visited = new boolean[n+1];
        visited2 = new boolean[n+1];

        for(int i=0; i<=n; i++){
            A[i] = new ArrayList<Integer>();
        }

        for(int i=0; i<m; i++){
            int u, w;
            u = sc.nextInt();
            w = sc.nextInt();

            A[u].add(w);
            A[w].add(u);
        }

        // 그래프 Check
        // for(int i=1; i<=n; i++){
        //     System.out.print("A[" + i + "] : ");
        //     for(int j=0; j<A[i].size(); j++){
        //         System.out.print(" " + A[i].get(j) + " ");
        //     }
        //     System.out.println();
        // }

        // 방문가능한 정점이 여러개인 경우 정점 번호가 작은것부터 방문하므로, Sorting 진행
        for(int i=1; i<=n; i++){
            A[i].sort(Comparator.naturalOrder());
        }

        
        // System.out.println("----- DFS Visited -----");
        DFS(v);

        System.out.println();

        BFS(v);

        sc.close();
    }

    public static void DFS(int start){
        // 아직 방문되지 않은 정점일 경우 
        if(!visited2[start]){
            visited2[start] = true;

            System.out.print(start + " ");
            for(int i=0; i<A[start].size(); i++){
                DFS(A[start].get(i));
            }
        }
    }


    public static void BFS(int start){

        ArrayDeque<Integer> dq = new ArrayDeque<>();

        // System.out.println("----- BFS Visited Check -----");

        // for(int i=0; i<visited.length; i++){
        //     System.out.print(visited[i] + " ");
        // }

        // Start!
        visited[start] = true;
        
        // System.out.println();
        // System.out.println("----- BFS Visit -----");
        System.out.print(start + " ");

        // 시작 정점과 연결된 모든 정점을 큐에 넣는다. 
        for(int i=0; i<A[start].size(); i++){
            visited[A[start].get(i)] = true;
            dq.offerLast(A[start].get(i));
        }

        // 큐가 빌 때까지 수행
        while(!dq.isEmpty()){
            int front = dq.pollFirst();
            System.out.print(front + " ");
            for(int i=0; i<A[front].size(); i++){
                // 연결된 정점 중 아직 방문되지 않은 정점이 있다면
                if(!visited[A[front].get(i)]){
                    visited[A[front].get(i)] = true;
                    dq.offerLast(A[front].get(i));
                }
            }
        }
    }

}