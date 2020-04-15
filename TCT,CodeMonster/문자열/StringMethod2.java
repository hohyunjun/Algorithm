

public class StringMethod2{
    public static void main(String [] args){

        String s = "Apple Banana Kiwi";

        System.out.println(s.substring(6)); // Banana Kiwi

        System.out.println(s.substring(s.indexOf("Banana"), s.indexOf(" ", s.indexOf("Banana")))); // Banana


    }
}