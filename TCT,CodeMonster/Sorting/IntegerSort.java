import java.util.*;

class Solution {

    public static void main(String[] args){

        int numbers[] = {3, 30, 34, 5, 9};

        // int는 Primitve 한 자료형, Integer는 Wrapper Class

        Integer IntegerNums[] = new Integer[numbers.length];

        for(int i=0; i<numbers.length; i++){
            IntegerNums[i] = numbers[i];
        }

        String answer = "";

        Arrays.sort(IntegerNums, new Comparator<Integer>(){
            public int compare(Integer l, Integer r){
                String ls = String.valueOf(l), rs = String.valueOf(r);
                
                return (Integer.parseInt(ls + rs) - Integer.parseInt(rs + ls)) * -1;
            }
        });

        StringBuilder sb = new StringBuilder();
        
        for(int i : IntegerNums){
            sb.append(String.valueOf(i));
        }
        
        answer = sb.toString();
        
        if(answer.charAt(0) == '0'){
            answer = "0";
        }

        System.out.println(answer);

    }
}