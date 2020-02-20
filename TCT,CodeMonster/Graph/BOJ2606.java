import java.util.ArrayList;
import java.util.Scanner;
import java.util.Comparator;
import java.util.ArrayDeque;

public class BOJ2606{

    public static ArrayList<Integer> A[];
    public static boolean V[];

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        // ArrayList 및 Visited 배열 선언
        A = (ArrayList<Integer>[]) new ArrayList[n+1];
        V = new boolean[n+1];

        // 그래프 표현
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

        BFS(1);

        int ans = 0;

        for(int i=1; i<=n; i++){
            if(V[i]) ans++;
        }

        System.out.println(ans - 1);

        sc.close();
    }

    public static void BFS(int start){

        ArrayDeque<Integer> dq = new ArrayDeque<>();

        // Start!
        V[start] = true;

        for(int i=0; i<A[start].size(); i++){
            V[A[start].get(i)] = true;
            dq.offerLast(A[start].get(i));
        }

        while(!dq.isEmpty()){
            int front = dq.pollFirst();
            for(int i=0; i<A[front].size(); i++){
                if(!V[A[front].get(i)]){
                    V[A[front].get(i)] = true;
                    dq.offerLast(A[front].get(i));
                }
            }
        }

    }


}