#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int a[5000001];

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    nth_element(a+1, a+k, a+n+1);

    cout << a[k] << '\n';


    return 0;
}