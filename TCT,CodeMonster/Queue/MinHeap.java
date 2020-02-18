import java.util.PriorityQueue;
import java.util.Scanner;

public class MinHeap{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

        int tc = sc.nextInt();

        while(tc-- != 0){
            int num = sc.nextInt();

            if(num == 0){
                if(pq.isEmpty()){
                    System.out.println(0);
                }else{
                    System.out.println(pq.poll());
                }
            }else{
                pq.offer(num);
            }
        }



        sc.close();

    }
}