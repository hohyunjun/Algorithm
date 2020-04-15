import java.util.*;
import java.io.*;

public class BOJ11404 {

    // 도시 간의 거리를 나타낼 배열
    static int d[][];

    static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        
        st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());

        d = new int[N+1][N+1];

        for(int i=0; i<N+1; i++){
            for(int j=0; j<N+1; j++){
                d[i][j] = i==j ? 0 : INF;
            }
        }

        while(M-- > 0){
            int u, v, c;

            st = new StringTokenizer(br.readLine());

            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            if(d[u][v] == INF){
                d[u][v] = c;
            }else if(d[u][v] > c){
                d[u][v] = c;
            }
        }

        // Floyd-Warshall

        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){

                    if(d[i][k] == INF || d[k][j] == INF) continue;

                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(d[i][j] == INF){
                    System.out.print("0 ");
                }else{
                    System.out.print(d[i][j] + " ");
                }
            }
            System.out.println();
        }


    }

}