import java.util.ArrayList;
import java.util.Scanner;
import java.util.ArrayDeque;
import java.util.Comparator;

public class BOJ2667{

    // 0~3까지 차례로 좌,상,우,하 
    public static int dx[] = {-1,0,1,0};
    public static int dy[] = {0,1,0,-1};

    // 2차원 배열 생성
    public static int A[][] = new int[25][25];
    public static int V[][] = new int[25][25];

    // 단지 수를 셀 변수
    public static int danji = 0;

    // 좌표를 저장할 Pair
    private static class Pair{
        public int x, y;

        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args){

        ArrayList<Integer> ans = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        // 집이 있는곳과 없는곳을 나타내는 배열을 입력받는다.
        for(int i=0; i<n; i++){
            String s = sc.nextLine();
            // System.out.println("String s : " + s);
            for(int j=0; j<n; j++){
                A[i][j] = s.charAt(j) - '0';
            }
        }

        // Algorithm : N * N 개의 정점을 모두 확인하면서,
        // A[i][j] == 1 이고, V[i][j] = 0 인 경우만 해당 정점으로부터 BFS 또는 DFS 를 돌린다.
        // cnt = 1 부터 시작해서 위의 조건에 해당하는 정점이 발견될 때마다 1씩 증가시켜주면서, V[i][j] 에 cnt 값을 채운다.
        // BFS를 수행할 때마다 몇 개의 집을 방문했는지 체크한다.

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(A[i][j] == 1 && V[i][j] == 0){
                    // System.out.println("===========Checking===========");
                    ans.add(BFS(new Pair(i, j), n));
                    // System.out.println("Start : " + i  + ", " + j);
                    // System.out.println("Danji : " + danji);
                }
            }
        }

        // 단지 수 sort
        ans.sort(Comparator.naturalOrder());

        System.out.println(danji);
        for(int i : ans){
            System.out.println(i);
        }

        sc.close();
    }

    public static int BFS(Pair start, int size){

        danji += 1;

        int danjiCnt = 0;

        ArrayDeque<Pair> dq = new ArrayDeque<>();

        // Queue 에 start Pair push
        dq.offerLast(start);
        V[start.x][start.y] = danji;
        danjiCnt++;

        while(!dq.isEmpty()){
            Pair front = dq.pollFirst();
            for(int i=0; i<4; i++){
                int nx = front.x + dx[i];
                int ny = front.y + dy[i];
                // nx, ny가 배열의 좌표 내 위치하는지 체크
                if(nx>=0 && ny>=0 && nx<size && ny<size){
                    // 해당 좌표에 집이 있고, 아직 방문되지 않았을 경우
                    if(A[nx][ny] == 1 && V[nx][ny] == 0){
                        dq.offerLast(new Pair(nx, ny));
                        V[nx][ny] = danji;
                        danjiCnt++;
                    }
                }
            }
        }

        return danjiCnt;

    }


}