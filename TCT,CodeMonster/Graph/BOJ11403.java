import java.util.*;

public class BOJ11403{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // 인접 행렬 그래프 저장
        int A[][] = new int[n][n];

        // 정답 저장할 인접 행렬 그래프
        int answer[][] = new int[n][n];

        // 방문했는지 안했는지 저장
        boolean V[] = new boolean[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                A[i][j] = sc.nextInt();
            }
        }


        // 해당 인접 행렬에 대해 BFS 수행
        // 정점 0 ~ n-1 까지 BFS
        for(int i=0; i<n; i++){
            ArrayDeque<Integer> dq = new ArrayDeque<>();

            dq.offerLast(i);

            while(!dq.isEmpty()){
                int first = dq.pollFirst();
                for(int j=0; j<n; j++){
                    // 경로가 있고, 아직 방문되지 않은 정점이라면
                    if(A[first][j] == 1 && V[j] == false){
                        dq.offerLast(j);
                        V[j] = true;
                        answer[i][j] = 1;
                    }
                }
            }

            // 방문 배열 초기화
            for(int j=0; j<n; j++){
                V[j] = false;
            }

        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(answer[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();

    }
}