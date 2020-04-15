import java.util.*;

public class HashMapSort{
    public static void main(String[] args){

        HashMap<String, Integer> m = new HashMap<>();

        m.put("A", 100);
        m.put("B", 2);
        m.put("C", 55);
        m.put("D", 1);
        m.put("E", 0);
        m.put("F", 100);

        // value 기준 내림차순 정렬, value 가 같으면 key 오름차순 정렬
        // (K,V) 형태의 Set으로 이루어진 List 생성 : List 넣고 Sort 진행
        List<Map.Entry<String, Integer>> list = new LinkedList<>(m.entrySet());

        System.out.println(list);

        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>(){
            public int compare(Map.Entry<String, Integer> l, Map.Entry<String, Integer> r){
                // 내림차순 정렬 : 비교 이렇게 하는거 괜찮은듯! 
                int comparison = (l.getValue() - r.getValue()) * -1;
                // 삼항연산자 : 조건문 ? 참일때 : 거짓일때
                return comparison == 0 ? l.getKey().compareTo(r.getKey()) : comparison;
            }
        });

        //순서 유지를 위해 LinkedHashMap 사용
        Map<String, Integer> sortedMap = new LinkedHashMap<>();

        // 정렬된 list 를 돌면서 값을 넣어준다.
        for(Map.Entry<String, Integer> es : list){
            sortedMap.put(es.getKey(), es.getValue());
        }

        System.out.println(sortedMap);

        // 익혀야 할 개념
        /*
        1. Collcections.sort, Comparator 사용
        2. 삼항연산자
        3. Map.Entry
        4. Iterator
        
        */

    }
}