#include <iostream>
using namespace std;

int main(){

    int n, m;
    int a[10002];

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int left = 0, right = 0, sum=a[0], ans = 0;

    while(left < n && right < n){
        if(sum < m){
            right += 1;
            sum += a[right];
        }else if(sum==m){
            ans += 1;
            right += 1;
            sum += a[right];
        }else if(sum > m){
            sum -= a[left];
            left += 1;
        }
    }

    cout << ans << '\n';


    return 0;
}