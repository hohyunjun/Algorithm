import java.util.HashSet;
import java.util.Scanner;

public class BOJ3052{
    public static void main(String[] args){

        int input[] = new int[10];

        HashSet<Integer> hs = new HashSet<Integer>();

        Scanner sc = new Scanner(System.in);

        for(int i=0; i<10; i++){
            input[i] = (sc.nextInt() % 42);
            hs.add(input[i]);
        }

        System.out.println(hs.size());

        System.out.println("======HashSet Traverse=====");

        for(int a : hs){
            System.out.print( a + " ");
        }


    }
}