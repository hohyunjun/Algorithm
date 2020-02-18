#include <iostream>
using namespace std;

int main(){

    int coins[] = {500,100,50,10,5,1};

    int price;

    cin >> price;

    int change = 1000 - price;

    int ans = 0;

    for(auto each : coins){
        if( change / each != 0 ){
            int tmp = change / each;
            ans += tmp;
            change -= tmp*each;
        }
    }

    cout << ans << '\n';

    return 0;
}