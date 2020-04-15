import java.util.*;
import java.io.*;

public class brst {

    public static void main(String args[]) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        System.out.println(a + ", " + b + ", " + c);


        st = new StringTokenizer(br.readLine());
        String tmp = st.nextToken();

        System.out.println(tmp);


    }


}