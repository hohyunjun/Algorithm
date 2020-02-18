import java.util.PriorityQueue;
import java.util.Comparator;

public class PriorityQueueTest{
    public static void main(String[] args){

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Default : 작은 수 -> 큰 수 오름차순으로 출력됨.
        pq.offer(4);
        pq.offer(3);
        pq.offer(2);
        pq.offer(1);

        while(!pq.isEmpty()){
            System.out.println(pq.poll());
        }

        // MaxHeap 으로 표현하기 : Comparator 사용
        PriorityQueue<Integer> mpq = new PriorityQueue<Integer>(new Comparator<Integer>(){
            public int compare(Integer l, Integer r){
                if( l < r ) return 1; // 앞에 오는 게 음수 반환, 지금은 내림차순 할 거니까 뒤에꺼가 더 큰 경우 양수를 줘서 순서를 바꿈.
                if( l == r ) return 0;
                return -1;
            }
        });

        mpq.offer(1);
        mpq.offer(2);
        mpq.offer(3);
        mpq.offer(4);

        // while(!mpq.isEmpty()){
        //     System.out.println(mpq.poll());
        // }

        
        System.out.print("MaxHeap : ");
        mpq.forEach((value) -> System.out.print(value + ", "));
        System.out.println("");


    }
}