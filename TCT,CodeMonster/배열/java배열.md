## Java 의 배열선언
 - java 배열 선언 및 초기화는 아래와 같이 진행한다.
 ```java
 int arr[] = new int[10];
 ```
 - 기본적으로, **boolean array의 경우 false, int array 의 경우 0, Object array 의 경우 null 값으로 자동 초기화**된다.

## ArrayList 와의 비교
 1. 배열
  - 배열의 크기는 한 번 정하면, 바꿀 수 없다.
     ```java
     Car carArr[] = new Car[5]; // 크기를 5에서 바꿀 수 없음
     // 배열의 크기를 가져오는 메소드
     for(int i=0; i< carArr.length; i++){
         System.out.println(carArr[i].name);
     }
     ```
  - 배열 초기화 시 메모리에 할당되어 ArrayList 보다 속도가 빠르다.

 2. ArrayList
  - ArrayList는 크기가 가변적이다.
  - 저장하는 데이터 수에 따라서 크기가 변경된다.(C++의 vector와 비슷한 느낌인가?)
  - 데이터 추가 시 add(), 삭제 시 remove() 사용한다.
  - 데이터 삭제 및 추가 시 메모리를 재할당하기 때문에 속도가 배열보다 느리다.
    ```java
    // ArrayList는 import 가 필요함
    import java.util.ArrayList;

    ArrayList<int> list = new ArrayList<int>();

    for(int i=0; i<5; i++){
        list.add(i);
    }

    // ArrayList 의 크기를 가져오는 메소드는 .size()
    for(int i=0; i< list.size(); i++){
        System.out.println(list.get(i)); // ArrayList의 i번째 요소를 가져오는 메소드 get(i)
    }

    ```
  - remove(index i) 는 i번째 인덱스에 있는 원소를 삭제한다.

 3. ArrayList 의 정렬
    ```java
    import java.util.ArrayList;
    import java.util.Comparator;

    public class SortingTest{
        public static void main(String[] args){

            ArrayList<Integer> test = new ArrayList<>();

            test.add(5);
            test.add(3);
            test.add(2);
            test.add(1);
            test.add(4);

            System.out.print("Before Sorting : [");

            for(int i : test){
                System.out.print(i + " ");
            }

            System.out.println("]");

            System.out.print("After Sorting : [");

            test.sort(Comparator.reverseOrder());

            for(int i : test){
                System.out.print(i + " ");
            }

            System.out.println("]");

        }
    }
    ```
 ## ArrayList 헷갈리는 것
  ```java
   // 여기서 B 와 C는 같은 의미인가?
        // ArrayList 안에 ArrayList 를 넣는다는 의미?
        // --> B는 ArrayList<Integer>를 원소로 가지는 배열
        // --> C는 ArrayList<Integer>를 원소로 가지는 ArrayList
        ArrayList<Integer> B[] = (ArrayList<Integer>[])new ArrayList[3];
        ArrayList<ArrayList<Integer>> C = new ArrayList<>();

        B[0] = new ArrayList<Integer>();
        B[1] = new ArrayList<Integer>();
        B[2] = new ArrayList<Integer>();

        B[0].add(1);
        B[1].add(2);
        B[2].add(3);

        for(int i=0; i<3; i++){
            System.out.print("B[" + i + "] : " );
            for(int j=0; j<B[i].size(); j++){
                System.out.print(B[i].get(j) + ", ");
            }
            System.out.println();
        }

        ArrayList<Integer> newArr = new ArrayList<>();

        C.add(newArr);
        C.add(new ArrayList<Integer>());
        C.add(new ArrayList<Integer>());

        C.get(0).add(1);
        C.get(1).add(2);
        C.get(2).add(3);

        System.out.println(C.size());

        for(int i=0; i<3; i++){
            System.out.print("C[" + i + "] : " );
            for(int j=0; j<C.get(i).size(); j++){
                System.out.print(C.get(i).get(j) + ", ");
            }
            System.out.println();
        }

  ```
