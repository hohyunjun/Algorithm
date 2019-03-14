#include <iostream>
using namespace std;

int main(){

    int n,s;
    int A[100002];

    cin >> n >> s;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    int left = 0, right = 0, sum = A[0], ans = 999999;
    while(left < n && right < n){
        if(sum >= s){
            ans = min(ans, right-left+1);
            if(sum==s){
                right+=1;
                sum+=A[right];
            }else{
                sum -= A[left];
                left+=1;
            }
        }else{
            right += 1;
            sum += A[right];
        }
    }

    if(ans == 999999) ans = 0;
    cout << ans << '\n';

    return 0;
}