import java.util.*;
import java.io.*;

public class BOJ2458 {

    static int d[][];
    static int INF = Integer.MAX_VALUE;
    public static void main(String args[])throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        d = new int[N+1][N+1];

        for(int i=0; i<N+1; i++){
            for(int j=0; j<N+1; j++){
                d[i][j] = i==j ? 0 : INF;
            }
        }

        // d[i][j] = 1 이다 ---> i가 j보다 작다
        // d[i][j] = -1 이다 ---> i가 j보다 크다

        while(M-- > 0){
            st = new StringTokenizer(br.readLine());

            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            d[u][v] = 1;
            d[v][u] = -1;
        }

        for(int k=1; k<N+1; k++){
            for(int i=1; i<N+1; i++){
                for(int j=1; j<N+1; j++){
                    // i와 j 중에서 누가 키가 큰지 알수 없는경우
                    if(d[i][j] == INF){
                        if(d[i][k] == 1 && d[k][j] == 1){ // i < k < j
                            d[i][j] = 1;
                        }
                        if(d[i][k] == -1 && d[k][j] == -1){ // i > k > j
                            d[i][j] = -1;
                        }
                    }
                }
            }
        }

        int answer = 0;

        for(int i=1; i<N+1; i++){
            int cnt = 0;
            for(int j=1; j<N+1; j++){
                if(d[i][j] != INF) cnt++; 
            }
            if(cnt == N) answer++;
        }

        System.out.println(answer);

    }

}