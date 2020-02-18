#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 하나의 톱니바퀴만 시계방향으로 돌리는 연산
void clockwise(vector<string> &t, int tnum){
    tnum -=1;
    char back = t[tnum][7]; // 맨 뒤 글자
    string tmp = "";
    tmp += back;
    for(int i=0; i<7; i++){
        tmp += t[tnum][i];
    }
    t[tnum] = tmp;
    return;
}

// 반시계
void unclockwise(vector<string> &t, int tnum){
    tnum -=1;
    char front = t[tnum][0];
    string tmp = "";
    for(int i=1; i<8; i++){
        tmp += t[tnum][i];
    }
    tmp += front;
    t[tnum] = tmp;
    return;
}

// 톱니바퀴를 돌리면서 다른 톱니바퀴도 돌려야 하는지 판별
void rotate(vector<string> &t, int tnum, int dir, vector<bool> &check){
    
    tnum -= 1;
    //어떤 톱니바퀴를 돌릴지
    if(tnum == 0){
        if(check[0] == true) return; // 이미 돌린 톱니바퀴라면
        check[0] = true;
        bool rotateR = false;
        if(t[0][2] != t[1][6] && check[1] == false){ // 두번째 톱니바퀴와의 방향이 같지 않을 경우
            rotateR = true;
        }
        if(dir == 1){
            clockwise(t, 1);
        }else{
            unclockwise(t, 1);
        }
        if(rotateR){
            if(dir == 1){
                rotate(t, 2, -1, check);
            }else{
                rotate(t, 2, 1, check);
            }
        }
    }else if(tnum == t.size()-1){ // 마지막 톱니바퀴일경우
        if(check[tnum] == true) return;
        check[tnum] = true;
        bool rotateL = false;
        // 세번째 톱니바퀴와 방향이 같지 않은 경우
        if(t[tnum][6] != t[tnum-1][2] && check[tnum-1] == false){ // 세번째 톱니바퀴를 반대로 돌려야한다.
            rotateL = true;
        }

        // 일단 현재꺼 돌리고
        if(dir == 1){
            clockwise(t, tnum+1);
        }else{
            unclockwise(t, tnum+1);
        }

        if(rotateL){
            if(dir == 1){
                rotate(t, tnum, -1, check);
            }else{
                rotate(t, tnum, 1, check);
            }
        }
    }else{
        if(check[tnum] == true) return;
        check[tnum] = true;
        bool rotateL = false, rotateR = false;
        // 두번째 톱니바퀴와 방향이 같지 않은 경우
        if(t[tnum][6] != t[tnum-1][2] && check[tnum-1] == false){
            rotateL = true;
        }
        // 네번째 톱니바퀴와 방향이 같지 않은 경우
        if(t[tnum][2] != t[tnum+1][6] && check[tnum+1] == false){
            rotateR = true;
        }
        // 먼저 현재 톱니바퀴 돌리고
        if(dir == 1){
            clockwise(t,tnum+1);
        }else{
            unclockwise(t,tnum+1);
        }

        // 연쇄적으로 돌아가야하는 톱니바퀴 체크
        if(rotateL){
            if(dir == 1){
                rotate(t, tnum, -1, check);
            }else{
                rotate(t, tnum, 1, check);
            }
        }

        if(rotateR){
            if(dir == 1){
                rotate(t,tnum+2,-1,check);
            }else{
                rotate(t,tnum+2,1,check);
            }
        }
    }

    return;
}

int Score(vector<string> t){
    int ans = 0;
    for(int i=0; i<t.size(); i++){
        if(t[i][0] == '1') ans += 1;
    }
    return ans;
}

int main(){

    int gatsu;

    cin >> gatsu;

    vector<string> t(gatsu); // 톱니바퀴 t 개

    for(int i=0; i<gatsu; i++){
        cin >> t[i];
    }

    int k; // 회전 횟수

    cin >> k;

    while(k--){
        int tnum, dir; // 회전시킨 톱니바퀴 번호, 방향
        cin >> tnum >> dir;
        vector<bool> check(gatsu, false);
        rotate(t, tnum, dir, check); // 톱니바퀴를 회전시키는 함수
    }

    int ans = Score(t);

    cout << ans << '\n';


    return 0;
}