import java.util.*;

public class StringArray{

    public static void main(String[] args){

        String test[] = new String[5];

        test[0] = "A";
        test[1] = "B";
        test[2] = "C";
        test[3] = "D";
        test[4] = "E";

        for(String s : test){
            System.out.print(s + ", ");
        }

        test[0] = "a";
        test[1] = "b";
        test[2] = "c";
        test[3] = "d";
        test[4] = "e";

        System.out.println();
        
        for(String s : test){
            System.out.print(s + ", ");
        }



    }


}