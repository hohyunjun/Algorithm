#include <iostream>
using namespace std;

int main(){

    int cnt = 20;
    int ans = 0;

    int service = 0;

    while(cnt){

        cnt--;
        ans++;
        service++;

        // 3인분먹으면 하나추가
        if(service == 3){
            ans++;
            service = 0;
        }

    }

    cout << ans << '\n';


    return 0;
}