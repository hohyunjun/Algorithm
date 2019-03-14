#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

map<string, int> dist; // 표를 string 형태로 나타낸 뒤 해당 string 까지의 dist 저장
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

string modulation(int a[3][3]){
    string tmp = "";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            tmp += a[i][j] + '0';
        }
    }
    return tmp;
}

void demodulation(string tmp, int (*arr)[3]){
    int cnt = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j] = tmp[cnt++] - '0';
        }
    }
    return;
}

int main(){

    int a[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> a[i][j];
        }
    }

    string start = modulation(a);

    queue<string> q;
    q.push(start);
    dist[start] = 1;

    while(!q.empty()){
        string x = q.front();
        int now[3][3];
        demodulation(x, now);
        int next[3][3];
        int zerox, zeroy; // 0의 위치 파악
        for(int i=0; i<3; i++){
            if(now[i][0] == 0){zerox = i; zeroy=0; break;};
            if(now[i][1] == 0){zerox = i; zeroy=1; break;};
            if(now[i][2] == 0){zerox = i; zeroy=2; break;};
        }
        for(int i=0; i<4; i++){
            int nx = zerox + dx[i];
            int ny = zeroy + dy[i];
            if(nx>=0 && ny>=0 && nx<3 && ny<3){ // 범위 내에 있을 경우
                demodulation(x,next);
                swap(next[nx][ny], next[zerox][zeroy]);
                string next_str = modulation(next);
                if(dist[next_str] == 0){
                    q.push(next_str);
                    dist[next_str] = dist[x] + 1;
                }else if(dist[next_str] != 0 && dist[next_str] > dist[x] + 1){
                    q.push(next_str);
                    dist[next_str] = dist[x] + 1;
                }
            }
        }
        q.pop();
    }

    string ans = "123456780";

    if(dist[ans] == 0){
        cout << -1 << "\n";
    }else{
        cout << dist[ans] - 1 << '\n';
    }

    return 0;
}