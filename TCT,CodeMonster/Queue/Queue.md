## Queue
 - Java에서는 스택을 Stack 클래스로 구현하여 제공하지만, Queue는 인터페이스만 있고 별도의 클래스가 없다. 
 - 그래서, Queue 인터페이스를 구현한 클래스들을 사용해야 한다.
 - Queue 의 경우, LinkedList 클래스를 사용해 구현한다.
 ```java
   // 일반 큐
    Queue<Integer> q = new LinkedList<Integer>();
    q.offer(1);
    q.offer(2);
    q.offer(3);
    q.offer(4);

    while(!q.isEmpty()){
        System.out.println(q.poll());
    }
 ```

## Deque
  - Deque 의 경우, 앞, 뒤에서 모두 삽입/삭제가 가능한 큐이다.(Double-ended-Queue)
  - ArrayDeque를 사용해서 구현한다.

  ```java
  
    Deque<Integer> dq = new ArrayDeque<>();
    
    // push 메소드
    dq.offerLast(1);
    dq.offerFirst(2);

    // pop 메소드
    dq.pollFirst();
    dq.pollLast();
  ```

## PriorityQueue
  - MinHeap, MaxHeap을 사용한 자료구조
  - Comparator를 사용해서 내가 원하는 대로 비교방식을 정해줄 수 있다.
  - 우선순위가 큰 값부터 poll()하는 자료구조
  ```java
  import java.util.PriorityQueue;
  import java.util.Comparator;

  public class PriorityQueueTest{
      public static void main(String[] args){

          PriorityQueue<Integer> pq = new PriorityQueue<>();

          // Default : 작은 수 -> 큰 수 오름차순으로 출력됨.
          pq.offer(4);
          pq.offer(3);
          pq.offer(2);
          pq.offer(1);

          while(!pq.isEmpty()){
              System.out.println(pq.poll());
          }

          // MaxHeap 으로 표현하기 : Comparator 사용
          PriorityQueue<Integer> mpq = new PriorityQueue<Integer>(new Comparator<Integer>(){
              public int compare(Integer l, Integer r){
                  if( l < r ) return 1; // 앞에 오는 게 음수 반환, 지금은 내림차순 할 거니까 뒤에꺼가 더 큰 경우 양수를 줘서 순서를 바꿈.
                  if( l == r ) return 0;
                  return -1;
              }
          });

          mpq.offer(1);
          mpq.offer(2);
          mpq.offer(3);
          mpq.offer(4);

          while(!mpq.isEmpty()){
              System.out.println(mpq.poll());
          }


      }
  }
  ```

## MaxHeap과 MinHeap으로 중간값 구하기
 - 숫자를 오름차순으로 정렬한다고 가정하고, 왼쪽에 MaxHeap, 오른쪽에 MinHeap이 있다고 생각한다.
 - MaxHeap.size() == MinHeap.size()일 때, 항상 MaxHeap에 숫자를 넣는다.
 - MaxHeap.size() > MinHeap.size() 인 경우에는 MinHeap에 숫자를 넣는다.
 - MaxHeap.peek() 값과 MinHeap.peek() 값을 비교해서, MaxHeap.peek() > MinHeap.peek() 인 경우, 두 값을 swap한다.
 - MaxHeap.peek() 값이 중간값이 된다.
 ```java
  import java.util.Scanner;
  import java.util.PriorityQueue;
  import java.util.Comparator;

  public class BOJ1655{
      public static void main(String[] args){

          PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
          PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(new Comparator<Integer>(){
              public int compare(Integer l, Integer r){
                  if(l<r) return 1;
                  if(l>r) return -1;
                  return 0;
              }
          });

          Scanner sc = new Scanner(System.in);

          int tc = sc.nextInt();

          while(tc-- != 0){
              
              int num = sc.nextInt();

              if(minHeap.size() == maxHeap.size()){
                  maxHeap.offer(num);
              }else{
                  minHeap.offer(num);
              }

              if(minHeap.isEmpty()){
                  System.out.println(maxHeap.peek());
              }else{
                      
                  if(maxHeap.peek() > minHeap.peek()){
                      int num1 = maxHeap.poll();
                      int num2 = minHeap.poll();

                      maxHeap.offer(num2);
                      minHeap.offer(num1);
                  }

                  System.out.println(maxHeap.peek());
              }

              // System.out.print("MaxHeap : ");
              // maxHeap.forEach((value) -> System.out.print(value + ", "));
              // System.out.println("");

              // System.out.print("MinHeap : ");
              // minHeap.forEach((value) -> System.out.print(value + ", "));
              // System.out.println("");
              
          }



          sc.close();


      }
  }
 ```
 