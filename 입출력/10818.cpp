#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int a;
    int t;
    vector<int> v;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    printf("%d %d", v[0], v[v.size()-1]);

    return 0;
}