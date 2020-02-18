#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n, m;

    cin >> n >> m ;

    vector<int> cards(n);

    for(int i=0; i<n; i++){
        cin >> cards[i];
    }

    vector<int> check;
    
    for(int i=0; i<3; i++){
        check.push_back(1);
    }
    for(int i=0; i<n-3; i++){
        check.push_back(0);
    }

    sort(check.begin(), check.end());

    int nearM = 0;

    do{
        int tmpSum = 0;
        for(int i=0; i<n; i++){
            if(check[i] == 1){
                tmpSum += cards[i];
            }
        }
        if(tmpSum == m){
            nearM = tmpSum;
            break;
        }else if(tmpSum < m){
            if(tmpSum > nearM){
                nearM = tmpSum;
            }
        }
    }while(next_permutation(check.begin(), check.end()));

    cout << nearM << '\n';

    return 0;
}