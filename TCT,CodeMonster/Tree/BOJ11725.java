import java.util.*;

public class BOJ11725{

    // 트리 구조를 표현할 ArrayList
    public static ArrayList<Integer> A[];

    // 트리의 부모 노드 및 Visited 를 표현
    public static int parent[];

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // 자꾸 까먹는 부분 - ArrayList 초기화 !!
        parent = new int[n+1];
        A = (ArrayList<Integer>[])new ArrayList[n+1];

        // Tree 표현하기
        for(int i=0; i<=n; i++){
            A[i] = new ArrayList<Integer>();
        }

        for(int i=0; i<n-1; i++){
            int u = sc.nextInt();
            int w = sc.nextInt();
            A[u].add(w);
            A[w].add(u);
        }

        BFS(1);

        for(int i=2; i<=n; i++){
            System.out.println(parent[i]);
        }

    }

    public static void BFS(int start){

        ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
        
        // root Node
        parent[start] = -1;
        dq.offerLast(start);

        while(!dq.isEmpty()){
            int front = dq.pollFirst();
            // 연결된 모든 자식노드 순회
            for(int i=0; i<A[front].size(); i++){
                // 아직 방문되지 않았다면
                if(parent[A[front].get(i)] == 0){
                    parent[A[front].get(i)] = front;
                    dq.offerLast(A[front].get(i));
                }
            }
        }


    }


}