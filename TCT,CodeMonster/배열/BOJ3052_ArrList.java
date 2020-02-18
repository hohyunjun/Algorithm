import java.util.ArrayList;
import java.util.Scanner;

public class BOJ3052_ArrList{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int cnt = 0;

        ArrayList<Integer> arr = new ArrayList<Integer>();

        boolean check[] = new boolean[1001];

        for(int i=0; i<10; i++){
            arr.add(sc.nextInt() % 42);
            check[arr.get(i)] = true;
        }

        for(int i=0; i<check.length; i++){
            if(check[i]){
                cnt++;
            }
        }

        System.out.println(cnt);

    }
}