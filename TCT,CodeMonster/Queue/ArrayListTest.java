import java.util.ArrayList;
import java.util.Comparator;

public class ArrayListTest{
    public static void main(String[] args){

        ArrayList<Integer> sarr = new ArrayList<>();

        sarr.add(0);
        sarr.add(1);
        sarr.add(2);
        sarr.add(3);

        sarr.sort(Comparator.reverseOrder());

        for(int i : sarr){
            System.out.println(i);
        }

        sarr.remove(0);

        System.out.println(sarr.get(0));

    }
}