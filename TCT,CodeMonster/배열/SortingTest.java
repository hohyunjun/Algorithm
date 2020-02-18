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