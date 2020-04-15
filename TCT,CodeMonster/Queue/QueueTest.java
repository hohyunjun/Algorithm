import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Deque;
import java.util.ArrayDeque;

public class QueueTest{
    public static void main(String[] args){

        // 일반 큐
        Queue<Integer> q = new LinkedList<Integer>();

        // 일반 스택
        Stack<Integer> st = new Stack<Integer>();

        q.offer(1);
        q.offer(2);
        q.offer(3);
        q.offer(4);

        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

        System.out.println("========Queue With Advanced For==========");

        for(int i : q){
            System.out.println(i);
        }

        System.out.println("========Stack With Advanced For==========");

        for(int i : st){
            System.out.println(i);
        }

        System.out.println("========Queue From the First==========");

        while(!q.isEmpty()){
            System.out.println(q.poll());
        }

        System.out.println("========Stack With Advanced For==========");

        while(!st.isEmpty()){
            System.out.println(st.pop());
        }

        System.out.println("Deque 선언 후 Deque 동작 st, q처럼 만들어보기");

        Deque<Integer> dq = new ArrayDeque<>();

        System.out.println("==========Deque Like Queue============");

        dq.offerLast(1);
        dq.offerLast(2);
        dq.offerLast(3);
        dq.offerLast(4);

        while(!dq.isEmpty()){
            System.out.println(dq.pollFirst());
        }

        System.out.println("==========Deque Like Stack============");

        dq.offerFirst(1);
        dq.offerFirst(2);
        dq.offerFirst(3);
        dq.offerFirst(4);

        while(!dq.isEmpty()){
            System.out.println(dq.pollFirst());
        }

        System.out.println("===========Deque Peek================");

        dq.offerLast(1);
        dq.offerLast(2);
        dq.offerLast(3);

        System.out.println(dq.peek());




    }
}