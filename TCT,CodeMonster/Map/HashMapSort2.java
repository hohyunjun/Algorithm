import java.util.*;

public class HashMapSort2{
    public static void main(String[] args){

        HashMap<String, Integer> m = new HashMap<>();

        m.put("A", 100);
        m.put("C", 500);
        m.put("B", 700);
        m.put("D", 200);
        m.put("E", 0);

        // value 기준 내림차순 정렬, value 가 같으면 key 오름차순 정렬
        List<Map.Entry<String, Integer>> list = new LinkedList(m.entrySet());

        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>(){
            public int compare(Map.Entry<String, Integer> l, Map.Entry<String, Integer> r){
                int comparison = (l.getValue() - r.getValue()) * -1;
                return comparison == 0 ? l.getKey().compareTo(r.getKey()) : comparison;
            }
        });

        // 순서 유지를 위해 LinkedHashMap 사용
        Map<String, Integer> sortedMap = new LinkedHashMap<>();

        for(Iterator<Map.Entry<String, Integer>> iter = list.iterator(); iter.hasNext();){
            Map.Entry<String, Integer> entry = iter.next();
            sortedMap.put(entry.getKey(), entry.getValue());
        }

        System.out.println(sortedMap);



    }
}