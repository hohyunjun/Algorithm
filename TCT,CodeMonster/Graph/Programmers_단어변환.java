import java.util.*;


class Solution {
    
    // 함수에서 불러쓸 수 있도록 전역변수
    public static String wordsList[];
    public static String targetWord;
    public static int minAns = 0x7FFFFFFF;
    public static boolean V[];
    
    // 단어가 한 개의 알파벳만 차이나는지 체크
    public boolean check(String a, String b){
        int diff = 0;
        for(int i=0; i<a.length(); i++){
            if(a.charAt(i) != b.charAt(i)){
                diff++;
                if(diff >= 2) return false;
            }
        }
        return true;
    }
    
    
    // 현재 단어, 단계를 가지고 있음
    public void dfs(String now, int cnt){
        
        if(now.equals(targetWord)){
            minAns = Math.min(minAns, cnt);
            return;
        }else if(cnt > wordsList.length){
            minAns = Math.min(minAns, cnt);
            return;
        }
        
        for(int i=0; i<wordsList.length; i++){
            if(check(wordsList[i],now) && V[i] == false){
                V[i] = true;
                dfs(wordsList[i], cnt+1);
                V[i] = false;
            }
        }
    }
        
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        // 전역변수화
        targetWord = target;
        wordsList = new String[words.length];
        V = new boolean[words.length];
        
        for(int i=0; i<words.length; i++){
            wordsList[i] = words[i];
        }
        
        boolean exists = false;
        
        for(String s : words){
            if(s.equals(target)){
                exists = true;
                break;
            }
        }
        
        if(!exists){
            answer = 0;
        }else{
            dfs(begin , 0);
            answer = minAns;
        } 
        
        return answer;
    }
}