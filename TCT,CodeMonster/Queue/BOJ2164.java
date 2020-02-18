import java.util.ArrayList;
import java.util.Deque;
import java.util.Scanner;
import java.util.ArrayDeque;

public class BOJ2164{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Deque<Integer> dq = new ArrayDeque<>();

        for(int i=1; i<=n; i++){
            dq.offerLast(i);
        }

        while(dq.size() != 1){

            dq.pollFirst();

            int first = dq.pollFirst();

            dq.offerLast(first);

        }

        System.out.println(dq.peekFirst());


        sc.close();
    }
}