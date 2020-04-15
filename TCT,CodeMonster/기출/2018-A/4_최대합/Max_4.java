import java.util.*;

public class Max_4{

    public static int A[][];

    public static int n;

    public static int answer = -0x7FFFFFFF;

    // n*n 부분배열에서, (i, j)좌표로부터 시작하는 m*m 부분배열의 합 구하기
    public static int Plus(int a, int b, int m){
        int hap = 0;

        for(int i=a; i<a+m; i++){
            for(int j=b; j<b+m; j++){
                hap += A[i][j];
            }
        }

        return hap;
    }


    // n*n 부분배열의 최댓값 계산해서 answer에 update
    public static void Calculate(int m){

        for(int i=0; i<(n-m+1); i++){
            for(int j=0; j<(n-m+1); j++){
                answer = Math.max(answer, Plus(i,j,m));
            }
        }
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        A = new int[n][n];

        // Setting Array Input
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                A[i][j] = sc.nextInt();
            }
        }

        // Sub-Array Count
        int cnt = 0;
        for(int i=1; i<=n; i++){
            cnt += (n-i+1) * (n-i+1);
        }

        System.out.println("[" + n + "x" + n + "배열의 부분 배열 개수] : " + cnt + "개");

        // 부분 배열의 최대합 구하기

        for(int i=1; i<=n; i++){
            Calculate(i);
        }

        System.out.println("[" + n + "x" + n + "배열의 부분 배열 내의 최대 합] : " + answer);

        sc.close();        

    }
}