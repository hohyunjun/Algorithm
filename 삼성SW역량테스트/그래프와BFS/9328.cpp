#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    // 감옥의 바깥 임의의 정점에서 시작해서 BFS돌린다
    // 각 알파벳 대문자의 좌표를 pair 형태로 저장한다.
    // 가지고 있는 열쇠를 활용해서 열 수 있는 문으로부터 BFS를 각각 수행하여 문서의 개수를 구한다.

    int t;

    cin >> t;

    while(t--){
        int h, w;

        cin >> h >> w;

        vector<string> A(h+2);
        string key;

        string tmp = "";

        for(int i=0; i<w+2; i++){
            tmp += ".";
        }

        A[0] = tmp;

        for(int i=1; i<h+1; i++){
            string tmp2 = ".";
            string tmp3 = "";
            cin >> tmp3;
            tmp2 += tmp3;
            tmp2 += ".";
            A[i] = tmp2;
        }

        A[h+1] = tmp;

        cin >> key;


        int check[h+2][w+2];
        memset(check, 0, sizeof(check));

        int ans = 0;

        bool keycheck[26] = {false};
        for(int i=0; i<key.length(); i++){
            if(key[i] == '0') continue;
            keycheck[key[i] - 'a'] = true;
        }

        // 감옥의 바깥 (0,0)으로부터 시작하여 BFS
        //vector< vector< pair<int,int> > > door(26);
        deque<pair<int,int>> door[26];

        deque<pair<int,int>> q;
        q.push_back(make_pair(0,0));
        check[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx<0 || ny<0 || nx>=h+2 || ny>=w+2) continue;
                if(check[nx][ny] != 0) continue;
                if(A[nx][ny] == '*') continue;
                check[nx][ny] = check[x][y];
                if(A[nx][ny] == '.'){
                    q.push_back(make_pair(nx,ny));
                }else if(A[nx][ny] == '$'){
                    q.push_back(make_pair(nx,ny));
                    ans+=1;
                }else{ // 알파벳일 경우 각 알파벳의 좌표를 저장
                    char alphabet = A[nx][ny];
                    // 대문자인 경우
                    if(alphabet - 'a' < 0){
                        if(keycheck[alphabet-'A']){
                            q.push_back(make_pair(nx,ny));
                        }else{
                            door[alphabet-'A'].push_back(make_pair(nx,ny));
                        }
                    }else{
                        q.push_back(make_pair(nx,ny));
                        if(!keycheck[alphabet-'a']){
                            keycheck[alphabet-'a'] = true;
                            while(!door[alphabet-'a'].empty()){
                                q.push_back(door[alphabet-'a'].front());
                                door[alphabet-'a'].pop_front();
                            }
                        }
                    }
                }
            }
        }

        // for(int i=0; i<26; i++){
        //     char tmp = i+'A';
        //     cout << tmp << " : ";
        //     for(int j=0; j<door[i].size(); j++){
        //         cout << door[i][j].first << " " << door[i][j].second << " // ";
        //     }
        //     cout << '\n';
        // }

        // 가지고 있는 key 들을 queue에 넣고, key 에 해당하는 문으로부터 BFS 돌린다.
        // 또 다른 key가 나올 경우 : q.push_back
        // 문서 발견 시 : ans += 1
        


        cout << ans << '\n';

    }



    return 0;
}