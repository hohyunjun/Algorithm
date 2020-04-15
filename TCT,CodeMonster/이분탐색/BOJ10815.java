import java.util.*;

public class BOJ10815{

    public static boolean bSearch(int arr[], int target){

        int low = 0;
        int high = arr.length - 1;
        int mid;

        while(low <= high){
            mid = (low + high) / 2;

            if(arr[mid] == target) return true;

            if(arr[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return false;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int n, m;

        n = sc.nextInt();

        int arr1[] = new int[n];

        for(int i=0; i<n; i++){
            arr1[i] = sc.nextInt();
        }

        m = sc.nextInt();

        int arr2[] = new int[m];

        for(int i=0; i<m; i++){
            arr2[i] = sc.nextInt();
        }

        // 오름차순 정렬
        Arrays.sort(arr1);

        for(int i=0; i<m; i++){
            if(bSearch(arr1, arr2[i])){
                System.out.print("1 ");
            }else{
                System.out.print("0 ");
            }
        }



        sc.close();

    }
}