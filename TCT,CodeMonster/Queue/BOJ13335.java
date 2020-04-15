import java.util.*;
import java.io.*;

public class BOJ13335 {

    public static class Truck{
        int start, weight;

        public Truck(int start, int weight){
            this.start = start;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());

        Deque<Integer> waiting = new ArrayDeque<>();

        st = new StringTokenizer(br.readLine());

        // 큐에 기다리는 트럭들의 무게를 넣음.
        for(int i=0; i<n; i++){
            waiting.offerLast(Integer.parseInt(st.nextToken()));
        }

        int answer = 0; // 모든 트럭이 다 건넜을 때 필요한 최단시간

        int bw = 0; // 다리 위에 올라가 있는 트럭들의 무게의 합

        Deque<Truck> bridge = new ArrayDeque<>();

        // 첫번째 트럭을 다리위에 올린다.
        answer++;
        bridge.offerLast(new Truck(answer, waiting.pollFirst()));
        bw += bridge.peek().weight;
        
        // 모든 자동차가 다 지나갈때까지 
        while(!waiting.isEmpty() || !bridge.isEmpty()){
            answer++;

            // 다리위에 있는 트럭 중 현재 시간에 이미 지나간 경우는 다리에서 빼준다.
            if(!bridge.isEmpty()){
                Truck front = bridge.peekFirst();
                if(answer - front.start == w){
                    bw -= front.weight;
                    bridge.pollFirst();
                }
            }

            // 다음 자동차가 올라올 수 있는 경우
            if(!waiting.isEmpty()){
                if(bw + waiting.peekFirst() <= l){
                    bridge.offerLast(new Truck(answer, waiting.peekFirst()));
                    bw += waiting.pollFirst();
                }
            }

        }

        System.out.println(answer);

    }

}