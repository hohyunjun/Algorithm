import java.util.*;

public class HashMapSort3{
    public static void main(String[] args){
        HashMap<String, Integer> m = new HashMap<>();

        m.put("A", 0);
        m.put("B", 150);
        m.put("C", -10);
        m.put("D", -100);
        m.put("E", 100);
        m.put("F", 0);

        // 위 Map에 대해, value 값을 기준으로 내림차순 정렬하시오.(단, value 값이 같다면 key 값을 기준으로 내림차순 정렬하시오)

        // 정렬을 위해 Map내부의 값들을 Set으로 바꾸어 리스트에 저장
        List<Map.Entry<String, Integer>> list = new LinkedList<>(m.entrySet());

        // 정렬 수행
        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>(){

            public int compare(Map.Entry<String, Integer> l, Map.Entry<String, Integer> r){
                int comparison = (l.getValue() - r.getValue()) * -1;

                return comparison == 0 ? l.getKey().compareTo(r.getKey()) * -1 : comparison;
            }
        });

        // 정렬된 List 내부 EntrySet 값들을 새로운 Map에 정렬된 형태로 저장
        LinkedHashMap<String, Integer> sortedMap = new LinkedHashMap<>();

        for(Map.Entry<String, Integer> es : list){
            sortedMap.put(es.getKey(), es.getValue());
        }

        System.out.println(sortedMap);

    }
}