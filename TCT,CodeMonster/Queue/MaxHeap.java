import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Comparator;

public class MaxHeap{
    public static void main(String[] args){
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>(){

            public int compare(Integer l, Integer r){

                if (l<r) return 1;
                if (l>r) return -1;

                return 0;
            }

        });

        Scanner sc = new Scanner(System.in);

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