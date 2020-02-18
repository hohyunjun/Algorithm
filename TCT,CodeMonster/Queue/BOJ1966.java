// 문제 풀이 방식
// 1. Pair 클래스를 만들어서, 몇번째 숫자인지를 큐에 주어진 숫자와 함께 저장
// 2. 그와 동시에, 큐에 주어진 숫자값을 따로 ArrayList 에 저장하여 내립차순으로 Sorting
// 3. 내림차순으로 Sorting한 ArrayList 의 첫번째 값과 계속 비교하면서 큐에서 값을 빼는 형태

import java.util.Deque;
import java.util.Scanner;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;

public class BOJ1966{

    private static class Pair{
        public int first;
        public int second;

        public Pair(int first, int second){
            this.first = first;
            this.second = second;
        }

    }


    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();

        while(tc-- != 0){
            int n, m;
            ArrayList<Integer> sarr = new ArrayList<>();

            n = sc.nextInt();
            m = sc.nextInt();

            Deque<Pair> dq = new ArrayDeque<Pair>();

            // 덱에 숫자를 넣는다.(dq 에는 구분자, priority에 중요도) 
            for(int i=0; i<n; i++){
                int inputNum = sc.nextInt();
                // index 값과 들어오는 숫자를 넣는다.
                dq.offerLast(new Pair(i, inputNum));
                // ArrayList 에 숫자를 넣는다.
                sarr.add(inputNum);
            }
            
            // Sorting 내림차순
            sarr.sort(Comparator.reverseOrder());

            int ans = 1;

           // 큐에서 m번째 위치의 숫자가 나올때 까지, 현재 Sorting 된 ArrayList를 탐색하면서 큐에서 숫자를 뺀다.

           while(true){

               // 현재 가장 큰 값이 큐의 가장 앞에 들어있는 값보다 큰경우, 큐의 가장 뒤에 재배치
               if(sarr.get(0) > dq.peekFirst().second){
                    Pair dqFirst = dq.pollFirst();
                    dq.offerLast(dqFirst);
               }else{ // 현재 가장 큰 값이 큐의 가장 앞에 들어있는 값과 같거나 작은 경우
                    if(dq.peekFirst().first == m){
                        System.out.println(ans);
                        break;
                    }else{
                        dq.pollFirst();
                        ans++;
                        sarr.remove(0);
                    }
               }
           }

        }

        sc.close();
    }


}