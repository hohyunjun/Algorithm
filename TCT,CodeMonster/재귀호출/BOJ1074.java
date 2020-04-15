import java.util.*;

public class BOJ1074{

    public static int arr[][];

    public static int cnt = 1;

    // 순회하면서 숫자 채우기
    public static void Traverse(int cury, int curx){

        

    }


    public static void main(String[] args){

        int n, r, c;

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();

        int arrSize = 1;

        while(n-- != 0){
            arrSize *= 2;
        }

        // 2차원 배열 초기화
        arr = new int[arrSize][arrSize];





        sc.close();
    }
}