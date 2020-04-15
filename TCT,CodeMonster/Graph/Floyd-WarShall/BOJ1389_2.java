import java.util.*;

import java.io.*;

/*
    케빈 베이컨의 6단계 법칙
     - 모든 정점에서 모든 정점까지의 최소거리를 구한다.
*/

public class BOJ1389_2 {

    // 정답 행렬
    public static int d[][];

    public static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());

        // N은 정점의 수, M은 간선의 수
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        d = new int[N+1][N+1];

        for(int i=0; i<N+1; i++){
            for(int j=0; j<N+1; j++){
                d[i][j] = i == j ? 0 : INF;
            }
        }

        while(M-- > 0){
            int u, v;

            st = new StringTokenizer(br.readLine());

            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            
            d[u][v] = 1;
            d[v][u] = 1;
        }

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

        int min = INF;
        int answer = 0;

        for(int i=1; i<=N; i++){
            int sum = 0;
            for(int j=1; j<=N; j++){
                sum+=d[i][j];
            }
            if(sum < min){
                min = sum;
                answer = i;
            }
        }

        System.out.println(answer);

    }
}