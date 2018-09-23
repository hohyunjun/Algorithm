#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, P;
    cin >> A >> P;

    vector<long long int> G(1000000); // 0으로 초기화된 10000개의 요소를 가지는 G vector 생성
    vector<long long int> D;
    D.push_back(A);

    int n = 0;
    while(1){
        string tmpstr = to_string(D[n]);
        int sum = 0;
        for (int i = 0; i < tmpstr.length(); i++){
            int init = 1;
            for (int j = 0; j < P; j++){
                init *= (tmpstr[i] - '0');
            }
            sum += init;
        }
        D.push_back(sum);
        n+=1;
        G[D[n - 1]] = D[n];
        if(G[D[n]]!=0){
            break;
        }
    }

    int foundIndex;

    for(int i=0; i<D.size(); i++){
        if(D[i]==D[D.size()-1]){
            foundIndex = i;
            break;
        }
    }

    cout << foundIndex << "\n";

    return 0;
}