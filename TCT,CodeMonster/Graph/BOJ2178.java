import java.util.*;

public class BOJ2178{

    // 좌표 이동
    public static int dx[] = {-1,0,1,0};
    public static int dy[] = {0,1,0,-1};

    // 미로
    public static int maze[][] = new int[100][100];
    
    // Visited 배열. 각 좌표마다 최소 이동 횟수 기록
    public static int V[][] = new int[100][100];

    // Pair 클래스
    public static class Pair{
        public int x, y;
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    // 가로, 세로
    public static int n;
    public static int m;

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        sc.nextLine();

        for(int i=0; i<n; i++){
            String s = sc.nextLine();
            for(int j=0; j<m; j++){
                maze[i][j] = s.charAt(j) - '0';
            }
        }

        BFS(new Pair(0,0));

        System.out.println(V[n-1][m-1]);

        sc.close();

    }

    public static void BFS(Pair start){

        ArrayDeque<Pair> dq = new ArrayDeque<>();

        // Start!
        dq.offerLast(start);
        V[start.x][start.y] = 1;

        while(!dq.isEmpty()){
            Pair front = dq.pollFirst();
            for(int i=0; i<4; i++){
                int nx = front.x + dx[i];
                int ny = front.y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m ){
                    // 아직 방문되지 않은 곳이라면
                    if(maze[nx][ny] == 1 && V[nx][ny] == 0){
                        dq.offerLast(new Pair(nx, ny));
                        V[nx][ny] = V[front.x][front.y] + 1;}
                    // }else if(maze[nx][ny] == 1 && V[nx][ny] > V[front.x][front.y] + 1){
                    //     dq.offerLast(new Pair(nx,ny));
                    //     V[nx][ny] = V[front.x][front.y] + 1;
                    // }
                }
            }
        }


    }
}