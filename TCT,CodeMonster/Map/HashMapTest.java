import java.util.*;

public class HashMapTest{
    public static void main(String[] args){

        HashMap<String, Integer> m = new HashMap<>();

        // HashMap에 아무것도 넣지 않았을 경우
        System.out.println("HashMap의 크기 : " + m.size()); // 0

        // 아무것도 넣지 않았을 때의 초기값은?
        System.out.println("HashMap 초기값 : " + m.get("A")); // null

        // HashMap에 저장
        m.put("A", 1);
        m.put("B", 1);
        m.put("C", 1);

        // HashMap.size();
        System.out.println("HashMap의 크기 : " + m.size());

        // HashMap 의 keySet 을 활용한 순회
        // keySet 체크
        Set set = m.keySet();

        System.out.println(set); // [A, B, C]

        for(String s : m.keySet()){
            System.out.println(s + " : " + m.get(s));
        }

        // HashMap에 들어있는 값 업데이트
        if(m.containsKey("A")){
            m.put("A", m.get("A") + 1);
        }
        
        for(String s : m.keySet()){
            System.out.println(s + " : " + m.get(s));
        }

        // EntrySet 활용
        Set entry = m.entrySet();

        System.out.println(entry);

    }
}