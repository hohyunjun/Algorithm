

public class StringMethod{
    public static void main(String[] args){

        String s = "abcdefgabcdefg";

        System.out.println(s.indexOf('a'));  // 0
        System.out.println(s.indexOf("def")); // 3
        System.out.println(s.indexOf("def", 4)); // 10
        System.out.println(s.indexOf("z"));

        String test = "123";
        String test2 = "1";

        int intTest = Integer.parseInt(test);
        int intTest2 = Integer.parseInt(test2);

        StringBuilder sb = new StringBuilder();

        sb.append(String.valueOf(intTest + intTest2));
        sb.append(test);

        System.out.println(sb);

    }
}