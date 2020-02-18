import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Comparator;

public class BOJ1655{
    public static void main(String[] args){

        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(new Comparator<Integer>(){
            public int compare(Integer l, Integer r){
                if(l<r) return 1;
                if(l>r) return -1;
                return 0;
            }
        });

        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();

        while(tc-- != 0){
            
            int num = sc.nextInt();

            if(minHeap.size() == maxHeap.size()){
                maxHeap.offer(num);
            }else{
                minHeap.offer(num);
            }

            if(minHeap.isEmpty()){
                System.out.println(maxHeap.peek());
            }else{
                    
                if(maxHeap.peek() > minHeap.peek()){
                    int num1 = maxHeap.poll();
                    int num2 = minHeap.poll();

                    maxHeap.offer(num2);
                    minHeap.offer(num1);
                }

                System.out.println(maxHeap.peek());
            }

            // System.out.print("MaxHeap : ");
            // maxHeap.forEach((value) -> System.out.print(value + ", "));
            // System.out.println("");

            // System.out.print("MinHeap : ");
            // minHeap.forEach((value) -> System.out.print(value + ", "));
            // System.out.println("");
            
        }



        sc.close();


    }
}