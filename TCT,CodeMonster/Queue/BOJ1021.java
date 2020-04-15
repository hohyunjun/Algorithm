import java.util.*;

public class BOJ1021{

    // 현재 큐의 상태를 나타낼 덱
    public static Deque<Integer> curDq = new ArrayDeque<>();

    // 최소 연산 횟수를 저장
    public static int answer = 0;

    public static void Simulation(int num){

        // target 숫자를 뽑아내기 위해,
        // 1. 2번연산 수행 시 몇 번의 연산이 필요한지.
        // 2. 3번연산 수행 시 몇 번의 연산이 필요한지.
        // 3. 1,2 번의 최솟값을 answer에 더하고, 최솟값에 해당하는 연산 결과를 curDq에 반영

        // 현재 front 가 그냥 찾는 숫자일 경우 시뮬레이션 필요 없음.
        if(curDq.peekFirst() == num){
            curDq.pollFirst();
            return;
        }

        // 2 번 연산 수행
        Deque<Integer> two = new ArrayDeque<>(curDq);
        int cnt2 = 0;

        while(two.peekFirst() != num){
            cnt2++;
            two.offerLast(two.pollFirst());
        }

        // 3번 연산 수행
        Deque<Integer> three = new ArrayDeque<>(curDq);
        int cnt3 = 0;

        while(three.peekFirst() != num){
            cnt3++;
            three.offerFirst(three.pollLast());
        }
        
        if(cnt2 < cnt3){
            answer += cnt2;
            curDq.clear();
            two.pollFirst();
            while(!two.isEmpty()){
                curDq.offerLast(two.pollFirst());
            }
            return;
        }else{
            answer += cnt3;
            curDq.clear();
            three.pollFirst();
            while(!three.isEmpty()){
                curDq.offerLast(three.pollFirst());
            }
            return;
        }


    }

    public static void main(String[] args){

        // 2번연산, 3번연산 구현해서 시뮬레이션 최솟값 반환

        Scanner sc = new Scanner(System.in);

        int n, m;

        n = sc.nextInt();
        m = sc.nextInt();

        // 뽑아내야 할 숫자들 저장
        ArrayList<Integer> target = new ArrayList<>();

        // 찾아야 할 target 숫자들 저장
        while(m-- != 0){
            target.add(sc.nextInt());
        }

        // 덱 초기화
        for(int i=1; i<=n; i++){
            curDq.offer(i);
        }

        for(int a : target){
            Simulation(a);
        }

        System.out.println(answer);


        sc.close();
    }
}