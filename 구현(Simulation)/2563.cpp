#include <iostream>
using namespace std;

bool paper[100][100];

int main(){

    int nums;

    cin >> nums;

    for(int i=0; i<nums; i++){
        int garo, sero;
        cin >> garo >> sero;

        garo -= 1;
        sero = 100 - sero - 9;

        for(int i=sero; i<=sero+9; i++){
            for(int j=garo; j<=garo+9; j++){
                paper[i][j] = true;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(paper[i][j]){
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}