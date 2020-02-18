#include <iostream>
using namespace std;

int sudoku[9][9];

// 가로, 세로, 작은네모
bool check(int row, int col, int num){

    // 가로
    for(int i=0; i<9; i++){
        if(sudoku[row][i] == num) return false;
    }

    // 세로
    for(int i=0; i<9; i++){
        if(sudoku[i][col] == num) return false;
    }

    // 작은네모
    int sr = row/3;
    int sc = col/3;
    
    for(int i=sr*3; i<sr*3+3; i++){
        for(int j=sc*3; j<sc*3+3; j++){
            if(sudoku[i][j] == num) return false;
        }
    }


    return true;
}


void solve(int row, int col){

    // 종료조건
    if(row == 9){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }

    if(sudoku[row][col] == 0){
        for(int i=1; i<=9; i++){
            if(check(row, col, i) && col != 8){ // sudoku[row][col]에 i가 들어갈 수 있다면
                sudoku[row][col] = i;
                solve(row, col+1);
                sudoku[row][col] = 0;
            }else if(check(row, col, i) && col == 8){
                sudoku[row][col] = i;
                solve(row+1, 0);
                sudoku[row][col] = 0;
            }
        }
    }else{
        if(col == 8){
            solve(row+1, 0);
        }else{
            solve(row, col+1);
        }
    }    
}

int main(){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
        }
    }

    solve(0,0);

    return 0;
}