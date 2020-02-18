import java.util.ArrayList;
import java.util.Scanner;

public class BOJ3052{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int arr[] = new int[10];

        boolean check[] = new boolean[1001];

        int cnt = 0;

        for(int i=0; i<10; i++){
            arr[i] = (sc.nextInt() % 42);
            check[arr[i]] = true;
        }

        for(int i=0; i<1001; i++){
            if(check[i]){
                cnt++;
            }
        }

        System.out.println(cnt);

    }
}