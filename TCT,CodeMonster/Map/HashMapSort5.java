import java.util.*;

public class HashMapSort5{
    public static void main(String[] args){

        HashMap<String, Integer> m = new HashMap<>();

        m.put("가", 5000);
        m.put("나", 1000);
        m.put("아", 2000);
        m.put("다", 3000);
        m.put("사", 4000);
        m.put("라", 2000);

        // 주어진 map을 key 값 기준으로 오름차순 정렬하시오(단, key 값이 같을 경우 value 값 기준으로 오름차순 정렬)

        System.out.println("Before Sorting : " + m);

        // list 에 넣고 sort 진행
        List<Map.Entry<String, Integer>> list = new LinkedList<>(m.entrySet());

        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>(){
            public int compare(Map.Entry<String, Integer> l, Map.Entry<String, Integer> r){

                int compare = l.getValue() - r.getValue();

                return compare == 0 ? l.getKey().compareTo(r.getKey()) : compare;
            }
        });

        LinkedHashMap<String, Integer> sortedMap = new LinkedHashMap<>();

        for(Map.Entry<String, Integer> es : list){
            sortedMap.put(es.getKey(), es.getValue());
        }

        System.out.println("After Sorting : " + sortedMap);

    }
}