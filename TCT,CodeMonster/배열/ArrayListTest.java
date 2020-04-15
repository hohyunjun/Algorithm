import java.util.*;

public class ArrayListTest{
    public static void main(String[] args){

        // 2차원 ArrayList test
        ArrayList<String[]> A = new ArrayList<String[]>();

        A.add(new String[]{"ABC", "DEF"});
        A.add(new String[]{"GHI"});

        System.out.println(A.size());

        for(String[] strs : A){
            for(String s: strs){
                System.out.print( s + " ");
            }
            System.out.println();
        }

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

        
    }
}