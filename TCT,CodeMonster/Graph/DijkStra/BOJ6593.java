import java.util.*;
import java.io.*;

public class BOJ6593 {

    // 빌딩 이동 
    static char building[][][] = new char[31][31][31];
    static int visit[][][] = new int[31][31][31];
    static int l, r, c;

    // 이동(서,북,동,남,상,하)
    static int dx[] = {-1,0,1,0,0,0};
    static int dy[] = {0,-1,0,1,0,0};
    static int dz[] = {0,0,0,0,1,-1};

    public static class Pair{
        int x, y, z;

        public Pair(int x, int y, int z){
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    // z 가 level, x 가 column, y 가 row
    public static void BFS(int sx, int sy, int sz){

        Pair start = new Pair(sx,sy,sz);
        visit[sz][sy][sx] = 1;

        Deque<Pair> dq = new ArrayDeque<>();

        dq.offerLast(start);

        while(!dq.isEmpty()){
            Pair front = dq.pollFirst();
            int curx = front.x;
            int cury = front.y;
            int curz = front.z;

            for(int i=0; i<6; i++){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                int nz = curz + dz[i];

                if(nz < l && ny < r && nx < c && nz >=0 && ny >=0 && nx >=0){
                    if(visit[nz][ny][nx] == 0 && (building[nz][ny][nx] == '.' || building[nz][ny][nx] == 'E')){
                        visit[nz][ny][nx] = visit[curz][cury][curx] + 1;
                        dq.offerLast(new Pair(nx,ny,nz));
                    }else if((building[nz][ny][nx] == '.' || building[nz][ny][nx] == 'E') && visit[nz][ny][nx] > visit[curz][cury][curx] + 1){
                        visit[nz][ny][nx] = visit[curz][cury][curx] + 1;
                        dq.offerLast(new Pair(nx,ny,nz));
                    }
                }
            }
        }
        return;
    }

    public static void main(String [] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        while(true){

            st = new StringTokenizer(br.readLine());

            l = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            if(l == 0 && r == 0 && c == 0) break;

            // initialize
            for(int i=0; i<31; i++){
                for(int j=0; j<31; j++){
                    for(int k=0; k<31; k++){
                        visit[i][j][k] = 0;
                    }
                }
            }


            int sx=0, sy=0, sz=0, ex=0, ey=0, ez=0;

            for(int i=0; i<l; i++){
                for(int j=0; j<r; j++){
                    st = new StringTokenizer(br.readLine());
                    String tmp = st.nextToken();
                    for(int k=0; k<c; k++){
                        building[i][j][k] = tmp.charAt(k);
                        if(building[i][j][k] == 'S'){
                            sx = k; sy = j; sz = i;
                        }else if(building[i][j][k] == 'E'){
                            ex = k; ey = j; ez = i;
                        }
                    }
                }
                st = new StringTokenizer(br.readLine());
            }

            BFS(sx, sy, sz);

            if(visit[ez][ey][ex] != 0){
                System.out.println("Escaped in " + (visit[ez][ey][ex]-1) + " minute(s).");
            }else{
                System.out.println("Trapped!");
            }

        }


    }

}