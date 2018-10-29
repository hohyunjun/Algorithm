#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    map<long long int, int> m;

    int N;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        long long int number;
        scanf("%lld", &number);
        m[number] += 1;
    }

    vector<long long int> maxkey;

    int maxcnt = 0;
    for(auto each:m){
        maxcnt = max(maxcnt, m[each.first]);
    }

    for(auto each:m){
        if(m[each.first] == maxcnt){
            maxkey.push_back(each.first);
        }
    }

    sort(maxkey.begin(), maxkey.end());

    printf("%lld\n", maxkey[0]);

    return 0;
}