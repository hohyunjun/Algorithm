import java.util.*;

// DFS 돌려서 경로 반환한 후 해당 String[] 배열을 ArrayList 에 담아, 정렬

class Solution {
    
    // 여행 경로들을 저장할 ArrayList
    public static ArrayList<String[]> ans = new ArrayList<>();

    // 티켓 사용 여부를 체크할 배열
    public static boolean V[];

    // 모든 가능한 경로를 순회할 DFS
    public static void DFS(String departure, String now[], int cnt, String tickets[][]){

        // 모든 도시를 방문한 경우, 경로를 저장
        if(cnt == now.length){
            String save[] = new String[cnt];
            for(int i=0; i<(cnt); i++){
                save[i] = now[i];
            }
            ans.add(save);
            return;
        }

        for(int i=0; i<tickets.length; i++){
            if(tickets[i][0].equals(departure) && V[i] == false){
                now[cnt++] = tickets[i][1];
                V[i] = true;
                DFS(tickets[i][1], now, cnt, tickets);
                cnt--;
                V[i] = false;
            }
        }

        return;
    }
    
    
    public String[] solution(String[][] tickets) {
        String[] answer = {};
        
        answer = new String[tickets.length + 1];
        
        // 여행 경로를 저장할 배열
        String now[] = new String[tickets.length + 1];
        int cnt = 0;
        now[cnt++] = "ICN";
        
        V = new boolean[tickets.length];
        
        DFS("ICN", now, cnt, tickets);
        
        Collections.sort(ans, (a, b) -> {
            
            int comparison = 0;
            
            for(int i=0; i<a.length; i++){
                if(!a[i].equals(b[i])){
                    comparison = a[i].compareTo(b[i]);
                    break;
                }
            }
            
            return comparison;
        });
        
        
        answer = ans.get(0);
        
        return answer;
    }
}