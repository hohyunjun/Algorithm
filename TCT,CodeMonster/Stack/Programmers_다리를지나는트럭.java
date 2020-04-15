import java.util.*;

public class Programmers_다리를지나는트럭 {


class Solution {
    
    public class Truck{

        int weight, startTime;

        public Truck(int w, int t){
            this.weight = w;
            this.startTime = t;
        }
    }    
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
    
        // 다리에 처음 올라간 시간 
        // 다리에 트럭이 더 올라올 수 있는지 확인
        // 마지막 트럭이 다리에 올라가는 시간만 알면 됨
        
        ArrayDeque<Truck> b = new ArrayDeque<>();
        
        ArrayDeque<Integer> Waiting = new ArrayDeque<>();
        
        // Waiting Queue 에 트럭 무게 넣고
        for(int a : truck_weights){
            Waiting.offerLast(a);
        }
        
        // 일단 다리 큐에 트럭 하나 넣음
        answer++;
        int wob = Waiting.peek();
        b.offerLast(new Truck(Waiting.pollFirst(), answer)); // 1초에 들어가는 첫 트럭
        
        // 다리 위에 올릴지 말지 판별
        while(!Waiting.isEmpty()){
            answer++; // 현재 경과 시간
            
            // 먼저 현재 다리 가장 앞에 있는 트럭이 빠져나갈 수 있는지 체크
            if(answer == b.peek().startTime + bridge_length){
                Truck t = b.pollFirst();
                wob -= t.weight;
            }
            
            // 만일 현재 가장 앞에서 기다리는 트럭이 올라올 수 있다면
            if(wob + Waiting.peek() <= weight){
                wob += Waiting.peek();
                b.offerLast(new Truck(Waiting.pollFirst(), answer));
            }
        }
        
        // Waiting 하고 있는 트럭들을 다리에 다 올렸으므로, 다리에서 하나씩 빼면서 answer update
        while(!b.isEmpty()){
            Truck t = b.pollFirst();
            answer = t.startTime + bridge_length;
        }
        
        return answer;
    }
}


}