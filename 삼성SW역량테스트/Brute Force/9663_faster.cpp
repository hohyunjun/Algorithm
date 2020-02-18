#include <iostream>
using namespace std;

int n;
//bool A[15][15];
int cnt = 0;
bool checkCol[15]; // |
bool checkDig[40]; // /
bool checkDig2[40]; // \

bool check(int row, int col){
    if(checkCol[col]) return false;
    if(checkDig[row+col]) return false;
    if(checkDig2[row+(n-1)-col]) return false;
    return true;
}

void go(int row){
    if(row == n){
        cnt += 1;
    }
    for(int col=0; col<n; col++){
        if(check(row,col)){
  //          A[row][col] = true;
            checkCol[col] = true;
            checkDig[row+col] = true;
            checkDig2[row + (n-1) - col] = true;
            go(row+1);
    //        A[row][col] = false;
            checkCol[col] = false;
            checkDig[row+col] = false;
            checkDig2[row + (n-1) - col] = false;
        }
    }
}

int main(){

    cin >> n;

    go(0);

    cout << cnt << '\n';


    return 0;
}