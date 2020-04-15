import java.util.*;

public class BOJ4458 {

    static int A[][] = new int[126][126];
    static int answer[][] = new int[126][126]; // (i,j) 까지의 최소거리
    static int dx[] = {-1,0,1,0};
    static int dy[] = {0,-1,0,1};
    static int INF = Integer.MAX_VALUE;

    public static class Pair{
        int x, y;
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void BFS(int x, int y, int n){

        answer[x][y] = A[x][y];

        Deque<Pair> dq = new ArrayDeque<>();

        dq.offerLast(new Pair(x, y));

        while(!dq.isEmpty()){

            Pair front = dq.pollFirst();

            int curx = front.x;
            int cury = front.y;

            for(int i=0; i<4; i++){
                int nextx = curx + dx[i];
                int nexty = cury + dy[i];

                if(nextx >= 0 && nexty >=0 && nextx < n && nexty <n){
                    if(answer[nextx][nexty] == INF){
                        answer[nextx][nexty] = answer[curx][cury] + A[nextx][nexty];
                        dq.offerLast(new Pair(nextx, nexty));
                    }else{
                        if(answer[nextx][nexty] > answer[curx][cury] + A[nextx][nexty]){
                            answer[nextx][nexty] = answer[curx][cury] + A[nextx][nexty];
                            dq.offerLast(new Pair(nextx, nexty));
                        }
                    }
                }
            }
        }

        return;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        int cnt = 0;

        while(true){
            cnt++;
            int n = sc.nextInt();

            if(n == 0) break;

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    answer[i][j] = INF;
                }
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    A[i][j] = sc.nextInt();
                }
            }

            BFS(0,0, n);

            System.out.println("Problem " + cnt + ": " + answer[n-1][n-1]);
        }
        sc.close();

    }

}