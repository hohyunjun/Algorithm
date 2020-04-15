import java.util.*;

public class DequeRemove{
    public static void main(String args[]){

        Deque<Integer> dq = new ArrayDeque<>();

        dq.offerFirst(100);
        dq.offerFirst(200);
        dq.offerFirst(300);

        System.out.println(dq.remove()); // 걍 맨 앞꺼 remove하는 메소드

        dq.offerLast(500);
        dq.offerFirst(1000);

        // Before Remove
        // while(!dq.isEmpty()){
        //     System.out.println(dq.poll());
        // }


        dq.remove(1000);

        // After Remove
        while(!dq.isEmpty()){
            System.out.println(dq.poll());
        }

        System.out.println("===================STACK Remove TEST====================");

        Stack<Integer> st = new Stack<>();

        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(1000);

        boolean flag = st.remove(Integer.valueOf(1000));

        while(!st.isEmpty()){
            System.out.println(st.pop());
        }

        System.out.println("===================STACK<String> Remove TEST====================");

        Stack<String> sst = new Stack<>();

        sst.push("1");
        sst.push("1000");
        sst.push("999");

        sst.remove("1000");

        while(!sst.isEmpty()){
            System.out.println(sst.pop());
        }


    }
}