import java.util.*;

// BFS로 풀어보기

class Solution {
    

    // 정답 String 배열을 저장할 ArrayList
    public static ArrayList<String[]> ans = new ArrayList<>();

    // 정답 저장
    public static String now[];
    
    // 방문 체크
    public static boolean V[];
    
    public static void BFS(String departure, int cnt, String tickets[][]){
        
        ArrayDeque<String> dq = new ArrayDeque<>();
        
        dq.offerLast(departure);
        
        while(!dq.isEmpty()){
            String front = dq.pollFirst();
            for(int i=0; i<tickets.length; i++){
                if(tickets[i][0].equals(front) && V[i] == false){
                    V[i] = true;
                    dq.offerLast(tickets[i][1]);
                    now[cnt++] = tickets[i][1];
                    break;
                }
            }
        }
        
    }
    
    public String[] solution(String[][] tickets) {
        String[] answer = {};
        
        answer = new String[tickets.length + 1];
        
        V = new boolean[tickets.length];
        
        now = new String[tickets.length + 1];
        int cnt = 0;
        now[cnt++] = "ICN";
        
        // BFS 돌리려면, 알파벳 순서가 앞서는 경로를 return 하기 위해 tickets 배열을 먼저 정렬한 후 BFS돌린다
        Arrays.sort(tickets, (a, b) -> {
            int comparison = 0;
            
            comparison = a[0].compareTo(b[0]);
            
            return comparison == 0 ? a[1].compareTo(b[1]) : comparison;
        });
        
        BFS("ICN", cnt, tickets);
        
        answer = now;
        
        return answer;
    }
}