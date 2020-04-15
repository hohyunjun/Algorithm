import java.util.*;

public class BOJ7576{

    // 가로, 세로
    public static int m, n;

    public static int dx[] = {-1,0,1,0};
    public static int dy[] = {0,1,0,-1};

    public static int A[][];
    public static int V[][];

    public static class Pair{
        int x, y;
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void BFS(){
        // dq 선언
        ArrayDeque<Pair> dq = new ArrayDeque<>();

        // 먼저, 익어있는 토마토의 좌표를 모두 dq에 넣는다
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(A[i][j] == 1){
                    dq.offerLast(new Pair(j,i));
                }
            }
        }

        // 큐에서 하나씩 빼면서 체크
        while(!dq.isEmpty()){
            Pair front = dq.pollFirst();
            for(int i=0; i<4; i++){
                int nx = front.x + dx[i];
                int ny = front.y + dy[i];
                // 좌표 범위 내라면
                if(nx >= 0 && ny >= 0 && nx < m && ny <n){
                    // 아직 익지 않은 토마토라면
                    if(A[ny][nx] == 0){
                        A[ny][nx] = A[front.y][front.x] + 1;
                        dq.offerLast(new Pair(nx, ny));
                    }
                }
            }
        }


    }

    public static void main(String[] args){

        int answer;

        Scanner sc = new Scanner(System.in);

        m = sc.nextInt();
        n = sc.nextInt();

        A = new int[n][m];
        V = new int[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                A[i][j] = sc.nextInt();
            }
        }

        int days = 0;

        // 익은 토마토의 좌표로부터 시작해서 BFS 돌린다.
        BFS();

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         System.out.print(A[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        // BFS 완료 후 전체에서 max 값
        int maxDay = -1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxDay = Math.max(maxDay, A[i][j] - 1);
            }
        }        

        answer = maxDay;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(A[i][j] == 0){
                    answer = -1;
                    break;
                }    
            }
        }        

        System.out.println(answer);


        sc.close();

    }
}