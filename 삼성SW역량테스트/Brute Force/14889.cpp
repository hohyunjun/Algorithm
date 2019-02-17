#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int S[21][21];
int minDiff = 0x7FFFFFFF;

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> S[i][j];
        }
    }

    vector<int> check;

    for(int i=0; i<n/2; i++){
        check.push_back(0);
    }

    for(int i=0; i<n/2; i++){
        check.push_back(1);
    }

    do{
        int Asum = 0;
        int Bsum = 0;
        vector<int> Ateam;
        vector<int> Bteam;

        for(int i=0; i<n; i++){
            if(check[i] == 0){
                Ateam.push_back(i);
            }else{
                Bteam.push_back(i);
            }
        }

        for(int i=0; i<n/2; i++){
            for(int j=i+1; j<n/2; j++){
                Asum += S[Ateam[i]][Ateam[j]] + S[Ateam[j]][Ateam[i]];
                Bsum += S[Bteam[i]][Bteam[j]] + S[Bteam[j]][Bteam[i]];
            }
        }

        int tmp = abs(Asum - Bsum);
        minDiff = min(tmp, minDiff);

    }while(next_permutation(check.begin(), check.end()));

    cout << minDiff << '\n';


    return 0;
}