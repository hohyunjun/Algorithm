import java.util.*;

public class HashMapSort4{
    public static void main(String[] args){

        HashMap<Integer, String> m = new HashMap<>();

        m.put(1, "A");
        m.put(100, "Z");
        m.put(1000, "C");
        m.put(50, "B");
        m.put(500, "D");
        m.put(900, "A");

        // Q. 위 HashMap 을 value 값에 대해 오름차순으로 정렬하시오(단, value 값이 같을 경우 key 값에 대해 내림차순 정렬)
        
        List<Map.Entry<Integer, String>> list = new LinkedList<>(m.entrySet());

        Collections.sort(list, new Comparator<Map.Entry<Integer, String>>() {
            public int compare(Map.Entry<Integer, String> l, Map.Entry<Integer, String> r){
                int comparison = l.getValue().compareTo(r.getValue());

                return comparison == 0 ? (l.getKey() - r.getKey()) * -1 : comparison;
            }
        });

        LinkedHashMap<Integer, String> sortedMap = new LinkedHashMap<>();

        for(Map.Entry<Integer, String> es : list){
            sortedMap.put(es.getKey(), es.getValue());
        }

        System.out.println(sortedMap);


        System.out.println("A".compareTo("A"));

    }
}