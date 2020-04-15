import java.util.*;
/*
    공유기 설치
     - 완전탐색으로 풀기에는 숫자 범위가 너무 크다
     - 이분 탐색을 활용해서 풀이해 본다.
     - 탐색할 것 : 가장 인접한 두 공유기 사이의 거리를 최대로 하는 경우
     - min = 0, max = arr[n-1] - arr[0]
*/

public class BOJ2110{

    // 집의 좌표를 담을 배열
    public static int arr[];

    public static int ans = 0;

    // 이분탐색 진행 : 가장 인접한 두 공유기 사이의 최대거리
    public static void binarySearch(int l, int r, int c){

        int mid;

        int lastLoc = 0;

        while(l <= r){

            mid = (l + r) / 2;

            int install = 1;
            lastLoc = arr[0];

            for(int i=1; i<arr.length; i++){
                if(arr[i] - lastLoc >= mid){
                    install++;
                    lastLoc = arr[i];
                }

                if(install >= c) break;
            }

            if(install < c){ // mid 간격으로 설치했을 때 공유기를 다 설치할 수 없을 경우, 간격을 줄여야 함
                r = mid - 1;
            }else{
                ans = Math.max(ans, mid);
                l = mid + 1;
            }
        }

        return;


    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int c = sc.nextInt();

        arr = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        int max = arr[n-1] - arr[0]; // 집 사이의 최대 거리

        binarySearch(0, max, c);

        System.out.println(ans);

        sc.close();

    }
}