import java.util.Scanner;

public class Hello{
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.print("INPUT N (2~9) : ");
        int n = sc.nextInt();

        int arr[][] = new int[n][n];

        // 왼쪽, 위 , 오른쪽, 아래
        int dx[] = {0,-1,0,1};
        int dy[] = {-1,0,1,0};

        int num = n*n;


        // n이 짝수일 때와 홀수일 때로 나누어서
        if(n%2==0){
            int dir = 2; // 짝수일 때는 최초 방향이 2(오른쪽)
            int x = (n-1);
            int y = 0;

            while(num != 0){
                
                // System.out.println("x : " + x + ", y : " + y + ", dir : " + dir);
                arr[x][y] = num--; // 일단 찍고
                // 다음 좌표 계산
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                // System.out.println("nx : " + nx + ", ny : " + ny);


                // 다음 좌표값이 valid 한지 체크
                if(nx < n && ny < n && nx >=0 && ny >=0 && arr[nx][ny] == 0){
                    //valid 하다면
                    x = nx;
                    y = ny;
                    
                }else{
                    // valid 하지 않다면
                    // 방향을 왼쪽으로 돌도록 바꿔주고(-1)
                    dir -= 1;
                    if(dir == -1) dir = 3;

                    x += dx[dir];
                    y += dy[dir];

                }

            }

        }else{
            int dir = 0; // 홀수일 때는 최초 방향이 0(왼쪽)
            int x = 0;
            int y = (n-1);

            while(num != 0){
                
                // System.out.println("x : " + x + ", y : " + y + ", dir : " + dir);
                arr[x][y] = num--; // 일단 찍고
                // 다음 좌표 계산
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                // System.out.println("nx : " + nx + ", ny : " + ny);


                // 다음 좌표값이 valid 한지 체크
                if(nx < n && ny < n && nx >=0 && ny >=0 && arr[nx][ny] == 0){
                    //valid 하다면
                    x = nx;
                    y = ny;
                    
                }else{
                    // valid 하지 않다면
                    // 방향을 왼쪽으로 돌도록 바꿔주고(-1)
                    dir -= 1;
                    if(dir == -1) dir = 3;

                    x += dx[dir];
                    y += dy[dir];

                }

            }

        }

        // 출력
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println();
        }



    }
}
