## Stack
```java
import java.util.Stack;
import java.util.Scanner;

public class BOJ10828{
    public static void main(String[] args){

        Stack<Integer> st = new Stack<Integer>();

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        while(n-- != 0){
            String cmd = sc.next();

            switch(cmd){
                case "push" : st.push(sc.nextInt());
                            break;
                case "pop" : if(!st.empty()){
                                System.out.println(st.pop());
                            }else{
                                System.out.println(-1);
                            } 
                            break;
                case "size" : System.out.println(st.size());
                            break;
                case "empty" : if(!st.empty()){
                                System.out.println(0);
                            }else{
                                System.out.println(1);
                            }
                            break;
                case "top" : if(!st.empty()){
                                System.out.println(st.peek());
                            }else{
                                System.out.println(-1);
                            } 
            
                            break;
                default: break;

            }

        }


    }
}
```