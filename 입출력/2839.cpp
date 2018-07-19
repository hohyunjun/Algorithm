#include <iostream>
using namespace std;

int main()
{

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, ans;

    cin >> N;

    if(N%5 == 0){
        ans = N/5;
        cout << ans << endl;
    }else{
        ans = N/5;
        N %= 5;
        while(ans > 0){
            if(N%3 == 0){
                ans += N/3;
                break;
            }
            ans -= 1;
            N += 5;
            if(N%3 == 0){
                ans += N/3;
                break;
            }
        }
        if(ans > 0){
            cout << ans << endl;
        }else if(N%3 == 0){
            ans = N/3;
            cout << ans << endl;
        }else{
            cout << "-1" << endl;
        }
    }

    return 0;
}