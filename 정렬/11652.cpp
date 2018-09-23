#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    long long int card[1000000];

    cin >> N;

    long long int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        card[i] = tmp;
    }

    sort(card, card+N);

    long long int ans = card[0];
    int cnt = 1;
    int maxcnt = 1;

    for(int i=1; i<N; i++){
        if(card[i] == card[i-1]){
            cnt++;
        }else{
            cnt = 1;
        }
        if(maxcnt < cnt){
            maxcnt = cnt;
            ans = card[i];
        }
    }

    cout << ans << endl;

    return 0;
}