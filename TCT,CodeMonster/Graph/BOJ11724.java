import java.util.*;

public class BOJ11724{

    // 그래프를 표현할 인접리스트
    public static ArrayList<ArrayList<Integer>> A = new ArrayList<>();
    // 방문을 표기할 배열
    public static boolean V[];

    public static void BFS(int start){

        ArrayDeque<Integer> dq = new ArrayDeque<>();

        dq.offerLast(start);
        V[start] = true;

        while(!dq.isEmpty()){
            int front = dq.pollFirst();
            for(int i=0; i<A.get(front).size(); i++){
                if(!V[A.get(front).get(i)]){
                    V[A.get(front).get(i)] = true;
                    dq.offerLast(A.get(front).get(i));
                }
            }
        }

    }


    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n, m;

        n = sc.nextInt();
        m = sc.nextInt();

        // 정점 개수만큼 인접리스트 추가
        for(int i=0; i<n; i++){
            A.add(new ArrayList<Integer>());
        }

        // V초기화
        V = new boolean[n];

        // 간선 받는다
        for(int i=0; i<m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();

            A.get(u-1).add(v-1);
            A.get(v-1).add(u-1);

        }

        // 모든 정점에 대해서, V[i] = false 일 경우 BFS를 돌린다.

        int cc = 0;

        for(int i=0; i<n; i++){
            if(!V[i]){
                cc++;
                BFS(i);
            }
        }

        System.out.println(cc);

        sc.close();

    }
}