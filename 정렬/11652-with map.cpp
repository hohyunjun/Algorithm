#include <iostream>
#include <map>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<long long int, int> card;

    int n;
    long long int tmp;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tmp;
        card[tmp] += 1;
    }

    int maxcnt = 0;
    long long int ans = 0;

    for(auto &p:card){
        if(p.second > maxcnt){
            maxcnt = p.second;
            ans = p.first;
        }
    }

    cout << ans << '\n';




    return 0;
}