import java.util.*;

public class BOJ1012{

    // 배추를 심을 밭
    public static int A[][] = new int[50][50];
    public static int V[][] = new int[50][50];

    // 가로, 세로길이
    public static int garo; 
    public static int sero;

    // 필요한 배추벌레 수
    public static int required = 0;

    // 좌표이동
    public static int dx[] = {-1,0,1,0};
    public static int dy[] = {0,1,0,-1};


    // Pair 클래스
    public static class Pair{
        public int x, y;

        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while(t-- != 0){

            garo = sc.nextInt();
            sero = sc.nextInt();
            int k = sc.nextInt();

            // 배추 심어진 위치 표시
            while(k-- != 0){
                int x = sc.nextInt();
                int y = sc.nextInt();
                A[x][y] = 1;
            }

            // 모든 배추밭을 돌면서 배추가 있고, 방문되지 않은 경우에만 BFS 수행
            for(int i=0; i<garo; i++){
                for(int j=0; j<sero; j++){
                    if(A[i][j] == 1 && V[i][j] == 0){
                        BFS(new Pair(i,j));
                    }
                }
            }

            System.out.println(required);

            // 다음 케이스를 돌리기 위해 초기화
            initialize();
        }

        sc.close();
    }

    public static void BFS(Pair start){

        required++;

        ArrayDeque<Pair> dq = new ArrayDeque<>();

        // 시작
        dq.offerLast(start);
        V[start.x][start.y] = 1;

        while(!dq.isEmpty()){
            Pair front = dq.pollFirst();

            for(int i=0; i<4; i++){
                int nx = front.x + dx[i];
                int ny = front.y + dy[i];
                if(nx>=0 && ny>=0 && nx<garo && ny<sero){
                    if(A[nx][ny] == 1 && V[nx][ny] == 0){
                        dq.offerLast(new Pair(nx,ny));
                        V[nx][ny] = 1;
                    }
                }
            }

        }

    }


    public static void initialize(){
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                A[i][j] = V[i][j] = 0;
            }
        }

        garo = sero = required = 0;
    }


}