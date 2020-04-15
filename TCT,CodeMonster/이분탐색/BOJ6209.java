import java.util.*;

public class BOJ6209{

    public static int arr[];

    public static int ans = 0;

    // 찾는 값 : 두 돌 사이의 최소 거리의 최댓값
    public static void bSearch(int l, int r, int c){

        int mid = 0;

        while(l <= r){

           // System.out.println(l + ", " + r);
            mid = (l+r)/ 2;

            int keep = 1;
            int last = arr[0];

            for(int i=1; i<arr.length; i++){
                if(arr[i] - last >= mid){
                    keep++;
                    last = arr[i];
                }

                if(keep >= c) break;
            }

            if(keep < c){ // 유지 되는 돌이 유지 되어야 하는 돌보다 적은 경우, 돌 사이의 거리를 줄여야 함
                r = mid - 1;
            }else{ // 유지 되는 돌이 유지 되어야 하는 돌보다 많은 경우, 돌 사이의 거리를 늘려야 함.
                ans = Math.max(ans, mid);
                l = mid + 1;
            }
        }

        return;

    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int d = sc.nextInt();
        int n = sc.nextInt();
        int m = sc.nextInt();

        arr = new int[n + 2];

        arr[0] = 0;
        arr[n+1] = d;

        for(int i=1; i<n+1; i++){
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        bSearch(0, arr[n+1] - arr[0], n-m+2);

        System.out.println(ans);

        sc.close();

    }
}