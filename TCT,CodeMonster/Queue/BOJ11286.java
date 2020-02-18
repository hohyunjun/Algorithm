import java.util.PriorityQueue;
import java.util.Comparator;
import java.lang.Math;
import java.util.Scanner;

public class BOJ11286{
    public static void main(String[] args){

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>( new Comparator<Integer>(){

            public int compare(Integer l, Integer r){
                // 더 큰수가 들어올 경우
                if(Math.abs(l) < Math.abs(r)){
                    return -1;
                }
                if(Math.abs(l) == Math.abs(r)){
                    if(l < r){
                        return -1;
                    }else if(l > r){
                        return 1;
                    }else{
                        return 0;
                    }
                }

                return 1;
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