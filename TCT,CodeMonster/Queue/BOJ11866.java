import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Scanner;
import java.util.ArrayList;

public class BOJ11866{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        Deque<Integer> dq = new ArrayDeque<>();

        ArrayList<Integer> ans = new ArrayList<>();

        int n = sc.nextInt();
        int k = sc.nextInt();

        for(int i=1; i<=n; i++){
            dq.offerLast(i);
        }

        int cnt = 1;

        while(!dq.isEmpty()){

            if(cnt == k){
                ans.add(dq.pollFirst());
                cnt = 1;
            }else{
                int first = dq.pollFirst();
                dq.offerLast(first);
                cnt++;
            }
        }
        
        System.out.print("<");
        for(int i=0; i<n - 1; i++){
            System.out.print(ans.get(i) + ", ");
        }
        System.out.print(ans.get(n-1));
        System.out.print(">");



        sc.close();

    }
}