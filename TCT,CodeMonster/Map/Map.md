## Map
 - Java에서 Map은 주로 Hashmap을 사용한다.
 - HashMap
  + Map 인터페이스의 한 종류로, (Key, Value)로 이루어져 있다.
  + Key 값은 중복이 불가능하고, value는 중복이 가능하다. value에 null 값도 사용 가능하다.

## HashMap Methods
 - void clear()
  + HashMap에 저장된 모든 객체를 제거한다.
 - Object clone()
  + 현재 HashMap을 복제하여 반환한다.
 - boolean containsKey(Object Key)
  + HashMap에 지정된 Key 가 포함되어 있는지 알려준다.
 - boolean containsValue(Object Value)
  + HashMap에 지정된 Value 가 포함되어 있는지 알려준다.
 - Set entrySet()
  + HashMap에 저장된 Key-Value 값을 엔트리(key와 값을 결합) 형태로 Set에 저장하여 반환
 - Object get(Object Key)
  + 지정된 Key의 값을 반환한다.
 - boolean isEmpty()
  + HashMap이 비어있는지 확인한다.
 - Set keySet()
  + HashMap에 저장된 모든 키가 저장된 Set을 반환한다.
 - Object put(Object Key, Object Value)
  + HashMap에 키와 값을 저장
 - void putAll(Map m)
  + Map에 해당하는 모든 요소를 HashMap에 저장한다.
 - Object remove(Object Key)
  + HashMap에서 지정된 키로 지정된 값을 제거한다.
 - int size()
  + HashMap에 저장된 요소의 개수를 반환한다.
 - Collection values()
  + HashMap에 저장된 모든 값을 컬렉션 형태로 반환한다.
```java
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
```

## HashMap의 Sorting
 - HashMap의 정렬은 아래와 같은 절차로 이루어진다.
   1. HashMap 내부 값들을 정렬하기 위해, HashMap 의 EntrySet을 List 에 저장
   2. entrySet 값을 저장한 list 를 Collections.sort를 사용하여 정렬
     + Comparator 를 사용하여 어떻게 비교를 해 줄지 정해준다.
   3. 정렬된 list를 새로 선언한 LinkedHashMap에 순서대로 넣는다.
 - 예시
 ```java
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
 ```
