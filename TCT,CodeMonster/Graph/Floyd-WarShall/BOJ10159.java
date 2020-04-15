import java.util.*;
import java.io.*;

public class BOJ10159 {

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

        while(M-- >0){

            st = new StringTokenizer(br.readLine());

            int u, v;

            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            // d[u][v] == 1 --> u 가 v보다 무겁다
            // d[u][v] == -1 --> u가 v 보다 가볍다

            d[u][v] = 1;
            d[v][u] = -1;
        }

        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(d[i][j] == INF){
                        if(d[i][k] == 1 && d[k][j] == 1){ // i > k > j
                            d[i][j] = 1;
                        }
                        if(d[i][k] == -1 && d[k][j] == -1){ // i < k < j
                            d[i][j] = -1;
                        }
                    }
                }
            }
        }


        for(int i=1; i<=N; i++){
            int cnt = 0;
            for(int j=1; j<=N; j++){
                if(d[i][j] == INF) cnt++;
            }
            System.out.println(cnt);
        }



    }

}