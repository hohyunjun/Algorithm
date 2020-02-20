import java.util.ArrayList;
import java.util.Scanner;
import java.util.Comparator;
import java.util.ArrayDeque;

public class BOJ2606_DFS{

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

        DFS(1);

        int ans = 0;

        for(int i=1; i<=n; i++){
            if(V[i]) ans++;
        }

        System.out.println(ans - 1);

        sc.close();
    }

    public static void DFS(int start){
        // 방문되지 않은 정점일 경우에만
        if(!V[start]){
            V[start] = true;
            for(int i=0; i<A[start].size(); i++){
                DFS(A[start].get(i));
            }
        }

    }


}