#include <iostream>
#include <vector>
using namespace std;

int di[1001];
int dd[1001];

int f(int n){
    int a;
    vector<int> A;
    A.push_back(0);
    for(int i=0; i<n; i++){
        cin >> a;
        A.push_back(a);
    }
    di[1] = 1;
    // di 값을 다 구한다.
    for(int i=2; i<=n; i++){
        int longgest = 0;
        for(int j=1; j<i; j++){
            if(A[j]<A[i]){
                longgest = max(longgest, di[j]);
            }
        }
        di[i] = longgest + 1;
    }

    // dd[i]를 구한다.
    dd[n] = 1;
    for(int i=n-1; i>=1; i--){
        int longgest = 0;
        for(int j=i+1; j<=n; j++){
            if(A[j] < A[i]){
                longgest = max(longgest, dd[j]);
            }
        }
        dd[i] = longgest + 1;
    }

    int answer = 0;
    for(int i=1; i<=n; i++){
        answer = max(answer, di[i] + dd[i] -1);
    }
    return answer;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    cout << f(N) << endl;

    return 0;
}