import java.util.*;
import java.io.*;

public class BOJ2503 {

    public static class Question{
        int number, strike, ball;

        public Question(int number, int strike, int ball){
            this.number = number;
            this.strike = strike;
            this.ball = ball;
        }
    }

    // 가능한 정답의 집합, 숫자 a가 정답이 될 수 있다면, possibleAnswers[a] = true
    public static boolean possibleAnswers[] = new boolean[1000];
    
    // strike, ball 판별
    public static int[] check(int num1, int num2){

        int ret[] = new int[2];

        String strNum1 = String.valueOf(num1);
        String strNum2 = String.valueOf(num2);

        int strike = 0;
        int ball = 0;

        for(int i=0; i<strNum1.length(); i++){

            if(strNum1.contains(String.valueOf(strNum2.charAt(i)))){
                ball++;
            }

            if(strNum1.charAt(i) == strNum2.charAt(i)){
                strike++;
                ball--;
            }

        }

        //System.out.println("Num1 : " + num1 + ", Num2 : " + num2 + ", Strike : " + strike + ", Ball : " + ball );

        ret[0] = strike;
        ret[1] = ball;
        
        return ret;
    }

    // possibleAnswers 배열에 표기하는 역할을 하는 함수
    public static void solution(ArrayList<Question> arr){

        for(int i=0; i<arr.size(); i++){
            for(int j=123; j<=987; j++){
                if(!possibleAnswers[j]) continue;
                int ret[] = new int[2];
                ret = check(arr.get(i).number, j); // 스트라이크, 볼 개수와 일치하는지 확인
                if(ret[0] != arr.get(i).strike || ret[1] != arr.get(i).ball){
                    possibleAnswers[j] = false;
                }
            }
        }

        return;
    }   

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());

        // 케이스의 수
        int N = Integer.parseInt(st.nextToken());

        ArrayList<Question> arr = new ArrayList<>();
        
        for(int i=0; i<N; i++){
            int a, b, c;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            
            arr.add(new Question(a, b, c));
        }
        
        for(int i=123; i<=987; i++){
            if(String.valueOf(i).contains("0")){
                possibleAnswers[i] = false;
                continue;
            }
            
            String strNum = String.valueOf(i);

            if(strNum.charAt(0) == strNum.charAt(1) || strNum.charAt(1) == strNum.charAt(2) || strNum.charAt(0) == strNum.charAt(2)){
                possibleAnswers[i] = false;
                continue;
            }

            possibleAnswers[i] = true;
        }


        solution(arr);           

        int answer = 0;

        for(int i=123; i<=987; i++){
            if(possibleAnswers[i]) answer++;
        }

        System.out.println(answer);

    }

}