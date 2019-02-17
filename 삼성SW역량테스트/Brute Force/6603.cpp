#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    while(true){
        int k;
        cin >> k;
        if(k==0) break;

        vector<int> p(k);

        for(int i=0; i<k; i++){
            cin >> p[i];
        }

        sort(p.begin(), p.end());

        vector<int> check;

        for(int i=0; i<6; i++){
            check.push_back(1);
        }
        for(int i=0; i<k-6; i++){
            check.push_back(0);
        }

        do{
            for(int i=0; i<k; i++){
                if(check[i] == 1){
                    cout << p[i] << " ";
                }
            }
            cout << '\n';
        }while(prev_permutation(check.begin(), check.end()));
        cout << '\n';
    }



    return 0;
}