#include <iostream>
using namespace std;

int sudoku[9][9];

bool check(int row, int col, int num){
    // 가로줄 체크
    for(int i=0; i<9; i++){
        if(sudoku[row][i] == num) return false;
    }

    // 세로줄 체크
    for(int i=0; i<9; i++){
        if(sudoku[i][col] == num) return false;
    }

    // 3*3 정사각형 체크
    int rowBegin, colBegin;

    if(row>=0 && row<=2){
        rowBegin = 0;
    }else if(row>=3 && row<=5){
        rowBegin = 3;
    }else{
        rowBegin = 6;
    }

    if(col>=0 && col<=2){
        colBegin = 0;
    }else if(col>=3 && col<=5){
        colBegin = 3;
    }else{
        colBegin = 6;
    }

    for(int i = rowBegin; i<rowBegin+3; i++){
        for(int j = colBegin; j<colBegin+3; j++){
            if(sudoku[i][j] == num){
                return false;
            }
        }
    }

    return true;
}


// sudoku[row][col]의 빈 sudoku칸을 채운다
void go(int row, int col){
    // cout << row << "," << col << '\n';
    // cout << sudoku[8][8] << '\n';
    // 종료조건
    if(row == 9 && col == 0){
        cout << '\n';

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    if(sudoku[row][col] == 0){
        // 진행조건
        for(int i=1; i<=9; i++){
            if(check(row, col, i) && col != 8){
                sudoku[row][col] = i;
                go(row, col+1);
                sudoku[row][col] = 0;
            }else if(check(row, col, i) && col == 8){
                sudoku[row][col] = i;
                go(row+1, 0);
                sudoku[row][col] = 0;
            }
        }
    }else{
         if(col == 8){
            go(row+1, 0);
        }else{
            go(row, col+1);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
        }
    }

    go(0,0);

    // if(check(0,0,1)){
    //     cout << "true" << '\n';
    // }

    return 0;
}